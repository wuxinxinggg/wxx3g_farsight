#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int datatype;
typedef struct node
{
	datatype data;
	struct node *next;
}linknode,*plinknode;

bool init_plinknode(plinknode *h)
{
	*h = (plinknode)malloc(sizeof(linknode));
	if ((*h) == NULL)
	{
		printf("Error:malloc failed\n");
		exit(1);
	}

	(*h)->next = NULL;
}

void josephu(plinknode h,int n,int k,int m)
{
	int i,j;
	plinknode p;
	for (i = 1;i<=n; i++)
	{
		if (i==1)
		{
			h=p=(plinknode)malloc(sizeof(linknode));
			p->data =i;
		}
		else
		{
			plinknode q = (plinknode)malloc(sizeof(linknode));
			if (q == NULL)
			{
				printf("Error:malloc error\n");
				exit(1);
			}
			p->next=q;
			q->data = i;
			p=p->next;
		}
	}	

	p->next = h;

	while(p->next != p)
	{
		for (j = k;j<=k+m; j++)
		{
			p=p->next;
		}

		printf("%d\n", p->data);

	}
	printf("\n");

}
int main(void)
{
	int n,k,m;
	plinknode h;
	init_plinknode(&h);

	printf("please input the number of n\n");
	scanf("%d",&n);

	printf("please input the number of k\n");
	scanf("%d",&k);

	printf("please input the number of m\n");
	scanf("%d",&m);

	josephu(h,n,k,m);

	return 0;
}