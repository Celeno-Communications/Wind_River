#if (__SIZEOF_POINTER__ == 8) && !defined(_FILE_OFFSET_BITS)
#define _FILE_OFFSET_BITS 64
#endif

#include "cl_reg.h"
#include <assert.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <linux/byteorder/little_endian.h>

struct cl_pci_reg_map
{
	volatile char *map_base;
	int devmem_fd;
	off_t phys_base_addr;
	off_t phys_last_addr;
};
static struct CLI_USB_Config usb_config;

static uint32_t usb_transfer_timeout_ms = 20000;
static uint32_t usb_connection_timeout_ms = 30000;
static bool usb_verbose = false;

struct cl_pci_reg_map map;

static off_t phys_addr_get(const char *param_name)
{
	const char *param;

	param = getenv(param_name);
	if (param == NULL)
		return 0;

	return strtoull(param, NULL, 16);
}

static uint32_t cl_pci_reg_read32(uint32_t offset)
{
	offset &= (map.phys_last_addr ^ map.phys_base_addr);
	assert(offset < map.phys_last_addr - map.phys_base_addr);
	return __le32_to_cpu(*(volatile uint32_t*)(map.map_base + offset));
}

static void cl_pci_reg_write32(uint32_t offset, uint32_t value)
{
	offset &= (map.phys_last_addr ^ map.phys_base_addr);
	assert(offset < map.phys_last_addr - map.phys_base_addr);
	*(volatile uint32_t*)(map.map_base + offset) = __cpu_to_le32(value);
}

static uint32_t cl_usb_reg_read32(uint32_t offset)
{
	uint32_t data = 0;
	int status;

	if ((offset & 0xf0000000) == 0)
		offset += XTENSA_PIF_BASE_ADDR;

	status = cl_usb_read32(offset, &data);
	assert(status == 0);
	return data;
}

static void cl_usb_reg_write32(uint32_t offset, uint32_t value)
{
	int status;

	if ((offset & 0xf0000000) == 0)
		offset += XTENSA_PIF_BASE_ADDR;

	status = cl_usb_write32(offset, value);
	assert(status == 0);
}


static void cl_pci_reg_close(void)
{
	/* We don't wan't to set errno in this function. */
	int errno_backup = errno;

	munmap((void*)map.map_base, map.phys_last_addr - map.phys_base_addr);

	close(map.devmem_fd);

	errno = errno_backup;
}

static int cl_pci_reg_open(void)
{
	map.phys_base_addr = phys_addr_get("CL_PCI_BASE_ADDR");
	map.phys_last_addr = phys_addr_get("CL_PCI_LAST_ADDR");

	if (!map.phys_base_addr || !map.phys_last_addr)	{
		errno = ENODEV;
		return -1;
	}

	map.devmem_fd = open("/dev/mem", O_RDWR | O_SYNC);
	if (map.devmem_fd == -1)
		return -1;

	map.map_base = mmap(0,
			    map.phys_last_addr - map.phys_base_addr,
			    PROT_READ | PROT_WRITE,
			    MAP_SHARED,
			    map.devmem_fd, map.phys_base_addr);
	if (map.map_base == MAP_FAILED)
		goto err;

	cl_reg_read32 = cl_pci_reg_read32;
	cl_reg_write32 = cl_pci_reg_write32;
	return 0;

err:
	return -1;	

}

static int cl_usb_reg_open(void)
{
	int err = -ENODEV;
	uint16_t pid = (uint16_t)phys_addr_get("CL_USB_PROD_ID");

	if (pid == 0)
		return -ENODEV;

	cl_usb_config_init(&usb_config);

	usb_config.transfer_timeout_ms = usb_transfer_timeout_ms;
	usb_config.connection_timeout_ms = usb_connection_timeout_ms;
	usb_config.verbose = usb_verbose;
	usb_config.silent = 1;
	usb_config.pid = pid;
	usb_config.sn = (uint8_t *)getenv("CL_USB_SER_NUM");

	err = cl_usb_open(&usb_config);

	cl_reg_read32 = cl_usb_reg_read32;
	cl_reg_write32 = cl_usb_reg_write32;

	if (err < 0) {
		printf("No USB device found with USB-PID: 0x%04x SN: %s\n", usb_config.pid, usb_config.sn);
	}
	return err;
}

int cl_reg_open(void)
{
	int err;

	err = cl_pci_reg_open();
	if (!err)
		return 0;

	return cl_usb_reg_open();
}


void cl_reg_close()
{
	cl_usb_close();
	cl_pci_reg_close();
}

inline void cl_reg_write8(uint32_t reg, uint8_t val)
{
	uint32_t retval = 0;

        retval = cl_reg_read32(reg);
	retval &= ~0xFF;
	retval |= val;
        cl_reg_write32(reg, retval);
}

inline void cl_reg_write16(uint32_t reg, uint16_t val)
{
	uint32_t retval = 0;

        retval = cl_reg_read32(reg);
	retval &= ~0xFFFF;
	retval |= val;
        cl_reg_write32(reg, retval);
}

int cl_get_wifi_mode(void)
{
	char *env;

	env = getenv("CL_USB_PROD_ID");
	if (env && strlen(env))
		return CL_DEVICE_IS_USB;

	return CL_DEVICE_IS_PCI;
}

struct CLI_USB_Config *cl_get_usb_config(void)
{
	return &usb_config;
}

void cl_reg_usb_configure_timeouts(uint32_t transfer_timeout_ms, uint32_t connection_timeout_ms)
{
	usb_transfer_timeout_ms = transfer_timeout_ms;
	usb_connection_timeout_ms = connection_timeout_ms;
}

void cl_reg_usb_configure_verbose(bool verbose)
{
	usb_verbose = verbose;
}
