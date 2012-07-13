#include <stdio.h>
#include <string.h>


#define SIZE 128

int main(void)
{
	char str[SIZE];
	char str1[SIZE];
	int i,j;

	printf("please input a string to operate:\n");
	fgets(str,SIZE,stdin);

	for(i=0;i<strlen(str);i++)
	{
		if(str[i] >= '0' && str[i] <= '9')
		{
			str1[j] = str[i];
			j++;
		}

	}

	for (j = 0; j < strlen(str1); j++) {
		printf("%s\n",str1);
	}

	return 0;
}
