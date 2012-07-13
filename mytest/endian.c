#include <stdio.h>

int main(void)
{
	typedef unsigned int word;
	typedef unsigned char byte;

	word val_32 = 0x12345678;
	byte val_8 = *((byte *)&val_32);

	printf("%x\n",val_8);
	return 0;
}
