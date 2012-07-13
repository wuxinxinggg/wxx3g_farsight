#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define SIZE 32
bool compare(const char *s1,const char *s2)
{
	if(strlen(s1) != strlen(s2))
		return true;
	int i=0, len=strlen(s1);

	while(i<len)
	{
	
		if(s1[i] != s2[i])
		{
			return true;
		}
		else
			continue;
		i++;
	}

	return false;
}
int main(void)
{
	char buf1[SIZE],buf2[SIZE];
	int i;

	fprintf(stderr,"please input two strings:\n");	
	fgets(buf1,SIZE,stdin);
	fgets(buf2,SIZE,stdin);
	
	//for(i=0;i<SIZE;i++)
	//	printf("%c\n",buf1[i]);


	if(!compare(buf1,buf2))
		fprintf(stdout,"they are the same\n");
	else
		fprintf(stdout, "they are different\n");

	return 0;
}
