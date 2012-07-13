#include <stdio.h>

int fibonacci(int num)
{
	if(num==1 || num==2)
		return 1;
	else
		return (fibonacci(num-1) + fibonacci(num-2));
}

int main(void)
{
	int num;
	printf("which Fibonacci num do you want? ");

	if((scanf("%d", &num)!=1) || num<=0){
		printf("we need a positive integer, Bye-bye!\n");
		return -1;
	}

	printf("the %dth Fibonacci number is: %d\n", \
				num, fibonacci(num));
	return 0;
}
