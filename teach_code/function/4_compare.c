#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 32

/**********************************************
   compare two strings, if they are the same
   it return false, otherwise, it will return
   ture.
***********************************************/
bool compare(const char *s1, const char *s2)
{
	if(strlen(s1) != strlen(s2))
		return true;

	int i=0, len=strlen(s1);

	while(i++ < len){

		if(s1[i] != s2[i])
			return true;
		else
			continue;
	}

	return false;
}

int main(void)
{
	char buf1[SIZE],  buf2[SIZE];

	fprintf(stderr, "input 2 strings: \n");
	fgets(buf1, SIZE, stdin);
	fgets(buf2, SIZE, stdin);

	if(!compare(buf1, buf2))
		fprintf(stderr, "they are the same.\n");
	else
		fprintf(stderr, "they are different.\n");

	return 0;
}
