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
		tmp[i]=p[9-n+i];
	}

	for(k=n;k<9;k++)	
	{
		tmp[k]=p[k-n];
	}

	for(j=0;j<9;j++)	
	{
		printf("%d\t",tmp[j]);
	}
	printf("\n");
	return 0;
}
