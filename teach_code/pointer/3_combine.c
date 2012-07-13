#include <stdio.h>
#include <string.h>

int main(void)
{
	char str1[10] = {"hello "};
	char str2[10] = {"world"};

	char *p = str1 + strlen(str1);
	char *q = str2;

	int size = sizeof str1;

	int available = size - strlen(str1) - 1;
	while(available-- > 0)
		*p++ = *q++;

	printf("%s\n", str1);

	return 0;
}
