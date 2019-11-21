/*
 *                   de uitbreiding
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#define EXT extern
#include "hfs.h"

void curd(char *cpn, int wortel)
{
	short res;
	Inode werkInode;
	res=namei(cpn);

	printf("resultaat van namei: %d \n",res);
	if (res==0 || res==-1){
		printf("res: %d \n",res);
		u.u_error=GEENINO;
		return ;
	}
	
	LeesInode(res,&werkInode);	
	DrukInode(&werkInode);
	if((werkInode.i_mode&S_IFMT)!=S_IFDIR){
		u.u_error=GEENDIR;
		return;
	}
	if (wortel==0){//normal dir
		u.u_cdir=res;
	}else{		//root dir
		u.u_rdir=res;	
	}
}

