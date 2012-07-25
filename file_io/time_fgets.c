#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int line = 0;	
	time_t timep;
	struct tm *p; //defined a tm struct
//	char * buf;
	FILE *fp;
	char buf[BUFSIZ];

	fp = fopen("time_fgets.txt","a+");
	if(NULL == fp)
	{
		perror("fopen");
		exit(1);
	}

	while(!feof(fp) && !ferror(fp))
	{
		memset(buf,'\0',sizeof(buf));//initial the array
		fgets(buf,sizeof(buf),fp);
		line++;
	}

	while(1)
	{
		timep = time(NULL);//get the calendar time
		p = localtime(&timep);//convert the calendar time to localtime

		memset(buf,'\0',sizeof(buf));

		sprintf(buf,"%2d,%d-%d-%d %d:%d:%d\n",\
				line++,1900+p->tm_year,1+p->tm_mon,\
				p->tm_mday,p->tm_hour,p->tm_min,p->tm_sec);

		fputs(buf,fp);
		fflush(NULL);
		printf("%s\n",buf);
		sleep(1);
	}

	fclose(fp);
#if 0
	/*calendar time to localtime*/
	timep = time(NULL);
	p = localtime(&timep);
	printf("%d\n",1900+p->tm_year);
	
	/*calendar time to the string of localtime*/
	buf = ctime(&timep);	
	printf("%s\n",buf);

	/*struct tm  time to the string of localtime*/
	buf = asctime(p);	
	printf("%s\n",buf);

#endif
	return 0;	
}
