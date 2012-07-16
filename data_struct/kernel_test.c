#include <stdio.h>
#include <stdlib.h>
#include "dlist.h"

struct list_test
{
	int data;
	struct list_head list;
};

int main(void)
{	int i;
	LIST_HEAD(node_head);
	struct list_test *ptr[10];
	struct list_head *p;
	struct list_test *pos;
	for(i=0; i<10; i++)
	{
		ptr[i] = (struct list_test *)malloc(sizeof(struct list_test));	
		if(ptr[i] == NULL)
		printf("malloc() error\n");
		ptr[i]->data = i;
	}
	for(i=0; i<10 ;i++)
	list_add_tail(&ptr[i]->list, &node_head);
	
	list_for_each(p,&node_head)
	{
		pos = list_entry(p, struct list_test, list);
		printf("%d\t", pos->data);
	
	}
}
