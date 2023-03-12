# SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
obj-$(CPTCFG_CL6K) += cl6k.o

ccflags-y += -DDRV_VERSION=\"$(DRV_VERSION)\"

# Stop these C90 warnings. We use C99.
ccflags-y += -Wno-declaration-after-statement -g

IFACE_PREFIX=wlan

define cc_ver_cmp
$(shell [ "$$($(CC) -dumpversion | cut -d. -f1)" -$(1) "$(2)" ] && echo "true" || echo "false")
endef

ifeq ($(call cc_ver_cmp,ge,8),true)
	ccflags-y += -Wno-error=stringop-truncation
	ccflags-y += -Wno-error=format-truncation
endif

ccflags-y += -D__CHECK_ENDIAN__ -DDEBUG -DCL_IFACE_PREFIX=\"$(IFACE_PREFIX)\"
cl-objs += \
	cl_wrs/cl_wrs.o \
	cl_wrs/cl_wrs_api.o \
	cl_wrs/cl_wrs_cli.o \
	cl_wrs/cl_wrs_tables.o \
	cl_wrs/cl_wrs_rssi.o \
	cl_wrs/cl_wrs_sta.o \
	cl_wrs/cl_wrs_ap.o \
	cl_wrs/cl_wrs_stats.o \
	cl_m2u.o \
	cl_igmp.o \
	cl_key.o \
	cl_sta.o \
	cl_msg_tx.o \
	cl_fw_msg.o \
	cl_utils.o \
	cl_channel.o \
	cl_rx.o \
	cl_rx_amsdu.o \
	cl_tx.o \
	cl_tx_amsdu.o \
	cl_vendor_cmd.o \
	cl_main.o \
	cl_mac_addr.o \
	cl_ops.o \
	cl_otp.o \
	cl_ampdu.o \
	cl_tx_inject.o \
	cl_enhanced_tim.o \
	cl_e2p.o \
	cl_calibration.o \
	cl_chan_info.o \
	cl_edca.o \
	cl_timer.o \
	cl_agg_cfm.o \
	cl_single_cfm.o \
	cl_bcmc_cfm.o \
	cl_tx_queue.o \
	cl_stats.o \
	cl_cca.o \
	cl_noise.o \
	cl_baw.o \
	cl_bsr.o \
	cl_bsrp.o \
	cl_power.o \
	cl_power_cli.o \
	cl_power_table.o \
	cl_um_helper.o \
	cl_radar.o \
	cl_bf.o \
	cl_sounding.o \
	cl_dbgfile.o \
	cl_reg_cli.o \
	cl_temperature.o \
	cl_recovery.o \
	cl_phy.o \
	cl_prot_mode.o \
	cl_rate_ctrl.o \
	cl_radio.o \
	cl_config.o \
	cl_tcv_config.o \
	cl_traffic.o \
	cl_traffic_mon.o \
	cl_age_out.o \
	cl_rssi.o \
	cl_fw_file.o \
	cl_rx_sens.o \
	cl_rx_filter.o \
	cl_bw_sig.o \
	cl_vns.o \
	cl_env_det.o \
	cl_maintenance.o \
	cl_vw.o \
	cl_fw_dbg.o \
	cl_rfic.o \
	cl_lcu.o \
	cl_nco.o \
	cl_dyn_mcast_rate.o \
	cl_dyn_bcast_rate.o \
	cl_vif.o \
	cl_mib.o \
	cl_msg_cfm.o \
	cl_msg_rx.o \
	cl_band.o \
	cl_agg_tx_report.o \
	cl_fw_test.o \
	cl_hw_assert.o \
	cl_dsp_load.o \
	cl_ate.o \
	cl_sw_txhdr.o \
	cl_chandef.o \
	cl_version.o \
	cl_cap.o \
	cl_agc_params.o \
	cl_ip.o \
	cl_vlan_dscp.o \
	cl_netlink.o \
	cl_cma.o \
	cl_dual_nav.o \
	cl_twt_frame.o \
	cl_twt.o \
	cl_bss_color.o \
	cl_twt_cli.o \
	cl_cecli.o \
	cl_omi.o \
	cl_tf.o \
	cl_ul_length.o \
	cl_ul_rssi.o \
	cl_data_rates.o \
	cl_agg_rx_report.o \
	cl_rx_reorder.o \
	cl_calib_common.o \
	cl_calib_dcoc.o \
	cl_calib_iq.o \
	cl_calib_runtime.o

ccflags-y += -DPRESILICON_TESTING
#ccflags-y += -DNATT_DBG

ifeq ($(CECFG_DUMMY_PHY),y)
	ccflags-y += -DCE_DUMMY_PHY
endif

ccflags-y += -I$(src)/cl_wrs -I$(src)/../cl_core -I$(src)/../cl_core/reg

# CONFIG_CL_SW_PROFILING=y
CONFIG_CL_UM_HELPER_DFLT=$(host_install_dir)"/scripts/cl_umh.sh"
ifdef CPTCFG_DEBUG_FS
	CONFIG_CL_DEBUGFS=y
endif

ifdef CONFIG_CL_SW_PROFILING
	ccflags-y += -DCONFIG_CL_SW_PROFILING
endif

ifdef CONFIG_CL_DEBUGFS
	ccflags-y += -DCONFIG_CL_DEBUGFS
	cl-objs += cl_debugfs.o
	ifdef CONFIG_CL_UM_HELPER_DFLT
		ccflags-y += -DCONFIG_CL_UM_HELPER_DFLT=\"$(CONFIG_CL_UM_HELPER_DFLT)\"
	else
		ccflags-y += -DCONFIG_CL_UM_HELPER_DFLT=\"\"
	endif
endif

EXTRA_CFLAGS += -I$(src) -Werror

ifeq ($(CECFG_TRACE),y)
# Without this flag, the cl_trace.h will be searched for in include/trace/events,
# which is not what we desire.
	CFLAGS_cl_trace.o := -I$(src) -Wno-unused-variable -Wno-uninitialized
	cl-objs += cl_trace.o
	ccflags-y += -DTRACE_SUPPORT
endif

cl-objs += \
	cl_usb.o \
	cl_rx_usb.o \
	cl_tx_usb.o \
	cl_msg_usb.o

cl-objs += \
	cl_pci.o \
	cl_rx_pci.o \
	cl_tx_pci.o \
	cl_msg_pci.o \
	cl_ipc.o \
	cl_irq.o

ifneq ($(CPTCFG_CL6K),)
ccflags-y += -DCONFIG_CL6K
cl6k-y += $(cl-objs)
endif

ifneq ($(CECFG_DEMO_ENABLED),)
ccflags-y += -DCONFIG_DEMO_ENABLED
endif

