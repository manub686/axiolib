/**
Atomix project, IO_BufferToPkt_i.h, TODO: insert summary here
Copyright (c) 2015 Stanford University
Released under the Apache License v2.0. See the LICENSE file for details.
Author(s): Manu Bansal
*/

#ifndef IO_BUFFERTOPKT_I_H
#define IO_BUFFERTOPKT_I_H 

#include "ORILIB_EthReaderBuffered_t.h"
#include "IO_BufferToPkt_t.h"

void IO_BufferToPkt_i (
      IN  ORILIB_t_EthReaderBuffer * state,
      OUT void * pkt,
      CF  IO_t_BufferToPktConf * conf
      );

void IO_BufferToPkt_i_conf (
	CF IO_t_BufferToPktConf * conf,
	Int32 qid,
	Uint32 drainQueue,
	Uint32 read_offset_in_bytes,
	Uint32 n_words_to_write
	);

#endif /* IO_BUFFERTOPKT_I_H */
