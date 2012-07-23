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

bool insert_slink(slink H,int n)
{
	//slink p = H;
	slink q = (slink)malloc(sizeof(slinknode));
	if (NULL == q)
	{
		printf("Error:malloc failed\n");
		return false;
	}
	q->data = n;
	q->next = H->next;
	H = q;

	return true;
}

int locate_node(slink H,int n)
{
	int i = 0;
	slink p = H->next;
	while(p)
	{
		i++;
		if (p->data == n)
		{
			printf("locate_node i = %d\n", i);
			return i;
		}

		p = p->next;
	}

	return i;
}

slink getnode(slink H,int i)
{
	int j = 0;
	slink p = H->next;

	while(p)
	{
		j++;
//		printf("j = %d\n", j);
		if (j == i)
		{
			printf("if----j = %d\n", j);
			return p;
		}

		p = p->next;
	}

	return p;

}

bool delete_slink(slink H,int n)
{
	int i = locate_node(H,n);
//	printf("delete_slink i == %d\n",i);
	slink p = getnode(H,i);
	slink q = getnode(H,i-1);	
	if (p && p->next)
	{
		printf("I am Here\n");
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
int main(void)
{
	int ret,n;
	slink H;
	init_link(&H);

	while(1)
	{
		printf("please input a number:\n");
		ret = scanf("%d",&n);
		if(ret == -1)
			break;
		if (n>0)
		{
			if (! insert_slink(H,n))
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
		}
	}

	
	return 0;
}