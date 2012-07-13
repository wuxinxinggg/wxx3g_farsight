#include <stdio.h>

int callme(void)
{
	static int call_times = 0;
	return ++call_times;
}

int main(void)
{
	int i = 0, calling = 0;

	while(i < 5){
		calling = callme();
		i++;
	}

	printf("the function have been called %d times\n", \
			calling);

	return 0;
}
