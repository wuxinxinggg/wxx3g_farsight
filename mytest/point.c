#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
#if 0
	int a[10],*b;
	int i;

	/*malloc for b*/
	if((b=(int *)malloc(10*sizeof(int))) == NULL)
	{
		perror("malloc");
		return -1;
	}
	memset(b,0,10);

	a[10] ='\0';
	for(i=0;i<10;i++)
		printf("%d\n",a[i]);
	//////////////////////////////////
	int s[5]={2,3,4,5,6};
	int i;
//	memset(s,'A',sizeof(s));
//	s[30]='\0';

	for (i = 0; i < 5; i++) {

	printf("i=%d;s[i]=%d\n",i,*(s+i));
	printf("++i=%d;s[++i]=%d\n",i,*(s+(++i)));
	printf("i++=%d;s[i++]=%d\n",i,s[i++]);

	}
#else
	printf("%f\n",(float)(25/15));
#endif
	return 0;
}
