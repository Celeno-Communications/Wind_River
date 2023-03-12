// Dump eLA memory to file
// Requires HW step B0
// Running this on A0 is not supported.
//
// New in. v 1.2b:
// In asic B0, in many cases eLA fails to stop by writing the la_ctrl_stop bit.
// Bits la_status[1:0] are b'01 instead of expected b'11,
// but the last written index in bits 31:16 of la_status looks correct.
// We must be able to get the data in this situation.
// For this we add switch --force that allows to copy the data if bits 1:0
// of the status are not b'11, with use of wrap-around detection logic.
// Waiting in this case does not make sense, caller must be sure.
// This is ugly and should be revised for future h/w development.

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdbool.h>
#include <errno.h>
#include <getopt.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>

#include "libdevmem.h"


#define VERSION "1.2e"

// Usage
// la_dump [options] OUTFILE - dump LA buffer to file
// la_dump --clear [value]   - fill LA buffer with 32-bit pattern (default=0)

// Options:
// --wait=N: poll for LA stopped (*) during N seconds, then fail.
//          If N<0 do s/w triger(*) and proceed. If N="forever", wait forever.
// --plain : copy from begin to end without wraparound
// --auto : automatically detect buffer begin, end and wrap-around (default)
//          The output data is reordered from 1st to last sample.
//     -v : verbose debug spew
// -f, --force : force copying, no matter what is la_status[1:0]
// --begin=FIRST [--end=LAST] - first,last index (inclusive) Default: 0 to 0xBFF.

// todo options for output format: %8.8X vs %X vs %#X ...
//  4 numbers per line or 1, binary output ...
//  nicely align, use format %8.8X ...
//


#define LA_BUFFER_ADDR     0x0100000
#define LA_MAX_LINE_CNT 0xC00
#define LA_LAST_LINE_NUM (LA_MAX_LINE_CNT - 1)
#define LA_LINE_SIZE 16
#define LA_START_STOP_ADDR 0x0030513C

#define LA_STATUS_REG_ADDR 0x00305110
#define     LA_STATUS_RUN_MASK      0x03
#define     LA_STATUS_RUN_IDLE      0x00
#define     LA_STATUS_RUN_HWTRIG    0x01
#define     LA_STATUS_RUN_ACTIVE    0x02
#define     LA_STATUS_RUN_STOP      0x03
#define     LA_STATUS_WRAP_AROUND   0x10
#define     LA_STATUS_VALID_MASK    0x0FFF0013

#define LA_CTRL_REG_ADDR   0x0030510C
#define     LA_CTRL_START_BIT       0x01
#define     LA_CTRL_STOP_BIT        0x02
#define     LA_CTRL_RESET_BIT       0x10

#define LA_CTRL_INPUT_BUS_POS     10
#define LA_CTRL_INPUT_BUS_MASK    ((uint32_t)0x7)
#define LA_CTRL_MEM_BUS_POS       8
#define LA_CTRL_MEM_BUS_MASK      ((uint32_t)0x3)
#define LA_XT_ENH_MODE_POS        15
#define LA_LMAC_CAPTURE_START_POS 16
#define LA_LMAC_CAPTURE_STOP_POS  17
#define LA_UMAC_CAPTURE_START_POS 24
#define LA_UMAC_CAPTURE_STOP_POS  25
#define LA_XT_ENH_MODE_BIT        ((uint32_t)(1<<15))
#define LA_LMAC_CAPTURE_START_BIT ((uint32_t)(1<<16))
#define LA_LMAC_CAPTURE_STOP_BIT  ((uint32_t)(1<<17))
#define LA_UMAC_CAPTURE_START_BIT ((uint32_t)(1<<24))
#define LA_UMAC_CAPTURE_STOP_BIT  ((uint32_t)(1<<25))

#define LA_CTRL_LOG_MODE_POS 2  // la_mode
#define LA_CTRL_LOG_MODE_MASK ((uint32_t)0x3)


#define LA_BUF_OFF    LA_BUFFER_ADDR
#define LA_CTRL       LA_CTRL_REG_ADDR
#define LA_STATUS     LA_STATUS_REG_ADDR
#define LA_STARTSTOP  LA_START_STOP_ADDR

