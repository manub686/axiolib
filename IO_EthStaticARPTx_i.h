/**
Atomix project, IO_EthStaticARPTx_i.h, TODO: insert summary here
Copyright (c) 2015 Stanford University
Released under the Apache License v2.0. See the LICENSE file for details.
Author(s): Manu Bansal
*/

#ifndef IO_ETHSTATICARPTX_I_H
#define IO_ETHSTATICARPTX_I_H 

#include "IO_EthStaticARPTx_t.h"

void IO_EthStaticARPTx_i (
	IN void * payload,
	CF IO_t_EthStaticARPTxConf * conf
      );

void IO_EthStaticARPTx_i_conf (
	CF IO_t_EthStaticARPTxConf * conf,
	IN Uint16 ether_type,
	IN Uint32 payload_container_length_in_bytes,
	IN Uint32 payload_length_in_bytes
      );

#endif /* IO_ETHSTATICARPTX_I_H */
