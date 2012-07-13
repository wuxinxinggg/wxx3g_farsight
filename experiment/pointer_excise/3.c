#include <stdio.h>

int main(void)
{
	char str1[20]={"Hello "};
	char str2[20]={"World "};
	char *p;
	int j,i;

	p=str1;	

	for(j=0;j<6;j++)
	{
		p[6+j]=str2[j];
		
	}
	
	for(i=0;i<20;i++)
	{
		
		printf("%c",p[i]);
	}
	
	printf("\n");
	return 0;
}
