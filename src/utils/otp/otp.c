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

#define OTP_OK   (0)
#define OTP_FAIL (-1)

// OTP Parameters
#define OTP_SIZE           (0x3FF)                 // 1KB = 8Kbit
#define OTP_SIZE_WORD       sizeof(uint32_t)
#define OTP_KEY_VAL1        0xA6EE17BF
#define OTP_KEY_VAL2        0x827532CD
#define OTP_WRITE_CMD       0x1
#define OTP_READ_CMD        0x2
#define OTP_MAX_POLLS       10
#define OTP_INIT_DELAY      32


#define REG_OTP_BASE_ADDR 0x007C9000

//----------------------------
// Global Variable
//----------------------------
int verbose = 0;

/**
 * @brief OTP_ADDR register definition
 *  OTP address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31    SUPPADD                   0
 *    07:00 OTP_ADDR                  0x0
 * </pre>
 */
#define OTP_OTP_ADDR_ADDR        (REG_OTP_BASE_ADDR + 0x0000000C)
#define OTP_OTP_ADDR_OFFSET      0x0000000C
#define OTP_OTP_ADDR_INDEX       0x00000003
#define OTP_OTP_ADDR_RESET       0x00000000

#define OTP_ADDR_SET(value)   \
    cl_reg_write32(OTP_OTP_ADDR_ADDR, value);

/**
 * @brief OTP_CMD register definition
 *  OTP command register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    01:00 OTP_CMD                   0x0
 * </pre>
 */
#define OTP_OTP_CMD_ADDR        (REG_OTP_BASE_ADDR + 0x00000000)
#define OTP_OTP_CMD_OFFSET      0x00000000
#define OTP_OTP_CMD_INDEX       0x00000000
#define OTP_OTP_CMD_RESET       0x00000000

#define OTP_CMD_SET(value)   \
    cl_reg_write32(OTP_OTP_CMD_ADDR, value);

