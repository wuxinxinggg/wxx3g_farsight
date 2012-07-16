#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int datatype;
typedef struct node
{
	datatype data;
	struct node *prior,*next;
}dlinknode,*dlink;

void init_dlink(dlink *p)
{

//create the double link and return the addr 

	*p=(dlink)malloc(sizeof(dlinknode));

	if(*p == NULL)
	{
		printf("Error:mall failed\n");
	}

//init the double link,let it direct to itself

	(*p)->prior = *p;
	(*p)->next = *p;

}

//#if 0 
dlink getlist(dlink H,int i)
  {
  	int j;
  	dlink p = H->next;

  	for (j = 0; j < i; j++)
  	{
  		p = p->next;
  	}	

  	return p;
  }
 // #endif

void dlink_insert(dlink H,int x,int i)
{

	dlink p,q;
	p = getlist(H,i);

	if (p==NULL)
	{
		printf("Error:p is NULL\n");
		exit(1);
	}
	else
	{
		q = (dlink)malloc(sizeof(dlinknode));
		q->data = x;
		//first stage
		q->prior = p->prior;
		//second stage
		p->prior->next = q;
		//third stage
		q->next = p;
		//forth stage
		p->prior = q;
	}

}

void show(dlink H)
    {

    	dlink p = H->next;
	while(p !=H)
	{
		printf("%d\t", p->data);
		p = p->next;
	}
	printf("\n");

    }

int main(void)
{
	int n,i,ret;
	dlink H;
	init_dlink(&H);

	while(1)
	{
		printf("please input a number:\n");
		ret = scanf("%d",&n);
		if(ret != 1)
		{
			break;
		}
		printf("please input a number of the insert position:\n");
		ret = scanf("%d",&i);
		if(ret != 1)
		{
			break;
		}

		dlink_insert(H,n,i);
		show(H);
	}

	return 0;
}