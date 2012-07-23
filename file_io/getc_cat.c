#include<stdio.h>

int main(int argc,char *argv[])
{
	FILE *fp;
	char ch;
	fp = fopen(argv[1],"r+");
	ch = fgetc(fp);//必须先取值再用feof(fp)来判断，否则会多一位文件结尾描述符（乱码）
	//while(ch != EOF)
	while(!feof(fp))
	{
		printf("%c",ch);
		ch = getc(fp);
	}
	
	fclose(fp);
	return 0;
	
}
