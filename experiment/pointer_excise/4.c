#include <stdio.h>

int main(void)
{
	int array[3][4]={{7,10,-2,3},{14,30,6,-15},{0,5,27,-7}};
	int (*p)[4];
	int i,j;
	int tmp=0;

	p=array;
	for(i=0;i<3;i++)	
	{
		for(j=0;j<4;j++)
		{
			tmp+=p[i][j];		
		}
	}
	printf("%d\n",tmp);


	return 0;
}
