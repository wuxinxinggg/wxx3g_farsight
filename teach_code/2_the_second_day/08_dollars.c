#include <stdio.h>

int main(void)
{
	int num, i=0;
	printf("Height: ");

	if(!scanf("%d", &num) || num <1){
		printf("we need a positive integer. Bye-Bye!\n");
		return 0;
	}

	while(i < num){
		int j;
		for(j=0; j<i+1; j++)
			printf("$");

		printf("\n");
		i++;
	}

	return 0;
}
