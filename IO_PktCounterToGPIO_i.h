/**
Atomix project, IO_PktCounterToGPIO_i.h, TODO: insert summary here
Copyright (c) 2016 Stanford University
Released under the Apache License v2.0. See the LICENSE file for details.
Author(s): Manu Bansal
*/

#ifndef IO_PKTCOUNTERTOGPIO_I_H
#define IO_PKTCOUNTERTOGPIO_I_H 
#include "IO_PktCounterToGPIO_t.h"
void IO_PktCounterToGPIO_i (
	IN IO_t_EthPacketCounterState * state,
	CF IO_PktCounterToGPIO_Conf * conf
	);


void IO_PktCounterToGPIO_i_conf (
	CF IO_PktCounterToGPIO_Conf * conf,
	IN Uint8 qid,
	IN Uint8 pin,
	IN Uint8 action
	);
#endif /* IO_PKTCOUNTERTOGPIO_I_H */
