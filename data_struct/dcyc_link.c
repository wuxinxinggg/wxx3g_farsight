#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int datatype;
typedef struct node
{
	datatype data;
	struct node *next, *prior;
}linknode, *plink;

void init_link(plink *pH)
{
	*pH = (plink)malloc(sizeof(linknode));
	if(NULL == *pH)
	{	
		printf("malloc error\n");
		exit(1);
	}
	(*pH)->next = (*pH);
	(*pH)->prior = (*pH);

}

bool add_node(plink H, datatype n)
{
	plink p = H->next;
	plink new = (plink)malloc(sizeof(linknode));
	new->data = n;
	new->prior = p->prior;
	p->prior->next = new;
	new->next = p;
	p->prior = new;
}

void show(plink H)
{
	plink p = H->next;
	while(p != H)
	{	
		printf("%d\t", p->data);
		p = p->next;
	}
	printf("\n");
}
int main(void)
{
	int n, ret;
	plink H;
	init_link(&H);
	while(1)
	{
		ret = scanf("%d", &n);
		if(ret != 1)
		break;
		add_node(H, n);
		show(H);
	}
	return 0;
	
}
