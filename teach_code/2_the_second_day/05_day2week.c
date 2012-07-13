#include <stdio.h>

#define DAYS_PER_WEEK 7

int main(void)
{
	int days;
	printf("how many days do you wanna calculate? ");
	if(scanf("%d", &days) != 1){
		printf("we need an integer number, Bye-bye!");
		return -1;
	}

	printf("%d days are %d weeks, %d days\n",
		days, days/DAYS_PER_WEEK, days%DAYS_PER_WEEK);
	return 0;
}
