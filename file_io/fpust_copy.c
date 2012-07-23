#include <stdio.h>
//实现文件拷贝
int main(int argc,char *argv[])
{
	FILE *fp;
	FILE *ffp;
	char buf[1024];

	if (argc != 3) 
		printf("usage error");
	
	fp = fopen(argv[1],"r+");
	ffp = fopen(argv[2],"w+");

	while(fgets(buf,1024,fp) != NULL)
	{
		fputs(buf,ffp);
	}

	fclose(fp);
	fclose(ffp);

	return 0;
	

}
