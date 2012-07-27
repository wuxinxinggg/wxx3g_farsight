#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/*
用顺序表存储一些正整数，输入正整数表示插入数据（比如输入3表示插入3），
输入负整数表示删除数据（比如输入-2表示删除2），输入字符表示退出程序。
插入和删除的过程中保持该表递增有序
*/

typedef int datatype;
#define Max 100

typedef struct
{
	datatype data[Max];
	int last;
}sqlist,*sqlink;

void init_list(sqlink *p)
{

	*p = (sqlink)malloc(sizeof(sqlist));
	if (*p == NULL)
	{
		printf("malloc Error\n");
		exit(1);
	}
	p->last=-1;	 //clearlist

}

bool is_full(sqlink L)
{
	return L->last>=Max - 1;
}

bool is_empty(sqlink L)
{
	return L->last=-1;
}
bool add_to_list(sqlink p,datatype x)
{
	if (is_full(p))
	{
		return false;
	}

	int i = p->last;

	while(i<0)
	{
		 p->data[++p->last]=x;
		 i--;
	}
	p->last++;
	return true;
}

void delete_from_list(sqlink L,datatype x)
{
	int i;
	int j;

	if (is_empty(L))
	{
		printf("the list is empty:\n");
	}
	for (i = 0;i<L->last;i++)
	{
		if (L->data[i]==x)
		{
			for (j = i;j<=L->last; j++)			
			{
				L->data[j+1]=L->data[j];
			}
		}
		else
			continue;
	}
	L->last--;
}
void show(sqlink L)
{
	int i;
	for(i=0;i<L->last;i++)
		printf("%d\n", L->data[i]);
}
int main(void)
{
	int i;
	int ret;
	datatype n;
	sqlink L;

	init_list(&L);	

	while(1)
	{
		printf("please into a num to operate:\n");

		ret=scanf("%d",&n);

		while ((ret != 1) && (getchar() != '\n') )
		{

		printf("Error:  please into again:\n");

		while( getchar() !='\n' )

			ret=scanf("%d",&n);
		}


		if ( n>=0 )
		{
			for (i = 0; i < L->last; i++)
			{
				if (  L->data[i]  == n )
				{
					printf("the num   is in the list .... Nothing be changed:\n");
					break;
				}
				else
				{

					printf("the num   is not in the list ....will be add_to_list:\n");

					add_to_list(L,n);
					show(L);
				}
			}	
		}
		else
		{
			for (i = 0; i < L->last; i++)
			{
				if ( L->data[i] == -n )
				{
					printf("num of %d is found in the list ,will be deleted\n", -n);
					delete_from_list(L,-n);
					show(L);
				}
				else
				{
					printf("num of %d is no found in the list ,nothing happened\n",-n );
				}

			}
		}

	}

	return 0;
}