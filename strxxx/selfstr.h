#include <stdio.h>
#include <string.h>

int selfstrlen(char *a)
{
	if (a == NULL)
	{
		throw("invalid arguments");
	}

	char *i = a;
	while (*i != '\0')
	{
		i++;
	}
	return i - a;
}


char *selfstrcpy(char *a,const char *b)
{
	if (a == NULL || b == NULL)
	{
		throw("invalid arguments");
	}

	char *a1 = a;

	while (*b != '\0')
	{
		*a = *b;
		a++;
		b++;
	}
	*a = '\0';

	return a1;
}

char *selfstrcat(char *c, const char *d)
{
	if (c == NULL || d == NULL)
	{
		throw("invalid arguments");
	}

	char * c1 = c;

	while(*c != '\0')
	{
		c++;
	}
	while(*d != '\0')
	{
		*c = *d;
		c++;
		d++;
	}
	*c = '\0';

	return c1;
}

int selfstrcmp(const char *e,const char *f)
{
	if (e == NULL || f == NULL)
	{
		throw("invalid arguments");
	}

	while (*e==*f)
	{
		if (*e=='\0')
		{
			return 0;
		}
		e++;
		f++;
	}
	return *(unsigned char*)e - *(unsigned char*)f;
}