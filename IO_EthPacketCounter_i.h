/**
Atomix project, IO_EthPacketCounter_i.h, TODO: insert summary here
Copyright (c) 2016 Stanford University
Released under the Apache License v2.0. See the LICENSE file for details.
Author(s): Manu Bansal
*/

#ifndef IO_ETHPACKETCOUNTER_I_H
#define IO_ETHPACKETCOUNTER_I_H

void IO_EthPacketCounter_i (
	IN IO_t_EthPacketCounterState	* state,
	CF IO_EthPacketCounterConf	* conf
	);


void IO_EthPacketCounter_i_conf (
	CF IO_EthPacketCounterConf	* conf,
	Uint64 timeout,
	void (*filter)(void *, Uint32, Int32 *, Uint32 *),
	In32 block_on_queue
	);

#endif /* IO_ETHPACKETCOUNTER_I_H */
