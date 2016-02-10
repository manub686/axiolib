/**
Atomix project, IO_EthIntfAddMAC_i.c, TODO: insert summary here
Copyright (c) 2016 Stanford University
Released under the Apache License v2.0. See the LICENSE file for details.
Author(s): Manu Bansal
*/

#include <osl/inc/swpform.h>
//#include <osl/inc/eth/eth.h>
#include <osl/eth/cpsw_singlecore.h>
#include "IO_EthIntfAddMAC_t.h"
#include "IO_util.h"

void IO_EthIntfAddMAC_i (
  CF IO_t_EthIntfAddMACConf * conf
  ) {

	if (Setup_PASS (conf->mac) != 0)
	{
		printf ("PASS setup failed \n");
		//return -1;
	}
	else
	{
		printf ("PASS is listening on mac addr "); 
		printMacAddr(conf->mac);
		printf("\n");
	}

}


void IO_EthIntfAddMAC_i_conf (
  CF IO_t_EthIntfAddMACConf * conf,
  IN Uint64 mac_addr
  ) {
  // Skip the 2 MSBs and copy the 6 LSBs
  memcpy(conf->mac, ((Uint8 *)&mac_addr) + 2, 6);

}
 
