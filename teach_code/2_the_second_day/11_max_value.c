#include <stdio.h>

int max(int x, int y, int z)
{
	int ret;
	ret = (x>y) ? x : y;
	ret = (ret>z) ? ret : z;

	return ret;
}

int main(void)
{
	int a, b, c;
	printf("pls input 3 integers:\n");

	if(scanf("%d%d%d", &a, &b, &c) != 3){
		printf("we need integers, Bye-bye!\n");
		return -1;
	}

	printf("the max value is: %d\n", max(a, b, c));
	return 0;
}
