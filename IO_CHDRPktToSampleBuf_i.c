/**
Atomix project, IO_CHDRPktToSampleBuf_i.c, TODO: pkt parser for USRPX300's CHDR protocol
Copyright (c) 2016 Stanford University
Released under the Apache License v2.0. See the LICENSE file for details.
Author(s): Manu Bansal
*/


#include <osl/inc/swpform.h>
#include "IO_CHDRPktToSampleBuf_t.h"
#include <ORILIB_util.h>

//static Uint32 seqs[30];
//static Uint32 sidx = 0;

void IO_CHDRPktToSampleBuf_i (
      IN  IO_t_CHDRParserState * state,
      IN  void * samplePkt,
      OUT void * sampleBuf,
      CF  IO_t_CHDRParserConf * conf
      ){


  Uint16 seqNo;
  Uint8 * sPkt = (Uint8 *)samplePkt;
  Uint8 * sBuf = (Uint8 *)sampleBuf;

  Uint32 read_offset_in_bytes = conf->sampleOffset;

  //TODO: #words to write should actually be read from CHDR
  Uint32 n_words_to_write = 80;

  //debugging output
  DEBUG_INFO(
  printf("srcIP: ");
  printIPAddr(sPkt + 26);
  printf(" dstIP: ");
  printIPAddr(sPkt + 30);
  )
  memcpy(&seqNo, sPkt+42, 2); seqNo <<= 4; seqNo >>= 4;
  DEBUG_INFO(
  printf(" udpSrcPort: %hu  udpDstPort: %hu CHDRseqNo: %hu\n",
      *(unsigned short *)(sPkt+34), 
      *(unsigned short *)(sPkt+36),
      seqNo
      ); 
  )
  if ((state->lastSeqNo + 1) % 4096 != seqNo) {
    state->missing++;
    state->lastMissStride = (4096 + seqNo - state->lastSeqNo - 1) % 4096;
  }


  if (read_offset_in_bytes % 4 == 0) {
    _mem4cpy(sBuf, sPkt + read_offset_in_bytes, n_words_to_write);
  }
  else {
    memcpy(sBuf, sPkt + read_offset_in_bytes, n_words_to_write << 2);
  }

  //memcpy(&seqs[sidx++], buf + read_offset_in_bytes - 4, 4);
  //sidx = sidx % 30;
  ////if (sidx == 0)
  //  //  SW_BREAKPOINT;
}

void IO_CHDRPktToSampleBuf_i_conf (
      CF  IO_t_CHDRParserConf * conf,
      IN  Uint32 sampleOffset
      ){

      conf->sampleOffset = sampleOffset;
}
