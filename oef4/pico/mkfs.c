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

void mkfs(short ninode, short nblok)
{
	printf("mkfs met inode %d en blok %d \n",ninode,nblok);
}

