#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include "malloc.h"
#include "16time.h"
/*
signature:02014b50
flienamelen offset:28
fliename offset:46
lastchange offset:12 and size 2
notzipsize offset:24 and size 4
endofcentral:06054b50
*/
int main()
{
	/*open and read the zip head*/
	char path[] = "c:\\workplace\\test2.zip";

	FILE *fp;
	fp = fopen(path, "rb");//if don't read without binary way,may end in advance.

	if (fp == NULL)
	{
		printf("there are no such file!!!\n");
		return 1;
	}

	
	int signature = 0x02014b50;
	int endofcentral = 0x06054b50;
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
	/*&signature + offset = the info what you want of each file*/
	WORD numb;
	DWORD size;
	int  u= 0;
	while (u < ziplen)
	{
		if (*(int*)(buf + u) == endofcentral)
		{
			numb = *(WORD *)(buf + u + 10);
			printf("File Numb:%d\n", numb);

		}
		else if (*(int*)(buf + u) == (endofcentral + 1))
		{

		}
		u++;
	}

	int i = 0;
	while (i < ziplen)
	{

		if (*(int*)(buf + i) == signature)
		{
			int o = 0;
			while (o < numb)
			{
				WORD filenamelen = *(WORD*)(buf + i + 28);
				WORD extrafieldlen = *(WORD*)(buf + i + 30);
				WORD filecommentlen = *(WORD*)(buf + i + 32);

				printf("[1]");
				char* fliename = (char *)malloc((filenamelen + 1)*sizeof(char));
				strncpy(fliename, buf + i + 46, filenamelen);
				fliename[filenamelen] = '\0';
				printf("filename:%s\n", fliename);
				free(fliename);

				printf("[2]");
				DWORD notzipsize = *(DWORD*)(buf + i + 24);
				printf("notzipsize:%d\n", notzipsize);

				printf("[3]");
				DWORD LAST = *(DWORD*)(buf + i + 12);
				printf("lastchange:%x\n", LAST);
				HEXtoTime(LAST);

				i = filenamelen + filecommentlen + extrafieldlen + i + 46;
				o++;
			}
		}
		else if (*(int*)(buf + i) == (signature + 1))
		{
			break;
		}

		i++;
	}

	free(buf);
	fclose(fp);


}