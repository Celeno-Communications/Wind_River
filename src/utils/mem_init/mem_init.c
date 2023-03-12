// MEM_INIT
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <stdint.h>
#include "cl_common.h"
#include "cl_reg.h"

#define FATAL do { fprintf(stderr, "Error at line %d, file %s (%d) [%s]\n", \
        __LINE__, __FILE__, errno, strerror(errno)); exit(1); } while(0)

#define SHARED_RAM_OFFSET 0x0
// Denali Cl6000 Shared RAM size is 384k
#define SHARED_RAM_SIZE 0x60000

#define LMAC_IRAM_OFFSET 0x240000
#define LMAC_IRAM_SIZE 0x40000
#define LMAC_DRAM_OFFSET 0x200000
#define LMAC_DRAM_SIZE 0x20000

#define UMAC_IRAM_OFFSET 0x2C0000
#define UMAC_IRAM_SIZE 0x30000
#define UMAC_DRAM_OFFSET 0x280000
#define UMAC_DRAM_SIZE 0x20000

#define SMAC_IRAM_OFFSET 0x340000
#define SMAC_IRAM_SIZE 0x40000
#define SMAC_DRAM_OFFSET 0x300000
#define SMAC_DRAM_SIZE 0x40000

#define LA_RAM_OFFSET 0x40000
#define LA_RAM_SIZE   0x20000

unsigned int req_offset=0;
unsigned int req_size=0;
unsigned int req_magic=0;
unsigned int req_loop_cnt=1;

int verbose=0;
void usage(char* cmd)
{
	fprintf(stderr, 
			"\nUsage:\t %s:[option] ram\n"
			"\t options: \n"
			"\t\t -o - offset \n"
			"\t\t -s - size \n"
			"\t\t -m - magic \n"
			"\t\t -l - loop count \n"
			"\t\t -v - verbose \n"
			"\t\t -h - help \n"
			"\t ram: \n"
			"\t MAC_SHARED_RAM  : initializes mac shared ram \n"
			"\t LMAC_IRAM  : initializes LMAC  IRAM \n"
			"\t LMAC_DRAM  : initializes LMAC  DRAM \n"
			"\t UMAC_IRAM  : initializes UMAC  IRAM \n"
			"\t UMAC_DRAM  : initializes UMAC  DRAM \n"
			"\t SMAC_IRAM  : initializes SMAC  IRAM \n"
			"\t SMAC_DRAM  : initializes SMAC  DRAM \n"
			"\t LA_RAM  : initializes ELA RAM \n"
			"\n\n\n",cmd
	       );
}


void init_range(uint32_t offset, int32_t range)
{
	uint32_t i;

	if (verbose) printf("offset=0x%x,range=0x%x\n",offset,range);
	
	if (cl_get_wifi_mode() == CL_DEVICE_IS_PCI) {
		for (i = 0 ;i < (range / 4); i++)
			cl_reg_write32(offset + 4*i, req_magic);
	}
	else {
		char *buf = malloc(range);
		if(!buf)
			return;
		memset(buf, req_magic, range);
		cl_usb_burst_write(offset, buf, range, false);
		free(buf);
	}

	if (verbose)
		printf("done!\n");
}


int main(int argc, char **argv)
{
	int opt, param, i;

	while ((opt = getopt(argc, argv, "vh:o:s:m:l:")) != -1)
	{
		switch (opt) 
		{
			case 'o':
				sscanf(optarg, "0x%x", &req_offset);
				break;
			case 's':
				sscanf(optarg, "0x%x", &req_size);
				break;
			case 'm':
				sscanf(optarg, "0x%x", &req_magic);
				break;
			case 'l':
				sscanf(optarg, "0x%x", &req_loop_cnt);
				break;
			case 'v':
				verbose = 1;
				printf("%s in verbose mode.\n",argv[0]); 
				break;
			case 'h':
				usage(argv[0]);
				exit(EXIT_SUCCESS);
				break;
			default: /* '?' */
				usage(argv[0]);
				exit(EXIT_SUCCESS);
		}
	}

	if (optind >= argc) 
	{
		fprintf(stderr, "Expected ram memory after options\n");
		usage(argv[0]);
		exit(EXIT_SUCCESS);
	}

	if (cl_reg_open())
	{
		perror("cl_reg_open");
		exit(EXIT_FAILURE);
	}

	param = optind ;

	if(req_size != 0)
	{
		if(verbose) printf("offset=%Xh,size=%Xh,magic=%Xh,loop=%Xh.\n",req_offset,req_size,req_magic,req_loop_cnt); 
		for (i=0; i< req_loop_cnt; i++)
			init_range(req_offset, req_size);
		argc = 0;
	}

	while (param<argc)
	{
		// Command Execute
		if (verbose)
			printf ("%s : ",argv[param]);

		if (strcmp(argv[param],"MAC_SHARED_RAM") == 0)
			init_range(SHARED_RAM_OFFSET, SHARED_RAM_SIZE);
		else if (strcmp(argv[param],"LMAC_IRAM") == 0)
			init_range(LMAC_IRAM_OFFSET, LMAC_IRAM_SIZE);
		else if (strcmp(argv[param],"LMAC_DRAM") == 0)
			init_range(LMAC_DRAM_OFFSET, LMAC_DRAM_SIZE);
		else if (strcmp(argv[param],"UMAC_IRAM") == 0)
			init_range(UMAC_IRAM_OFFSET, UMAC_IRAM_SIZE);
		else if (strcmp(argv[param],"UMAC_DRAM") == 0)
			init_range(UMAC_DRAM_OFFSET, UMAC_DRAM_SIZE);
		else if (strcmp(argv[param],"SMAC_IRAM") == 0)
			init_range(SMAC_IRAM_OFFSET, SMAC_IRAM_SIZE);
		else if (strcmp(argv[param],"SMAC_DRAM") == 0)
			init_range(SMAC_DRAM_OFFSET, SMAC_DRAM_SIZE);
		else if (strcmp(argv[param],"LA_RAM") == 0)
			init_range(LA_RAM_OFFSET, LA_RAM_SIZE);
		else
		{
			printf("ERROR: unknown command(%s)\n",argv[param]);
			exit(1);
		}

		param++;
	}

	cl_reg_close();

	if(verbose) printf ("all done.\n");
	exit(EXIT_SUCCESS);
}
