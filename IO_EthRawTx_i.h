/**
Atomix project, IO_EthRawTx_i.h, TODO: insert summary here
Copyright (c) 2015 Stanford University
Released under the Apache License v2.0. See the LICENSE file for details.
Author(s): Manu Bansal
*/

#ifndef IO_ETHRAWTX_I_H
#define IO_ETHRAWTX_I_H 

#include "IO_EthRawTx_t.h"

void IO_EthRawTx_i (
	IN void * payload,
	CF IO_t_EthRawTxConf * conf
      );

void IO_EthRawTx_i_conf (
	CF IO_t_EthRawTxConf * conf,
	IN char * dst_mac_address,
	IN Uint16 ether_type,
	IN Uint32 payload_container_length_in_bytes,
	IN Uint32 payload_length_in_bytes
      );

#endif /* IO_ETHRAWTX_I_H */
