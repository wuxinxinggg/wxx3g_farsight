#include <stdio.h>

int main(void)
{
	int a[10]={0,3,7,5,13,9,11,17,15,19};
	int b[10]={2,10,4,8,6,14,18,12,1,16};
	int c[20];
	int *p;
	int i,j,k,m,n;
	int tmp;

	p=c;

	for(i=0;i<10;i++)
	{
		p[i]=a[i];
	}

	for(j=0;j<10;j++)
	{
		p[10+j]=b[j];
	}

	for(k=0;k<20;k++)
	{
		for(m=0;m<19;m++)
		{
			if(p[m]>p[m+1])	
			{
				tmp=p[m+1];
				p[m+1]=p[m];
				p[m]=tmp;	
			}
		}
	}
	
	for(n=0;n<20;n++)
	{
		printf("p[%d]=%d\n",n,p[n]);
	}
	return 0;
}
