#include <stdio.h>

int main(int argc, char *argv[])
{
	int i=0;
	while(i++ < argc-1)
		printf("%s\t", argv[i]);
	printf("\n");

	return 0;
}
