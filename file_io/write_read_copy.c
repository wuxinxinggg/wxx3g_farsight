#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(int argc,char *argv[])
{
	int read_fd;
	int write_fd;
	int read_size;
	int write_size;
	char buf[BUFSIZ];
	int before_read_size_1,before_read_size_2,unwrite;
	int before_read_size_all_2 = 0,before_read_size_all_1 = 0;
	int offset;
	

	read_fd = open(argv[1],O_RDONLY);
	if(read_fd == -1)	
	{
		perror("open");
		exit(1);
	}

	write_fd = open(argv[2],O_RDONLY);//the file of argv[2] should exist,or program will go wrong
	if(write_fd == -1)	
	{
		perror("open");
		exit(1);
	}

	//////////////////////////////go on to copy the lines if something go wrong//////////////////////////////////
	
	memset(buf,'\0',sizeof(buf));
	before_read_size_1 = read(read_fd,buf,sizeof(buf));
	before_read_size_all_1 +=before_read_size_1;

	while(before_read_size_1 > 0)
	{
		memset(buf,'\0',sizeof(buf));
		before_read_size_1 = read(read_fd,buf,sizeof(buf));
		before_read_size_all_1 +=before_read_size_1;
	}

	memset(buf,'\0',sizeof(buf));
	before_read_size_2 = read(write_fd,buf,sizeof(buf));
	before_read_size_all_2 +=before_read_size_2;

	while(before_read_size_2 > 0)
	{
		memset(buf,'\0',sizeof(buf));
		before_read_size_2 = read(write_fd,buf,sizeof(buf));
		before_read_size_all_2 +=before_read_size_2;
	}

	printf("before_read_size_all_1 = %d\n",before_read_size_all_1);
	printf("before_read_size_all_2 = %d\n",before_read_size_all_2);

	if(before_read_size_all_1 > before_read_size_all_2)
	{
		close(write_fd);

		write_fd = open(argv[2],O_WRONLY|O_APPEND);//the file of argv[2] should exist,or program will go wrong
		if(write_fd == -1)	
		{
			perror("open");
			exit(1);
		}
		

		unwrite = before_read_size_all_1 - before_read_size_all_2;
		printf("unwrite = %d\n",unwrite);

		offset = lseek(read_fd,before_read_size_all_2,SEEK_SET);//to seek the position of the unwrited position
		if(offset < 0)
		{
			perror("lseek");
			exit(1);
		}

		printf("offset = %d\n",offset);

		memset(buf,'\0',sizeof(buf));
		read_size = read(read_fd,buf,sizeof(buf));

		printf("read_size = %d\n",read_size);
		while(read_size > 0)
		{	
			if(read_size < sizeof(buf))
			{
	
				write_size = write(write_fd,buf,read_size); //the function of write return the bytes that write successfully
				printf("write_size = %d\n",write_size);
			}

			else
			{
				while(read_size > 0)
				{
					write_size = write(write_fd,buf,read_size);
					printf("else: write_size = %d\n",write_size);

					memset(buf,'\0',sizeof(buf));
					read_size = read(read_fd,buf,sizeof(buf));
				}
			}
		}

	}

	////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	close(read_fd);
	close(write_fd);

	return 0;
}
