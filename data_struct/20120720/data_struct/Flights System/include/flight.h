#ifndef	__FLIGHT_H__
#define	__FLIGHT_H__

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include "list.h"

#define NUMBER 10
#define ADDR 40
#define DATE 20
#define TIME 20
#define PRICE 10

#define MAXLINE 80

typedef	struct flight   
{	  
	char	number[NUMBER]; // Ticket number  e.g "A0001"

	char	depart_address[ADDR]; // Department  e.g "NewYork"
	char	arrive_address[ADDR]; // Destination

	char	date[DATE]; // Date of departure  e.g "2011.10.21"
	char	time[TIME]; // time of departure  e.g "08:30am"

	char	price[PRICE]; // e.g $1200.0
	char	type; // e.g 'A' (class A)
}datatype;

typedef struct node   
{		  
	datatype info;	   
	struct list_head list;
}node, *linklist;

void welcome(void);
void help(void);
void Scanf(const char *, int *, int, int);
FILE *Fopen(const char *, const char *);

linklist read_flight(void);

void title(void);
void show_all(linklist);
void show(linklist);

void find(linklist);
void sort(linklist);

/**************************************
	MACROs for searching
***************************************/
#define FIND(head, string, member) ({\
	linklist pos;\
	\
	list_for_each_entry(pos, &(head->list), list){ \
		if(strcmp(string, pos->info.member)) \
			continue; \
		show(pos); \
		count++; \
	} \
})

#define FIND_TYPE(head, ch, member) do{ \
	linklist pos;\
	list_for_each_entry(pos, &(head->list), list){ \
		if(ch != pos->info.member) \
			continue; \
		show(pos); \
		count++; \
	} \
}while(0)


/*************************************
	MACROs for sorting
**************************************/
#define SORT(head, member) ({ \
	linklist pos, q, tmp; \
	list_for_each_entry(pos, &head->list, list){ \
							\
		list_for_each_entry(q, &head->list, list){ \
							\
			if(q == pos) \
				break; \
					\
			if(strcmp(q->info.member, pos->info.member) > 0){ \
				list_move_tail(&pos->list, &q->list); \
				tmp = pos; \
				pos = q; \
				q = tmp; \
			} \
		} \
	} \
	show_all(head); \
})

#endif
