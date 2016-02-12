/**
Atomix project, IO_EthPacketCounter_t.h, TODO: insert summary here
Copyright (c) 2016 Stanford University
Released under the Apache License v2.0. See the LICENSE file for details.
Author(s): Manu Bansal
*/

#ifndef IO_ETHPACKETCOUNTER_T_H
#define IO_ETHPACKETCOUNTER_T_H

#include <osl/inc/swpform.h>

typedef struct {
  Uint64 timeout;
  void (*filter)(void *, Uint32, Int32 *, Uint32 *);
  Int32 block_on_queue;
 } IO_EthPacketCounterConf;

 #define IO_ETHPACKETCOUNTER_N_QUEUES  10

 typedef struct {
   Uint32 packet_count[IO_ETHPACKETCOUNTER_N_QUEUES];
 } IO_t_EthPacketCounterState;

#endif /* IO_ETHPACKETCOUNTER_T_H */
