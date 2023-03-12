/*
 * EEPROM Driver
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include "cl_common.h"
#include "cl_reg.h"
//----------------------------
// MACRO
//----------------------------
  
#define FATAL do { fprintf(stderr, "Error at line %d, file %s (%d) [%s]\n", \
  __LINE__, __FILE__, errno, strerror(errno)); exit(1); } while(0)

#define MY_FATAL(err) do { fprintf(stderr, "Error at line %d, file %s [Error: %s]\n", \
  __LINE__, __FILE__, err); exit(1); } while(0)

#define __FUNC_ENTRY__ if (verbose) { printf(">>> %s: Entry\n",__func__); }

#define E2P_OK   (0)
#define E2P_FAIL (-1)

// EEPROM Parameters - Suitable for ATMEL AT24C16BN
#define EEPROM_SIZE     (0x800)                 // 2KB = 16Kbit
#define PAGE_SIZE       (unsigned long )0x10   // 16 Bytes
#define PAGE_MASK       ((PAGE_SIZE) - 1)       // 0xF
#define PAGE_SHIFT      (0x4)

#define PAGE_NUM(addr)                  (addr>>PAGE_SHIFT)
#define PAGE_OFF(addr)                  (addr&PAGE_MASK)
#define EEPROM_OFFSET(page,page_off)    ((page<<PAGE_SHIFT)|page_off)

typedef enum
{
	BIT0,
	BIT1,
	BIT2,
	BIT3,
	BIT4,
	BIT5,
	BIT6,
	BIT7,
	BIT8,
	BIT9,
	BIT10,
	BIT11,
	BIT12,
	BIT13,
	BIT14,
	BIT15,
	BIT16,
	BIT17,
	BIT18,
	BIT19,
	BIT20,
	BIT21,
	BIT22,
	BIT23,
	BIT24,
	BIT25,
	BIT26,
	BIT27,
	BIT28,
	BIT29,
	BIT30,
	BIT31
} BITNUM;

#define _BIT(pos) (1U<<(pos)) 

#define I2CE_BASE    0x607C3000

////////////////////////////////////////////////////////////////////////////////
// MACSYS_I2C:: PRERLO (0x0) - Clock Prescale register lo-byte
// Width: 8, Access: RW, Reset: 0xff.
#define I2C_PRERLO (I2CE_BASE + 0x0)

// 7:0 P_LO
#define P_LO    (BIT0)

#define P_LO_MASK          (0xFF<<P_LO)

////////////////////////////////////////////////////////////////////////////////
// MACSYS_I2C:: PRERHI (0x4) - Clock Prescale register lo-byte
// Width: 8, Access: RW, Reset: 0xff.
#define I2C_PRERHI (I2CE_BASE + 0x4)

// 7:0 P_HI
#define P_HI    (BIT0)

#define P_HI_MASK          (0xFF << P_HI)


////////////////////////////////////////////////////////////////////////////////
// MACSYS_I2C:: CTR (0x8) - Control Register
// Width: 8, Access: RW, Reset: 0x00.
#define I2C_CTR (I2CE_BASE + 0x8)

// 7 EN 
// 6 IEN
#define EN    (BIT7) // ‘1’ the core is enabled.
#define IEN   (BIT6) // ‘1’ interrupt is enabled.

////////////////////////////////////////////////////////////////////////////////
// MACSYS_I2C:: TXR_RXR (0xC) - Transmit Register - Data
// Width: 8, Access: W, Reset: 0x00.
#define I2C_TXD (I2CE_BASE + 0xC)

// 7:0 TXD
#define TXD    (BIT0) // Next byte to transmit via I2C

#define TXD_MASK          (0xFF<<TXD)

////////////////////////////////////////////////////////////////////////////////
// MACSYS_I2C:: TXR_RXR (0xC) - Transmit Register - Address
// Width: 8, Access: W, Reset: 0x00.
#define I2C_TXADDR (I2CE_BASE + 0xC)

// 7:1 TXADDR
// 0 RDWR
#define TXADDR      (BIT1) // I2C Slave Address
#define RDWR        (BIT0) // ‘1’ = reading from slave. ‘0’ = writing to slave.

#define TXADDR_MASK          (0x7F<<TXADDR)

////////////////////////////////////////////////////////////////////////////////
// MACSYS_I2C:: TXR_RXR (0xC) - Receive Register
// Width: 8, Access: R, Reset: 0x00.
#define I2C_RXD (I2CE_BASE + 0xC)

// 7:0 RXD
#define RXD    (BIT0) // Last byte received via I2C.

#define RXD_MASK          (0xFF<<RXD)

////////////////////////////////////////////////////////////////////////////////
// MACSYS_I2C:: CR_SR (0x10) - Command Register
// Width: 8, Access: WC, Reset: 0x00.
#define I2C_CR (I2CE_BASE + 0x10)

// 7 STA
// 6 STO
// 5 RD
// 4 WR
// 3 ACK
// 2:1 RES
// 0 IACK
#define STA     (BIT7) // generate (repeated) start condition.
#define STO     (BIT6) // generate stop condition.
#define RD      (BIT5) // read from slave.
#define WR      (BIT4) // write to slave.
#define ACK     (BIT3) // when a receiver, sent ACK (ACK = ‘0’) or NACK (NACK = ‘1’).
#define IACK    (BIT0) // Interrupt acknowledge, When set, clears a pending interrupt.

////////////////////////////////////////////////////////////////////////////////
// MACSYS_I2C:: CR_SR (0x10) - Status Register
// Width: 8, Access: R, Reset: 0x00.
#define I2C_SR (I2CE_BASE + 0x10)

// 7 RX_ACK
// 6 BUSY
// 5 AL
// 4:2 RES
// 1 TIP
// 0 IF
#define RX_ACK      (BIT7) // Received acknowledge from slave - ‘1’ = No acknowledge received
#define BUSY        (BIT6) // I2C bus busy - ‘1’ after START signal detected. ‘0’ after STOP signal detected.
#define AL          (BIT5) // Arbitration lost - This bit is set when the core lost arbitration.
#define TIP         (BIT1) // Transfer in progress. ‘1’ when transferring data. ‘0’ when transfer complete.
#define IF          (BIT0) // Set when interrupt is pending, cause a processor interrupt if the IEN bit is set.

//----------------------------
// Global Variable
//----------------------------
int verbose = 0;
int dry_run = 0;


void cl_e2p_init()
{
    __FUNC_ENTRY__

    // Disable I2C Core
    cl_reg_clear_bit(I2C_CTR,_BIT(EN)); // (0x607C3000)+(0x8)

    // pclk = 240MHz, desired SCL = 400KHz.
    // Prescale = [240e6 / (5*400e3) ] – 1 = 120 -1 = 119 = 77h

    // Set Pre-Scaler LO
    cl_reg_write32(I2C_PRERLO, 0x77); // (0x607C3000)+(0x0)
    
    // Set Pre-Scaler Hi
    cl_reg_write32(I2C_PRERHI, 0x0); // (0x607C3000)+(0x4)

    // Enable I2C Core
    cl_reg_set_bit(I2C_CTR,_BIT(EN)); // (0x607C3000)+(0x8)
}


void cl_e2p_test()
{
    __FUNC_ENTRY__

    uint32_t val = cl_reg_read32(0x607C50e0); // (0x607C5000)+(0xe0)
    printf("MACSYS_GCU_XT_CONTROL=0x%x.\n", val);
}

#define I2C_EEPROM_ADDR(page)   (0xA0|((page>>3)&0xE)) // [1-0-1-0-P2-P1-P0-0]
#define E2P_MAX_POLLS 100

#define I2C_POLL_XFER_ACKED   \
{   \
    int __val, __cnt=0; \
    usleep(1000); \
    while( ((__val=cl_reg_read32(I2C_SR)) & _BIT(TIP)) && (++__cnt < E2P_MAX_POLLS) ); \
    if(__cnt==E2P_MAX_POLLS) MY_FATAL("Reach Retry Count"); \
    if(__val & _BIT(RX_ACK)) MY_FATAL("No ACK"); \
    if(verbose) {printf("I2C_POLL_XFER_ACKED: val=%Xh, cnt=%d.\n", __val, __cnt);} \
}

#define I2C_POLL_XFER_NO_ACKED   \
{   \
    int __val, __cnt=0; \
    usleep(1000); \
    while( ((__val=cl_reg_read32(I2C_SR)) & _BIT(TIP)) && (++__cnt < E2P_MAX_POLLS) ); \
    if(__cnt==E2P_MAX_POLLS) MY_FATAL("Reach Retry Count"); \
    if(!(__val & _BIT(RX_ACK))) MY_FATAL("No NO_ACK"); \
    if(verbose) {printf("I2C_POLL_XFER_NO_ACKED: val=%Xh, cnt=%d.\n", __val, __cnt);} \
}

#define I2C_START_WRITE(page) \
    cl_reg_write32(I2C_TXADDR, (I2C_EEPROM_ADDR(page)) & TXADDR_MASK); \
    cl_reg_write32(I2C_CR, _BIT(STA)|_BIT(WR));

#define I2C_START_READ(page)  \
    cl_reg_write32(I2C_TXADDR, ((I2C_EEPROM_ADDR(page)) & TXADDR_MASK) | _BIT(RDWR)); \
    cl_reg_write32(I2C_CR, _BIT(STA)|_BIT(WR));

#define I2C_WRITE(data)   \
    cl_reg_write32(I2C_TXD, data & TXD_MASK); \
    cl_reg_write32(I2C_CR, _BIT(WR));

#define I2C_READ(data)   \
    cl_reg_write32(I2C_CR, _BIT(RD)); \
    I2C_POLL_XFER_ACKED; \
    data = cl_reg_read32(I2C_RXD) & RXD_MASK;

#define I2C_WRITE_STOP(data)   \
    cl_reg_write32(I2C_TXD, data & TXD_MASK); \
    cl_reg_write32(I2C_CR, _BIT(STO)|_BIT(WR));

#define I2C_READ_STOP(data)   \
    cl_reg_write32(I2C_CR, _BIT(STO)|_BIT(RD)|_BIT(ACK)); \
    I2C_POLL_XFER_NO_ACKED \
    data = cl_reg_read32(I2C_RXD) & RXD_MASK;

//
// Name: cl_e2p_read_byte_random()
// Description: This read operation indicating the offset to read from.
//
unsigned int cl_e2p_read_byte_random(int addr)
{
	unsigned int val;

	__FUNC_ENTRY__

	// clock in the address to read from.
	I2C_START_WRITE(PAGE_NUM(addr));
	I2C_POLL_XFER_ACKED;
	I2C_WRITE(addr); // addr 8 lsbits are 4 bits page lsbits or`ed with 4 bits page offset
	I2C_POLL_XFER_ACKED;

	// read single byte
	I2C_START_READ(PAGE_NUM(addr));
	I2C_POLL_XFER_ACKED;
	I2C_READ_STOP(val);

	return val;
}

//
// Name: cl_e2p_read_byte_current()
// Description: This read operation is without indicating the offset to read from.
// The address is only needed for the device address which is don't care.
// The internal data word address counter maintains the last address accessed
// during the last read or write operation, incremented by one.
//
unsigned int cl_e2p_read_byte_current()
{
	unsigned int val;

	__FUNC_ENTRY__

	// read single byte - page number is don't care
	I2C_START_READ(0x0);
	I2C_POLL_XFER_ACKED;
	I2C_READ_STOP(val);

	return val;
}

//
// Name: cl_e2p_read_byte_sequential()
// Description: This is a multi-read operation.
// As long as the EEPROM receives an acknowledge, it will continue to increment
// the data word address and serially clock out sequential data words.
//
void cl_e2p_read_byte_sequential(int addr, unsigned char * val, int num_of_bytes)
{
	int i;
	__FUNC_ENTRY__

		// clock in the address to read from.
	I2C_START_WRITE(PAGE_NUM(addr));
	I2C_POLL_XFER_ACKED;
	I2C_WRITE(addr); // addr 8 lsbits are 4 bits page lsbits or`ed with 4 bits page offset
	I2C_POLL_XFER_ACKED;

	// read single byte
	I2C_START_READ(PAGE_NUM(addr));
	I2C_POLL_XFER_ACKED;

	// clock in the read data.
	for(i=0;i<(num_of_bytes-1);i++,val++)
	{
		I2C_READ(*val);
		//I2C_POLL_XFER_ACKED;
	}

	// read last byte
	I2C_READ_STOP(*val);
}

//
// Name: cl_e2p_write_byte()
// Description: This is a write single byte operation indicating the offset to write to.
//
void cl_e2p_write_byte(int addr,unsigned int val)
{
	__FUNC_ENTRY__

	// clock in the address to write to.
	I2C_START_WRITE(PAGE_NUM(addr));
	I2C_POLL_XFER_ACKED;
	I2C_WRITE(addr); // addr 8 lsbits are 4 bits page lsbits or`ed with 4 bits page offset
	I2C_POLL_XFER_ACKED;

	// clock in the data to write
	I2C_WRITE_STOP(val);
	I2C_POLL_XFER_ACKED;
}

//
// Name: cl_e2p_write_page()
// Description: This is a write page (up to 16 bytes) operation indicating the offset to write to.
//
int cl_e2p_write_page(int page,int off,unsigned char * val, int num_of_bytes)
{
	int i;

	__FUNC_ENTRY__

	if (num_of_bytes > PAGE_SIZE)
		return E2P_FAIL;


	// clock in the address to write to.
	I2C_START_WRITE(page);
	I2C_POLL_XFER_ACKED;
	I2C_WRITE(EEPROM_OFFSET(page,off)); // addr 8 lsbits are 4 bits page lsbits or`ed with 4 bits page offset
	I2C_POLL_XFER_ACKED;

	// clock in the data to write.
	for(i=0;i<(num_of_bytes-1);i++,val++)
	{
		I2C_WRITE(*val);
		I2C_POLL_XFER_ACKED;
	}

	// clock in the last data byte to write
	I2C_WRITE_STOP(*val);
	I2C_POLL_XFER_ACKED;

	// Make sure to wait longer before moving to another page - Not sure why
	usleep(2000);

	return E2P_OK;
}

//
// Name: cl_e2p_write()
// Description: This is a general write function
//
int cl_e2p_write(int addr,unsigned char * val, int num_of_bytes)
{
	int offset,size,i=0;

	__FUNC_ENTRY__
		if (verbose) printf("%s: addr=%Xh,num_of_bytes=%Xh.\n",__func__,addr,num_of_bytes);

	if (num_of_bytes > EEPROM_SIZE)
		return E2P_FAIL;

	while(num_of_bytes>0)
	{
		offset = PAGE_OFF(addr);

		if ( num_of_bytes > PAGE_SIZE - offset )
			size = PAGE_SIZE - offset;
		else
			size = num_of_bytes;

		if (verbose) printf("loop%d: page=%Xh,offset=%Xh,val=%Xh,size=%Xh.\n",i++,PAGE_NUM(addr),offset,*val, size);
		cl_e2p_write_page(PAGE_NUM(addr),offset,val, size);

		num_of_bytes -= size;
		addr += size;
		val += size;
	}

	return E2P_OK;
}


int dump_file_to_buf(char * filename, unsigned char * buf, int * buf_size)
{
	FILE *fp;
	unsigned int size;
	size_t ret;

	__FUNC_ENTRY__

	fp = fopen(filename,"r");

	if (fp == 0)
	{
		if (verbose)
			printf("\nERROR: can't find %s\n\n", filename);

		return E2P_FAIL;
	}

	fseek(fp, 0, SEEK_END);
	size = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	if (size > *buf_size) 
	{
		if (verbose)
			printf("\nERROR: %s too large (filesize=%Xh,e2p_size=%Xh).\n\n", filename, size, *buf_size);

		fclose(fp);
		return E2P_FAIL;
	}

	ret = fread(buf, size, 1, fp);

	if (ret != 1)
		printf("\nERROR: %s fread() failure (ret = %zu).\n\n", filename, ret);

	fclose(fp);
	//    buf[size] = 0;
	*buf_size = size;

	return E2P_OK;
}


void hex_dump(char *str, unsigned char *src, unsigned int len, int is_hex)
{       
	unsigned char *pt;
	int x;

	pt = src;
	if(is_hex)
	{
		printf("%s: %p, len = %d\n", str, src, len);
		for (x=0; x<len; x++)
		{
			if (x % 16 == 0)
			{
				printf("0x%04x : ", x);
			}
			printf("%02x ", ((unsigned char)pt[x]) );
			if (x % 16 == 15)
			{
				printf("\n");
			}
		}
		printf("\n");
	}
	else
	{
		printf("%s: %p, len = %d\n", str, src, len);
		for (x=0; x < (len >> 2); x++)
		{
			if (x % 4 == 0)
			{
				printf("0x%04zx : ", x*(sizeof(long)));
			}
			printf("%08lx ", *((unsigned long *)(pt+x*sizeof(long))));
			if (x % 4 == 3)
			{
				printf("\n");
			}
		}
		printf("\n");
	}
}


void usage(char * cmd)
{
        fprintf(stderr, 
            "\nUsage:\t%s [opt] cmd\n"
            "\t options: \n"
            "\t\t -d - dry-run \n"
            "\t\t -v - verbose \n"
            "\t\t -h - help \n"
            "\t commands: \n"
            "\t init      : I2C init\n"
            "\t test      : I2C test\n"
            "\t read      : Read Byte from eeprom\n"
            "\t\t example: \n"
            "\t\t > cl_e2p read 0x20\n"
            "\t\t description: read from eeprom offset 0x20. \n"
            "\t read_seq  : Sequential Read from eeprom\n"
            "\t\t example: \n"
            "\t\t > cl_e2p read_seq 0x0 0x800\n"
            "\t\t description: read all eeprom. from offset 0x0 to 2KB.\n"
            "\t write     : Write Byte to eeprom\n"
            "\t\t example: \n"
            "\t\t > cl_e2p write 0x20 0x99 \n"
            "\t\t description: burn 0x99 to eeprom offset 0x20. \n"
            "\t writefile : Write File to eeprom\n"
            "\t\t example: \n"
            "\t\t > cl_e2p writefile 0x0 eeprom.img \n"
            "\t\t description: burn all eeprom.img file from the start of the eeprom. \n"
            "\t\n\n\n",
           cmd);
}


//----------------------------
// Main
//----------------------------
int main(int argc, char **argv)
{
	int e2p_addr = 0;
	int opt;

	while ((opt = getopt(argc, argv, "dvhb:")) != -1)
	{
		switch (opt) 
		{
			case 'd':
				dry_run = 1;
				printf("%s in dry_run mode.\n",argv[0]); 
				break;
			case 'v':
				verbose = 1;
				printf("%s in verbose mode.\n",argv[0]); 
				break;
			case 'h':
				usage(argv[0]);
				exit(EXIT_FAILURE);
				break;
			default: /* '?' */
				usage(argv[0]);
				exit(EXIT_FAILURE);
		}
	}

	if (optind >= argc) 
	{
		fprintf(stderr, "Expected command after options\n");
		usage(argv[0]);
		exit(EXIT_FAILURE);
	}

	if (verbose) 
	{
		//printf("MMap Size = %lx\n", MAP_SIZE);
		//printf("MMap Mask = %lx\n", MAP_MASK);
		//printf("MMap Phys = %p\n", phys_base_addr);
	}

	if (cl_reg_open())
	{
		perror("cl_reg_open");
		exit(EXIT_FAILURE);
	}

	// Command Execute
	if (strcmp(argv[optind], "init") == 0)
		cl_e2p_init();
	else if (strcmp(argv[optind], "test") == 0)
		cl_e2p_test();
	else if (strcmp(argv[optind], "read") == 0) 
	{
		unsigned int val;

		if (argc != optind + 2)
		{
			printf("illegal usage - %s expected offset...\n\n",argv[optind]);
			exit(EXIT_FAILURE);
		}

		sscanf(argv[optind + 1], "0x%x", &e2p_addr);

		val = cl_e2p_read_byte_random(e2p_addr);
		printf("E2PROM[%Xh]: val=%Xh.\n",e2p_addr,val);
	}
	else if (strcmp(argv[optind], "read_current") == 0) 
	{
		unsigned int val;

		if (argc != optind + 1)
		{
			printf("illegal usage - %s does not expect offset...\n\n",argv[optind]);
			exit(EXIT_FAILURE);
		}

		val = cl_e2p_read_byte_current();
		printf("E2PROM->current: val=%Xh.\n",val);
	}
	else if (strcmp(argv[optind],"read_seq") == 0) 
	{
		unsigned char *e2p_buf;
		int num_of_bytes;
		char prefix[120];

		if( argc != optind + 3 )
		{
			printf("illegal usage - %s expected offset & size...\n\n",argv[optind]);
			exit(EXIT_FAILURE);
		}

		sscanf(argv[optind+1], "0x%x", &e2p_addr);
		sscanf(argv[optind+2], "0x%x", &num_of_bytes);

		if (num_of_bytes > EEPROM_SIZE - e2p_addr)
			num_of_bytes = EEPROM_SIZE - e2p_addr;

		e2p_buf = malloc(num_of_bytes);

		if (verbose)
			printf("%s: e2p_addr=0x%Xh, num_of_bytes=%Xh.\n", argv[optind], e2p_addr,num_of_bytes);

		cl_e2p_read_byte_sequential(e2p_addr, e2p_buf, num_of_bytes);

		sprintf(prefix, "eeprom->read_seq[%s]", argv[optind+1]);

		hex_dump(prefix, e2p_buf, num_of_bytes, 1);

	}
	else if (strcmp(argv[optind], "write") == 0)
	{
		unsigned int val;

		if( argc != optind + 3 )
		{
			printf("illegal usage - %s expected offset & value...\n\n",argv[optind]);
			exit(EXIT_FAILURE);
		}

		sscanf(argv[optind+1], "0x%x", &e2p_addr);
		sscanf(argv[optind+2], "0x%x", &val);

		printf("writing %Xh to addr %Xh.\n", val, e2p_addr);
		cl_e2p_write_byte(e2p_addr,val);

		//     val=cl_e2p_read_byte_random(e2p_addr);
		//      printf("E2PROM[%Xh]: val=%Xh.\n",e2p_addr,val);
	}
	else if (strcmp(argv[optind], "writefile") == 0) 
	{
		char filename[120];
		unsigned char e2p_buf[EEPROM_SIZE];
		int num_of_bytes = EEPROM_SIZE;

		if( argc != optind + 3 )
		{
			printf("illegal usage - %s expected offset & filename...\n\n",argv[optind]);
			exit(EXIT_FAILURE);
		}

		sscanf(argv[optind+1], "0x%x", &e2p_addr);
		sprintf(filename, "%s", argv[optind+2]);

		// this is the max number of bytes available in eeprom
		num_of_bytes = EEPROM_SIZE - e2p_addr;

		if (dump_file_to_buf(filename, e2p_buf, &num_of_bytes) == E2P_FAIL)
		{
			printf("%s: file not found or too big, aborting...\n", argv[optind]);
			exit(EXIT_FAILURE);
		}

		if (verbose)
			hex_dump(filename, e2p_buf, num_of_bytes, 1);

		printf("writing %s file (size=%Xh) to addr %Xh.\n",filename,num_of_bytes,e2p_addr);

		cl_e2p_write(e2p_addr,e2p_buf, num_of_bytes);

	}
	else 
	{
		printf("ERROR: unknown command(%s)\n", argv[optind]);
		exit(EXIT_FAILURE);
	}

	cl_reg_close();

	if (verbose)
	{
		printf("\n");
		printf("%s %s: Done\n", argv[0], argv[optind]);
		printf("\n");
	}

	fflush(stdout);

	return 0;
}
