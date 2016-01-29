/**
Atomix project, IO_util.h, TODO: insert summary here
Copyright (c) 2016 Stanford University
Released under the Apache License v2.0. See the LICENSE file for details.
Author(s): Manu Bansal
*/

#ifndef IO_UTIL_H
#define IO_UTIL_H 

#include <ti/platform/platform.h>

void IO_parseMACAddr(char * macString, char * macArray);
void IO_init_platform_info();
void IO_platform_get_info(platform_info * p_info);

#endif /* IO_UTIL_H */
