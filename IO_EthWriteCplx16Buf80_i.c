#include <osl/inc/swpform.h>
#include "IO_EthWriteCplx16Buf80_t.h"
#include <ORILIB_util.h>

void IO_EthWriteCplx16Buf80_i (
	IN IO_t_CHDRHeaderState		* inpState,
	IN ORILIB_t_Cplx16Buf80		* sampleBuf,
	OUT IO_t_CHDRHeaderState	* outState 
	) {
	
	Uint8 sPkt[400];

	Uint8 * sBuf = (Uint8 *)sampleBuf;
	Uint8 eth_ip_udp_hdrs[42] = {
	        0x00, 0x00, 0x00, 0x00, 0x00, 0x00,            // Dest MAC (0)
	        0x00, 0x01, 0x01, 0x01, 0x01, 0x01,            // Src MAC (6)
	        0x08, 0x00,                                    // Ethertype IPv4 (12)
		0x45, 0x00, 0x00, 0x00,                        // IP version, services, (14) total length (16)
		0x00, 0x00, 0x00, 0x00,                        // IP ID, flags, fragment offset 
		0x05, 0x11, 0x00, 0x00,                        // IP ttl, protocol (UDP), hdr checksum
		0xC0, 0xA8, 0x0A, 0x01,                        // Source IP address
		0xC0, 0xA8, 0x0A, 0x02,                        // Destination IP address
		0x00, 0x00, 0x00, 0x00,                        // UDP source port, dest port
		0x00, 0x00, 0x00, 0x00				// UDP len, UDP checksum
	};                        
	Uint32 ethIpUdpHeaderLen = 42;
	Uint32 cvitaHeaderLen = 16;
	Uint32 totalHeaderLen = 58;
	Uint16 seqNo = inpState->seqNo;

	// set 42 bytes of header :
	// 14 for ethernet, 20 for ip, 8 for udp
	memcpy(sPkt, eth_ip_udp_hdrs, ethIpUdpHeaderLen);
	memset(sPkt + ethIpUdpHeaderLen, 0, cvitaHeaderLen);

	// Setting the CVITA header fields
	// sequence number
	seqNo = (seqNo + 1) % 4096;
	memcpy(sPkt + ethIpUdpHeaderLen, &seqNo, 2);
	

	// 80 samples in the buffer - each of 4 bytes
	memcpy(sPkt + totalHeaderLen, sBuf, 80*4);

	eth_send(sPkt, 	totalHeaderLen + 80*4);
}
