#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 64

bool is_within(char ch, const char *s, int size)
{
	int i = 0;

	while(i < size){
		if(ch == s[i++])
			return true;
		else
			continue;
	}

	return false;
}

int main(void)
{
	char ch;
	char str[SIZE];

	printf("input a string: \n");
	fgets(str, SIZE, stdin);

	printf("input a character: \n");
	while(1){
		scanf("%c", &ch);

		if(is_within(ch, str, strlen(str)))
			printf("yes\n");
		else
			printf("no\n");
		scanf("\n");
	}

	return 0;
}
