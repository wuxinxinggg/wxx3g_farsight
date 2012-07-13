#include <stdio.h>

float legendre(int n, int x)
{
	if(n == 0)
		return 1;
	if(n == 1)
		return x;

	int m = (2*n-1)*x*legendre(n-1, x) - (n-1)*legendre(n-2, x);

	return m/n;
}

int main(void)
{
	printf("input n, x:\n");
	int n, x;

	scanf("%d%d", &n, &x);

	printf("%f\n", legendre(n, x));

	return 0;
}
