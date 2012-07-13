#include <stdio.h>
#include <stdlib.h> // enable the function rand()

void func1(int row, int col, double (*target)[col], double source[][col])
{
	for(int i=row; i>0; i--){
		for(int j=col; j>0; j--){
			target[i-1][j-1] = source[i-1][j-1];
		}
	}
}

void func2(int row, int col, double target[][col], double (*source)[col])
{
	printf("source:\n");
	for(int i=row; i>0; i--){
		for(int j=col; j>0; j--){
			printf("%f\t", source[i-1][j-1]);
		}
		printf("\n");
	}

	printf("target:\n");
	for(int i=row; i>0; i--){
		for(int j=col; j>0; j--)
			printf("%f\t", target[i-1][j-1]);
		printf("\n");
	}
}

int main(void)
{
	int i, j;
	int row, col;
	
	printf("pls input the rows and cols of the source array:\n");
	if(scanf("%d%d", &row, &col) != 2){
		printf("rows and cols must be integers, Bye-bye!\n");
		return -1;
	}

	double source[row][col];
	//fill the source array with some random digits
	for(i=0; i<row; i++){
		for(j=0; j<col; j++){
			//rand() respond for generating a random integer
			source[i][j] = (double)rand() / (double)rand();
		}
	}

	double target[row][col];
	//assign the source array to the target
	func1(row, col, target, source);
	//display two arrays
	func2(row, col, target, source);

	return 0;
}
