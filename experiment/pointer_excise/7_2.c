#include <stdio.h>

int main(void)
{
	int s[]={1,2,3,4,5,6,7,8,9};	
	int *p;
	int i,j,k,n;
	int ret;
	int tmp;

	p=s;
	printf("please input the number between 1 to 9:\n");
	ret=scanf("%d",&n);
	while((ret !=1)||(getchar() !='\n'))
	{
		printf("Error:please input the number between 1 to 9 again:\n");
		while(getchar() !='\n')
		{
			ret=scanf("%d",&n);
		}
	}
	
	for(i=0;i<n;i++)	
	{
		tmp=p[8];

		for(j=8;j>0;j--)
		{
			p[j]=p[j-1];
		}

		p[0]=tmp;
	}

	for (k = 0; k < 9; k++) {
		printf("%d\t",p[k]);
	}

	printf("\n");

	return 0;
}
