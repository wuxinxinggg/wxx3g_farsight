#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 64

/*传参是单个字符串用数组实现*/
int is_within(char a,char p[])	
{
	int i;

	for(i=0;i<strlen(p);i++)
	{
		if(a==p[i])
		{
			printf("a is in the string\n");
			return 1;
		}
		else
			continue;
	}

	printf("a is not in the string\n");

	return 0;
}
int main(void)
{
	char str[SIZE];
	char a;

	fprintf(stderr,"please input  a string to check:\n");

	/*fgets第一个参数是接受的指针，第二个参数是接受的字符串的大小，第三个是字符串的输入流*/
	fgets(str,SIZE,stdin);

	fprintf(stderr,"please input a character:\n");
/*当scanf和fgets同时出现时，必须先接收字符串再接收scanf输入的字符*/	
	scanf("%c",&a);


	printf("the return of in_within is %d\n",is_within(a,str));

	return 0;
}
