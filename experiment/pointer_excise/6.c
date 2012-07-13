#include <stdio.h>
#include <string.h>

int main(void)
{
	char *str[5]={"I","linux","am","programer","the"};	
	int i,j,k;
	char *tmp;	
	
	for(i=0;i<5;i++)
	{
		for(j=0;j<4;j++)	
		{
			if((strlen(str[j]))>(strlen(str[j+1])))
			{
				tmp=str[j+1];
				str[j+1]=str[j];
				str[j]=tmp;
			}
		}
	}
	
	for(k=0;k<5;k++)
	{
		printf("%s\n",str[k]);
	}
	return 0;
}
