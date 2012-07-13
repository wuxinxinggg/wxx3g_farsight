#include <stdio.h>

#define __CHAR_UNSIGNED__ // enable the "unsigned char" vertion
#include <limits.h> // for CAHR_MIN and CHAR_MAX

#define SEC_YEAR 3.1536e7

int main(void)
{
	short age;
	float seconds;
	printf("how old are you: ");

	if(scanf("%hd", &age) != 1){
		printf("your age should be an positive interge. Bye-bye!\n");
		return -1;
	}

	if(age > CHAR_MAX-155 || age < CHAR_MIN){
		printf("your age should be in the range from %hhu to %hhu.\n", \
					CHAR_MIN, CHAR_MAX-155);		
		return -2;
	}

	seconds = age * SEC_YEAR;
	printf("you have pass %.0lf seconds in your life!\n", seconds);

	return 0;
}
