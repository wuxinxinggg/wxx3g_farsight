#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAXLINE 50
typedef struct sockaddr SA;

int main(void)
{
	int listenfd,connfd;
	socklen_t clilen;
	struct sockaddr_in myaddr,cliaddr;
	char buf[MAXLINE] = "Welcome to TCP server";

	if((listenfd = socket(PF_INET,SOCK_STREAM,0)) < 0 )
	{
		perror("socket");
		exit(-1);
	}

	memset(&myaddr,'0',sizeof(myaddr));

	myaddr.sin_family = PF_INET;
	myaddr.sin_port = htons(8888);
	myaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	if(bind(listenfd,(SA *)&myaddr,sizeof(myaddr)) < 0)
	{
		perror("bind");
		exit(-1);
	}

	listen(listenfd,5);

	while(1)
	{
		clilen = sizeof(cliaddr);
		connfd = accept(listenfd,(SA *)&cliaddr,&clilen);
		printf("connection from %s,port %d \n",inet_ntoa(cliaddr.sin_addr),ntohs(cliaddr.sin_port));
		send(connfd,buf,sizeof(buf),0);
		close(connfd);
	}
	return 0;
}