#define CE_NXMAC_SIGNATURE_ADDR  0x00400000
#define CE_NXMAC_SIGNATURE_ADDR0 (CE_NXMAC_SIGNATURE_ADDR)
#define CE_NXMAC_SIGNATURE_ADDR1 (CE_NXMAC_SIGNATURE_ADDR0 + 0x10000)
#define CE_NXMAC_SIGNATURE_ADDR2 (CE_NXMAC_SIGNATURE_ADDR0 + 0x20000)

#define CL_MMAP_SIZE   0x430000

#define GCU_BASE_ADDR      0x00600000
#define GCU_LOG_RT_CTRL_ADDR (0x00041140 + GCU_BASE_ADDR)


static void usage(const char *cmd)
{
   fprintf(stderr, 
        "\nla_dump_mem v." VERSION "\n"
        "Usage:\n"
        "%s OUTFILE - check LA status and dump memory to OUTFILE\n"
        "%s --clear [value=0] - fill the memory\n"
        "  --plain  : dump from first to last index, not using la_status wrap-around detection logic.\n"
        "  --wait=N : poll for N seconds for LA to stop. If N<0 trigger and proceed, else fail\n"
        "             --wait forever : poll forever\n"
        "  --auto : auto detect start, stop and wrap-around index (default on B0)\n"
        "  --begin=FIRST --end=LAST - first,last index (inclusive) Default: 0 to 0xBFF.\n"      
        "  --force : copy data no matter what, ignore la_status\n"
        "  -v      : verbose prints\n"
        "  --clear[=value=0] : clear logger memory (no other parameters)\n"
        "\nExit status: 0=success, 20-23: unexpected LA state (0-3)\n"
        "\n",
        cmd, cmd);
}

static struct option aopts[] = {
{ "auto",    no_argument,       NULL, 'w'},   // Auto detect begin, end, wraparound. Requires step B.
{ "begin",   required_argument, NULL, 'F'},   // begin index in plain mode ('FROM')
{ "end",     required_argument, NULL, 'T'},   // end inclusive index in plain mode ('TO')
{ "plain",   no_argument,       NULL, 'A'},   // Dump whole buffer in plain mode
{ "wait",    required_argument, NULL, 't'},   // Poll for N sec. for LA stop, then fail or trigger
{ "force",        no_argument,  NULL, 'f'},   // Force copying even if status is not stopped
{ "force-with-status", no_argument,  NULL, 'x'},  // as above but exit status reflects LA status
                                              //   If N<0 force stop and proceed.
{ "help",    no_argument,       NULL, '?'},
{ "clear",   optional_argument, NULL, 'C'},   // fill [with value]
{0,0,0,0},
};

static int g_dbg = 0;
static int g_wait_stop_sec = 0;
static bool g_auto_wrap = true; // default: --auto
static bool g_force     = false;
static bool g_force_ret_status = false; // return status (20+x) when used --force
static uint32_t g_real_la_status = 0;
static uint32_t g_fill_val32 = 0;

static int la_sts_to_exst(uint32_t sts);
static unsigned strtou32_strict(uint32_t *pnum, const char *str);
static int strtoint_strict(int *pnum, const char *str);



static void stop_lcu(struct dmem_mapping_s *dm)
{
    //gcu_log_rt_ctrl_lcu_stop_setf(1);
    uint32_t v32 = dmem_read32(dm, GCU_LOG_RT_CTRL_ADDR);
    dmem_write32(dm, GCU_LOG_RT_CTRL_ADDR, (v32 | 0x00000020));
}

// Use heuristic to restore unreadable la_ctrl bits to STOP:
static uint32_t recover_stop_bits(uint32_t ctrl)
{
    switch ((ctrl >> LA_CTRL_MEM_BUS_POS) & LA_CTRL_MEM_BUS_MASK)
    {
       case 0: //MAC
             break; // nothing special
       case 1: // LCU
             // stop bit and status - in its own register set
             fprintf(stderr, "WARNING: LCU mode not supported! use lcu_driver!\n");
             break;
       case 2: // LMAC
             ctrl |= LA_LMAC_CAPTURE_STOP_BIT;
             break;
       case 3: // UMAC
             ctrl |= LA_UMAC_CAPTURE_STOP_BIT;
             break;
    }
    ctrl &= ~LA_CTRL_START_BIT; // clear la_ctrl_start bit (paranoic...)
    ctrl |= LA_CTRL_STOP_BIT;   // main stop bit, good for all modes
    return ctrl;
}

