#include "inc.h"

void process_conn_server(int s)
{
	ssize_t size = 0;
	char buffer[BUFSIZ];

	while(1)
	{
		size = read(s,buffer,sizeof(buffer));//读取客户端的数据
		
		write(STDOUT_FILENO,buffer,size);//将客户端的数据输出到屏幕，write的时候要注意size为read的size
		if(0 == size)
		{
			return;
		}

		sprintf(buffer,"%d bytes altogether\n",size);
		write(s,buffer,strlen(buffer)+1);
	}
}

void process_conn_client(int sc)
{
	ssize_t size;
	ssize_t size_ss;
	char buffer[BUFSIZ];

	while(1)
	{
		printf("please input something to send to server\n");
		if((size = read(STDIN_FILENO,buffer,sizeof(buffer))) < 0)
		{
			perror("read server");
			continue;
		}
		else
		{
			write(sc,buffer,size);
			size_ss = read(sc,buffer,sizeof(buffer));
			write(STDOUT_FILENO,buffer,size_ss);
			printf("\n");
		}
	}
}
