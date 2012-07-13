#include <stdio.h>

typedef union{
	long i;
	int k[5];
	char c;
}DATE;
struct data {
	int cat;
	DATE cow;
	double dog;
}too;
int main(void)
{
	printf("size of union=%d\n",sizeof(DATE));
	printf("size of data=%d\n",sizeof(struct data));
	printf("%d\n",sizeof(struct data)+sizeof(DATE));
	return 0;
}
