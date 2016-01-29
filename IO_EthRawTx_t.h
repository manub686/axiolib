/**
Atomix project, IO_EthRawTx_t.h, TODO: insert summary here
Copyright (c) 2015 Stanford University
Released under the Apache License v2.0. See the LICENSE file for details.
Author(s): Manu Bansal
*/

#ifndef IO_ETHRAWTX_T_H
#define IO_ETHRAWTX_T_H 

#include <osl/inc/swpform.h>

typedef struct {
  char dst_mac_address[6];
  Uint16 ether_type;
  Uint32 payload_container_length_in_bytes;
  Uint32 payload_length_in_bytes;
} IO_t_EthRawTxConf;

#endif /* IO_ETHRAWTX_T_H */
