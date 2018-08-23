#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct tm_unz_s
{
	unsigned int tm_sec;            /* seconds after the minute - [0,59] */
	unsigned int tm_min;            /* minutes after the hour - [0,59] */
	unsigned int tm_hour;           /* hours since midnight - [0,23] */
	unsigned int tm_mday;           /* day of the month - [1,31] */
	unsigned int tm_mon;            /* months since January - [0,11] */
	unsigned int tm_year;           /* years - [1980..2044] */
} tm_unz;



void HEXtoTime(unsigned long ulDosDate)

{
	tm_unz ptm;
	unsigned long uDate;
	uDate = (unsigned long)(ulDosDate >> 16);
	ptm.tm_mday = (unsigned int)(uDate & 0x1f);//low 5 digit express day
	ptm.tm_mon = (unsigned int)((((uDate)& 0x1E0) / 0x20));//middle 4 digit express month
	ptm.tm_year = (unsigned int)(((uDate & 0x0FE00) / 0x0200) + 1980);//high 7 digit express year

	ptm.tm_hour = (unsigned int)((ulDosDate & 0xF800) / 0x800);//high 5 digit express hour
	ptm.tm_min = (unsigned int)((ulDosDate & 0x7E0) / 0x20);//middle 6 digit express min
	ptm.tm_sec = (unsigned int)(2 * (ulDosDate & 0x1f));//low 5 digit express sec.5 digit can express 31s,2*(5 digit) can express 62s.

	printf("%d/%d/%d  %02d:%02d:%02d\n", ptm.tm_year, ptm.tm_mon, ptm.tm_mday, ptm.tm_hour, ptm.tm_min, ptm.tm_sec);

}

