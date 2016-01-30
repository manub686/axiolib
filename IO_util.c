/**
Atomix project, IO_util.c, TODO: insert summary here
Copyright (c) 2016 Stanford University
Released under the Apache License v2.0. See the LICENSE file for details.
Author(s): Manu Bansal
*/

#include <ti/platform/platform.h>
#include <ORILIB_util.h>

static platform_info p_I;

void IO_printIPAddr(void * addr) {
  unsigned char * p = (unsigned char *)addr;
  printf("%u.%u.%u.%u", *p, *(p+1), *(p+2), *(p+3));
}

void IO_printMacAddr(void * addr) {
  int i = 0;
  unsigned char * p = (unsigned char *)addr;
  for (i = 0; i < 5; i++) {
    printf("%02x:", p[i]);
  }
  printf("%02x", p[i]);
}


void IO_parseMACAddr(char * macString, char * macArray) {
  int i;
  int values[6];
  uint8_t bytes[6];
  char * mac = macString;

  //if( 6 == sscanf(mac, "%x:%x:%x:%x:%x:%x%c",
  if( 6 == sscanf(mac, "%x.%x.%x.%x.%x.%x%c",
      &values[0], &values[1], &values[2],
      &values[3], &values[4], &values[5] ) )
  {
      /* convert to uint8_t */
      for( i = 0; i < 6; ++i )
	  bytes[i] = (uint8_t) values[i];

      memcpy(macArray, bytes, 6);
  }

  else
  {
      /* invalid mac */
      //printf("bad mac address string\n");
  }
}



void IO_init_platform_info() {
  platform_get_info(&p_I);
  printf("My mac address is ");
  printMacAddr(p_I.emac.efuse_mac_address);
  printf("\n");
}

void IO_platform_get_info(platform_info * p_info) {
  memcpy(p_info, &p_I, sizeof(platform_info));
}
