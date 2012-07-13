#include <stdio.h>

#define __CHAR_SIGNED__ // enable the "signed char" version
#include <limits.h> // for CHAR_MIN and CHAR_MAX

int main(void)
{
	short ch;

	printf("pls input an ASCII value(0-127): ");
	int ret1, ret2;

	/*************************************
	   deal with all invalid conditions:
	   1: input doesn't match the format.
	**************************************/
	while((ret1=scanf("%hd", &ch)) != 1 ||
		((ret2=getchar()) != '\n') ||
	/**************************
	   2: input out of range.
	***************************/
		(ch>CHAR_MAX || ch<0)){

		/****************************
		   discards invalid inputs
		*****************************/
		if(ret1!=1 || ret2!='\n')
			while(getchar() != '\n');

		printf("input invalid!\n");
		printf("pls input an ASCII value(0-127): ");
	}

	printf("the character of %d is '%c'\n", ch, (char)ch);

	return 0;
}
