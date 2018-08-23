#include <stdio.h>
#include <string.h>
#include "malloc.h"
using namespace std;


int main()
{

	char *path = "c:\\workplace\\test1.dat";
	FILE *fp;
	fp = fopen(path, "rb");

	if (fp == NULL)
	{
		printf("there are no such file!!!\n");
		return 1;
	}
	
	int i = 0;
	fseek(fp, 0, SEEK_END);
	int len = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	printf("len:%d\n", len);
	char *buf = (char *)malloc(len*sizeof(char));

	if (fread(buf, 1, len, fp) != len)
	{
		printf("READ ERROR!!!");
	}
	printf("Result:");
	while (i < len)
	{
		char *P = (char *)malloc(2 * sizeof(char));
		strncpy(P, buf + i, 1);
		P[1] = '\0';
		printf("%s", P);
		i++;
		free(P);
	}
	printf("\n\n----THE END----\n");

	free(buf);

	fclose(fp);

}

