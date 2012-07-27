#include <stdio.h>

struct whichday{
	int year;
	int mon;
	int day;
}a1={2012,6,30};
int main(void)
{
	struct whichday *p;
	p=&a1;
	if(((p->year)%4==0) &&((p->year)%400==0) )
	
}
