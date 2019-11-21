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

void unlnk(char *cpn)
{
	short res;
	Inode werkInode;
	res=namei(cpn);
	printf("-------------Unlink--------------- \n");
	printf("resultaat van namei: %d \n",res);
	if (res==0 || res==-1){
		u.u_error=GEENINO;
		printf("FAILED, namei gaf mij %d! \n",res);
		return;
	}	
	LeesInode(res,&werkInode);
	

	int isLeeg=1;	
	if((werkInode.i_mode&S_IFMT)==S_IFDIR){	
		printf("dit is een map \n");
		Dir *dp;
		char buf[BLOKSIZE];
		dp=(Dir*)buf;
		int offset=0;
		printf("werkInode size: %d \n",werkInode.i_size);
		isLeeg=0;//	
		while (offset<werkInode.i_size){
			printf("offset %i \n",offset);
			if ((offset%BLOKSIZE)==0){
				LeesBlok(werkInode.i_blok[offset/BLOKSIZE],buf);
				dp=(Dir*)buf;
			}
			DrukBlok(buf,BLOKSIZE);
			if(dp->d_ino!=0){
				if(strcmp(dp->d_naam,"..")==0 || strcmp(dp->d_naam,".")==0){
					printf("dir is leeg\n");
					isLeeg=1;
				}else{
					printf("dir bevat iets\n");
					isLeeg=0;//bevat stuff
					break;
				}
			}
			offset+=DIRLEN;
			dp++;
		}
	}else{
		if (isLeeg){
			printf("is leeg of is bestand \n");
			DrukInode(&werkInode);
			printf("werkInode->i_link: %d \n",werkInode.i_link);
			if (werkInode.i_link<=2){
				werkInode.i_link=0;
				Dir *dp;
				char buf[BLOKSIZE];
				dp=(Dir*)buf;
				int offset=0;
				printf("werkInode size: %d \n",werkInode.i_size);
				if ((offset%BLOKSIZE)==0){
					LeesBlok(werkInode.i_blok[offset/BLOKSIZE],buf);
					dp=(Dir*)buf;
				}
				printf("diract gekregen door namei %d\n",u.u_diract);
				while (offset<u.u_diract){
					dp++;
					offset+=DIRLEN;
				}
				printf("offset in is leeg %d \n",offset);
				dp->d_ino=0;
				//dp->d_naam="000000";
				SetBfree(res);
				SetIfree(res);
				SchrijfBlok(werkInode.i_blok[u.u_diract/BLOKSIZE],dp);
			}else{
				werkInode.i_link-=1;
			}
			DrukInode(&werkInode);
			SchrijfInode(res,&werkInode);
			
		}else{
			u.u_error=NIETLEEG;
			printf("Failed to Unlink, map contains things \n");
			return;
		}
	}
}

