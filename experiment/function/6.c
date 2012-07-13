#include <stdio.h>

int main(int argc, const char *argv[])
{
	int i=1;

	while(i<argc)
	{
		printf("%s\t",argv[i++]);
	}

	printf("\n");
	return 0;
}
