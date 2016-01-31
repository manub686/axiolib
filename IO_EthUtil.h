/**
Atomix project, IO_EthUtil.h, TODO: insert summary here
Copyright (c) 2016 Stanford University
Released under the Apache License v2.0. See the LICENSE file for details.
Author(s): Manu Bansal
*/

#ifndef IO_ETHUTIL_H
#define IO_ETHUTIL_H 

#include <osl/inc/swpform.h>
#include <osl/inc/eth/eth.h>

extern char IO_ethPktBuf[1500];

void IO_UDPFillHeader(
	Uint16 srcPort,
	Uint16 dstPort,
	Uint16 udpLen
	);

void IO_IPFillHeader(
	char * srcIP,
	char * dstIP,
	Uint8 proto
	);

void IO_EthFillHeader(
	char * dst_mac_address,
	Uint16 ether_type
	);

void IO_EthFillPayload(
	char * payload, 
	Uint32 pld_len
	);

void IO_EthRawTx_(
	Uint32 frame_len
	);

#endif /* IO_ETHUTIL_H */
