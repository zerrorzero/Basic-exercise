#include <stdio.h>
#include <string.h>
#include "selfstr.h"

int main()
{
	char s[1024],b[1024];
	printf("input the first one:");
	gets_s(s);
	printf("input the next one:");
	gets_s(b);

	int d,j;
	char e[1024],f[1024];
	char g[1024] = "STRCAT";
	d = selfstrlen(s);
	j = strlen(s);
	selfstrcpy(e,s);
	strcpy_s(f, s);
	selfstrcat(g,s);
	strcat_s(g, s);
	printf("this is the result of mylen:%d\n", d);
	printf("this is the result of strlen:%d\n", j);
	printf("this is the result of mycpy:%s\n", e);
	printf("this is the result of strcpy:%s\n", f);
	printf("this is the result of mycat:%s\n", g);
	printf("this is the result of strcat:%s\n", g);
	if (selfstrcmp(s,b)>0)
	{
		printf("this is the result of mycmp:%s\n > %s\n", s,b);
	}
	else if (selfstrcmp(s,b)<0)
	{
		printf("this is the result of mycmp:%s\n < %s\n", s, b);
	}
	else
	{
		printf("this is the result of mycmp:%s\n = %s\n", s, b);
	}

	if (strcmp(s, b) > 0)
	{
		printf("this is the result of strcmp:%s\n > %s\n", s, b);
	}
	else if (strcmp(s, b) < 0)
	{
		printf("this is the result of strcmp:%s\n < %s\n", s, b);
	}
	else
	{
		printf("this is the result of strcmp:%s\n = %s\n", s, b);
	}
}