static int wait_stopped(struct dmem_mapping_s *dm, int wait_s)
{
    // Poll for LA ready for wait_s seconds
  
    bool force_trigger = false;
    bool wait_forever = (wait_s == INT_MAX);
    uint32_t sts;

    if (wait_s < 0) {
       wait_s = -wait_s;
       force_trigger = true;
    }

    // Poll for LA stopped, every 1 sec:
    do {
       sts = dmem_read32(dm, LA_STATUS);
       g_real_la_status = sts;
       if (g_dbg > 2) fprintf(stderr, "poll LA_STATUS=%#x\n", sts);
       if (0 != (sts & ~LA_STATUS_VALID_MASK)) {
         fprintf(stderr, "ERROR: Undefined bits set in LA status! %#8.8X\n", sts);
         return 2;
       }

       if ( (sts & LA_STATUS_RUN_MASK) == LA_STATUS_RUN_STOP ) {
          return 0; // Trace done
       }
      
       if ( g_force ) {
          if (g_dbg) {
             switch (sts & LA_STATUS_RUN_MASK) {
                case LA_STATUS_RUN_IDLE:   fprintf(stderr, "LA is idle\n"); break;
                case LA_STATUS_RUN_HWTRIG: fprintf(stderr, "LA is hw-triggered\n"); break;
                case LA_STATUS_RUN_ACTIVE: fprintf(stderr, "LA is active!\n"); break;
             }
          }
         return 0; // do not loop, go anyway
       }

       if (wait_s-- > 0) sleep(1);

    } while( wait_s > 0 || wait_forever);

    // Timeout and LA not stopped
    if (!force_trigger) {
          fprintf(stderr, "LA is not stopped! sts=%#x\n", sts);
          return la_sts_to_exst(sts);
    }

    // Force stop LA logger:
    // Preserve CTRL bits - this is needed for Xtensa and possibly other sources;
    // Must not write LA_CTRL without these bits - otherwise status does not read correctly.
    uint32_t ctrl = dmem_read32(dm, LA_CTRL);
    ctrl = recover_stop_bits(ctrl);

    if ( 1 == (ctrl >> LA_CTRL_MEM_BUS_POS) & LA_CTRL_MEM_BUS_MASK ) {
       // LCU mode: stop it, but don't know how to detect start/stop index!
       stop_lcu(dm);
    }

    dmem_write32(dm, LA_CTRL, ctrl);
    usleep(500);
    sts = dmem_read32(dm, LA_STATUS);
    g_real_la_status = sts;

    if ( (sts & LA_STATUS_RUN_MASK) == LA_STATUS_RUN_STOP ) {
        fprintf(stderr, "LA force-stopped! sts=%#x\n", sts);
        return 0;
    }
   
    fprintf(stderr, "LA failed to stop! sts=%#x\n", sts);
    return la_sts_to_exst(sts);
}


static int la_get_buf_ranges(struct dmem_mapping_s *dm, 
                             int *b1, int *e1, int *b2, int *e2)
{
       int start1, stop1, start2, stop2;
       uint32_t startstop = dmem_read32(dm, LA_STARTSTOP);
       stop1  = startstop >> 16;
       start1 = startstop & 0xFFFF;
       
       if ( stop1 > LA_LAST_LINE_NUM || start1 > LA_LAST_LINE_NUM || (start1 >= stop1) )
       { 
           printf("ERROR: LA start/stop reg value bad! %#x\n", startstop);
           return -1;
       }
       
       uint32_t sts = dmem_read32(dm, LA_STATUS);
       int wrap = !!(sts & LA_STATUS_WRAP_AROUND);
       uint32_t last_written;
       last_written = sts >> 16;
       
       if ( last_written > stop1 || last_written < start1 ) {
           printf("ERROR: LA last written index not in [start,stop] %#x %#x\n", startstop, last_written);
           return -1;
       }

       if (wrap) {
            if (last_written == stop1) {
                 start2 = stop2 = -1;
            } else {
                 start2 = start1;
                 stop2 = last_written; 
                 start1 = last_written + 1;
            }

            printf("Detected start=%d %#x stop=%d %#x wrap_pos=%d %#x\n", start1, start1, stop1, stop1, last_written, last_written);

       } else {
           stop1 = last_written; // not wrapped => last = last_written
           start2 = stop2 = -1;
           printf("Detected start=%d %#x last_wr=%d %#x \n", start1, start1, last_written, last_written);
       }

       *b1 = start1; *b2 = start2; *e1 = stop1; *e2 = stop2;
       return 0;
}

