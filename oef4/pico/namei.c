 /*
  *      namei.c         Ruben Kindt 
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#define EXT extern
#include "hfs.h"


short namei(char* input)
{	
	int i=0;
	short ui;
	Inode  werkInode;
	if (input[0]=='/')
	{
		i++;
		ui=u.u_rdir;
	}else
	{
		ui=u.u_cdir;
		//DrukInode(&werkInode);
	}
	DrukInode(&werkInode);
	LeesInode(ui,&werkInode);	
	
	while(input[i] != '\0')
	{
		int j=0;
		memset(u.u_dirent.d_naam,'\0',sizeof(u.u_dirent.d_naam));
		while(input[i] !='/' && input[i]!='\0')
		{
		//	printf("i: %i j:%i \n",i,j);
			if(j<NAMELEN)
				u.u_dirent.d_naam[j]=input[i];
			i++;
			j++;
		}
		while (input[i]=='/'){
			i++;
		}
		printf("naam copied %s \n",u.u_dirent.d_naam);
		if(ui==u.u_rdir && strcmp(u.u_dirent.d_naam,"..")==0){
			printf(".. bij root \n");
			continue;
		}

		if((werkInode.i_mode&S_IFMT)!=S_IFDIR){
			printf("error \n");
			u.u_error=GEENDIR;
			return -1;
		}
	
		Dir *dp;
		char buf[BLOKSIZE];
		dp=(Dir*)buf;
		int offset=0;
		printf("werkInode size: %d \n",werkInode.i_size);
		int gevonden;
		int diract_niet_gezet=1;
		while (offset<werkInode.i_size)
		{
			gevonden=0;
			printf("offset %i \n",offset);
			if ((offset%BLOKSIZE)==0){
				LeesBlok(werkInode.i_blok[offset/BLOKSIZE],buf);
				dp=(Dir*)buf;
			}
			
			DrukBlok(buf,BLOKSIZE);
			if(dp->d_ino!=0){
				printf("d_naam om te vergelijken: %s \n", dp->d_naam);
				if(strcmp(dp->d_naam,u.u_dirent.d_naam)==0)
				{
					u.u_dirent.d_ino=dp->d_ino;
					printf("ik heb iets gevonden %s \n",dp->d_naam);
					u.u_pdir=ui;
					ui=dp->d_ino;
					LeesInode(dp->d_ino,&werkInode);	
					u.u_diract =offset;
					gevonden=1;
					break;
				}
			}else{
				if(diract_niet_gezet){
					diract_niet_gezet=0;
					u.u_diract =offset;
				}	
			}
			offset+=DIRLEN;
			dp++;
		}
		if(diract_niet_gezet)
			u.u_diract =offset;
		if (gevonden==0){
			u.u_pdir=ui;
			if(input[i]=='\0'){
				return 0;
			}else{
				return -1;
			}
		}
		
	}
	return(ui);
}
