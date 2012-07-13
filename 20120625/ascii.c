#include <stdio.h>
int main(void)
{
	int num;
	for(num=0;num<=255;num++)
	{
		printf("please input the ascii number and enter Ctr+C to exit\n");
		scanf("%d",&num);
		printf("the origin character of %d is %c\n",num,num);
	}
	
	return 0;
}
