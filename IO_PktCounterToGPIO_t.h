/**
Atomix project, IO_PktCounterToGPIO_t.h, TODO: insert summary here
Copyright (c) 2016 Stanford University
Released under the Apache License v2.0. See the LICENSE file for details.
Author(s): Manu Bansal
*/

#ifndef IO_PKTCOUNTERTOGPIO_T_H
#define IO_PKTCOUNTERTOGPIO_T_H

#include "IO_EthPacketCounter_t.h"
typedef struct {
  Uint8 qid;
  Uint8 pin;
  Uint8 action;
} IO_PktCounterToGPIO_Conf;

#endif /* IO_PKTCOUNTERTOGPIO_T_H */
