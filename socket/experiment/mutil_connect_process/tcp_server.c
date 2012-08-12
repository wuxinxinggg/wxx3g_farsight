#include "inc.h"

int main(void)
{
	int ss,sc; //ss为和客户端建立连接之前服务器的描述符，sc为accept之后的文件描述符
	pid_t pid;

	if((ss = socket(AF_INET,SOCK_STREAM,0)) < 0)
	{
		perror("ss socket");
		exit(-1);
	}

	struct sockaddr_in server_addr;
	struct sockaddr_in client_addr;

	memset(&server_addr,0,sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(PORT);
//	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

	if(bind(ss,(struct sockaddr *)&server_addr,sizeof(server_addr)) < 0)
	{
		perror("bind ss");
		exit(-1);
	}

	if(listen(ss,5) < 0)
	{
		perror("listen");
		exit(-1);
	}
	
	while(1)
	{
		int clilen = sizeof(client_addr);
		if((sc = accept(ss,(struct sockaddr *)&client_addr,&clilen)) < 0)
		{
			perror("accept sc");
			continue;
		}

		pid = fork();
		if(-1 == pid)
		{
			perror("fork");
			exit(-1);
		}
		
		else if(0 == pid )
		{
			close(ss);//在子进程中关闭服务器的侦听
			process_conn_server(sc); //处理连接
		}
		else
		{
			close(sc); //父进程中关闭客户端的连接
		}


	}

	return 0;
}
