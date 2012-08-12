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
	int sockfd,nbyte;
	struct sockaddr_in servaddr;
	char buf[MAXLINE];

	if((sockfd = socket(PF_INET,SOCK_STREAM,0)) < 0)
	{
		perror("socket");
		exit(-1);
	}

	bzero(&servaddr,sizeof(servaddr)); //same as memset(&servaddr,'0',sizeof(servaddr));
	servaddr.sin_family = PF_INET;
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	servaddr.sin_port = htons(8888);

	if(connect(sockfd,(SA *)&servaddr,sizeof(servaddr)) < 0)
	{
		perror("connect");
		exit(-1);
	}

	if((nbyte = recv(sockfd,buf,MAXLINE,0)) < 0)
	{
		perror("recieve");
		exit(-1);
	}
	printf("recv from server:%s\n",buf);

	return 0;
}
