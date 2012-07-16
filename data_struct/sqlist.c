#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX 100
typedef int datatype;

typedef struct seqlist
{
	datatype data[MAX];
	int last;
}sqlist,*sqlink;

void init_sqlist(sqlink *pl)
{
	*pl = (sqlink)malloc(sizeof(sqlist));
	if(*pl == NULL)
	{
		printf("malloc error\n");
		exit(1);
	}
	(*pl)->last = -1;
}

bool is_full(sqlink L)
{
	return L->last >= MAX-1;
}
bool is_empty(sqlink L)
{
	return L->last == -1;
}

bool insert(sqlink L, datatype x)
{
	if(is_full(L))
		return false;
	L->data[++L->last] = x;	
	return true;
}
bool delete(sqlink L, datatype x)
{
	int i,j;
	if(is_empty(L))
		return false;
	for(i=0;i<=L->last; i++)
	{
		if(L->data[i] != x)
			continue;
		else
		{
			for(j=i+1; j<=L->last ; j++)	
				L->data[j-1] = L->data[j];
			L->last--;
		}
		return true;
	}
	printf("no record\n");
	return false;
}
void show(sqlink L)
{
	int i;
	if(is_empty(L))
		return ;
	for(i=0; i<=L->last; i++)
		printf("%d\t", L->data[i]);
	printf("\n");
}
int main(void)
{
	int n;
	int ret;
	sqlink L;
	init_sqlist(&L);
	while(1)
	{
		ret = scanf("%d", &n);
		if(ret != 1)
			break;
		if(n >= 0)
		{
			if(insert(L, n))
			{
				show(L);
				continue;
			}
			printf("isnert failed\n");

		}
		else 
		{
			if(delete(L, -n))
			{
				show(L);
				continue;
			}
			printf("delete failed\n");
		}
	}	
	return 0;
}
