#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE1 64
#define SIZE2 20

int main(void)
{
	/***************************
	   buf should be set to 0
	****************************/
	char buf[SIZE1] = {[0 ... SIZE1-1] = '\0'};
	fgets(buf, SIZE1, stdin);

	int array[SIZE2] = {[0 ... SIZE2-1] = 0};
	char tmp[SIZE2];
	int begin=0, end=0, i=0;

	while(begin < SIZE1){

		memset(tmp, 0, SIZE2);

		/************************************
		   locate the beginning of a digit
		*************************************/
		while(buf[begin]<'0' || buf[begin]>'9')
			begin++;

		end = begin + 1;

		/*********************************
		   locate the end of the digit
		**********************************/
		while(buf[end]>='0' && buf[end]<='9')
			end++;

		strncpy(tmp, buf+begin, end-begin);
		array[i++] = atoi(tmp);

		/*********************************
		   search the next digit, start
		   the next character at "end+1"
		**********************************/
		begin = end + 1;
	}

	printf("digit number: %d\n", --i);
	printf("they are: ");
	int j = 0;
	while(j < i)
		printf("%d\t", array[j++]);
	printf("\n");

	return 0;
}
