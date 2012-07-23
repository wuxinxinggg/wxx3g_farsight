#include <stdio.h>
#include "../include/flight.h"

void help(void)
{
	printf("\n======================"
		"========================\n");
	printf("  [1]Import [2]Print [3]Find [4]Sort [0]Quit");
	printf("\n");
	printf("==========================="
		"===================\n");
}

void welcome(void)
{
	printf("\n\tWelcome to Flights System");
}

void Scanf(const char *format, int *p, int low, int high)
{
	int ret;
	int ch;
	while((ret=scanf(format, p)) == 0 ||
		(ch=getchar()) != '\n' ||
		*p < low || *p > high){

		if(ret == 0)
			while(getchar() != '\n');
		printf("Invalid input. please try again.\n");
	}
}

FILE *Fopen(const char *path, const char *mode)
{
	FILE *fp;
again:
	fp = fopen(path, mode);

	if(fp == NULL && errno == EINTR)
		goto again;

	return fp;
}

linklist read_flight(void)
{
	printf("Import file (Ctrl+D to cancel):");
	char path[MAXLINE];
	scanf("%s", path);

	FILE *fp;
	fp = Fopen(path, "r+");
	if(fp == NULL){
		perror("\nWARNING");
		help();
		return NULL;
	}

	char buf[MAXLINE];
	char *delim = ",\t";
	char *p = NULL;

	linklist head = (linklist)malloc(sizeof(node));
	INIT_LIST_HEAD(&(head->list));

	int info_count = 0;
	while(1){
		if(fgets(buf, MAXLINE, fp) == NULL)
			break;

		p = strtok(buf, delim);
		linklist new = (linklist)malloc(sizeof(node));

		int i;
		for(i=1; p!=NULL; i++, p=strtok(NULL, delim)){
			switch(i)
			{
			case 1:
				strncpy(new->info.number, p, NUMBER);
				break;
			case 2:
				strncpy(new->info.depart_address, p, ADDR);
				break;
			case 3:
				strncpy(new->info.arrive_address, p, ADDR);
				break;
			case 4:
				strncpy(new->info.date, p, DATE);
				break;
			case 5:
				strncpy(new->info.time, p, TIME);
				break;
			case 6:
				strncpy(new->info.price, p, PRICE);
				break;
			case 7:
				new->info.type = *p;
				break;
			default:
				fprintf(stderr, "too many info items!\n");
				exit(0);
			}
		}

		// add the new node
		list_add(&(new->list), &(head->list));
		info_count++;
	}

	printf("read file successful! %d items"
		" have been read.\n", info_count);

	return head;
}


linklist Read_flight(void)
{
	linklist head;
	head = read_flight();
	if(head != NULL)
		show_all(head);
	return head;
}

void title(void)
{
	printf("***********************************"
		"**********************************");

	printf("\nnumber");
	printf("\taddress");
	printf("\t\t\tdate\t     time");
	printf("\tprice");
	printf("\ttype\n");

	printf("-----------------------------------"
		"----------------------------------\n");
}

void show_all(linklist head)
{
	if(head == NULL){
		printf("\tNo Info.\n");
		return;
	}

	title();

	linklist pos;

	list_for_each_entry(pos, &(head->list), list){

		printf("%s", pos->info.number);

		printf("\t%s", pos->info.depart_address);
		printf(" --> %-15s", pos->info.arrive_address);

		printf("\t%s, ", pos->info.date);
		printf("%s", pos->info.time);
		printf("\t%s", pos->info.price);

		printf("\t%c\n", pos->info.type);
	}

	printf("***********************************"
		"**********************************\n");
	printf("[1]Import [2]Print [3]Find [4]Sort [0]Quit\n");
	printf("==========================="
		"===================\n");
}

void show(linklist p)
{
	if(p == NULL){
		printf("\tNo Info.\n");
		return;
	}

	printf("%s", p->info.number);

	printf("\t%s", p->info.depart_address);
	printf(" --> %-15s", p->info.arrive_address);

	printf("\t%s, ", p->info.date);
	printf("%s", p->info.time);
	printf("\t%s", p->info.price);

	printf("\t%c\n", p->info.type);

	return;
}
