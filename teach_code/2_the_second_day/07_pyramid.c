#include <stdio.h>
#include <ctype.h>

int main(void)
{
	char ch;
	printf("Pls input a latter: ");
	scanf("%c", &ch);
	if(!isupper(ch)){
		printf("we need a capital latter.\n");
		return -1;
	}

	char space, line;
	space = ch-'A';
	line = space+1;
	
	/********************************
	   print space+1 lines totally
	*********************************/
	while(space+1){

		/****************
		   print spaces
		*****************/
		char spa = space;
		while(spa--)
			printf(" ");

		/******************************
		   print letters ascendingly
		*******************************/
		int s = line-space-1;
		spa = 'A';
		while(s){
			printf("%c", spa++);
			s--;
		}

		/******************************
		   print letters descendingly
		*******************************/
		while(spa >= 'A')
			printf("%c", spa--);

		printf("\n");
		space--;
	}

	return 0;
}
