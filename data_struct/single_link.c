#include <stdio.h>
#include <stdlib.h>

typedef int datatype;

typedef struct node
{
	datatype data;
	struct node *next;
}slinknode,*slink;

void init_link(slink *p)
{

	*p=(slink)malloc(sizeof(slinknode));

	if(*p == NULL )
	{
		printf("Error:malloc failed\n");
	}
	
}

void show(slink H)
{
	slink p=H->next;
	while(p && p->next != NULL )
	{
		printf("p->data=%d\t",p->data);
		p=p->next;
	}
	printf("\n");
}
int main(void)
{
	int ret,n;
	slink p,r,H;
	init_link(&H);
	r = H;
	while(1)
	{
		if (ret == -1)
			break;

		printf("please input a number:\n");
		ret = scanf("%d",&n);
		p=(slink)malloc(sizeof(slinknode));
		p->data = n;
		r->next = p;
		r = p;
		r->next = NULL;
		show(H);
	}

	
	return 0;
}