#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>
#include <unistd.h>
#include "libusb-1.0/libusb.h"
#include "cl6000_usb_test_wrapper_priv.h"
#include "cl6000_usb_test.h"
#include <fcntl.h>

static uint16_t vid = CL6000_UMAC_VID;
static uint16_t pid = CL6000_UMAC_PID;
static uint8_t ecm_ctrl_class = 0x02;
static uint8_t ecm_ctrl_subcode = 0x06;
static uint8_t ecm_data_class = 0x0A;
static uint8_t ecm_data_subcode = 0x00;


#define PACKET_COUNT (8192)
#define PACKET_COUNT_SHORT (512)
#define VERSION (4)
#define TEST_TIMEOUT 400
#define TPUT_SECURITY_GAP 0.0

int usb_ecm_test(libusb_device_handle *handle, libusb_device *device);

#define VOID_PARAM {USBW_VOID,{0,0,0,0}}

static struct USBW_TestCase testcases_umac[] = {
    //#01
    {    "ECM-LOOP-64", 0.0, 0.0, TPUT_SECURITY_GAP, 0, VOID_PARAM, {VERSION, 0, USBW_IDLE,  0x0,  0, 0, USBW_LOOP, {PACKET_COUNT, PACKET_COUNT*64, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {    "ECM-LOOP-1025", 0.0, 0.0, TPUT_SECURITY_GAP, 0, VOID_PARAM, {VERSION, 0, USBW_IDLE,  0x0,  0, 0, USBW_LOOP, {PACKET_COUNT, PACKET_COUNT*1025, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {    "ECM-LOOP-1532", 0.0, 0.0, TPUT_SECURITY_GAP, 0, VOID_PARAM, {VERSION, 0, USBW_IDLE,  0x0,  0, 0, USBW_LOOP, {PACKET_COUNT, PACKET_COUNT*1532, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {    "ECM-US-1532", 0.0, 0.0, TPUT_SECURITY_GAP, 0, VOID_PARAM, {VERSION, 0, USBW_IDLE,  0x0,  0, 0, USBW_UP_STREAM, {PACKET_COUNT, PACKET_COUNT*1532, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {    "ECM-DS-1532", 0.0, 0.0, TPUT_SECURITY_GAP, 0, VOID_PARAM, {VERSION, 0, USBW_IDLE,  0x0,  0, 0, USBW_DOWN_STREAM, {PACKET_COUNT, PACKET_COUNT*1532, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
};

static size_t number_testcases = sizeof(testcases_umac) / sizeof(testcases_umac[0]);

int apre_usb_ecm_test()
{
  libusb_context *context = NULL;
  libusb_device_handle *handle = NULL;
  libusb_device *device = NULL;
  int result = PASSED;

  if (boot_drv_usb_cfg()->verbose)
  {
    TEST_INFO("Executing %s vid==0x%04x pid=0x%04x ...\n", __FUNCTION__, vid, pid);
  }
  libusb_init(&context);
  handle = libusb_open_device_with_vid_pid(context, vid, pid);
  if (handle == NULL)
  {
    libusb_exit(context);
    TEST_INFO("Error: failed to open usb device\n");
    return FAILED;
  }

  device = libusb_get_device(handle);
  if (device == NULL)
  {
    libusb_close(handle);
    libusb_exit(context);
    TEST_INFO("Error: failed to claim usb device\n");
    return FAILED;
  }

  result = usb_ecm_test(handle, device);

  libusb_close(handle);
  libusb_exit(context);
  return result;
}

int get_interface(libusb_device *dev, uint8_t ifc_class, uint8_t ifc_subclass)
{
  const struct libusb_interface *inter;
  const struct libusb_interface_descriptor *interdesc;
  struct libusb_config_descriptor *config = NULL;

  if (libusb_get_config_descriptor(dev, 0, &config))
  {
    return -1;
  }
  for (uint8_t i = 0; i < config->bNumInterfaces; i++)
  {
    inter = &config->interface[i];
    interdesc = &inter->altsetting[0];
    if (interdesc->bInterfaceClass == ifc_class && interdesc->bInterfaceSubClass == ifc_subclass)
    {
      libusb_free_config_descriptor(config);
      return i;
    }
  }
  libusb_free_config_descriptor(config);
  return -1;
}

int get_endpoint(libusb_device *dev, uint8_t ifc_num, uint8_t direction)
{
  struct libusb_config_descriptor *config = NULL;
  const struct libusb_interface *inter;
  const struct libusb_interface_descriptor *interdesc;

  if (libusb_get_config_descriptor(dev, 0, &config))
  {
    return -1;
  }

  if (ifc_num < config->bNumInterfaces)
  {
    inter = &config->interface[ifc_num];
    interdesc = &inter->altsetting[0];
    for (uint8_t ep_idx = 0; ep_idx < interdesc->bNumEndpoints; ep_idx++)
    {
      const struct libusb_endpoint_descriptor *ep_desc = &interdesc->endpoint[ep_idx];
      if ((ep_desc->bEndpointAddress & LIBUSB_ENDPOINT_DIR_MASK) == direction)
      {
        int ep = ep_desc->bEndpointAddress;
        libusb_free_config_descriptor(config);
        return ep;
      }
    }
  }
  libusb_free_config_descriptor(config);
  return -1;
}


void clear_in_pipe(libusb_device_handle *handle,uint8_t ep_in)
{
  uint8_t data_in[2048];
  int len_in = 0;
  int result = 0;
  while (!result)
  {
    result = libusb_bulk_transfer(handle, ep_in, data_in, sizeof(data_in), &len_in, 1000);
  }
}

static int transfer_data(libusb_device_handle *handle, uint8_t ep_in, uint8_t ep_out, struct USBW_TestCase* tc)
{
  size_t transfers = tc->control_request.packets.packet_count;
  size_t size = tc->control_request.packets.number_bytes/tc->control_request.packets.packet_count;
  int result = 0;
  size_t i = 0;
  int len_out = 0;
  int len_in = 0;
  uint8_t *data_out = malloc(size);
  uint8_t *data_in = malloc(size);
  int percent=0;
  int old_percent=0;
  errno = 0;
  result = 0;
  TEST_INFO("\n        Running");
  while (i++ < transfers && !result)
  {
    memset(data_out, i, size);
    if (tc->control_request.direction == USBW_LOOP || tc->control_request.direction == USBW_DOWN_STREAM) {
      result = libusb_bulk_transfer(handle, ep_out, data_out, size, &len_out, 10000);
      if (result || len_out != size){
        TEST_INFO("Error: write failed. ec: %d size out %u\n", result, len_out);
        result= -1;
        break;
      }
    }
    if (tc->control_request.direction == USBW_LOOP || tc->control_request.direction == USBW_UP_STREAM) {
      result = libusb_bulk_transfer(handle, ep_in, data_in, size, &len_in, 10000);
     if (result || len_in != size)
      {
        TEST_INFO("Error: read failed. ec: %d size in %u \n", result, len_in);
        result= -1;
        break;
      }
      if (tc->control_request.packets.pattern != USBW_DONT_CARE) {
        if (memcmp(data_out, data_in, size))
        {
          TEST_INFO("Error: data compare failed\n");
          result = -1;
        }
      }
    }

    percent = (i*20)/transfers;
    if (percent != old_percent) {
        printf(".");fflush(stdout);
        old_percent=percent;
    }
  }
  free(data_in);
  free(data_out);
  return result ? FAILED : PASSED;
}

static void usb_test_wait_finished(int32_t timeout_seconds)
{
    TEST_INFO("\n        Wait for finish ");
    uint32_t test_status=0;
    cl_usb_read32(UMAC_WRAPPER_TEST_STATUS_BASE + WRAPPER_TEST_STATUS_STATE_OFFSET, &test_status);
    while((test_status != USBW_STATUS_FINISHED) && (timeout_seconds > 0)){
        sleep(5);
        timeout_seconds -= 5;
        cl_usb_read32(UMAC_WRAPPER_TEST_STATUS_BASE + WRAPPER_TEST_STATUS_STATE_OFFSET, &test_status);
        TEST_INFO(".");
        fflush(stdout);
    }

    if (timeout_seconds <= 0){
        TEST_INFO("\n*** Timeout , test not finished");
    }else{
      TEST_INFO("\n. done");
    }
}

static int usb_ecm_single_test(libusb_device_handle *handle,int ep_in,  int ep_out,struct USBW_TestCase* tc ,int tc_idx,CL_USB_SPEED speed)
{
  int result = 0;
  tc->control_request.cmd=USBW_START;
  tc->control_request.sequence_id=tc_idx+1;
  clear_in_pipe(handle,ep_in);
  usb_wrapper_test_write_request_at(UMAC_WRAPPER_TEST_CONTROL_BASE,&tc->control_request);
  result = transfer_data(handle, ep_in, ep_out, tc);
  if (result == PASSED) {
    usb_test_wait_finished(10);
    result = usb_wrapper_test_evaluate(UMAC_WRAPPER_TEST_STATUS_BASE,tc,0,speed);
  }
  return result;
}

int usb_ecm_test(libusb_device_handle *handle, libusb_device *dev)
{
  int result = PASSED;
  int ctrl_ifc = -1;
  int data_ifc = -1;

  int data_in_ep = -1;
  int data_out_ep = -1;
  CL_USB_SPEED speed = CL_USB_SPEED_SUPER;

  if (libusb_get_device_speed(dev) == LIBUSB_SPEED_HIGH) {
      speed = CL_USB_SPEED_HIGH;
  }

  TEST_INFO("ECM Loopback test\n");

  ctrl_ifc = get_interface(dev, ecm_ctrl_class, ecm_ctrl_subcode);
  data_ifc = get_interface(dev, ecm_data_class, ecm_data_subcode);

  if (ctrl_ifc == -1 || data_ifc == -1)
  {
    TEST_INFO("Error: failed to claim usb device\n");
    return FAILED;
  }

  if (libusb_kernel_driver_active(handle, ctrl_ifc) || libusb_kernel_driver_active(handle, data_ifc))
  {
    libusb_detach_kernel_driver(handle, ctrl_ifc);
    libusb_detach_kernel_driver(handle, data_ifc);
  }
  if (libusb_claim_interface(handle, ctrl_ifc))
  {
    TEST_INFO("Error: failed to claim ctrl interface %d \n", ctrl_ifc);
    return FAILED;
  }
  if (libusb_claim_interface(handle, data_ifc))
  {
    TEST_INFO("Error: failed to claim data interface %d \n", data_ifc);
    return FAILED;
  }

  // TEST_INFO("Using interfaces %d / %d\n",ctrl_ifc,data_ifc);

  data_in_ep = get_endpoint(dev, data_ifc, LIBUSB_ENDPOINT_IN);
  data_out_ep = get_endpoint(dev, data_ifc, LIBUSB_ENDPOINT_OUT);
  if (data_in_ep == -1 || data_out_ep == 1)
  {
    TEST_INFO("Error: failed to get endpoints\n");
    result = FAILED;
  }
  else
  {
    size_t passed = 0 ;
    size_t failed = 0 ;
    for (size_t tc =0; tc< number_testcases;tc++){
       TEST_INFO("\n\nExecute test %s %zu/%zu\n",testcases_umac[tc].description,tc+1,number_testcases);
       result = usb_ecm_single_test(handle,data_in_ep, data_out_ep,&testcases_umac[tc],tc,speed);
       if (result) {
         failed++;
       }else{
         passed++;
       }
    }
    if (failed){
      TEST_INFO("\n\nFAILED: %zu/%zu\n",failed,number_testcases);
    }else{
      TEST_INFO("\n\nPASSED: %zu/%zu\n",number_testcases,number_testcases);
    }
  }



  libusb_release_interface(handle, ctrl_ifc);
  libusb_release_interface(handle, data_ifc);

  return result;
}
