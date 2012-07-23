#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*实现单链表的创建，查询，插入，删除，转置，显示，合并*/
typedef int datatype;
typedef struct node
{
	datatype data;
	struct node *next;
}slinknode,*slink;

int input_a_num(void)//实现让用户输入一个数字
{
	int n,ret; 
	ret = scanf("%d",&n);
	while((ret != 1) && (getchar() != '\n'))
	{
		printf("Error:please input again:\n");
		ret = scanf("%d",&n);
	}
	
	return n;
}

char input_a_alphabet(void)//实现让用户输入一个字符
{
	char c;
	scanf("%c",&c);
	
	return c;
}

void creat_slink(slink *H,int num) //创建单链表
{
	int ret;
	int n,i=1;
	slink r,p;
	*H = (slink)malloc(sizeof(slinknode));
	if (NULL == (*H))
	{
		printf("Error:malloc failed\n");
		exit(1);
	}
	(*H)->next = NULL;

	r = *H;
	printf("Please input the %dth number:\n",i);
	ret = scanf("%d",&n);
	while(ret == 1 && num > 0)
	{
		p = (slink)malloc(sizeof(slinknode));
		if ( NULL == p)
		{
			printf("Error:malloc failed\n");
		}
		p->data = n;
		r->next = p;
		r = p;
		if(--num > 0)
		{
			printf("Please input the %dth number:\n",++i);
			while(getchar() != '\n');
		//num is to control the number of the link
			ret = scanf("%d",&n);
		}
	}
	r->next = NULL;
}

void show(slink H)//显示链表内容
{
	slink p = H->next;
	while(p)
	{
		printf("%d\t", p->data);
		p = p->next;
	}
	printf("\n");
}

slink append_slink(slink a,slink b)
{
	slink c;
	c = a;//c为指向a的节点，一定要注意c是指针，所以只是指向，而不是赋值。。。。
	while(c->next)
	{
		c = c->next;
	}

	c->next = b->next;

	return a;
}

void value_locate(slink a,int n)
{
	slink p = a->next;

	int i = 0;

	while(p && p->data != n)
	{
		p = p->next;
		i++;
	}
	
	printf("the address of the %d is %p,it's the %dth number\n", n,p,i);
}

void pos_locat(slink a,int i)
{
	slink p = a->next;
	int j = 0;
	while( p->next && j<i)
	{
		j++;
		p = p->next;
	}

	if(j == i)
	{
		printf("the %d number is %d\n", i,p->data);
	}
	else
	{
		printf("the number is not in the list\n");
	}

}
void head_insert_slink(slink a,int n)
{
	slink q;

	q = (slink)malloc(sizeof(slinknode));
	if (NULL == q) {
	printf("Error:malloc failed\n");
	}
	q->data = n;
	q->next = a->next;
	a->next = q;
}

void rear_insert_slink(slink a,int n)
{
	slink p = a->next;
	slink r,q;

	while(p && p->next)
	{
		p = p->next;
	}
	r = p;
	r->next = NULL;

	q = (slink)malloc(sizeof(slinknode));
	if (NULL == q) 
	{
		printf("Error:malloc failed\n");
	}
	q->data = n;
	r->next = q;
	q->next = NULL;
	r = q;
}

void revert_slink(slink a)
{
	slink p = a->next;
	slink q;
	a->next = NULL; //断开a的头节点

	while(p)
	{
		q = p;
		p = p->next;
		q->next = a->next;
		a->next = q;
	}
	
}

void delete_slink(slink a,int n)//删除第一个是报错。。。
{
	slink p = a->next;
	slink q;

	while(p && p->next->data != n) //找到n的前一个节点，必须保证要删除的节点和它的下一个节点存在
	{
		p = p->next;
	}

	if(p && p->next && p->next->data == n)
	{
		q = p->next; //保存要删除的节点以释放
		p->next = p->next->next; //删除n所在的节点
		free(q);
	}
	else
	{
		printf("the number of %d is not exist\n", n);
	}

}
int main(void)
{
	slink a;
	slink b;
	char op;
	int num;
	char im;
#if 0
#endif

	while(1)
	{
		printf("*****************************************************************************************************************\n");
		printf("\t******Welcome to use the single link operator******\n");

		printf("\n\tplease choose to operate:\n\n\
				\"c\" to create a link\n\
				\"s\" to show a link\n\
				\"i\" to insert a number to link\n\
				\"r\" is to revert a link\n\
				\"a\" is to append a link to another\n\
				\"l\" is to locate a number\n\
				\"d\" is to delete a number\n\
				\"q\" is to exit\n");
		printf("\n");
		printf("*****************************************************************************************************************\n");

		op = input_a_alphabet();

		switch(op)
		{
			case 'c':
				printf("please input the number of the link\n");
				num = input_a_num();
				

				creat_slink(&a,num);
				while(getchar() != '\n');
				break;

			case 's':
				printf("the link is:\t");
				show(a);
				while(getchar() != '\n');// 清空缓冲区，否则每次输入的回车会被当成字符读入走default
				break;

			case 'i':
				printf("please input a number to insert:\n");
				num = input_a_num();
				printf("please input the insert method:\n\
						h is to insert after the head of the link\n\
						r is to insert after the rear of the link\n");
				while(getchar() != '\n');
				im = input_a_alphabet();
				printf("%c\n",im);

				if(im == 'h')
				{
					head_insert_slink(a,num);
				}
				else if(im == 'r')
				{
					rear_insert_slink(a,num);
				}
				printf("\n");
				show(a);
				while(getchar() != '\n');
				break;


			case 'r':
				revert_slink(a);
				printf("the revert link is:\t");
				show(a);
				printf("\n");
				while(getchar() != '\n');
				break;

			case 'a':
				printf("please input the number of the first link\n");
				num = input_a_num();
				creat_slink(&a,num);

				printf("please input the number of the second link\n");
				num = input_a_num();
				creat_slink(&b,num);

				slink c = append_slink(a,b);
				printf("the appended link is:\t");
				show(c);
				printf("\n");
				while(getchar() != '\n');
				break;

			case 'l':
				printf("\nplease input a number to locate\n");
				num = input_a_num();
				printf("please choose the locate method\n\
						\t'v' is value locate\n\
						\t'n' is the sequent locate\n\n");
				while(getchar() != '\n');
				im = input_a_alphabet();
				if (im == 'v') 
				{
					value_locate(a,num);
				}
				else if (im =='n') {
					pos_locat(a,num);
				}
				while(getchar() != '\n');
				break;

			case 'd':
				printf("please input a number to delete\n");
				num = input_a_num();
				delete_slink(a,num);
				show(a);
				while(getchar() != '\n');// 清空缓冲区，否则每次输入的回车会被当成字符读入走default
				break;

			case 'q':
				while(getchar() != '\n');
				goto bye;	

			default:
				printf("\n");
				printf("\t******Welcome to use the single link operator******\n");
				break;
		}
	}
	
	bye:
		printf("************Enjoy yourself!************\n\n\t\tbye bye\n\n");		
	return 0;
}
