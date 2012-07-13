#include <stdio.h>
#include <string.h>

//删除字符串中的空格
void fun(char *p1,char *p2)
{
//以下只能删除中间间隔一个空格的情况
/*
	int i,temp;
	for(i=0;i<strlen(p);i++)
	{
		//如果是空格就跟下一个字符交换位置，直到把所有空格都排到后面
		if(p[i]==' ')
		{
			temp=p[i];
			p[i]=p[i+1];
			p[i+1]=temp;
		}
	}
*/

	int i,j=0;
	for(i=0;i<strlen(p1);i++)
	{
		//把除了空格以外的字符存入另一个数组
		if(p1[i]!=' ')
		{
			p2[j]=p1[i];
			//存一个加一个
			j++;
		}
	}
	p2[j]='\0';
}
int main(void)
{
	int i=0;
	char str1[40],str2[40];
	
	printf("please input str:");
	gets(str1);
/*
	fun(str);
	//遇到空格就不再输出，只输出字符串
	while(str[i]!=' ')
	{
		printf("%c",str[i]);
		i++;
	}
*/
	fun(str1,str2);
	printf("%s\n",str2);
	
	return 0;
}
