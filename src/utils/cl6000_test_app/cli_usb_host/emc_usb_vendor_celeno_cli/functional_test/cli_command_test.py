#!/usr/bin/env python3
import unittest
import time

import usb.core
import usb.util

# /etc/udev/rules.d/99-emsys.rules
# SUBSYSTEM=="usb", ENV{DEVTYPE}=="usb_device", ATTR{idVendor}=="33de", ATTR{idProduct}=="6000", MODE="0666"
# and reboot or run as root


EMC_USB_CELENO_CLI_TRANFER_SIZE = 1*1024

"""
Device assumption:
  - device implements celeno cli protocol on interface 1
"""



class TestCliCommand(unittest.TestCase):

    def setUp(self):
        self.dev = usb.core.find(idVendor=0x33DE, idProduct=0x6000)
        if self.dev is None:
            raise ConnectionError('Device not found')

        # unconfigure first to reset endpoints, loopback buffer
        self.dev.set_configuration(0)
        # configure, buffer must be empty now
        self.dev.set_configuration()

        # get endpoints
        cfg = self.dev.get_active_configuration()
        intf = cfg[(0,0)]

        self.ep_in = usb.util.find_descriptor(
            intf,
            custom_match = \
            lambda e: \
                usb.util.endpoint_direction(e.bEndpointAddress) == \
                usb.util.ENDPOINT_IN)

        assert self.ep_in is not None

        self.ep_out = usb.util.find_descriptor(
            intf,
            custom_match = \
            lambda e: \
                usb.util.endpoint_direction(e.bEndpointAddress) == \
                usb.util.ENDPOINT_OUT)


        assert self.ep_out is not None

        assert self.ep_out.wMaxPacketSize == self.ep_in.wMaxPacketSize

    def tearDown(self):
        usb.util.dispose_resources(self.dev)


    def test_keep_alive(self):
        """
        send KeepAlive (id = 0x05, sequnce_id = 1, parm[0..2] = 0)
        """
        msg_out = bytearray(b'\x05\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00')
        self.ep_out.write(msg_out)
        msg_in = self.ep_in.read(EMC_USB_CELENO_CLI_TRANFER_SIZE)
        print(msg_in)
        self.assertEqual(20, len(msg_in))

    def test_serial(self):
        serial = usb.util.get_string(self.dev, 3)
        assert '123456789ABCDEF1' == serial
        
    def test_double_alt_settings(self):
        self.dev.set_interface_altsetting(interface = 0, alternate_setting = 1)
        self.dev.set_interface_altsetting(interface = 0, alternate_setting = 1)
        self.dev.set_interface_altsetting(interface = 0, alternate_setting = 0)
        self.dev.set_interface_altsetting(interface = 0, alternate_setting = 0)

        # check that device was not crashed
        self.test_keep_alive()

if __name__ == '__main__':
    unittest.main()
