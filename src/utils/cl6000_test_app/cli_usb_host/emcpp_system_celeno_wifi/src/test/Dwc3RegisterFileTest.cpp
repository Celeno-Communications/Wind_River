/**
 * @file
 *
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 *
 ****************************************************************************/

#include "emcpp/test/UnitTest.hpp"

#undef HAVE_CMAKE_CONFIGURE
#include "emc/usb/driver/dwc3/regfile.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
#pragma GCC diagnostic ignored "-Wunused-parameter"

#define __INLINE static inline
#define REG_DWC_usb3_BASE_ADDR 0
#define REG_PL_RD(addr) 0
#define REG_PL_WR(addr, val)
#define ASSERT_ERR(cond) while (!cond) {}

#include "reg_dwc_usb3.h.gen"
#pragma GCC diagnostic pop

namespace emcpp { namespace system { namespace celeno {

  class Dwc3RegisterFileTest : public test::TestFixture {
  public:
    void test_register_offsets()
    {
      EMCPP_TEST_ASSERT_EQ((unsigned)DWC_usb3_GSBUSCFG0_OFFSET,
                           offsetof(EMC_USB_DRIVER_DWC3_registers_t, global_soc_bus_config_0));
      EMCPP_TEST_ASSERT_EQ((unsigned)DWC_usb3_GSBUSCFG1_OFFSET,
                           offsetof(EMC_USB_DRIVER_DWC3_registers_t, global_soc_bus_config_1));
      EMCPP_TEST_ASSERT_EQ((unsigned)DWC_usb3_GTXTHRCFG_OFFSET,
                           offsetof(EMC_USB_DRIVER_DWC3_registers_t, global_tx_threshold_control));
      EMCPP_TEST_ASSERT_EQ((unsigned)DWC_usb3_GRXTHRCFG_OFFSET,
                           offsetof(EMC_USB_DRIVER_DWC3_registers_t, global_rx_threshold_control));
      EMCPP_TEST_ASSERT_EQ((unsigned)DWC_usb3_GCTL_OFFSET,
                           offsetof(EMC_USB_DRIVER_DWC3_registers_t, global_core_control));
      EMCPP_TEST_ASSERT_EQ((unsigned)DWC_usb3_GPMSTS_OFFSET,
                           offsetof(EMC_USB_DRIVER_DWC3_registers_t, global_power_management_status));
      EMCPP_TEST_ASSERT_EQ((unsigned)DWC_usb3_GSTS_OFFSET,
                           offsetof(EMC_USB_DRIVER_DWC3_registers_t, global_status));
      EMCPP_TEST_ASSERT_EQ((unsigned)DWC_usb3_GUCTL1_OFFSET,
                           offsetof(EMC_USB_DRIVER_DWC3_registers_t, global_user_control_1));
      EMCPP_TEST_ASSERT_EQ((unsigned)DWC_usb3_GSNPSID_OFFSET,
                           offsetof(EMC_USB_DRIVER_DWC3_registers_t, global_synopsys_id));
      EMCPP_TEST_ASSERT_EQ((unsigned)DWC_usb3_GGPIO_OFFSET,
                           offsetof(EMC_USB_DRIVER_DWC3_registers_t, global_gpio));
      EMCPP_TEST_ASSERT_EQ((unsigned)DWC_usb3_GUID_OFFSET,
                           offsetof(EMC_USB_DRIVER_DWC3_registers_t, global_user_id));
      EMCPP_TEST_ASSERT_EQ((unsigned)DWC_usb3_GUCTL_OFFSET,
                           offsetof(EMC_USB_DRIVER_DWC3_registers_t, global_user_control));
      EMCPP_TEST_ASSERT_EQ((unsigned)DWC_usb3_GBUSERRADDRLO_OFFSET,
                           offsetof(EMC_USB_DRIVER_DWC3_registers_t, global_soc_bus_error_address_lo));
      EMCPP_TEST_ASSERT_EQ((unsigned)DWC_usb3_GBUSERRADDRHI_OFFSET,
                           offsetof(EMC_USB_DRIVER_DWC3_registers_t, global_soc_bus_error_address_hi));
      EMCPP_TEST_ASSERT_EQ((unsigned)DWC_usb3_GPRTBIMAPLO_OFFSET,
                           offsetof(EMC_USB_DRIVER_DWC3_registers_t,
                                    global_superspeed_port_to_usb_instance_mapping_lo));
      EMCPP_TEST_ASSERT_EQ((unsigned)DWC_usb3_GPRTBIMAPHI_OFFSET,
                           offsetof(EMC_USB_DRIVER_DWC3_registers_t,
                                    global_superspeed_port_to_usb_instance_mapping_hi));
      EMCPP_TEST_ASSERT_EQ((unsigned)DWC_usb3_GHWPARAMS0_OFFSET,
                           offsetof(EMC_USB_DRIVER_DWC3_registers_t, global_hw_parameters_0));
      EMCPP_TEST_ASSERT_EQ((unsigned)DWC_usb3_GHWPARAMS1_OFFSET,
                           offsetof(EMC_USB_DRIVER_DWC3_registers_t, global_hw_parameters_1));
      EMCPP_TEST_ASSERT_EQ((unsigned)DWC_usb3_GHWPARAMS2_OFFSET,
                           offsetof(EMC_USB_DRIVER_DWC3_registers_t, global_hw_parameters_2));
      EMCPP_TEST_ASSERT_EQ((unsigned)DWC_usb3_GHWPARAMS3_OFFSET,
                           offsetof(EMC_USB_DRIVER_DWC3_registers_t, global_hw_parameters_3));
      EMCPP_TEST_ASSERT_EQ((unsigned)DWC_usb3_GHWPARAMS4_OFFSET,
                           offsetof(EMC_USB_DRIVER_DWC3_registers_t, global_hw_parameters_4));
      EMCPP_TEST_ASSERT_EQ((unsigned)DWC_usb3_GHWPARAMS5_OFFSET,
                           offsetof(EMC_USB_DRIVER_DWC3_registers_t, global_hw_parameters_5));
      EMCPP_TEST_ASSERT_EQ((unsigned)DWC_usb3_GHWPARAMS6_OFFSET,
                           offsetof(EMC_USB_DRIVER_DWC3_registers_t, global_hw_parameters_6));
      EMCPP_TEST_ASSERT_EQ((unsigned)DWC_usb3_GHWPARAMS7_OFFSET,
                           offsetof(EMC_USB_DRIVER_DWC3_registers_t, global_hw_parameters_7));
      EMCPP_TEST_ASSERT_EQ((unsigned)DWC_usb3_GDBGFIFOSPACE_OFFSET,
                           offsetof(EMC_USB_DRIVER_DWC3_registers_t, global_debug_fifo_space_available));
      EMCPP_TEST_ASSERT_EQ((unsigned)DWC_usb3_GDBGLTSSM_OFFSET,
                           offsetof(EMC_USB_DRIVER_DWC3_registers_t, global_debug_ltssm));
      EMCPP_TEST_ASSERT_EQ((unsigned)DWC_usb3_GDBGLNMCC_OFFSET,
                           offsetof(EMC_USB_DRIVER_DWC3_registers_t, global_debug_lnmcc));
      EMCPP_TEST_ASSERT_EQ((unsigned)DWC_usb3_GDBGBMU_OFFSET,
                           offsetof(EMC_USB_DRIVER_DWC3_registers_t, global_debug_bmu));
      EMCPP_TEST_ASSERT_EQ((unsigned)DWC_usb3_GDBGLSPMUX_HST_OFFSET,
                           offsetof(EMC_USB_DRIVER_DWC3_registers_t, global_debug_lsp_mux));
      EMCPP_TEST_ASSERT_EQ((unsigned)DWC_usb3_GDBGLSP_OFFSET,
                           offsetof(EMC_USB_DRIVER_DWC3_registers_t, global_debug_lsp));
      EMCPP_TEST_ASSERT_EQ((unsigned)DWC_usb3_GDBGEPINFO0_OFFSET,
                           offsetof(EMC_USB_DRIVER_DWC3_registers_t, global_debug_endpoint_info_0));
      EMCPP_TEST_ASSERT_EQ((unsigned)DWC_usb3_GDBGEPINFO1_OFFSET,
                           offsetof(EMC_USB_DRIVER_DWC3_registers_t, global_debug_endpoint_info_1));
      EMCPP_TEST_ASSERT_EQ((unsigned)DWC_usb3_GPRTBIMAP_HSLO_OFFSET,
                           offsetof(EMC_USB_DRIVER_DWC3_registers_t, global_highspeed_port_to_usb_instance_mapping_lo));
      EMCPP_TEST_ASSERT_EQ((unsigned)DWC_usb3_GPRTBIMAP_HSHI_OFFSET,
                           offsetof(EMC_USB_DRIVER_DWC3_registers_t, global_highspeed_port_to_usb_instance_mapping_hi));
      EMCPP_TEST_ASSERT_EQ((unsigned)DWC_usb3_GPRTBIMAP_FSLO_OFFSET,
                           offsetof(EMC_USB_DRIVER_DWC3_registers_t, global_fullspeed_port_to_usb_instance_mapping_lo));
      EMCPP_TEST_ASSERT_EQ((unsigned)DWC_usb3_GPRTBIMAP_FSHI_OFFSET,
                           offsetof(EMC_USB_DRIVER_DWC3_registers_t, global_fullspeed_port_to_usb_instance_mapping_hi));
      EMCPP_TEST_ASSERT_EQ((unsigned)DWC_usb3_GUCTL2_OFFSET,
                           offsetof(EMC_USB_DRIVER_DWC3_registers_t, global_user_control_2));

      //SSIC global_usb3_rmmi_control[16]
      if (verbose()) {
        std::cout << "offset 0x" << std::hex
                  << offsetof(EMC_USB_DRIVER_DWC3_registers_t,
                    global_usb3_rmmi_control) << " (RMMICTL) missing in Celeno header" << std::dec << std::endl;
      }
      //global_usb2_phy_config[16];
      if (verbose()) {
        std::cout << "offset 0x" << std::hex
                  << offsetof(EMC_USB_DRIVER_DWC3_registers_t,
                    global_usb2_phy_config) << " (USB2PHY) missing in Celeno header" << std::dec << std::endl;
      }
      //SSIC/Hibernate global_usb3_pipe_control[16];
      if (verbose()) {
        std::cout << "offset 0x" << std::hex
                  << offsetof(EMC_USB_DRIVER_DWC3_registers_t,
                    global_usb3_pipe_control) << " (USB3PIPE) missing in Celeno header" << std::dec << std::endl;
      }
      //global_tx_fifo_size[32];
      if (verbose()) {
        std::cout << "offset 0x" << std::hex
                  << offsetof(EMC_USB_DRIVER_DWC3_registers_t,
                    global_tx_fifo_size) << " (TXFIFOSIZE) missing in Celeno header" << std::dec << std::endl;
      }
      //Hibernate global_rx_fifo_size[32];
      if (verbose()) {
        std::cout << "offset 0x" << std::hex
                  << offsetof(EMC_USB_DRIVER_DWC3_registers_t,
                    global_rx_fifo_size) << " (RXFIFOSIZE) missing in Celeno header" << std::dec << std::endl;
      }
      //Hibernate global_event_regs[32]
      if (verbose()) {
        std::cout << "offset 0x" << std::hex
                  << offsetof(EMC_USB_DRIVER_DWC3_registers_t,
                    global_event) << " (GEVENT) missing in Celeno header" << std::dec << std::endl;
      }
      EMCPP_TEST_ASSERT_EQ((unsigned)DWC_usb3_GHWPARAMS8_OFFSET,
                           offsetof(EMC_USB_DRIVER_DWC3_registers_t, global_hw_parameters_8));

      // used in host operation only:
      // EMCPP_TEST_ASSERT_EQ((unsigned)DWC_usb3_GUCTL3_OFFSET, offsetof(EMC_USB_DRIVER_DWC3_registers_t, ));

      EMCPP_TEST_ASSERT_EQ((unsigned)DWC_usb3_GTXFIFOPRIDEV_OFFSET,
                           offsetof(EMC_USB_DRIVER_DWC3_registers_t, global_tx_fifo_priority_device));

      // used in host operation only:
      // EMCPP_TEST_ASSERT_EQ((unsigned)DWC_usb3_GFLADJ_OFFSET, offsetof(EMC_USB_DRIVER_DWC3_registers_t, ));

      EMCPP_TEST_ASSERT_EQ((unsigned)DWC_usb3_DCFG_OFFSET,
                           offsetof(EMC_USB_DRIVER_DWC3_registers_t, device_config));
      EMCPP_TEST_ASSERT_EQ((unsigned)DWC_usb3_DCTL_OFFSET,
                           offsetof(EMC_USB_DRIVER_DWC3_registers_t, device_control));
      EMCPP_TEST_ASSERT_EQ((unsigned)DWC_usb3_DEVTEN_OFFSET,
                           offsetof(EMC_USB_DRIVER_DWC3_registers_t, device_event_enable));
      EMCPP_TEST_ASSERT_EQ((unsigned)DWC_usb3_DSTS_OFFSET,
                           offsetof(EMC_USB_DRIVER_DWC3_registers_t, device_status));
      EMCPP_TEST_ASSERT_EQ((unsigned)DWC_usb3_DGCMDPAR_OFFSET,
                           offsetof(EMC_USB_DRIVER_DWC3_registers_t, device_generic_command_parameter));
      EMCPP_TEST_ASSERT_EQ((unsigned)DWC_usb3_DGCMD_OFFSET,
                           offsetof(EMC_USB_DRIVER_DWC3_registers_t, device_generic_command));
      EMCPP_TEST_ASSERT_EQ((unsigned)DWC_usb3_DALEPENA_OFFSET,
                           offsetof(EMC_USB_DRIVER_DWC3_registers_t, device_active_endpoint_enable));
      //command[32]
      if (verbose()) {
        std::cout << "offset 0x" << std::hex
                  << offsetof(EMC_USB_DRIVER_DWC3_registers_t,
                    command) << " (DEPCMD) missing in Celeno header" << std::dec << std::endl;
      }
    }

    EMCPP_TEST_SUITE(Dwc3RegisterFileTest);
    EMCPP_TEST_ADD(test_register_offsets);
    EMCPP_TEST_SUITE_END();
  };

  EMCPP_TEST_SUITE_INSTANTIATION(Dwc3RegisterFileTest);

}}}
