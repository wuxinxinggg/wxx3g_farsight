#include <stdio.h>

int main(void)
{
	int i,j;
	
	for(i=1;i<=9;i++)
	{
		for(j=1;j<=9-i;j++)
		{
			printf(" ");
		}

		for(j=1;j<=i;j++)
		{
			printf("%d",j);
		}
		
		for(j=i-1;j>0;j--)
		{
			printf("%d",j);
		}
	printf("\n");
	}
}
