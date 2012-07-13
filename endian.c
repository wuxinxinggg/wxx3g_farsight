#include <stdio.h>

int main(void)
{
	int word = 0x12345678;	

	//printf("%x",*(char *(&word)));
	printf("%x\n",*((char *)(&word)));
	
	return 0;
}
