#include <stdio.h>

int main(void)
{
	int word=0x12345678;
	int endian;

	printf("%x\n",*(char *)(&word));
	printf("%d\n",*(char *)(&word));

	//120 is the Dec of the Hex num of 78
	if(*(char *)(&word)==120)
	{
		printf("big endian\n");
		return 0;
	}
	else 
	{
		printf("little endian\n");
		return 1;
	}
	return 0;
}
