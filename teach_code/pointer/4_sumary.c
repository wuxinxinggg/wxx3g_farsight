#include <stdio.h>

int main(void)
{
	int array[3][4] = {{7, 10, -2, 3},
			   {14, 30, 6, -15},
			   {0, 5, 27, -7}};

	/**************************************
	   p[0] --> array[0]:{7, 10, -2, 3}
	   p[1] --> array[1]:{14, 30, 6, -15}
	   p[2] --> array[2]:{0, 5, 27, -7}
	***************************************/
	int (*p[3])[4] = {&array[0], &array[1], &array[2]};

	int sum = 0;
	int i, j;
	for(i=0; i<3; i++){
		for(j=0; j<4; j++)
			sum += (*p[i])[j];
	}

	printf("sum: %d\n", sum);

	return 0;
}
