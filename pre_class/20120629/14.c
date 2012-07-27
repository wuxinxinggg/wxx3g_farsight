#include <stdio.h>
#include <math.h>

double transform(double *source,double *target,int n,double (*p)(double))
{
	int i;
	for (i = 0; i < n; i++) {
		target[i]=sin(source[i]);
		printf("%s\n"，target[i]);
	}
}

int main(void)
{
	double *source[100];
	double *target[100];
	transform(source,target,100,sin);
	return 0;
}
