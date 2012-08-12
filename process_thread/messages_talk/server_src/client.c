#include "../inc/msg_link.h"

int main(int argc,char *argv[])
{
	key_t key;
	int msgid;
	pid_t pid;
	struct msgbuf msg;
	int TYPE_ME;

	if(argc < 2)
	{
		printf("Usage:%s your_name\n",argv[0]);
		exit(-1);
	}

	TYPE_ME = getpid();

	 //生成key
	if((key = ftok(".",'s')) < 0)
	{
		perror("ftok_client");
		exit(-1);
	}
	
	//打开服务器创建的消息队列
	if((msgid = msgget(key,0666)) < 0)
	{
		printf("the server is not exist\n");
		exit(-1);
	}

	//每次启动客户端首先注册
	msg.mtype = TYPE_SRV;
	msg.subtype = REGISTER;
	msg.pid = getpid();
	strcpy(msg.alias_name,argv[1]);
	msgsnd(msgid,&msg,MSG_LEN,0);

	//客户端双进程实现读和写操作
	if((pid = fork()) < 0)
	{
		perror("fork");
		exit(-1);
	}

	else if(pid == 0)
	{
		msgrcv(msgid,&msg,MSG_LEN,TYPE_ME,0);
		//如果收到退出指令，通知父进程然后自己退出
		if(strncmp(msg.mtext,"quit",4) == 0)
		{
			printf("the server will quit in three second\n");
			kill(getppid(),SIGUSR1);
			exit(0);
		}
		if(strncmp(msg.mtext,"exit",4) == 0)
		{
			msg.subtype = OFFLINE;
		}

		switch(msg.subtype)
		{
			case ONLINE:
				printf("[%s] On Line\n",msg.alias_name);
				break;
			
			case OFFLINE:
				printf("[%s] Off Line\n",msg.alias_name);
				break;
			
			case PUBLIC_TALK:
				printf("[%s]\n",msg.alias_name);
				printf("[%s]\n",msg.mtext);
				break;

			case PERSONAL_TALK:
				break;

			default:
				break;
		}
	}
	else
	{
		msg.mtype = TYPE_SRV;
		msg.subtype = PUBLIC_TALK;
		while(1)
		{
			printf("[%s]\n",msg.alias_name);
			fgets(msg.mtext,MSG_LEN,stdin);
			msgsnd(msgid,&msg,MSG_LEN,0);
			if(strncmp(msg.mtext,"exit",4) == 0)
			{
				msg.subtype = OFFLINE;
				msgsnd(msgid,&msg,MSG_LEN,0);
				sleep(0);
				exit(0);
			}
		}
	}

	return 0;
}

