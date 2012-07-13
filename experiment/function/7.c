#include <stdio.h>

float legende(int n,int x)
{
	int m;

	if (n==0) {
		return 1;
	}

	if (n==1) {
		return x;	
	}

	m = (2*n-1)*x*legende(n-1,x)-(n-1)*legende(n-2,x);
		
	return m/n;
}
int main(void)
{
	int x,ret,n;

	printf("please input two number:\n");

	ret=scanf("%d%d",&n,&x);

	while((ret != 2) || (getchar() != '\n'))

	{
		printf("Error:please input two number:\n");

		while(getchar() != '\n')
			ret=scanf("%d%d",&n,&x);

	}	

	printf("the %d legende of %d is %f\n",n,x,legende(n,x));

	return 0;
}
