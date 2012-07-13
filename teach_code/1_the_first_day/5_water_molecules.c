#include <stdio.h>

#define WATER_MOLCULER 3.0e-23

int main(void)
{
	double water_molculers;
	float quota;
	printf("how many quarts of the water? ");

	if(scanf("%f", &quota)!=1 || quota<0){
		printf("we need a positive digit. Bye-bye!\n");
		return -1;
	}

	water_molculers = (quota*950) / WATER_MOLCULER;
	printf("awesome! you've got %le water molecules!\n", \
				water_molculers);

	return 0;
}
