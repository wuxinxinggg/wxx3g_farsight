#include <stdio.h>
#include <math.h>

int prime(int a)
{
	int i;
	int ret;
	int k;
	int flag=1,j;

	printf("please input a number:\n");
	ret = scanf("%d",&a);
	while((ret !=1)||(getchar() !='\n'))
	{
		printf("please input a number again:\n");
		while(getchar() != '\n')
		{
			ret=scanf("%d",&a);
		}
	}
	
	for(j=1;j<=a;j++)
	{
		k=sqrt(j);
		for(i=2;i<=k;i++)
		{
			if(j%i == 0)
			{
				flag=0;
			}
		}
		if(flag)
		{
			printf("all the primes less than %d\n",j);
			
		}
		flag=1;
	}
}
int main(void)
{
	int a;

	prime(a);
	
	return 0;

}
