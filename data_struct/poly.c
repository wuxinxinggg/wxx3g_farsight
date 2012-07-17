#include <stdio.h>
#include <stdlib.h>

typedef struct poly
{
	int coef;
	int exp;
	struct poly *next;
}polylink;

polylink *polylink_create(int n,int a[][2])
{
	polylink *h,*p,*q;
	int i;
	h =(polylink *)malloc(sizeof(polylink));
	h->next = NULL;
	p = h;

	for (i = 0;i<n; i++)
	{
		q = (polylink *)malloc(sizeof(polylink));
		q->coef = a[i][0];
		q->exp = a[i][1];
		q->next = NULL;
		p->next = q;
		p = q;
	}
	return p;
}

void polylink_display(polylink *h)
{
	polylink *p = h->next;
	while(p)
	{
		printf("%d,%d\n", p->coef,p->exp);
		p = p->next;
	}
	printf("\n");
}

void polylink_add(polylink *h1,polylink *h2)
{
	polylink *p,*q,*r;
	p = h1->next;
	q = h2->next;
	r =h1;
	while(p && q)
	{
		if (p->exp < q->exp)
		{
			r->next = p;
			r = p;
			p = p->next;
		}
		else
		{
			if (p->exp > q->exp)
			{
				r->next =q;
				r =q;
				q = q->next;
			}
			else
			{
				p->coef += p->coef;
				if (p->coef)
				{
					r->next = p;
					r = p;
				}	
				p = p->next;
				q = q->next;
			}

		}
	}
	if (p == NULL)
	{
		r->next = q;
	}
	else
		r->next = p;
}

int main(void)
{
	int a[][2]={{5,0},{2,1},{8,8},{3,16}};
	int b[][2]={{6,1},{23,6},{-8,8}};
	polylink *h1,*h2;
	h1 = polylink_create(4,a);
	h2 = polylink_create(3,b);
	polylink_add(h1,h2);
	polylink_display(h1);

	return 0;
}