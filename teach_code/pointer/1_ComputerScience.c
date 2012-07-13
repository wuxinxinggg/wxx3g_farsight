#include <stdio.h>
#include <string.h>

int main(void)
{
	/********************************************
	   when a char array has been initialized,
	   the number of elements could be omitted.
	*********************************************/
	char string[] = "Computer Science";
	char *p = string;

	int i, len = strlen(string);

	printf("%s\n", string);	

	for(i=0; i<len; i+=2)
		printf("%c", *(p+i));
	printf("\n");

	return 0;
}
