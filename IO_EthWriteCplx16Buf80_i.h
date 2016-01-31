#ifndef IO_ETHWRITECPLX16BUF80_I_H
#define IO_ETHWRITECPLX16BUF80_I_H


void IO_EthWriteCplx16Buf80_i (
	IN IO_t_CHDRHeaderState		* inpState,
	IN ORILIB_t_Cplx16Buf80		* sampleBuf,
	OUT IO_t_CHDRHeaderState	* outState 
	);

#endif
