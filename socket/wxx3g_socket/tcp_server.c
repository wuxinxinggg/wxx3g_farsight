#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define MAXLINE 128

int main(void)
{
	int sockserv_fd,conn_fd;
	socklen_t clilen;
	char buf[MAXLINE] = "[Hello] Welcome to the tcp server";
	
	if((sockserv_fd = socket(AF_INET,SOCK_STREAM,0)) < 0)
	{
		perror("socket");
		exit(-1);
	}

	struct sockaddr_in servaddr,cliaddr;
	memset(&servaddr,'0',sizeof(servaddr));
	
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	servaddr.sin_port = htons(12345);

	if(bind(sockserv_fd,(struct sockaddr *)&servaddr,sizeof(servaddr)) < 0)
	{
		perror("bind");
		exit(-1);
	}

	listen(sockserv_fd,5);

	while(1)
	{
		clilen = sizeof(cliaddr);
		conn_fd = accept(sockserv_fd,(struct sockaddr *)&cliaddr,&clilen); 
		printf("connection form %s,port %d\n",inet_ntoa(cliaddr.sin_addr),ntohs(cliaddr.sin_port));

		send(conn_fd,buf,sizeof(buf),0);

		close(conn_fd);
	}

	return 0;
}
