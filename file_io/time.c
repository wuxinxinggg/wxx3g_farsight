#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main(void)
{

	time_t timep;
	struct tm *p; //defined a tm struct
	char * buf;

	timep = time(NULL);
	p = localtime(&timep);
	printf("%d\n",1900+p->tm_year);
	
	buf = ctime(&timep);	
	printf("%s\n",buf);

	buf = asctime(p);	
	printf("%s\n",buf);
	return 0;	
}
