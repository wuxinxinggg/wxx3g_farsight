#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//use fread and fwrite to copy a file

int main(int argc,char *argv[])
{
	FILE *read_fp;
	FILE *write_fp;

	long len;
	long file_size;
	char buf[BUFSIZ];

	if(argc != 3)
		printf("usage error\n");

	read_fp = fopen(argv[1],"r+");
	if(NULL == read_fp )
	{
		perror("Error:fopen failed");
		exit(1);
	}
	write_fp = fopen(argv[2],"w+");
	if(NULL == write_fp )
	{
		printf("Error:fopen failed");
		exit(1);
	}

	fseek(read_fp,0,SEEK_END);

	file_size = ftell(read_fp);
	len = file_size;

	if(len == 0)
	{
		printf("the file is empty");
	}

	fseek(read_fp,0,SEEK_SET);
	
	while(!feof(read_fp) && !ferror(read_fp))
	{
		memset(buf,'\0',sizeof(buf));
		fread(buf,BUFSIZ,1,read_fp);
		if(len <= BUFSIZ)
		{
			fwrite(buf,len,1,write_fp);
			break;
		}
		else
		{
			fwrite(buf,BUFSIZ,1,write_fp);	
			len -=BUFSIZ;
		}
	}

	fclose(read_fp);
	fclose(write_fp);

	return 0;
}
