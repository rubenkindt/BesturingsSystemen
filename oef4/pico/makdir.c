/*
 *                   
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#define EXT extern
#include "hfs.h"

void makdir(char *cpn)
{
	printf("Make dir %s voor %d \n", cpn,u.u_uid);
}

