/**
Atomix project, IO_BufferToPkt_i.c, TODO: insert summary here
Copyright (c) 2015 Stanford University
Released under the Apache License v2.0. See the LICENSE file for details.
Author(s): Manu Bansal
*/



#include "ORILIB_EthReaderBuffered_t.h"
#include "IO_BufferToPkt_t.h"
#include <ORILIB_util.h>

static Uint32 seqs[30];
static Uint32 sidx = 0;


void IO_BufferToPkt_i (
      IN  ORILIB_t_EthReaderBuffer * state,
      OUT void * pkt,
      CF  IO_t_BufferToPktConf * conf
      ) {

  char * buf;
  Uint32 idx;
  Uint32 nwr;
  Uint32 nwr0;
  Uint32 ndw;
  Int32 qid;

  Uint32 read_offset_in_bytes = conf->read_offset_in_bytes;
  Uint32 n_words_to_write = conf->n_words_to_write;

  //id of the buffer queue being accessed
  qid = conf->qid; 


  nwr = state->nWritten[qid];
  nwr0 = nwr;
  //idx = state->lastWritten[qid];
  idx = ((state->lastWritten[qid] + ORILIB_ETHREADERBUFFERED_N_BUFS) - nwr + 1) 
  	% ORILIB_ETHREADERBUFFERED_N_BUFS;

  buf = state->pktBuf[qid][idx];

  //MSS is 1536, which is 384 words
    if (n_words_to_write == 0 || n_words_to_write > 384) {
      n_words_to_write = 384;
    }


  if (nwr > 0) {
  //ndw = ceil(MSS, 8);
  //_mem4cpy(pkt, buf, ndw * 2);

    if (read_offset_in_bytes % 4 == 0) {
      //_mem4cpy(pkt + read_offset_in_bytes, buf, 384);  //1536/4
      _mem4cpy(pkt, buf + read_offset_in_bytes, n_words_to_write);
    }
    else {
      memcpy(pkt, buf + read_offset_in_bytes, n_words_to_write << 2);
      memcpy(&seqs[sidx++], buf + read_offset_in_bytes - 4, 4);
      sidx = sidx % 30;
      //if (sidx == 0)
    	//  SW_BREAKPOINT;
    }

  }
  else {
    memset(pkt, 0, n_words_to_write << 2);
  }

  //idx = nwr > 0 ? (idx + 1) % N_BUFS : idx;
  nwr = nwr > 0 ? nwr - 1 : 0;

  if (conf->drainQueue) {
    //drain all remaining pkts in the queue
    nwr = 0;
  }

  //state->lastWritten[qid] = idx;
  state->nWritten[qid] = nwr;

  //printf("IO_BufferToPkt: qid: %d, nwr0: %d, nwr: %d\n", qid, nwr0, nwr);
}

void IO_BufferToPkt_i_conf (
	CF IO_t_BufferToPktConf * conf,
	Int32 qid,
	Uint32 drainQueue,
	Uint32 read_offset_in_bytes,
	Uint32 n_words_to_write
	){

  //queue to access for a pkt
  conf->qid = qid;

  //whether to drain out remaining pkts in queue; this is useful if this is
  //going to be the last pkt get call for the queue in this batch of pkts.
  conf->drainQueue = drainQueue;	

  //TODO maybe:
  //pkt retrieval order: LIFO if isLIFO == 1, FIFO otherwise
  //conf->isLIFO = isLIFO;

  conf->read_offset_in_bytes = read_offset_in_bytes;
  conf->n_words_to_write = n_words_to_write;
}
