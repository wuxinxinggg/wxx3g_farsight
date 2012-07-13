#include <stdio.h>
int main(void){
	int age;
	for(age=1;age<=200;age++){
		printf("please enter your age and enter Ctr+C to exit the application\n");
		scanf("%d",&age);
		printf("almost %d seconds has passed of your life\n",age*365*24*3600);
	}
	return 0;
}
