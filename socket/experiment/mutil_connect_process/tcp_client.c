#include "inc.h"

int main(void)
{
	int sc; 
	
	if((sc = socket(AF_INET,SOCK_STREAM,0)) < 0)
	{
		perror("socket");
		exit(-1);
	}

	struct sockaddr_in serveraddr;

	bzero(&serveraddr,sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(PORT);
	//serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
	serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	if(connect(sc,(struct sockaddr *)&serveraddr,sizeof(serveraddr)) < 0)
	{
		perror("connect");
		exit(-1);
	}
	process_conn_client(sc);
	close(sc);

	return 0;
}
