#include <stdio.h>

int call_times()
{
	static int i=0;
	i++;
	return i;
}
int main(void)
{
	int j,times;

	for(j=0;j<=5;j++)
	{
		call_times();
	}

	times=call_times();	

	printf("the call times of the function of call_times is %d\n",times);
}
