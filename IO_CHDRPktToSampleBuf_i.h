/**
Atomix project, IO_CHDRPktToSampleBuf_i.h, TODO: insert summary here
Copyright (c) 2016 Stanford University
Released under the Apache License v2.0. See the LICENSE file for details.
Author(s): Manu Bansal
*/

#ifndef IO_CHDRPKTTOSAMPLEBUF_I_H
#define IO_CHDRPKTTOSAMPLEBUF_I_H 

#include "IO_CHDRPktToSampleBuf_t.h"

void IO_CHDRPktToSampleBuf_i (
      IN  IO_t_CHDRParserState * state,
      IN  void * samplePkt,
      OUT void * sampleBuf,
      CF  IO_t_CHDRParserConf * conf
      );

void IO_CHDRPktToSampleBuf_i_conf (
      CF  IO_t_CHDRParserConf * conf,
      IN  Uint32 sampleOffset
      );


#endif /* IO_CHDRPKTTOSAMPLEBUF_I_H */
