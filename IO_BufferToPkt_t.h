/**
Atomix project, IO_BufferToPkt_t.h, TODO: insert summary here
Copyright (c) 2015 Stanford University
Released under the Apache License v2.0. See the LICENSE file for details.
Author(s): Manu Bansal
*/

#ifndef IO_BUFFERTOPKT_T_H
#define IO_BUFFERTOPKT_T_H 

typedef struct {
  Int32 qid;
  Uint32 drainQueue;
  Uint32 read_offset_in_bytes;
  Uint32 n_words_to_write;
} IO_t_BufferToPktConf;

#endif /* IO_BUFFERTOPKT_T_H */
