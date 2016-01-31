/**
Atomix project, IO_EthRawTx_i.c, Raw ethernet transmission block. This block 
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

#include "IO_EthRawTx_t.h"
//#include "DPDX_pkt_templates.h"
//#include "ORILIB_PLCPParser_t.h"

#include "IO_util.h"
#include "IO_EthUtil.h"


void IO_EthRawTx_i (
	IN void * payload,
	CF IO_t_EthRawTxConf * conf
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

  IO_EthFillHeader(
  	conf->dst_mac_address, 
	*(Uint16 *)conf->ether_type
	);

  IO_EthFillPayload(
	payload, 
	pld_len
	);

  IO_EthRawTx_(
	pld_len + 14 + 4
	);
}


void IO_EthRawTx_i_conf (
	CF IO_t_EthRawTxConf * conf,
	IN char * dst_mac_address,
	IN Uint16 ether_type,
	IN Uint32 payload_container_length_in_bytes,
	IN Uint32 payload_length_in_bytes
      ) {
  IO_parseMACAddr(dst_mac_address, conf->dst_mac_address);
  conf->ether_type = ether_type;
  conf->payload_container_length_in_bytes = payload_container_length_in_bytes;
  conf->payload_length_in_bytes = payload_length_in_bytes;
}
