#ifndef IO_ETHWRITECPLX16BUF80_I_H
#define IO_ETHWRITECPLX16BUF80_I_H


#include "ORILIB_t.h"
#include "IO_EthWriteCplx16Buf80_t.h"

void IO_EthWriteCplx16Buf80_i (
	IN ORILIB_t_Cplx16Buf80		* sampleBuf,
	CF IO_t_EthWriteCplx16Buf80Conf * conf
	);

void IO_EthWriteCplx16Buf80_i_conf(
	CF IO_t_EthWriteCplx16Buf80Conf * conf,
	IN char * dst_mac_addr
      );
#endif
