#include <stdio.h>

struct mon{
#if 0
	char name[10];
	char sname[3];	
	int days;
#endif
	char *name;
	char *sname;	
	int days;
}january={"january","Jan",31},*p,test;

int main(void)
{
	p=&january;
	test=january;
	
	printf("p->:\nname=%s\tsname=%s\tdays=%d\t\n",p->name,p->sname,p->days);
	printf("january.name:\nname=%s\tsname=%s\tdays=%d\t\n",january.name,january.sname,january.days);
	printf("test.name:\nname=%s\tsname=%s\tdays=%d\t\n",test.name,test.sname,test.days);
	printf("(*p):\tname=%s\nsname=%s\ndays=%d\n",(*p).name,(*p).sname,(*p).days);
	
	return 0;
}