#define ASSERT_ERR_CHIP(condition) \
	do { \
		if (!(condition)) \
			printf("ASSERT_ERR(" #condition ")\n"); \
	} while (0)


#define OTP_CMD_OTP_CMD_SETF(otpcmd)   \
    ASSERT_ERR_CHIP((((uint32_t)otpcmd << 0) & ~((uint32_t)0x00000003)) == 0); \
    cl_reg_write32(OTP_OTP_CMD_ADDR, (uint32_t )otpcmd << 0);

/**
 * @brief OTP_READ_VAL register definition
 *  OTP read value register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 OTP_READ_VAL              0x0
 * </pre>
 */
#define OTP_OTP_READ_VAL_ADDR        (REG_OTP_BASE_ADDR + 0x00000008)
#define OTP_OTP_READ_VAL_OFFSET      0x00000008
#define OTP_OTP_READ_VAL_INDEX       0x00000002
#define OTP_OTP_READ_VAL_RESET       0x00000000

static inline uint32_t otp_otp_read_val_get()
{
	return cl_reg_read32(OTP_OTP_READ_VAL_ADDR);
}

/**
 * @brief OTP_STAT register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    04    OTP_PWOK                  1
 *    03    OTP_RD_DED                0
 *    02    OTP_RD_SEC                0
 *    01    OTP_READY                 1
 *    00    OTP_WRITE_FAILED          0
 * </pre>
 */
#define OTP_OTP_STAT_ADDR        (REG_OTP_BASE_ADDR + 0x00000004)
#define OTP_OTP_STAT_OFFSET      0x00000004
#define OTP_OTP_STAT_INDEX       0x00000001
#define OTP_OTP_STAT_RESET       0x00000012

static inline uint8_t otp_otp_stat_otp_rd_ded_getf()
{
	uint32_t local_val = cl_reg_read32(OTP_OTP_STAT_ADDR);

	return (uint8_t)((local_val & ((uint32_t)0x00000008)) >> 3);
}

static inline uint8_t otp_otp_stat_otp_ready_getf()
{
	uint32_t local_val = cl_reg_read32(OTP_OTP_STAT_ADDR);

	return (uint8_t)((local_val & ((uint32_t)0x00000002)) >> 1);
}

static inline uint8_t otp_otp_stat_otp_write_failed_getf()
{
	uint32_t local_val = cl_reg_read32(OTP_OTP_STAT_ADDR);

	return (uint8_t)((local_val & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief OTP_KEY register definition
 *  OTP key register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 OTP_KEY                   0x0
 * </pre>
 */
#define OTP_OTP_KEY_ADDR        (REG_OTP_BASE_ADDR + 0x00000014)
#define OTP_OTP_KEY_OFFSET      0x00000014
#define OTP_OTP_KEY_INDEX       0x00000005
#define OTP_OTP_KEY_RESET       0x00000000

#define OTP_KEY_SET(value)   \
    cl_reg_write32(OTP_OTP_KEY_ADDR, value);

/**
 * @brief OTP_WRITE_VAL register definition
 *  OTP write value register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 OTP_WRITE_VAL             0x0
 * </pre>
 */
#define OTP_OTP_WRITE_VAL_ADDR        (REG_OTP_BASE_ADDR + 0x00000010)
#define OTP_OTP_WRITE_VAL_OFFSET      0x00000010
#define OTP_OTP_WRITE_VAL_INDEX       0x00000004
#define OTP_OTP_WRITE_VAL_RESET       0x00000000

#define OTP_WRITE_VAL_SET(value)   \
    cl_reg_write32(OTP_OTP_WRITE_VAL_ADDR, value);

static int otp_init_blow()
{
	unsigned long delay = OTP_INIT_DELAY;
	int cnt = OTP_MAX_POLLS;

	// Open OTP module
	OTP_KEY_SET(OTP_KEY_VAL1);
	OTP_KEY_SET(OTP_KEY_VAL2);

	// Wait for OTP_READY
	while (!otp_otp_stat_otp_ready_getf() && cnt--) {
		usleep(delay);
		delay <<= 1;
	}

	if (!cnt && !otp_otp_stat_otp_ready_getf()) {
		printf("\nOTP device busy\n");
		return OTP_FAIL;
	}

	return OTP_OK;
}

static inline void otp_end_blow() //phase i
{
	OTP_KEY_SET(0x00);
}

static int _otp_write_word(uint32_t addr, uint32_t val) //phase c +d+e
{
	unsigned long delay = OTP_INIT_DELAY;
	int cnt = OTP_MAX_POLLS;

	OTP_ADDR_SET(addr);

	OTP_WRITE_VAL_SET(val);

	OTP_CMD_SET(OTP_WRITE_CMD);

	// Wait for OTP_READY
	while (!otp_otp_stat_otp_ready_getf() && cnt--) {
		usleep(delay);
		delay <<= 1;
	}

	if (!cnt && !otp_otp_stat_otp_ready_getf()) {
		printf("\nOTP device busy\n\n");
		return OTP_FAIL;
	}

	if (otp_otp_stat_otp_write_failed_getf()) {
		printf("\nOTP write error\n\n");
		return OTP_FAIL;
	}

	return OTP_OK;
}


//
// Name: cl_otp_read_word_random()
// Description: This read operation indicating the offset to read from.
//
int cl_otp_read_word_random(int addr, uint32_t *data)
{
	unsigned long delay = OTP_INIT_DELAY;
	int cnt = OTP_MAX_POLLS;

	__FUNC_ENTRY__

	/* Wait for OTP_READY */
	while (!otp_otp_stat_otp_ready_getf() && cnt--) {
		usleep(delay);
		delay <<= 1;
	}

	if (!cnt && !otp_otp_stat_otp_ready_getf()) {
		printf("\nOTP device busy\n\n");
		return OTP_FAIL;
	}

	/* Define addr of the fuse */
	OTP_ADDR_SET(addr);

	/* Write READ_CMD to OPT_CMD */
	OTP_CMD_OTP_CMD_SETF((uint32_t)OTP_READ_CMD);

	while(!otp_otp_stat_otp_ready_getf() && cnt--) {
		usleep(delay);
		delay <<= 1;
	}

	if (!cnt && !otp_otp_stat_otp_ready_getf()) {
		printf("\nOTP device busy\n\n");
		return OTP_FAIL;
	}

	if (otp_otp_stat_otp_rd_ded_getf())
		return OTP_FAIL;


	*data = otp_otp_read_val_get();

	return OTP_OK;
}

//
// Name: cl_otp_read_word_sequential()
// Description: This is a multi-read operation.
// As long as the EEPROM receives an acknowledge, it will continue to increment
// the data word address and serially clock out sequential data words.
//
int cl_otp_read_word_sequential(int addr, uint32_t * val, int num_of_words)
{
	int i;
	__FUNC_ENTRY__

	for(i=0;i<num_of_words;i++)
	{
		if (cl_otp_read_word_random(addr + i, val + i))
			return OTP_FAIL;
	}

	return OTP_OK;
}

//
// Name: cl_otp_write_word()
// Description: This is a write 32 byte operation indicating the offset to write to.
//
int cl_otp_write_word(int addr, unsigned int val)
{
	uint32_t read_val;

	__FUNC_ENTRY__

	if (cl_otp_read_word_random(addr, &read_val))
		return OTP_FAIL;

	if (read_val) {
		printf("address %d already have value %x\n", addr, read_val);
		return OTP_FAIL;
	}

	if (otp_init_blow())
		return OTP_FAIL;

	if (_otp_write_word(addr, val))
		return OTP_FAIL;

	otp_end_blow();

	return OTP_OK;
}


//
// Name: cl_e2p_write()
// Description: This is a general write function
//
int cl_otp_write_sequential(int addr, unsigned int * val, int num_of_words)
{
	int i=0;

	__FUNC_ENTRY__

	for (i=0;i<num_of_words;i++)
	{
		if (cl_otp_write_word(addr + i, *(val + i)))
			return OTP_FAIL;
	}

	return OTP_OK;;
}


int dump_file_to_buf(char * filename, unsigned int * buf, int * buf_size)
{
	FILE *fp;
	unsigned int size;
	size_t ret;

	__FUNC_ENTRY__

	fp = fopen(filename, "r");

	if (fp == 0)
	{
		if (verbose)
			printf("\nERROR: can't find %s\n\n", filename);

		return OTP_FAIL;
	}

	fseek(fp, 0, SEEK_END);
	size = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	ret = fread(buf, size, 1, fp);

	if (ret != 1)

	fclose(fp);

	return OTP_OK;
}


void hex_dump(char *str, uint32_t *src, unsigned int len)
{
	uint32_t *pt;
	int x;

	pt = (uint32_t *)src;

	printf("%s: %p, len = %d\n", str, src, len);
	for (x=0;x<len; x++)
	{
		if (x % 4 == 0)
		{
			printf("0x%04x : ", x);
		}
		printf("%08x ", ((uint32_t)pt[x]) );
		if (x % 4 == 3)
		{
			printf("\n");
		}
	}
	printf("\n");
}


void usage(char * cmd)
{
        fprintf(stderr,
            "\nUsage:\t%s [opt] cmd\n"
            "\t options: \n"
           "\t\t -v - verbose \n"
            "\t\t -h - help \n"
            "\t commands: \n"
            "\t read      : Read word from otp\n"
            "\t\t example: \n"
            "\t\t > otp read 0x20\n"
            "\t\t description: read from otp offset 0x20. \n"
            "\t read_seq  : Sequential Read from otp\n"
            "\t\t example: \n"
            "\t\t > otp read_seq 0x0 0x800\n"
            "\t\t description: read all otp. from offset 0x0 to 2KB.\n"
            "\t write     : Write Byte to otp\n"
            "\t\t example: \n"
            "\t\t > otp write 0x20 0x99 \n"
            "\t\t description: burn 0x99 to otp offset 0x20. \n"
            "\t writefile : Write File to otp\n"
            "\t\t example: \n"
            "\t\t > otp writefile 0x0 otp0.bin \n"
            "\t\t description: write otp0.bin file starting from adress 0. \n"
            "\t\n\n\n",
           cmd);
}


//----------------------------
// Main
//----------------------------
int main(int argc, char **argv)
{
	int otp_addr = 0;
	int opt;

	while ((opt = getopt(argc, argv, "dvhb:")) != -1)
	{
		switch (opt)
		{
			case 'v':
				verbose = 1;
				printf("%s in verbose mode.\n", argv[0]);
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

	if (cl_reg_open())
	{
		perror("cl_reg_open");
		exit(EXIT_FAILURE);
	}

	// Command Execute
	if (strcmp(argv[optind], "read") == 0)
	{
		uint32_t val;

		if (argc != optind + 2)
		{
			printf("illegal usage - %s expected offset...\n\n", argv[optind]);
			exit(EXIT_FAILURE);
		}

		sscanf(argv[optind + 1], "0x%x", &otp_addr);

		if (!cl_otp_read_word_random(otp_addr, &val))
			printf("OTP[%Xh]: val=%Xh.\n", otp_addr, val);
	}
	else if (strcmp(argv[optind], "read_seq") == 0)
	{
		uint32_t *otp_buf;
		int num_of_words;
		char prefix[120];

		if( argc != optind + 3 )
		{
			printf("illegal usage - %s expected offset & size...\n\n", argv[optind]);
			exit(EXIT_FAILURE);
		}

		sscanf(argv[optind + 1], "0x%x", &otp_addr);
		sscanf(argv[optind + 2], "0x%x", &num_of_words);

		if (num_of_words > OTP_SIZE/OTP_SIZE_WORD - otp_addr)
			num_of_words = OTP_SIZE/OTP_SIZE_WORD - otp_addr;

		otp_buf = malloc(num_of_words*OTP_SIZE_WORD);

		if (verbose)
			printf("%s: otp_addr=0x%Xh, num_of_words=%Xh.\n",
			       argv[optind], otp_addr, num_of_words);

		if (!cl_otp_read_word_sequential(otp_addr, otp_buf, num_of_words))
			sprintf(prefix, "otp->read_seq[%s]", argv[optind + 1]);

		hex_dump(prefix, otp_buf, num_of_words);

	}
	else if (strcmp(argv[optind], "write") == 0)
	{
		unsigned int val;

		if( argc != optind + 3 )
		{
			printf("illegal usage - %s expected offset & value...\n\n", argv[optind]);
			exit(EXIT_FAILURE);
		}

		sscanf(argv[optind + 1], "0x%x", &otp_addr);
		sscanf(argv[optind + 2], "0x%x", &val);

		if (!cl_otp_write_word(otp_addr, val))
			printf("writing %Xh to addr %Xh.\n", val, otp_addr);
	}
	else if (strcmp(argv[optind], "writefile") == 0)
	{
		char filename[120];
		unsigned int otp_buf[OTP_SIZE];
		int num_of_words = OTP_SIZE/OTP_SIZE_WORD;

		if( argc != optind + 3 )
		{
			printf("illegal usage - %s expected offset & filename...\n\n", argv[optind]);
			exit(EXIT_FAILURE);
		}

		sscanf(argv[optind + 1], "0x%x", &otp_addr);
		sprintf(filename, "%s", argv[optind + 2]);

		// this is the max number of bytes available in eeprom
		num_of_words = OTP_SIZE/OTP_SIZE_WORD - otp_addr;

		if (dump_file_to_buf(filename, otp_buf, &num_of_words) == OTP_FAIL)
		{
			printf("%s: file not found or too big, aborting...\n", argv[optind]);
			exit(EXIT_FAILURE);
		}

		if (verbose)
			hex_dump(filename, otp_buf, num_of_words);

		if (!cl_otp_write_sequential(otp_addr, otp_buf + otp_addr, num_of_words))
			printf("writing %s file (size=%Xh) to addr %Xh.\n",
			       filename, num_of_words, otp_addr);
	}
	else
	{
		printf("ERROR: unknown command(%s)\n", argv[optind]);
		exit(EXIT_FAILURE);
	}

	cl_reg_close();

	fflush(stdout);

	return 0;
}

