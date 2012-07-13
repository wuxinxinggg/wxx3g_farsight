#include <stdio.h>
#include <limits.h>

#define SIZE 7

int max(int x, int y)
{
	return ((x>y) ? x : y);
}

int max_sum(int a[], int size)
{
	int start[size];
	int all[size];
	int i;

	start[size-1] = a[size-1];
	all[size-1] = a[size-1];

	for(i=size-2; i>=0; i--){
		start[i] = max(a[i], a[i]+start[i+1]);
		all[i] = max(start[i], all[i+1]);
	}
	return all[0];
}

int main(void)
{
	int a[SIZE] = {-2, 5, 3, -6, 4, -8, 6};
	printf("answer: %d\n", max_sum(a, SIZE));
	return 0;
}
