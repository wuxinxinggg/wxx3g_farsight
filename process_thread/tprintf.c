#include "wxx3g.h"
#if 0
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <time.h>
#endif
int tprintf(const char *fmt,...)
{
	va_list args;
	struct tm *tstruct;
	time_t tsec;

	tsec = time(NULL);
	tstruct = localtime(&tsec);

	printf("%02d:%02d:%02d %5d|",tstruct->tm_hour,\
			tstruct->tm_min,tstruct->tm_sec,getpid());

	va_start(args,fmt);
	return vprintf(fmt,args);
}

#if 0
int main(void)
{
	tprintf("Hello World\n");

	return 0;
}
#endif
