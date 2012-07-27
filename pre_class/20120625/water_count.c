#include <stdio.h>
int main(void){
	float quart;
	while (1)
	{
	
		printf("please input the quart number that you want to caculate and enter Ctr+C to exit\n");
		scanf("%f",&quart);
		quart=quart*950/3.0e-23;
		printf("the total molecular of water is %f\n",quart);
	}
	return 0;
}
