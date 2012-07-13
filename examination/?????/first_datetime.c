#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void delete_space(char *p1,char *p2)
{
	int i,j;

	for(i=0;i<strlen(p1);i++)
	{
		if (p1[i] != ' ') {
			p2[j]=p1[i];
			j++;
		}
	}
//	p2[j] = '\0';
}

void GetMemory(char *p,int num)
{
	*p = (char *)malloc(sizeof(num));
}
/****************************结构体**********************************/
struct node
{
	int data;
	struct node *next; //占用的存储空间为一个指针占用的空间
}*p;
/****************************联合体**********************************/
union dt{
	int a;
	char b;
	double c;
}data;
/*data可以作为函数实参，data的每个成员起始地址相同，变量data所占的字节数与成员c（即成员中占用存储空间最大的那个相同），联合体只能输出最后一次赋值的成员值，其他成为值为相应类型的0*/
/****************************计算字符串的长度**********************************/
int func(char *s)
{
	char *t=s;	

	while(*t++);//一直自加到字符串的截止位，即\0
	t--;
	return(t-s);//s为字符串的首元素地址，t为字符串最后一位的地址
}
/****************************计算字符串的长度**********************************/

/****************************指针自加**********************************/
void fun(char **p)
{
	++p;
	printf("%s\n",*p);
}
/****************************指针自加**********************************/
int fun_21(char s[])
{
	int n=0;
	while('0'<=*s && *s<='9') //'0'<=*s && *s<='9'不能修改为'0'<=*s<='9'，没有x<=y<=z这样的表达式，这个条件输出字符串中第一个非数字之前的数字
	{
		n=10*n+*s-'0';
		s++;
	}
	return(n);
}

int main(void)
{
/****************************do while**********************************/
#if 0
	/*do {}while()语句执行一次，while中的条件如果不是终止条件将执行表达式操作后退出*/
	int i=0;
	do
	{
		printf("%d",i);
	}while(i++);

	printf("%d\n",i);
#endif

/****************************赋值**********************************/
	/*赋值从右到左，并且左值不能是表达式*/
#if 0
	int a,b,c;

	a=1;
	b=2;
	c=3;
	a=a+7=c+b;

	printf("%d\t%d\t%d\t\n",a,b,c);
#endif

/****************************先自减，再输出**********************************/
#if 0
	int y=9;
	for(;y>0;y--)
	{
		if(y%3==0)
			printf("%d\n",--y);
	}

#endif

/****************************计算char类型长度**********************************/
#if 0
	char p[]={'1','2','3'},*q=p;

	printf("%d\n",sizeof(p[0]));

	printf("%d\n",sizeof(p));

	printf("%d\n",sizeof(char));

	printf("%d\n",sizeof(*q));//*p是char类型，所以其实相当于sizeof(char)
#endif

/****************************计算字符串的长度**********************************/
#if 0
	char str[128];

	strcpy(str,"123");

	printf("%d\n",func(str));
#endif

/****************************指针自加**********************************/
#if 0
	char *a[]={"Morning","Afternoon","Evening","Night"};
	fun(a);
#endif

/****************************fun_21输出数组中第一个非数字字符前的所有数字**********************************/
#if 0
	char s[10]={'6','*','1','*','4','*','9','*','0','*'};
	printf("%d\n",fun_21(s));
#endif


/****************************联合体**********************************/
	/*联合体只能引用最后被赋值的成员，引用其他成员将输出相应类型的0*/
#if 0
	data.a=5;	
	printf("%f\n",data.c);
#endif

/****************************取余运算**********************************/
	/*n<m,n对m取余的值为n本身*/
#if 0
	int n=12345,d;
	while(n!=0)
	{
		d=n%10;
		printf("%d\n",3%6);
		n/=10;
	}
#endif

/****************************结构体**********************************/
#if 0
	printf("%d\n",sizeof(struct node));

#endif

/****************************类型转换**********************************/
#if 0
	printf("%d\n",(int)((double)5/2+2.5));
	
	printf("%d\n",(int)((int)5/2+2.5));

#endif

/***************************输出数组字符串***********************************/
#if 0
	char s[]="man";
	int i;

	for(i=0;s[i];i++) //当第二个条件为false的时候，跳出循环，对于字符串来说，\0是推出
		printf("%c%c%c%c\n",s[i],*(s+i),*(i+s),i[s]);
#endif


/***************************打印void类型变量***********************************/
#if 0
	char *cptr,c;
	void *vptr,v;
	c=10;
	v=0;
	cptr=&c;
	vptr=&v;
	printf("%c%p\n",c,&v);
#endif

/***************************指针操作***********************************/

#if 0
	char *str = NULL;
	GetMemory(str,100);
	strcpy(str,"hello");
	printf("%s\n",str);


	char *str = (char *)malloc(100);
	strcpy(str,"hello");
	free(str);

	if(str != NULL) //str保存了malloc分配的地址，str本身保存再栈中，程序运行结束前，空间不会释放，所以str保存的地址内容不会free掉
	{
		strcpy(str,"world");
		printf("%s",str);
	}

#endif

	char str1[100];
	char str2[100];

	printf("please input a string to operate:\n");

	fgets(str1,100,stdin);
	//gets(str1);

	delete_space(str1,str2);

	printf("%s\n",str2);

	return 0;

}