// Write one 4-word element
void write_out(FILE *fo, uint32_t data[4], int index)
{
   static const char frmt[] = 
      "%X %X %X %X # [0x%X]\n";  // 1,2,3,4
   //   "#8.8%X %#8.8X %#8.8X %#8.8X # %u\n";  // 1,2,3,4
   //   "#4$8.8%X  %1$#8.8X %2$#8.8X %3$#8.8X # %5$u\n"; // 4,1,2,3
   fprintf(fo, frmt, data[0], data[1], data[2], data[3],  index);
}


static int la_fill_mem(struct dmem_mapping_s *dm, uint32_t fill_val32)
{
    // Fill LA memory with 32-bit pattern, currently removed
    // TODO honor start& stop parameters, force=> reset LA

    return 0;
}


int main(int argc, char **argv)
{
    const char *progname = argv[0];
    int rc = 0;
    uint32_t nfirst = 0, nlast = LA_LAST_LINE_NUM;
    char *fname = NULL;   
    int opt;
    int longindex;

    struct dmem_mapping_s dms = {
      .map_addr = 0,  // from device offset 0
      .map_size = CL_MMAP_SIZE, 
      //.flags = MF_READONLY,  // need to write to stop LA
      };
   
    fprintf(stderr, "DUMP LA MEM v.%s\n", VERSION);

    while ((opt = getopt_long_only(argc, argv, "fxvwF:T:t:", aopts, &longindex)) != -1) 
    {
        //printf("opt %c optind=%d\n", opt,  optind); 
        switch(opt) {
            case 'v': //verbose
                g_dbg++;
                break;
            case 'A':
                if(g_dbg) printf("Dump all plain\n");
                g_auto_wrap = false;
                break;
            case 'w':
                if(g_dbg) printf("Detect buffer limits and wraparound\n");
                g_auto_wrap = true;
                break;
            case 'F':
                if(g_dbg) printf("From index: %s\n", optarg);
                rc = strtou32_strict(&nfirst, optarg);
                if (rc) goto err_args;
                break;
            case 'T':
                if(g_dbg) printf("To index: %s\n", optarg);
                rc += strtou32_strict(&nlast, argv[2]);
                if (rc) goto err_args;
                break;
            case 't':
                if(g_dbg) printf("WaitSec=%s\n", optarg);
                if (0 == strcasecmp(optarg, "forever") || 0 == strcasecmp(optarg, "INF")) {
                    g_wait_stop_sec = INT_MAX;
                } else {
                    rc = strtoint_strict(&g_wait_stop_sec, optarg);
                    if (rc) goto err_args;
                }
                break;
            case 'f': // --force
               if(g_dbg) printf("Ignore LA status\n");
               g_force = true;
               break;
            case 'x': // --force-with-status
               if(g_dbg) printf("Ignore LA status and return exit code 20+n\n");
               g_force = true;
               g_force_ret_status = true;
               break;
            case 'C':
                if (optarg) {
                    int n;
                    rc = strtoint_strict(&n, optarg);
                    if (rc) goto err_args;
                    g_fill_val32 = n;
                }
                return la_fill_mem(&dms, g_fill_val32);

            case '?':
                if (argv[optind-1] && strstr(argv[optind-1], "help")) {
                     usage(progname);
                } else {
                    fprintf(stderr, "Unknown option, --help for usage %s\n", argv[optind-1]);
                }
                return 1;
       }
    }

    fname = argv[optind];
    if (!fname) {
       fprintf(stderr, "Missing output filename. Run with --help for usage\n");
       return 1;
    }

    if(g_dbg) fprintf(stderr, "Output filename %s\n", fname);

    if ( nlast < nfirst || 
       nfirst > LA_LAST_LINE_NUM || 
       nlast > LA_LAST_LINE_NUM )
    {
       fprintf(stderr, "End index < begin or out of range\n");
       exit(1);
    }

    rc = dmem_init();  // libdevmem
    if (rc == 0) {
        rc = dmem_mapping_map(&dms);
        //printf("rc=%d va=%p\n", rc, dms.map_ptr);
    }

    if (rc != 0 || !dms.map_ptr) {
       fprintf(stderr, "ERROR: cannot access device memory!\n");
       dmem_print_version();
       exit(2);
    }

    //Sanity: is alive?
    uint32_t v = dmem_read32(&dms, CE_NXMAC_SIGNATURE_ADDR0);
    if (v != 0x05) {
       fprintf(stderr, "ERROR: signature0 bad! %#X\n", v);
       return 2;
    }

    rc = wait_stopped(&dms, g_wait_stop_sec);
    if ( 0 != rc ) {
       return rc;
    }

    FILE *fo = fopen(fname, "wt");
    if (!fo) {
        fprintf(stderr, "ERROR: cannot create output file %s\n", fname);
        exit(2);
    }

    int start1, stop1, start2 = -1, stop2 = -1; // 2 ranges in case of wraparound
    start1 = nfirst; stop1 = nlast;

    if (g_auto_wrap) {
       // Use start & stop register and detect wrap-around
       // This requires B0 chip (on FPGA - only the right mode!)
#if 0 // do not probe for B0, rely on environment
       v = dmem_read32(&dms, CE_NXMAC_SIGNATURE_ADDR2);
       if (v != 0x05) {
           fprintf(stderr, "ERROR: Not B0 device? MU2 signature bad! %#X\n", v);
           return 2;
       }
#endif
       rc = la_get_buf_ranges(&dms, &start1, &stop1, &start2, &stop2);
       if (rc != 0) {
           fprintf(stderr, "ERROR: could not detect written area\n");
           return 4;
       }
    }

    uint32_t *q = (uint32_t*)dmem_get_pointer(&dms, LA_BUF_OFF, LA_MAX_LINE_CNT*16);
    int ecnt = stop1 - start1 + 1;
    int i = 0;
    uint32_t *p;

    for (i = 0, p = q + (start1 * 4); i < ecnt; i++, p += 4) {
       uint32_t v[4];
       dmem_read_buf32p(p, v, 4); // read one LA entry: 4*uint32
       write_out(fo, v,  (i + start1));
    }

    if (start2 >= 0) {
        fprintf(fo, "#------------ Wrap-around---------\n");
        ecnt = stop2 - start2 + 1;
        for (i = 0, p = q + (start2 * 4); i < ecnt; i++, p += 4) {
            uint32_t v[4];
            dmem_read_buf32p(p, v, 4); // read one LA entry: 4*uint32
            write_out(fo, v, (i + start2));
        }
    }

    fclose(fo);

    fprintf(stderr, "----------- done -----------\n");

    if (!g_force_ret_status)
        return 0;
    
    return la_sts_to_exst(g_real_la_status);
   
  err_args:
    printf("Error in command parameters\n");
    return 2;
}


// Make return status from LA status
// Returns 20 +
// - running, waiting for trigger: 1
// - running, triggered: 2
// - triggered and stopped: 3
// - idle: 0
static int la_sts_to_exst(uint32_t sts)
{
   return (sts & 0x3) + 20;
}

static unsigned strtou32_strict(uint32_t *pnum, const char *str)
{
    char *endp = NULL;
    unsigned long u;
    errno = 0;
    u = strtoul(str, &endp, 0);
    if (errno != 0 || (endp && 0 != *endp)) {
        return -1;
    }
    if (u > UINT32_MAX) {
        return -2;
    }
    *pnum = (unsigned)u;
    return 0;
}


static int strtoint_strict(int *pnum, const char *str)
{
   return (int)strtou32_strict( (uint32_t*)pnum, str );
}

