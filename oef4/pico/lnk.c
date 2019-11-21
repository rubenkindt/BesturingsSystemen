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

void lnk( char *cpn, char *new)
{
	printf("Link %s %s\n", cpn, new);
}

