#include <stdio.h>
#include "../include/flight.h"

void sort_type(linklist head)
{
	linklist pos, q, tmp;

	list_for_each_entry(pos, &head->list, list){
		
		list_for_each_entry(q, &head->list, list){

			if(q == pos)
				break;

			if(q->info.type > pos->info.type){
				list_move_tail(&pos->list, &q->list);
				tmp = pos;
				pos = q;
				q = tmp;
			}
		}
	}

	show_all(head);
}

void sort_price(linklist head)
{
	linklist pos, q, tmp;

	list_for_each_entry(pos, &head->list, list){
		
		list_for_each_entry(q, &head->list, list){

			if(q == pos)
				break;

		//	if(strcmp(q->info.price, pos->info.price) > 0){
			double price1 = atof(q->info.price + 1); // "+1" means to discard prefix '$'
			double price2 = atof(pos->info.price + 1);

			if(price1 > price2){
				list_move_tail(&pos->list, &q->list);
				tmp = pos;
				pos = q;
				q = tmp;
			}
		}
	}

	show_all(head);
}


void sort(linklist head)
{
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

	int choice;
	Scanf("%d", &choice, 1, 7);

#if 0
	switch(choice)
	{
	case 1:
		SORT(head, depart_address);
		break;
	case 2:
		SORT(head, date);
		break;
	case 3:
		SORT(head, time);
		break;
	case 4:
		SORT(head, number);
		break;
	case 5:
		sort_price(head);
		break;
	case 6:
		sort_type(head);
		break;
	default:
		printf("invalid input.");
	}
#endif
	switch(choice)
	{
	case 1:
		SORT(head, depart_address);
		break;
	case 2:
		SORT(head, date);
		break;
	case 3:
		sort_type(head);
		break;
	default:
		printf("invalid input.");
	}
}
