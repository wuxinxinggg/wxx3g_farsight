#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int datatype;
typedef struct node
{
	datatype data;
	struct node *next;
}linklist,*plinklist;

typedef struct 
{
	linklist *front,*rear;
}linkqueue;


void init_queue(linkqueue **q)
{
	(*q)= (linkqueue *)malloc(sizeof(linkqueue));
	plinklist p =(plinklist)malloc(sizeof(linklist));

	(*q)->front = (*q)->rear=p; //let the front of the queue point to the head node;

	(*q)->front->next = NULL;

}

bool is_empty(linkqueue *q)
{
	return (q->front == q->rear);
}

bool in_queue(linkqueue *q,datatype n)
{
	q->rear->next = (plinklist)malloc(sizeof(linklist)); 	//request new node behide the rear ;
	q->rear=q->rear->next;	//modify rear ponter
	q->rear->data = n;  //store the data in new nod
	q->rear->next = NULL;   //let the new nod be the rear
	return true;
}

bool out_queue(linkqueue *q,datatype *x)
{
	if(is_empty(q))
	{
		printf("the queue is empty\n");	
		return false;
	}
	else
	{
		plinklist s;  //define a auxiliary pointer
		s = q->front; //point the auxiliary pointer to the front node
		q->front = q->front->next;  //reset the front node

		free(s);   //free the before front
		*x = q->front->data;  //return the data of the front before
	}

	return true;

}

bool show(linkqueue *q)
{
	plinklist p;

	p = q->front->next;

	if(is_empty(q))
	{
		printf("the queue is empty\n");	
		return false;
	}

	while(p)
	{
		printf("%d\t", p->data);
		p=p->next;
	}

	printf("\n");

	return true;
}

int main(void)
{
	linkqueue *q;
	init_queue(&q);
	while(1)
	{
		datatype ret,n;
		printf("please input something to operate,number will in queue,and character will out queue\n");
		ret = scanf("%d",&n);
		if (ret ==1)
		{
			if(! in_queue(q,n))	
			{
				printf("Error:in queue failed\n");
				continue;
			}
			show(q);
		}
		else
		{
			if(! out_queue(q,&n))
			{
				printf("Error:out queue failed\n");
				continue;
			}
			show(q);
			while(getchar() != '\n');
		}
	}

	return 0;
}