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


void makfile(char *cpn,  short mode, short size, char opvul)
{
	printf("makFile %s voor %d  met %o : %d * %c tekens\n", 
				cpn,u.u_uid,mode,size,opvul);
}

