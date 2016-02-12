/**
Atomix project, IO_EthPacketCounter_i.c, TODO: insert summary here
Copyright (c) 2016 Stanford University
Released under the Apache License v2.0. See the LICENSE file for details.
Author(s): Manu Bansal
*/

#include <osl/inc/swpform.h>
#include <osl/inc/amem4cpy_inl.h>
#include <osl/inc/eth/eth.h>
#include <osl/inc/uhd/uhd.h>
#include <osl/inc/eth/view_ale_table.h>
#include <string.h>
#include "ORILIB_t.h"
#include <ti/csl/csl_tsc.h>

#include <oros/sysilib/SYS_TimeStamp.h>
#include "ORILIB_util.h"
#include "IO_EthPacketCounter_t.h"

void IO_EthPacketCounter_i (
	IN IO_t_EthPacketCounterState	* state,
	CF IO_EthPacketCounterConf	* conf
	) {

  Uint8* rx_packet = NULL;
  Uint32 rx_packet_len = 0;
  Int32 qid;
  Uint32 blocked = 1;

  Int32 ret = -1;

  volatile Uint64 entr_tsc = CSL_tscRead();
  volatile Uint64 exit_tsc = entr_tsc + conf->timeout;
  volatile Uint64 curr_tsc;
  
  curr_tsc = CSL_tscRead();
	
  if (conf->block_on_queue < 0) {
    blocked = 0;
  } else {
    blocked = (state->packet_count[conf->block_on_queue] == 0);
  }

  // wait until timeout
  while (blocked || (curr_tsc < exit_tsc)) {
    ret = eth_recv(&rx_packet, &rx_packet_len, 0);
    curr_tsc = CSL_tscRead();
    if (ret < 0) { continue; }

    void (*filter)(void *, Uint32, Int32 * qid, Uint32 *);
    filter = conf->filter;
    (*filter)(rx_packet, rx_packet_len, &qid, (Uint32 *)NULL);

    if (qid < 0 || qid >= IO_ETHPACKETCOUNTER_N_QUEUES) {
      DEBUG_DATA(
        printf("bad queue id, dropping pkt...\n");
      )
    } else {
      state->packet_count[qid]++;
    }

    if (conf->block_on_queue < 0) {
      blocked = 0;
    } else {
      blocked = (state->packet_count[conf->block_on_queue] == 0);
    }

  }
}

void IO_EthPacketCounter_i_conf (
	CF IO_EthPacketCounterConf	* conf,
	Uint64 timeout,
	void (*filter)(void *, Uint32, Int32 *, Uint32 *),
	Int32 block_on_queue
	) {
  conf->timeout = timeout;
  conf->filter = filter;
  conf->block_on_queue = block_on_queue;
}
