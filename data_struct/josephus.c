#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int datatype;
typedef struct node
{
	datatype data;
	struct node *next;
}linknode , *plink;

plink creat_cyc(int n)
{
	int i;
	plink pH = NULL;
	plink r;
	for(i=1; i<=n; i++)	
	{
		plink new = (plink)malloc(sizeof(linknode));
		new->data = i;
		new->next = NULL;
		if(pH == NULL)
			pH = new;
		else
			r->next = new;
		r = new;
	}
	r->next = pH;
	return pH;


}

void josphus(plink H, int n ,int k ,int m)
{
	int i;
	plink q;
	plink p = H;
	for(i=0 ; i<k-1; i++)
		p = p->next;
	while(p->next != p)
	{

		for(i=0 ; i<m-1; i++)
		{
			q = p;
			p = p->next;
		}
		q->next = p->next;
		printf("%d\t", p->data);
		free(p);
		p =q->next;
	}
	printf("%d", p->data);
	free(p);
	printf("\n");
}

int main(void)
{
	int m, k ,n;
	plink H = NULL;
	printf("input the number of people=");
	scanf("%d", &n);
	printf("input the start number = ");
	scanf("%d", &k);
	printf("input the out number= ");
	scanf("%d", &m);
	H = creat_cyc(n);
	josphus(H, n, k, m);
}
