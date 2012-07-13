#include <stdio.h>

int main(void)
{
	int i;

	double str[]={1,2,3,4,5};
	for(i=0;i<5;i++)	
	{
		printf("str[%d] = %lf\n",i,str[i]);
	}
	return 0;
}
