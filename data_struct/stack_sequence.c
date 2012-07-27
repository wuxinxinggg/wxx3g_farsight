#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define MAX 128

//number will be pushed,alphabet will be poped

typedef int datatype;
typedef struct 
{
	datatype data[MAX];
	int top;
}seqstack,*stacklist;

void init_stack(stacklist *stack)
{

	*stack = (stacklist)malloc(sizeof(seqstack));
	if(NULL == stack)
	{
		perror("malloc");
		exit(1);
	}
	(*stack)->top = -1;
}

bool is_full(stacklist stack)
{
	return stack->top == MAX - 1;
}

bool push(stacklist stack,datatype n)
{
	if(is_full(stack))
	{
		printf("error:the seqstack is full\n");
		return false;
	}
	else
	{
		stack->top++;
		stack->data[stack->top] = n;
	}
	return true;
}

bool is_empty(stacklist stack)
{
	return stack->top == -1;
}

bool pop(stacklist stack,datatype *loc)
{
	if(is_empty(stack))
	{
		printf("the seqstack is empty\n");
		return false;
	}
	else
	{
		*loc = stack->data[stack->top--];
	}
	return true;
}

void show(stacklist stack)
{
	int i;
	for(i = 0;i <= stack->top;i++)
	{
		printf("%d\t",stack->data[i]);
	}

	printf("\n");
}
int main(void)
{
	int n,ret;
	stacklist stack;
	datatype loc;

	init_stack(&stack);

	while(1)
	{
		printf("************************************************************************************\n\n\n");
		printf("please input something to control\
			numbers will be pulled\n,and alphabet will be poped\n");	
		printf("************************************************************************************\n\n");

		ret = scanf("%d",&n);

		if(ret == 1)
		{
			if(! push(stack,n))
			{
				printf("push error:\n");
				break;
			}
			else
			{
				show(stack);
				continue;
			}
		}
		else if(ret == -1)
		{
			if(!pop(stack,&loc))
			{
				printf("pop error:\n");
				break;
			}
			else
			{
				show(stack);
				continue;
			}
		}
	}

	return 0;
}
