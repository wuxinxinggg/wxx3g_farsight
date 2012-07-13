#include <stdio.h>

int main(void)
{
	int s[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

	int m;
	scanf("%d", &m);

	int k[9], i=0;

	while(i < m){
		k[i] = s[9-m+i];
		i++;
	}

	while(i < 9){
		k[i] = s[i-m];
		i++;
	}

	for(i=0; i<9; i++)
		printf("%d\t", k[i]);
	printf("\n");

	return 0;
}
