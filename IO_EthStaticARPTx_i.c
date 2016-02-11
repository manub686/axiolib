/**
Atomix project, IO_EthStaticARPTx_i.c, Raw ethernet transmission block. This block 
can read in from orilib bit cache structure too with the right combination of
configuration parameters.

Copyright (c) 2015 Stanford University
Released under the Apache License v2.0. See the LICENSE file for details.
Author(s): Manu Bansal
*/

#include <osl/inc/swpform.h>
#include <osl/inc/amem4cpy_inl.h>
#include <osl/inc/eth/eth.h>
#include <string.h>
//#include "ORILIB_EthReader_t.h"
//#include "ORILIB_EthWriter_t.h"
#include "ORILIB_t.h"

#include <ti/platform/platform.h>

#include "IO_EthStaticARPTx_t.h"
//#include "DPDX_pkt_templates.h"
//#include "ORILIB_PLCPParser_t.h"

#include "IO_util.h"
#include "IO_EthUtil.h"


void IO_EthStaticARPTx_i (
	IN void * payload,
	CF IO_t_EthStaticARPTxConf * conf
      ){
  Uint32 pld_len;


  //copy payload
  if (conf->payload_length_in_bytes == 0) {
    //treat payload container as a bit cache with data 
    //capacity of conf->payload_container_length_in_bytes,
    //followed by an unsigned int indicating number of valid
    //bits in the container
    pld_len = *(Uint32 *)(payload + conf->payload_container_length_in_bytes);
    pld_len = pld_len/8;
  }
  else {
    pld_len = conf->payload_length_in_bytes;
  }

  Uint32 dst_ip;
  memcpy(&dst_ip, (Uint8 *)payload + 16, 4);

  char dst_mac_addr[6];  

  Uint32 arp_table_length = sizeof(conf->arp_table_ip)/sizeof(conf->arp_table_ip[0]);

  int index;
  for (index = 0; index < arp_table_length; index++) {
    if (dst_ip == conf->arp_table_ip[index]) {
       // Skip the 2 MSBs and copy the 6 LSBs in the mac address
       memcpy(dst_mac_addr, ((Uint8 *)&conf->arp_table_mac[index]) + 2, 6);
    }
  }
/*  //192.168.2.1
  if (dst_ip == 0xc0a80201) {	
    char dst_mac_addr_string[] = "00.08.dc.1e.cf.6b";
    IO_parseMACAddr(dst_mac_addr_string, dst_mac_addr);
//    dst_mac_addr = {0x21, 0x21, 0x21, 0x21, 0x21, 0x21};

  //192.168.2.2
  } else if (dst_ip == 0xc0a80202) {
    char dst_mac_addr_string[] = "00.08.dc.1e.cf.6d";
    IO_parseMACAddr(dst_mac_addr_string, dst_mac_addr);
//    dst_mac_addr = {0x22, 0x22, 0x22, 0x22, 0x22, 0x22};

  //192.168.3.1
  } else if (dst_ip == 0xc0a80301) {
    char dst_mac_addr_string[] = "c0.3f.d5.6e.3d.dd";
    IO_parseMACAddr(dst_mac_addr_string, dst_mac_addr);
//    dst_mac_addr = {0x31, 0x31, 0x31, 0x31, 0x31, 0x31};

  //192.168.3.2
  } else if (dst_ip == 0xc0a80302) {
    char dst_mac_addr_string[] = "c0.3f.d5.6e.3d.dd";
    IO_parseMACAddr(dst_mac_addr_string, dst_mac_addr);
//    dst_mac_addr = {0x32, 0x32, 0x32, 0x32, 0x32, 0x32};

  //192.168.3.3
  } else if (dst_ip == 0xc0a80303) {
    char dst_mac_addr_string[] = "c0.3f.d5.6e.3d.dd";
    IO_parseMACAddr(dst_mac_addr_string, dst_mac_addr);
//    dst_mac_addr = {0x33, 0x33, 0x33, 0x33, 0x33, 0x33};
  }*/
 

  IO_EthFillHeader(
  	dst_mac_addr, 
	0x0800
	);

  IO_EthFillPayload(
	payload, 
	pld_len
	);

  IO_EthRawTx_(
	pld_len + 14 + 4
	);
  // Assuming payload starts with a IP header
  DEBUG_INFO(
  printf("outgoing : length = %u srcIP = ", pld_len + 14 + 4);
  printIPAddr((Uint8 *) payload + 12);
  printf(" destIP = ");
  printIPAddr((Uint8 *) payload + 16);
  Uint8 protocol = *((Uint8 *)payload + 9);
  printf(" ip protocol = %u \n", protocol);
  )
}


void IO_EthStaticARPTx_i_conf (
	CF IO_t_EthStaticARPTxConf * conf,
	IN Uint32 node_0_ip,
	IN Uint64 node_0_mac,
	IN Uint32 node_1_ip,
	IN Uint64 node_1_mac,
	IN Uint32 node_2_ip,
	IN Uint64 node_2_mac,
	IN Uint32 node_3_ip,
	IN Uint64 node_3_mac,
	IN Uint32 node_4_ip,
	IN Uint64 node_4_mac,
	IN Uint32 payload_container_length_in_bytes,
	IN Uint32 payload_length_in_bytes
      ) {
  conf->arp_table_ip[0] = node_0_ip;
  conf->arp_table_mac[0] = node_0_mac;
  conf->arp_table_ip[1] = node_1_ip;
  conf->arp_table_mac[1] = node_1_mac;
  conf->arp_table_ip[2] = node_2_ip;
  conf->arp_table_mac[2] = node_2_mac;
  conf->arp_table_ip[3] = node_3_ip;
  conf->arp_table_mac[3] = node_3_mac;
  conf->arp_table_ip[4] = node_4_ip;
  conf->arp_table_mac[4] = node_4_mac;

  conf->payload_container_length_in_bytes = payload_container_length_in_bytes;
  conf->payload_length_in_bytes = payload_length_in_bytes;
}
