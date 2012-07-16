#include <stdio.h>

typedef int datatype;

typedef struct node
{
	datatype data;
	struct node *next;
}linknode,*link;

void init_link(link *p)
{

	*p=(link)malloc(linknode);

	if(*p == NULL )
	{
		printf("Error:malloc failed\n");
	}
	
}
int main(void)
{
	
	return 0;
}