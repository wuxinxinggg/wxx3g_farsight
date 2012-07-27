#include <stdio.h>

#define MIN(x,y) ((x<y)?(x):(y))

int main(void)
{
	printf("the min of the two num is %d\n",MIN(5,9));
	return 0;
}
