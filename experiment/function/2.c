#include <stdio.h>

int echo_char(char a,int amount,int line)
{
	int i,j;
	for (i = 0; i < line; i++) {
		for(j=0;j<amount;j++)
			printf("%c\t",a);
		printf("\n");
	}

	return 0;
}
int main(void)
{
	int ret;
	char a;
	int amount,line;
	printf("please input the character to show and how many lines characters/line to show:\n");
	ret=scanf("%c%d%d",&a,&amount,&line);	
	while((ret != 3) || (getchar() != '\n'))
	{
		printf("Error:please input again:\n");
		while(getchar() != '\n')
			ret=scanf("%c%d%d",&a,&amount,&line);	
	}

	echo_char(a,amount,line);

	return 0;
}
