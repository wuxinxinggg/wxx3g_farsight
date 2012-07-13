#include <stdio.h>

int main(void)
{
	int s[8]={1,2,3,4,5,6,7,8};
	int *p;
	int i,j;
	int tmp[8];

	p=s;
	for(i=0;i<8;i++)
	{
		tmp[i]=p[7-i];
	}
	
	p=tmp;
	
	for(j=0;j<8;j++)
	{
		printf("%d\t",p[j]);
	}

	printf("\n");

	return 0;
}
