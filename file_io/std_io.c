#include <stdio.h>

int main(void)
{
	//全缓冲：
	int i;
	for (i = 0; i < 2; i++) 
	{
		printf("full --> hello world");
	}

	//无缓冲：
	fprintf(stderr,"fprintf hello world");

	//行缓冲
	printf("line --> hello world\n");	

	//强制刷新数据流
	printf("nothing --> hello world");	
	fflush(NULL);//强制刷新缓冲区，所有将输出

	while(1);//让程序进入死循环，否则程序将退出，程序退出则自动清空缓冲区

	return 0;
}
