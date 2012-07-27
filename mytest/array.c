#include <stdio.h>

int main(void)
{
	int a[2][2];
	
	printf("&a =%p\n",&a);
	printf("&a[0] =%p\n",&a[0]);
	printf("&a[0][0] =%p\n",&a[0][0]);
	
	printf("/////////////////////////////////////////////////\n");
	
	int *ptr;
	int torf[2][2]={12,14,16};
	
	ptr=torf[0];
	printf("torf =%p\n",torf);
	printf("&torf =%p\n",&torf);
	printf("&torf[0] =%p\n",&torf[0]);
	printf("&torf[0][0] =%p\n",&torf[0][0]);

	return 0;
}
