/**
Atomix project, IO_EthIntfAddMAC_i.h, TODO: insert summary here
Copyright (c) 2016 Stanford University
Released under the Apache License v2.0. See the LICENSE file for details.
Author(s): Manu Bansal
*/

#ifndef IO_ETHINTFADDMAC_I_H
#define IO_ETHINTFADDMAC_I_H


void IO_EthIntfAddMAC_i (
  CF IO_t_EthIntfAddMACConf * conf
  );



void IO_EthIntfAddMAC_i_conf (
  CF IO_t_EthIntfAddMACConf * conf,
  IN Uint64 mac_addr
  );
#endif /* IO_ETHINTFADDMAC_I_H */
