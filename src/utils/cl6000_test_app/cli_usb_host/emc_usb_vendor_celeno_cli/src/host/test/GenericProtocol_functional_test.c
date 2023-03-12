/**
 * @file
 * @brief   Generic Protocol functional test main
 * @author  <karsten.pahnke@emsys.de>
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/
#include "emc/usb/vendor/celeno/cli/host/test/GenericProtocol_functional_test_impl.h"

int main(int argc, char* argv[])
{
  return GenericProtocol_functional_test_run(argc, argv);
}
