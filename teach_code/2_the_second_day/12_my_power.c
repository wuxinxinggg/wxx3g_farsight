#include <stdio.h>

float my_power(float num, int pow)
{
	int i;
	float tmp = num;
	if(pow > 0){
		for(i=0; i<pow-1; i++){
			num *= tmp;
		}
		return num;
	}
	else{
		pow *= -1;
		for(i=0; i<pow-1; i++){
			num *= tmp;
		}
		return 1/num;
	}
}

int main(void)
{
	float num;
	int pow;
	printf("Pls input the base and"
		"power number(e.g: 3.14^2):");

	if(scanf("%f^%d", &num, &pow) != 2){
		printf("we nedd a float digit"
			"and an integer. Bye-bye!\n");
		return -1;
	}

	/**************************************
	   0^0 is NOT allowed in mathematical
	***************************************/
	if((num==0) && (pow == 0))
		printf("invalid operands.\n");

	/*********************
	  0^x(x!=0) equals 0
	**********************/
	else if(num == 0)
		printf("answer: 0\n");

	/*********************
	  x^0(x!=0) equals 1
	**********************/
	else if(pow == 0)
		printf("answer: 1\n");

	else
		printf("answer: %.6f\n",
			my_power(num, pow));

	return 0;
}
