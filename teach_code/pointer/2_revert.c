#include <stdio.h>

#define LENGTH 8

void show_data(int s[], int size)
{
	int i;
	for(i=size; i>0; --i)
		printf("%d\t", s[size-i]);
	printf("\n");
}

void revert(int s[], int size)
{
	int i, tmp;
	for(i=0; i<size/2; i++){
		tmp = s[i];
		s[i] = s[size-i-1];
		s[size-i-1] = tmp;
	}
}

int main(void)
{
	int s[LENGTH] = {1, 2, 3, 4, 5, 6, 7, 8};

	show_data(s, LENGTH);

	revert(s, LENGTH);

	show_data(s, LENGTH);

	return 0;
}
