#include <stdio.h>

float cube(float f)
{
	return f*f*f;
}

int main(void)
{
	float f;
	printf("pls input a float num: ");
	
	if(scanf("%f", &f) != 1){
		printf("we need a float num, Bye-bye!\n");
		return -1;
	}

	printf("cube of %f is %f\n", f, cube(f));
	return 0;
}
