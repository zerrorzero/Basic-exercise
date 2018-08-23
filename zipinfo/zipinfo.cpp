/*#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "malloc.h"
#include "16time.h"
/*
signature:02014b50
flienamelen offset:28
fliename offset:46
lastchange offset:12 and size 2
notzipsize offset:24 and size 4

int main()
{
	//char path[]="c:\\workplace\\test2.zip";
	/*open and read the zip head
	char path[100];
	printf("input your filepath:");
	gets_s(path);
    printf("%s\n", path);

	FILE *fp;
	fp=fopen(path, "rb");//if don't read without binary way,may end in advance.

	if (fp == NULL)
	{
		printf("there are no such file!!!\n");
		return 1;
	}

	int i = 0;
	int signature = 0x02014b50;
	fseek(fp, 0, SEEK_END);
	int ziplen = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	printf("len:%d\n", ziplen);
	char* buf = (char *)malloc(ziplen*sizeof(char));

	if (fread(buf, 1, ziplen, fp) != ziplen)
	{
		printf("ERROR!!!");
	}

	/*print the head information*/
	/*&signature + offset = the info what you want of each file
	while(i<ziplen)
	{
		if (*(int*)(buf+i)==signature)
		{
			printf("[1]");
			unsigned short filenamelen = *(unsigned short*)(buf+i+28);
			char* fliename = (char *)malloc((filenamelen+1)*sizeof(char));
			strncpy(fliename,buf+i+46,filenamelen);
			fliename[filenamelen] = '\0';
			printf("filename:%s\n", fliename);
			free(fliename);

			printf("[2]");
			char* notzipsize = (char *)malloc(4*sizeof(char));
			strncpy(notzipsize, buf + i + 24, 4);
			printf("notzipsize:%d\n", *(unsigned short*)notzipsize);
			free(notzipsize);

			printf("[3]");
			char* TIME = (char *)malloc(2 * sizeof(char));
			strncpy(TIME, buf + i + 12, 2);
			//printf("lastchange:%x\n", *(unsigned short*)TIME);
			char* DATA = (char *)malloc(2 * sizeof(char));
			strncpy(DATA, buf + i + 14, 2);
			//printf("lastchange:%x\n", *(unsigned short*)DATA);
			printf("lastchange:%x\n", (*(unsigned short*)DATA << 16) + *(unsigned short*)TIME);
			//int a = 0;
			//a = ((*(unsigned short*)DATA << 16) + *(unsigned short*)TIME);
			//printf("%d\n", a);
			HEXtoTime(*(unsigned short*)DATA, *(unsigned short*)TIME);
			free(TIME);
			free(DATA);
		}
		
		i++;
		
	}

	free(buf);
	fclose(fp);


}*/
