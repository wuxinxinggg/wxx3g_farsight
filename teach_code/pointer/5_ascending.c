#include <stdio.h>

int main(void)
{
	int a[5] = {1, 3, 5, 7, 9};
	int b[5] = {2, 4, 60, 80, 100};

	int *p = a; // int *p = &a[0];
	int *q = b;

	int i=0, j=0;

	while(1){

		if(i>=5 || j>=5)
			break;

		if(*p < *q){
			printf("%d\n", *p);
			i++;
			p = a + i;
		}
		else{
			printf("%d\n", *q);
			j++;
			q = b + j;
		}
	}

	if(i < 5)
		while(i++ < 5){
			printf("%d\n", *p);
			p = a + i;
		}
	else
		while(j++ < 5){
			printf("%d\n", *q);
			q = b + j;
		}

	return 0;
}
