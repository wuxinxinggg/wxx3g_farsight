#include <stdio.h>

int func1(int a,int b)
{
	return (a+b);
}

int func2(int a,int b)
{
	return (a-b);
}
int func3(int a,int b)
{
	return (a*b);
}
int main(void)
{
	int a,b,ret;
	printf("please input two number two caculate:\n");
	ret=scanf("%d%d",&a,&b);
	while((ret != 2)||(getchar() != '\n'))
	{
		printf("Error:please input two number two caculate again:\n");
		while(getchar() != 2)
			ret=scanf("%d%d",&a,&b);
	}



	printf("a+b=%d\na-b=%d\na*b=%d\n",func1(a,b),func2(a,b),func3(a,b));
	return 0;
}
