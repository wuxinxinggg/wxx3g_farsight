#include <stdio.h>

int main(void)
{
	/***************************
	   Fahrenheit and Celsius
	****************************/
	float fah, cel;

	printf("pls input the temperature"
		"you wanna calculate: ");
	scanf("%f", &fah);

	cel = (5*(fah-32))/9;
	printf("It equals %.2f\n", cel);
	return 0;
}
