#include <stdio.h>

int sum(int, int);
int diff(int, int);
int mutil(int, int);

int main(void)
{
	int i = 1, j = 2;

	printf("sum: %d\n", sum(i, j));
	printf("diff: %d\n", diff(i, j));
	printf("mutil: %d\n", mutil(i, j));

	return 0;
}

int sum(int x, int y)
{
	return x+y;
}

int diff(int x, int y)
{
	return x-y;
}

int mutil(int x, int y)
{
	return x*y;
}
