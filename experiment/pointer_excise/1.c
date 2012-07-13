#include <stdio.h>

int main(void)
{
	char a[]="Computer Science";
	char *pa;
	int i;
	pa=a;
	
	for(i=0;i<16;i++)
	{
		printf("%c ",pa[i]);
	} 
	printf("\n");
	return 0;
}
