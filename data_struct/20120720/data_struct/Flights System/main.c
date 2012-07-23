#include <stdio.h>
#include "include/flight.h"

int main(void)
{
	welcome();
	help();

	int choice;
	Scanf("%d", &choice, 0, 5);

	linklist head = NULL;
	while(1){

		switch(choice)
		{
		case 1: // IMPORT

			head = Read_flight();
			break;
		
		case 2: // SHOW

			show_all(head);
			break;

		case 3: // FIND

			find(head);
			break;

		case 4: // SORT

			sort(head);
			break;

		case 5: // GET HELP

			help();
			break;

		case 0: // QUIT

			printf("Bye-bye!\n");
			exit(0);
	
		default:
			break;

		} // swtich

		Scanf("%d", &choice, 0, 5);
	}

	return 0;
}
