#include <stdio.h>
#include <string.h>

int main(void)
{
	char *str[5] = { "this",
			 "is",
			 "a",
			 "testing",
			 "string"};

	int i = 0, j = 0;
	char *p;

	while(i < 5){
		j = 0;
		while(j < 4){
			if(strcmp(str[j], str[j+1]) < 0){
				j++;
				continue;
			}
			else{
				p = str[j];
				str[j] = str[j+1];
				str[j+1] = p;
			}
			j++;
		}
		i++;
	}

	for(i=0; i<5; i++)
		printf("%s\n", str[i]);
	
	return 0;
}
