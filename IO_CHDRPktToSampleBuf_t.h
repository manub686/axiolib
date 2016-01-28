/**
Atomix project, IO_CHDRPktToSampleBuf_t.h, TODO: insert summary here
Copyright (c) 2016 Stanford University
Released under the Apache License v2.0. See the LICENSE file for details.
Author(s): Manu Bansal
*/

#ifndef IO_CHDRPKTTOSAMPLEBUF_T_H
#define IO_CHDRPKTTOSAMPLEBUF_T_H 

typedef struct {
  Uint32 lastSeqNo;
  Uint32 missing;
  Uint32 lastMissStride;
} IO_t_CHDRParserState; 

typedef struct {
  Uint32 sampleOffset;
} IO_t_CHDRParserConf;

#endif /* IO_CHDRPKTTOSAMPLEBUF_T_H */
