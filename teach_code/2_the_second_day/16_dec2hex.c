#include <stdio.h>
#include <stdbool.h>
#define LIM 32

int main(void)
{
	int decimal;
	bool negative = false;
	printf("pls input the integer to convert:\n");

	if(!scanf("%d", &decimal)){
		printf("we need an integer, Bye-bye!\n");
		return -1;
	}
	if(decimal < 0){
		negative = true; 
		decimal *= -1;
	}

	int i, num[LIM];
	for(i=0; i<LIM && decimal!=0; i++){
		num[i] = decimal%16;
		decimal /= 16;
	}

	int j;
	if(negative)
		printf("answer: -0x");
	else
		printf("answer: 0x");

	for(j=i; j>0; j--){
		switch(num[j-1]){
			case 10:
				printf("a");
				break;
			case 11:
				printf("b");
				break;
			case 12:
				printf("c");
				break;
			case 13:
				printf("d");
				break;
			case 14:
				printf("e");
				break;
			case 15:
				printf("f");
				break;
			default:
				printf("%d", num[j-1]);
				break;
		} //switch
	} //for
	printf("\n");

	return 0;
}
