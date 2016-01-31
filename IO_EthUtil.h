/**
Atomix project, IO_EthUtil.h, TODO: insert summary here
Copyright (c) 2016 Stanford University
Released under the Apache License v2.0. See the LICENSE file for details.
Author(s): Manu Bansal
*/

#ifndef IO_ETHUTIL_H
#define IO_ETHUTIL_H 

#include <osl/inc/swpform.h>

extern char IO_ethPktBuf[1500];

void IO_EthRawTx_(
	char * dst_mac_address,
	Uint16 ether_type,
	char * payload,
	Uint32 payload_len
	);

#endif /* IO_ETHUTIL_H */
