#include <stdio.h>

void swap(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

void taxis(int a[], int size)
{
	int i=0, j;

	while(i < size){

		j = 0;
		while(j++ < size-i){

			if(a[j-1] < a[j])
				continue;
			else
				swap(&a[j-1], &a[j]);
		}
		i++;
	}
		
}

void show(int a[], int size)
{
	int i = 0;
	while(i < size)
		printf("%d\t", a[i++]);
	printf("\n");
}

int main(void)
{
	int array[] = {1, 3, 5, 7, 6, 4, 2};

	show(array, 7);
	taxis(array, 7);
	show(array, 7);

	return 0;
}
