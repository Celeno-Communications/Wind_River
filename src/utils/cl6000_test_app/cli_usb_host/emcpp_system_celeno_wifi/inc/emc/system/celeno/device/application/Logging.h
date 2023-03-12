/**
 * @file
 * @brief
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/

#ifndef EMC_SYSTEM_CELENO_DEVICE_APPLICATION_Logging_H
#define EMC_SYSTEM_CELENO_DEVICE_APPLICATION_Logging_H

#include "emc/system/celeno/configure.h"
#include "emc/log/log.h"

// clang-format off extern C
#ifdef __cplusplus
extern "C" {
#endif
// clang-format on extern C

void CELENO_logging_init(void);

emc_logger_t* CELENO_logging_logger_init(void);

emc_logger_t* CELENO_logging_logger_wifi(void);
emc_logger_t* CELENO_logging_logger_wifi_us(void);
emc_logger_t* CELENO_logging_logger_wifi_us_mux(void);
emc_logger_t* CELENO_logging_logger_wifi_us_sens_onl(void);
emc_logger_t* CELENO_logging_logger_wifi_us_sens_ofl(void);
emc_logger_t* CELENO_logging_logger_wifi_us_data_rx(void);
emc_logger_t* CELENO_logging_logger_wifi_us_rxm0(void);

emc_logger_t* CELENO_logging_logger_wifi_ds(void);
emc_logger_t* CELENO_logging_logger_wifi_ds_tx0(void);
emc_logger_t* CELENO_logging_logger_wifi_ds_tx1(void);
emc_logger_t* CELENO_logging_logger_wifi_ds_tx2(void);
emc_logger_t* CELENO_logging_logger_wifi_ds_tx3(void);
emc_logger_t* CELENO_logging_logger_wifi_ds_bcn(void);
emc_logger_t* CELENO_logging_logger_wifi_ds_htp(void);
emc_logger_t* CELENO_logging_logger_wifi_ds_sensing(void);
emc_logger_t* CELENO_logging_logger_wifi_ds_resp(void);

emc_logger_t* CELENO_logging_create_logger_lli_us(emc_std_uint8_t lli_index);
emc_logger_t* CELENO_logging_create_logger_lli_ds(emc_std_uint8_t lli_index);

// clang-format off extern C
#ifdef __cplusplus
}
#endif
// clang-format on extern C

#endif /* EMC_SYSTEM_CELENO_DEVICE_APPLICATION_Logging_H */
