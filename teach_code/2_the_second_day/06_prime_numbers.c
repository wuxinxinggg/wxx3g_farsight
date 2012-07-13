#include <stdio.h>
#include <stdbool.h>

bool prime(int num)
{
	int i;
	for(i=2; i*i<=num; i++){
		if(num%i == 0)
			return false;
		else
			continue;
	}
	return true;
}

int main(void)
{
	int boundary;
	printf("Input the boudary: ");

	if(scanf("%d", &boundary) != 1){
		printf("we need an integer. Bye-bye!\n");
		return -1;
	}

	int num, total=0;
	for(num=2; num < boundary+1; num++){

		if(prime(num)){
			printf("%d\t", num);
			total++;

			/***************************
			   print 5 primes per line
			****************************/
			if(total%5 == 0)
				printf("\n");
		}
	}

	printf("\n=================="
		"\ntotal: %d primes.\n"
		"==================\n", total);

	return 0;
}
