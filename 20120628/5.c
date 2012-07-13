#include <stdio.h>

/*函数Test调用完函数get_memory后返回p[]的地址给str后系统自动释放函数get_memory的内存空间，导致str出现指针悬停现象，打印出来的值是一个不确定的值*/
char *get_memory(void){
	char p[]="hello world";
	return p;
}

void Test(void){
	char *str=NULL;
	str = get_memory();
	printf("%s\n",str);
}

int main(void)
{
	Test();
}

