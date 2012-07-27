#include <stdio.h>

int main(int argc,char* argv[])
{
	int ret,i,j;
	char caps;
	
	printf("please input the caps:");
	
	ret=scanf("%c",&caps);
	while((ret !=1)||(getchar() != '\n'))
	{
		printf("Error: please input again:\n");
		while(getchar() != '\n')
		{
			ret=scanf("%c",&caps);
		}
	}
	for(i=1;i<=caps-'A'+1;i++)
	{
	
		for(j=1;j<=caps-'A'-i;j++)
		{
			printf(" ");
		}

		for(j=1;j<=i;j++)
		{
			printf("%c",j+'A'-1);
		}

		for(j=i-1;j>0;j--)
		{
			printf("%c",j+'A'-1);
		}
		printf("\n");
	}

	return 0;
}
