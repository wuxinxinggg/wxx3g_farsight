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
	(*p)->last = -1;	 //clearlist

}

bool is_full(sqlink L)
{
	return L->last>=Max - 1;
}

bool is_empty(sqlink L)
{
	return L->last==-1;
}
bool add_to_list(sqlink p,datatype x)
{
	if (is_full(p))
	{
		return false;
	}
	p->data[++p->last]=x;
	return true;
}

bool delete_from_list(sqlink L,datatype x)
{
	int i;
	int j;

	if (is_empty(L))
	{
		printf("Error:the list is empty:\n");
		return false;
	}
	for (i = 0;i<=L->last;i++)
	{
		if (L->data[i]==x)
		{
			for (j = i+1;j<=L->last; j++)			
			{
				L->data[j-1]=L->data[j];
			}
			L->last--;
		}
		else
			continue;
	}

	return true;
}
void show(sqlink L)
{
	if (is_empty(L))
	{
		printf("the sqlink is empty\n");
	}
	int i;
	for(i=0;i<=L->last;i++)
		printf("%d\t", L->data[i]);
	printf("\n");
}
int main(void)
{
	int ret;
	datatype n;
	sqlink L;

	init_list(&L);	

	while(1)
	{
		printf("please into a num to operate:\n");

		ret=scanf("%d",&n);

		if(ret ==-1)
			break;

		if ( n>=0 )
		{
			if(add_to_list(L,n))
			{

				show(L);
				continue;
			}
			else
				printf("add to list failed\n");
		}
		else
		{
			if (delete_from_list(L,-n))
			{
				show(L);
				continue;
			}
			else
				printf("delete delete_from_list failed\n");
		}

	}

	return 0;
}