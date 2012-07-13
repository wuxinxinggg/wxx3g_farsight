#include <stdio.h>

int main(void)
{
	int begin;
	printf("pls input an integer: ");

	if(scanf("%d", &begin) != 1){
		printf("we need an integer, bye-bye!\n");
		return -1;
	}

    int i;
	for(i=0; i<=10; i++){
		printf("%d\n", begin+i);
	}

	return 0;
}
