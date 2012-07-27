#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef int datatype;

typedef struct list
{
	datatype data[MAX];
	int len;
}sqlist;

void init_sqlist(sqlist **s)
{
	*s = (sqlist *)malloc(sizeof(sqlist));
	if (NULL == (*s))
	{
		printf("Error:malloc failed\n");
		exit(1);
	}
	(*s)->len = 0;
}

int half_search(sqlist *s,int k)
{
	int high,low,mid;
	high = s->len;
	low = 1;
	while(high >= low)
	{
		mid = (high+low)/2;

		if (k == (s->data[mid]))
		{
			return mid;
		}
		else if(k >(s->data[mid]))
		{
			low = mid+1;
		}
		else
		{
			high = mid -1;
		}
	}

	return 0;
}
#if 0
bool is_sequence(sqlist *s)
{
	int i;
	bool flags;
	for (i = 1; i < s->len; i++)
	{
		if(s->data[i] <= s->data[i+1])
			flags = true;
		else
			flags = false;
	}
}
#endif

int seq_search(sqlist *s,int k)
{
	int i;
	s->data[0]= k;
	for (i = (s->len); i >= 0; i--)
	{
		if (s->data[i] == k)
			return i;
	}
	return 0;
}
int main(void)
{
	sqlist *s;
	int i,k,result;
	char m;
	init_sqlist(&s);

	printf("please the len 0f the list\n");
	scanf("%d",&(s->len));

	for (i = 1; i <= (s->len); i++)
	{

		printf("please input the %dth number\n",i );
		scanf("%d",&(s->data[i]));
	}

	printf("please input the number to search\n" );
	scanf("%d",&k);

	getchar(); //clear the buffer area,so we need to getchar,or the enter will be the char m

	printf("please input the method to search:\n s will use sequence search\n h will use half search\n" );
	scanf("%c",&m);

	if (m == 'h')
	{
		result = half_search(s,k);

	}

	else if(m == 's')
	{
		result = seq_search(s,k);
	}

	else
	{
		printf("Error:input error ,input the method again\n");
	}

	if (result == 0)
	{
		printf("the number is not recorded\n");	
	}
	else
	{
		printf("the position of the number is %d ,data is %d\n",result,s->data[result] );
	}

	return 0;
}