#include <stdio.h>
#include <stdlib.h>


typedef int datatype;
typedef struct node
{
	datatype data;
	struct node *prior,*next;
}dlinknode,*dlink;

void init_dlink(dlink *p)
{
	*p = (dlink)malloc(sizeof(dlinknode));
	if (*p == NULL)
	{
		printf("Error:malloc failed\n");
	}

	(*p)->prior = *p;
	(*p)->next = *p;
}

void dlink_add(dlink H,datatype n)
{
	dlink p = H->next;
	dlink q = (dlink)malloc(sizeof(dlinknode));	
	if(q == NULL)
		printf("Error:malloc failed\n");
	q->data = n;
	q->prior = p->prior;
	p->prior->next = q;
	q->next = p;
	p->prior = q;

}
void show(dlink H)
{
	dlink p=H->next;
	while(p !=H)
	{
		printf("%d\t",p->data);
		p=p->next;
	}
	printf("\n");
}
int main(void)
{
	dlink H;
	int n,ret;
	init_dlink(&H);

	while(1)
	{
		printf("please input a data :\n");
		ret = scanf("%d",&n);

		if (ret !=1 )
		{
			break;
		}

		dlink_add(H,n);
		show(H);
	}
	return 0;
}