#include <stdio.h>
//实现文件的拷贝功能
int main(int argc,char *argv[])
{
	FILE *fp;
	FILE *fpp;
	int ch;

	fp = fopen(argv[1],"r+");
	fpp = fopen(argv[2],"w+");
	
	if(argc != 3)
		printf("usage error\n");

	ch = fgetc(fp);  //必须先取值再用feof判断，否则拷贝的文件最后多出一个结尾符
	while(! feof(fp))
	{
		fputc(ch,fpp);
		ch = fgetc(fp);
	}

	return 0;
}
