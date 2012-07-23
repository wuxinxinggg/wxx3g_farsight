#include<stdio.h>
#include<errno.h>
#include<string.h>

int main(void)
{
	FILE *fp;
	int n,m;

	fp = fopen("out.txt","r+");
	if((fp = fopen("out.txt","r+")) == NULL)
	{
		fprintf(stderr,"fopen failed:%s \n",strerror(errno));
		return -1;
	}

	freopen("out.txt","w+",stdout);

	printf("Hi,I am freopen(\"out.txt\",\"w+\",stdout)\n");

	freopen("in.txt","r+",stdin);

	scanf("%d%d",&n,&m);
	
	fprintf(stdout,"m = %d\n",m);
	fprintf(stdout,"n = %d\n",n);
	fprintf(stdout,"m+n = %d\n",m+n);
	fclose(fp);

	return 0;
}
