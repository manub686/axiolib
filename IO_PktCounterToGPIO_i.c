/**
Atomix project, IO_PktCounterToGPIO_i.c, TODO: insert summary here
Copyright (c) 2016 Stanford University
Released under the Apache License v2.0. See the LICENSE file for details.
Author(s): Manu Bansal
*/

#include "IO_PktCounterToGPIO_t.h"
#include "IO_EthPacketCounter_t.h"
#include "ORILIB_util.h"

void IO_PktCounterToGPIO_i (
	IN IO_t_EthPacketCounterState * state,
	CF IO_PktCounterToGPIO_Conf * conf
	) {

  if (state->packet_count[conf->qid] > 0) {
    ORILIB_gpio_output_control(0, conf->pin, conf->action);
    state->packet_count[conf->qid] -= 1;
  }
}

void IO_PktCounterToGPIO_i_conf (
	CF IO_PktCounterToGPIO_Conf * conf,
	IN Uint8 qid,
	IN Uint8 pin,
	IN Uint8 action
	) {

  conf->qid = qid;
  conf->pin = pin;
  conf->action = action;
}
