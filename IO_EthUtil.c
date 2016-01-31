/**
Atomix project, IO_EthUtil.c, TODO: insert summary here
Copyright (c) 2016 Stanford University
Released under the Apache License v2.0. See the LICENSE file for details.
Author(s): Manu Bansal
*/

#include <osl/inc/swpform.h>
#include <osl/inc/amem4cpy_inl.h>
#include <osl/inc/eth/eth.h>
#include <string.h>
#include "ORILIB_t.h"

#include <ti/platform/platform.h>
#include "IO_util.h"

//NET_MSS
char IO_ethPktBuf[1500];

void IO_EthRawTx_(
	char * dst_mac_address,
	Uint16 ether_type,
	char * payload,
	Uint32 payload_len
	){

	platform_info pi;
	NET_ip_packet * ip_pkt = NULL;
	Uint32 pkt_len;
	char * pkt;
	Uint32 pld_len = payload_len;

	pkt = IO_ethPktBuf;
	ip_pkt = (NET_ip_packet *)pkt;
	IO_platform_get_info(&pi);

	//copy dst mac address into mac dst addr
	memcpy(pkt, dst_mac_address, 6);

	//copy our mac address into mac src addr
	memcpy(pkt + 6, pi.emac.efuse_mac_address, 6);

	//set ethertype
	memcpy(pkt + 12, &ether_type, 2);


	memcpy(pkt + 14, payload, pld_len);
	pkt_len = pld_len + 14 + 4;

	eth_send((uint8_t *)pkt, pkt_len);


	DEBUG_INFO(
	printf("EthRawTx: txPktLen: %d, ", pkt_len);
	printf(" dst:");
	eth_printMAC(ip_pkt->hw_header.dst_eth);
	printf(" src:");
	eth_printMAC(ip_pkt->hw_header.src_eth);
	)
}
