#include <osl/inc/swpform.h>
#include "IO_EthWriteCplx16Buf80_t.h"
#include <ORILIB_util.h>
#include "ORILIB_t.h"

//Uint8 sPkt[400];
#include "IO_EthUtil.h"

void IO_EthWriteCplx16Buf80_i (
	IN ORILIB_t_Cplx16Buf80		* sampleBuf,
	CF IO_t_EthWriteCplx16Buf80Conf * conf
	){
	//IN IO_t_CHDRState		* inpState

	static Uint16 seqNo = 0;

	char * pkt;
	pkt = IO_ethPktBuf;
	NET_udphdr * udphdr = (NET_udphdr *)(pkt + 14 + 20);
	

	Uint32 cvitaHeaderLen = 16;
	Uint32 totalHeaderLen = 58;
	Uint16 srcPort = 0x1234;
	Uint16 dstPort = 49153;
	char srcIP[4] = {0xc0, 0xa8, 0xc0, 0xa8};	//192.168.192.168
	char dstIP[4] = {0xc0, 0xa8, 0xc0, 0xa9};	//192.168.192.169
	Uint16 ether_type = 0x0800;
	//Uint32 frame_len = 14 + 20 + 8 + 16 + 80 * 4 + 4;
	Uint32 frame_len = 14 + 20 + 8 + 16 + 80 * 4;
	//Uint16 seqNo = inpState->seqNo;


	// set 42 bytes of header :
	// 14 for ethernet, 20 for ip, 8 for udp

	IO_UDPFillHeader(srcPort, dstPort, 8 + 16 + 80 * 4);

	IO_IPFillHeader(srcIP, dstIP, 0x11);	//0x11 is for UDP

	IO_EthFillHeader(conf->dst_mac_addr, ether_type);


	// Setting the CVITA header fields
	// sequence number
	seqNo = (seqNo + 1) % 4096;
	memcpy(pkt + 14 + 20 + 8, &seqNo, 2);

	// 80 samples in the buffer - each of 4 bytes
	memcpy(pkt + totalHeaderLen, sampleBuf, 80*4);
	DEBUG_INFO(
	printf(" outgoing packet of 80 samples with CHDRseqNo : %u\n", seqNo);
	)
	IO_EthRawTx_(frame_len); 
}


void IO_EthWriteCplx16Buf80_i_conf(
	CF IO_t_EthWriteCplx16Buf80Conf * conf,
	IN Uint64 dst_mac_addr
      ) {
  // Skip the 2 MSBs and copy the 6 LSBs
  memcpy(conf->dst_mac_addr, ((Uint8 *)&dst_mac_addr) + 2, 6);
}
