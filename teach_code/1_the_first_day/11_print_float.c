#include <stdio.h>

int main(void)
{
	float f;
	printf("pls input a float digit:\n");

	if(scanf("%f", &f) != 1){
		printf("we need a float digit, Bye-bye!\n");
		return -1;
	}

	printf("you have input %.2f or %.2e\n", f, f);
	return 0;
}
