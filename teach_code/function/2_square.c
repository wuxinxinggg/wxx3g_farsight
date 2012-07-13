#include <stdio.h>

void draw_square(char x, int column, int row)
{
	int i=0, j;

	while(i++ < row){

		j = 0;
		while(j++ < column)
			printf("%c", x);

		printf("\n");
	}
}

int main(void)
{
	int column, row;

	printf("column and row: ");
	scanf("%d%d", &column, &row);

	draw_square('*', column, row);

	return 0;
}
