#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 13

typedef int keytype;
typedef struct node
{
	keytype key;
	struct node *next;
}hashnode;

void create_hash(int a[],hashnode hash[],int n,int m)
{
	int i,j;
	hashnode *p;

	for (i = 0; i < m; i++)
	{
		hash[i].next = NULL;
	}
	for (i = 0; i < n; i++)
	{
		p = (hashnode *)malloc(sizeof(hashnode));
		p->key = a[i];
		j = a[i]%m;
		p->next = hash[j].next;
		hash[j].next = p;
	}
}

void show(hashnode hash[],int n,int m)
{
	int i;
	hashnode *p;
	printf("hash is:\n");
	for (i = 0; i < m; i++)
	{
		printf("%2d", i);
		p = hash[i].next;
		while(p != NULL)
		{
			printf("%4d", p->key);
			p=p->next;
		}
		printf("\n");
	}
}
hashnode *hash_search(hashnode hash[],int k,int m)
{
	hashnode *p;
	int d = k%m;
	p = hash[d].next;
	while(p && p->key !=k)
		p = p->next;

	return p;
}
int main(void)
{
	int k;
	int a[] = {23,34,14,38,46,16,68,15,07,31,26};
	int n = 11;
	int m = MAX;

	hashnode *p;
	hashnode hash[MAX];
	create_hash(a,hash,n,m);
	show(hash,n,m);

	printf("input the number to search:\n");
	scanf("%d",&k);
	p = hash_search(hash,k,m);
	if(p == NULL)
		printf("the number is not exit\n");
	else
		printf("the number is :%d\n", p->key);

	return 0;
}