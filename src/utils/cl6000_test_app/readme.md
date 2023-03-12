# Overview
This readme describes the usage of the programs together with the CLI USB interface of CL6000.

# Build

`svn checkout .../integration_CL6000/Emsys/cl6000/trunk`
 
## Prerequisites

- install libusb-1.0
  (install libusb: `sudo apt-get install libusb-1.0.0-dev`)
- install cmake, see https://cmake.org/, version >= 19

## Build Cl6000 fw test application

Run

```bash
make -C cl6000_test_app 
```

## Build and install cli_usb host library manually

After installation of the cli_usb library the header definitions can be found in:
- cli/cli.h for backward compatibility, this header is deprecated
- cli/cli_usb.h This header file provides all capabilities of the Bootrom CLI operations.
- cli/libcli_usb.a contains the implementation

```bash
cd cl6000_test_app/cli_usb_host
cmake -H. -Bbin -DUSECASE=emcpp_system_celeno_wifi/eme/host_cli.usecase.cmake -DCMAKE_INSTALL_PREFIX=..
make -C ./bin install_cli
```

## Build Cli_demo
The application cli_usb_demo demonstrates the full functionality of the cli_host library, single read/write, 
burst read/write, combined single read/write as well as umac usb disconnect and restart.

```bash
cd cl6000_test_app
make -C cli
```

To run the applications:

```bash
sudo ../A/cli_lecacy_demo
sudo ../A/cli_usb_demo
```

# Applications

## Execution 
Due to the access constraints of linux to usb devices, any access to usb devices requires extended privileges.
This can be achieved by either:
Run the application as root with "sudo".
Or by installing udev-rules on the system accordingly.

## CLI Functional Test Application

The test application does a functional test of the cli protocol implementation of the UMAC USB bootloader application. This includes operations as 
- Simple Read/Write/WriteFast
- Keep Alive, Get Version
- Burst Read/Write/WriteFast

Special operations as
- UMAC Execute
- UMAC Restart
- USB Disconnect

can't be tested, as these operations lead to a USB disconnect.
The binary contains the test code as well as the full implementation of the host side cli protocoll. So it does not reference any symbols of the cli_usb_host library mentioned above.

Build the test application:
```bash
cd cl6000_test_app/cli_usb_host
cmake -H. -Bbin -DUSECASE=emcpp_system_celeno_wifi/eme/host_cli.usecase.cmake
make -C ./bin HostGenericProtocol_functional_test
```

Execution:
```bash
sudo ./bin/emc_usb_vendor_celeno_cli/src/host/test/HostGenericProtocol_functional_test 0x40080000
```

## Demo Applications

The application `cli_usb_demo` demonstrates the usage of the usb cli interface.
Both applications can be executed without further prerequisites, as they use the umac IRAM for test purpose.

## FW test application

see `./A/cl6000_boot_A -h`

There is a umac cli usb self test, which can be executed with:
```sudo CL_HW_MODEL=CL_PALLADIUM ./A/cl6000_boot_A umac_cli_selftest
```

E.g. the UMAC LMAC fw test is supported as follows:
For reference a working coretetest can be found in `cli/reference_umac_test.7z`.

```
sudo CL_HW_MODEL=CL_PALLADIUM ./A/cl6000_boot_A -v -p. load_test coretestfw.bin no_load no_load
```
