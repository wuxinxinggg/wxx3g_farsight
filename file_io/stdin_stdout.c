#include <stdio.h>

int main(int argc,char *argv[])
{
	while(1)
	{
		putc(getc(stdin),stdout);
	}
	return 0;
}
