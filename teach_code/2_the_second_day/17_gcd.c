#include <stdio.h>

int gcd(int x, int y)
{
	int max, min, tmp;
	min = x<y ? x : y;
	max = x>y ? x : y;

	while(min != 0){
		tmp = min;
		min = max%min;
		max = tmp;
	}

	return max;
}

int main(void)
{
	int a, b;
	printf("pls input two integers:\n");
	
	if(scanf("%d%d", &a, &b) != 2){
		printf("we need two integers, Bye-bye!\n");
		return -1;
	}

	printf("the greatest common divisor of"
		"them is: %d\n", gcd(a, b));

	return 0;
}
