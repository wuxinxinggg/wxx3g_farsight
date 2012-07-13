#include <stdio.h>

#define MIN 60

int main(void)
{
	int minutes;
	printf("how many minutes do you wanna calculate? ");

	if(scanf("%d", &minutes) != 1){
		printf("we need an integer. Bye-bye!\n");
		return -1;
	}

	printf("%d hours and %d minutes\n", minutes/MIN, minutes%MIN);
	return 0;
}
