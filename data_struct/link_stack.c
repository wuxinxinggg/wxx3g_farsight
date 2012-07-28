#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int datatype;
typedef struct node
{
	datatype data;
	struct node *next;
}linkstack,*plinkstack;


void init_linkstack(plinkstack *top) //栈的初始话其实就是置空栈，这是和链表的区别
{
	*top = NULL; //链栈置空栈是置栈顶指针为空，栈的置空栈是让栈顶top = -1
}

bool push_stack(plinkstack *top,datatype n)//因为链栈没有头节点，每次的入栈都要改变栈顶，所以必须传栈顶的指针
{
	//对于链表是每次插入都是malloc分配内存，所以不用判断是否满栈
	plinkstack p;//定义辅助指针

	p = (plinkstack)malloc(sizeof(linkstack));
	if(NULL == p)
	{
		perror("malloc");
		return false;
	}
	p->data = n; //将数据存入新节点
	p->next = (*top);//让新节点的next指针域指向原来的栈顶，链栈只能在栈顶操作，而且没有头节点
	(*top) = p;//改变栈顶位置

	return true;
}

bool is_empty(plinkstack top)
{
	return top == NULL; //栈顶指针为空，即为空栈
}

bool pop_stack(plinkstack *top,datatype *n)//出栈前要取数据，所以要传数据的地址
{
	plinkstack p;
	if(is_empty(*top))
	{
		printf("the linkstack is empty\n");
		return false;
	}

	*n = (*top)->data; //取数据
	p = (*top); //保存原先栈顶指针，以便释放
	(*top) = (*top)->next;//改变栈顶指针
	free(p);//释放原来栈顶空间

	return true;
}

void show(plinkstack top)
{
	while(top)
	{
		printf("%d\t",top->data);
		top = top->next;
	}

	printf("\n");
}

int main(void)
{
	plinkstack top;
	datatype n;
	int ret;
	init_linkstack(&top);

	while(1)
	{
		printf("please input num to operate:\n");
		printf("\n\t\tn >= 0 will be inserte\n");
		printf("\n\t\tn < 0 will be deleted\n");
		printf("\n\t\tothers will be exist\n");

		ret = scanf("%d",&n);
		if(ret != 1)
			break;
		if(n >= 0)
		{
			if(!push_stack(&top,n))
			{
				printf("push error\n");
				exit(1);
			}
			else 
			{
				show(top);
				continue;
			}
		}
		else if(n<0)
		{
			if(!pop_stack(&top,&n))
			{
				printf("pop error\n");
				exit(1);
			}
			else 
			{
				show(top);
				continue;
			}
		}

	}
	
	return 0;
}
