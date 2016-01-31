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

void IO_UDPFillHeader(
	Uint16 srcPort,
	Uint16 dstPort,
	Uint16 udpLen
	){
	char * pkt;
	pkt = IO_ethPktBuf;
	NET_udphdr * udphdr = (NET_udphdr *)(pkt + 14 + 20);
	udphdr->source = srcPort;
	udphdr->dest = dstPort;
	udphdr->len = udpLen;
	udphdr->check = 0;
}

void IO_IPFillHeader(
	char * srcIP,
	char * dstIP,
	Uint8 proto
	){
	
	//{
	//0x45, 0x00, 0x00, 0x00,                        // IP version, services, (14) total length (16)
	//0x00, 0x00, 0x00, 0x00,                        // IP ID, flags, fragment offset 
	//0x05, 0x11, 0x00, 0x00,                        // IP ttl, protocol (UDP), hdr checksum
	//0xC0, 0xA8, 0x0A, 0x01,                        // Source IP address
	//0xC0, 0xA8, 0x0A, 0x02,                        // Destination IP address
	//0x00, 0x00, 0x00, 0x00,                        // UDP source port, dest port
	//0x00, 0x00, 0x00, 0x00				// UDP len, UDP checksum
	//};                        


	char * pkt;
	pkt = IO_ethPktBuf;
	memset(pkt + 14, 0, 20);

	pkt[14     ] = 0x45; 	// IP version, hdr len
	pkt[14 +  9] = 0x7f;	// IP ttl
	pkt[14 + 10] = proto;	// protocol
	memcpy(pkt + 14 + 12, srcIP, 4);
	memcpy(pkt + 14 + 16, dstIP, 4);
}

void IO_EthFillHeader(
	char * dst_mac_address,
	Uint16 ether_type
	){

	char * pkt;
	platform_info pi;

	pkt = IO_ethPktBuf;
	IO_platform_get_info(&pi);

	//copy dst mac address into mac dst addr
	memcpy(pkt, dst_mac_address, 6);

	//copy our mac address into mac src addr
	memcpy(pkt + 6, pi.emac.efuse_mac_address, 6);

	//set ethertype
	memcpy(pkt + 12, &ether_type, 2);
}

void IO_EthFillPayload(
	char * payload, 
	Uint32 pld_len
	){

	char * pkt;
	pkt = IO_ethPktBuf;
	memcpy(pkt + 14, payload, pld_len);
}

void IO_EthRawTx_(
	Uint32 frame_len
	){

	NET_ip_packet * ip_pkt = NULL;
	char * pkt;

	pkt = IO_ethPktBuf;
	ip_pkt = (NET_ip_packet *)pkt;

	eth_send((uint8_t *)pkt, frame_len);

	DEBUG_INFO(
	printf("EthRawTx: txPktLen: %d, ", frame_len);
	printf(" dst:");
	eth_printMAC(ip_pkt->hw_header.dst_eth);
	printf(" src:");
	eth_printMAC(ip_pkt->hw_header.src_eth);
	)
}

