#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>


int main(int argc,char *argv[])
{
	int read_fd;
	int write_fd;
	int read_size;
	int write_size;
	char buf[BUFSIZ];
	char *ptr;
	int before_read_size_1,before_read_size_2,unwrite;
	int before_read_size_all_2 = 0,before_read_size_all_1 = 0;
	int offset;
	

	read_fd = open(argv[1],O_RDONLY);
	if(read_fd == -1)	
	{
		perror("open");
		exit(1);
	}

	write_fd = open(argv[2],O_RDWR|O_CREAT|O_EXCL,0644);//if the file is not exist,creat it,or open it 
	if(write_fd == -1)
	{
		write_fd = open(argv[2],O_RDONLY);//the file of argv[2] should exist,or program will go wrong
		if(write_fd == -1)	
		{
			perror("open");
			exit(1);
		}
	}

	//////////////////////////////continue to copy the lines if something go wrong and exit//////////////////////////////////
	
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

	////////////////////////////////////////////////////////////////////////////////////////////////////////////
	if(before_read_size_all_1 > before_read_size_all_2) //if before_read_size_all_1 is lagrger \
		than before_read_size_all_2,means the file is not equal to the read file ...write with append
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

	///////////////////////////////////////////this is the normal read and write function/////////////////////////////////////////////////////////////////
		while(read_size = read(read_fd,buf,sizeof(buf)))
		{	
			if((read_size == -1) && (errno != EINTR)) //read error
				break;
			else if(read_size > 0)
			{
				ptr = buf; //to remember the last written position 
				while(write_size = write(write_fd,ptr,read_size)) //the function of write return the bytes that write successfully
				{
					if((write_size == -1)) //write error
						break;
					else if(write_size == read_size) //write finished
						break;
					else if(write_size > 0)
					{
						read_size -=write_size;
						ptr +=write_size;
					}
				}
			}
		}
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	close(read_fd);
	close(write_fd);

	return 0;
}
