#include <stdio.h>

int main(void)
{
	int i;
	int s=0;
	int n;
	int ret;

	printf("please input the number to get the total from 1 to n:\n");
	ret=scanf("%d",&n);	
	while((ret!=1)||(getchar()!='\n'))
	{
		printf("Error:please input the number again:\n");
		while (getchar()!='\n') {
			ret=scanf("%d",&n);
		}
	}

	for (i = 0; i < n+1; i++) {
		s+=i;
	}
	
	printf("the total from 1 to %d is %d\n",n,s);
	return 0;
}
