#include <stdio.h>
#include "../include/flight.h"

void find(linklist head)
{
	static int count;
	count = 0;

	if(head == NULL){
		printf("\tNo Info.\n");
		return;
	}

	printf("\n======================"
		"===================\n");
#if 0
	printf("[1]By Addr. [2]By Date. [3]By Time.\n"
	       "[4]By Num.  [5]By Price.[6]By Type.\n");
#endif
	printf("[1]By Addr. [2]By Date. [3]By Type.\n");
	printf("========================"
		"================\n");

	char buf[MAXLINE];

	int choice;
	Scanf("%d", &choice, 0, 7);

#if 0
	switch(choice)
	{
	case 1:
		printf("address:(e.g:北京)");
		scanf("%s", buf);
		FIND(head, buf, depart_address);
		FIND(head, buf, arrive_address);
		break;
	case 2:
		printf("date:(2011.12.13)");
		scanf("%s", buf);
		FIND(head, buf, date);
		break;
	case 3:
		printf("time:(14:50pm)");
		scanf("%s", buf);
		FIND(head, buf, time);
		break;
	case 4:
		printf("number:(A0010)");
		scanf("%s", buf);
		FIND(head, buf, number);
		break;
	case 5:
		printf("price:($100.0)");
		scanf("%s", buf);
		FIND(head, buf, price);
		break;
	case 6:
		printf("type:(A-C)");
		char c;
		scanf("%c", &c);
		FIND_TYPE(head, c, type);
		break;
	default:
		printf("invalid input.");
	}
#endif
	switch(choice)
	{
	case 1:
		printf("address:(e.g:北京)");
		scanf("%s", buf);
		title();
		FIND(head, buf, depart_address);
		FIND(head, buf, arrive_address);
		break;
	case 2:
		printf("date:(2011.12.13)");
		scanf("%s", buf);
		FIND(head, buf, date);
		break;
	case 3:
		printf("type:(A-C)");
		char c;
		scanf("%c", &c);
		FIND_TYPE(head, c, type);
		break;
	default:
		printf("invalid input.");
	}

	if(count == 0)
		printf("No such flight.\n");
	else{
		printf("**********************************"
		       "*********************************\n");
	}
	printf("[1]Import [2]Print [3]Find [4]Sort [0]Quit\n");
	printf("==========================="
		"===================\n");
}
