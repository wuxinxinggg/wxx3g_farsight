#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

	(*p)->next = NULL;
	
}
//rear insert
bool rear_insert_slink(slink H,slink *r,int n)
{
	slink p;
		
	p = (slink)malloc(sizeof(slinknode));
	if (NULL == p)
	{
		printf("Error:malloc failed\n");
		return false;
	}
	p->data = n;
	(*r)->next = p;
	*r = p;
	(*r)->next = NULL;

	return true;

}

//head insert
bool head_insert_slink(slink H,int n)
{
	slink q = (slink)malloc(sizeof(slinknode));
	if (NULL == q)
	{
		printf("Error:malloc failed\n");
		return false;
	}
	q->data = n;
	q->next = H->next;
	H->next = q;

	return true;
}

//an zhi cha zhao
slink locate_node(slink H,int n)
{
	slink p = H->next;
	while(p && p->next && p->next->data != n)
	{
		p = p->next;
	}

	return p;
}

//an xu hao cha zhao
slink getnode(slink H,int i)
{
	int j = 0;
	slink p = H->next;

	while(p->next !=NULL  && j <i)
	{
		p = p->next;
		j++;
	}
	if (j == i)
	{
		return p;
	}

	return NULL;

}

bool delete_slink(slink H,int n)
{
	slink p;
	slink q;
	q = locate_node(H,n);
	p = q->next;	

	if (q&& q->next)
	{
		q->next = p->next;
		free(p);
	}

	return true;
}

void show(slink H)
{
	slink p=H->next;

	while(p)
	{
		printf("%d\t",p->data);
		p=p->next;
	}

	printf("\n");
}

void head_revert_slink(slink H)
{
	slink q;
	slink p;
	p = H->next;	
	H->next = NULL;

	while(p)
	{
		q = p->next;
		p->next = H->next;
		H->next = p;
		p = q;
	}
}

void rear_revert_slink(slink H)
{
	slink r,q,p;
	p = H->next;
	r = H;
	H->next = NULL;
	while(p)
	{
		q = p->next;
		r->next = p;
		r = p;
		r->next = NULL;
		p = q;
	}
}
int main(void)
{
	int ret,n;
	slink H;
	slink r;
	init_link(&H);
	r = H;

	while(1)
	{
		printf("please input a number:\n");
		ret = scanf("%d",&n);
		if(ret == -1)
			break;
		if (n>0)
		{
			if (! rear_insert_slink(H,&r,n))
			{
				printf("Error:insert failed\n");
				continue;
			}
			show(H);
		}
		else
		{
			if (! delete_slink(H,-n))
			{
				printf("Error:delete failed\n");
				continue;
			}
			show(H);
			rear_revert_slink(H);
			show(H);
			head_revert_slink(H);
			show(H);
		}
	}

	
	return 0;
}
