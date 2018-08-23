#include <stdio.h>
#include <string.h>
#include "malloc.h"

int main()
{
	char sr[1024];
	int a;
	printf("please chose whatever you want:\n[1]string in cmd \n[2]txt file \n");
	scanf_s("%1d",&a);
	if (a!=1 && a!=2)
	{
		printf("please input correct numb");
	}
	fflush(stdin);
	switch (a)
	{
	case 1:
	{
		printf("please write whatever you want:\n");
		gets_s(sr);

		int m;
		m = strlen(sr)-1;


		do
		{
			printf("%c", sr[m]);
			m--;
		} while (m >= 0);
		break;
	}
	case 2:
	{

		char *path = "c:\\workplace\\12.txt";
		FILE *fp;
		fp = fopen(path, "rb");

		if (fp == NULL)
		{
			printf("there are no such file!!!\n");
			return 1;
		}
		fseek(fp, 0, SEEK_END);
		int len = ftell(fp);
		fseek(fp, 0, SEEK_SET);
		char* buf = (char *)malloc((len)*sizeof(char));

		if (fread(buf, 1, len, fp) != len)
		{
			printf("READ ERROR!!!");
		}
		
		int i = len-1;
		while (i>=0)
		{
			char *p = (char *)malloc(2*sizeof(char));
			strncpy(p, buf+i,1);//strncpy cannot add '\0' at end when it read string.
			p[1] = '\0';//if your string haven't '\0',your need add it by yourself.
			printf("%s", p);
			i--;

		}
		break;
	}
	}
	

	printf("\n--end--\n");



}