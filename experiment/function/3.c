#include <stdio.h>

void swap(int *p1,int *p2)
{
	int tmp;
//为什么不能只交换p1和p2的对象的地址实现值交换。。。即：
#if 0
	int *tmp;
	tmp=p2;
	p2=p1;
	p1=tmp;
#endif
	tmp=*p2;
	*p2=*p1;
	*p1=tmp;
}

void taxis(int n,int str[n])
{
	int i,j,k;
//	int tmp;
	for (j = 0; j < n; j++) {
		for(i=0;i<n-1;i++)
		{
			if(str[i]>str[i+1])	
			{
				swap(&str[i],&str[i+1]);
			}
#if 0
			{
				tmp=str[i+1];
				str[i+1]=str[i];
				str[i]=tmp;
			}
#endif
			else
				continue;
		}
	}

	for (k = 0; k < n; k++) {
		printf("%d\t",str[k]);
	}

	printf("\n");
}

int main(void)
{
	int str[8]={11,22,32,2,7,13,27,1};

	taxis(8,str);

	return 0;
}
