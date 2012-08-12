#include "../inc/msg_link.h"

int main(void)
{
	pid_t pid;
	key_t key;
	struct msgbuf msg;
	int msgid;

	//生成key
	if((key = ftok(".",'s')) < -1)	
	{
		perror("ftok");
		exit(-1);
	}

	if((msgid = msgget(key,IPC_CREAT|0666)) < 0)
	{
		perror("msgget");
		exit(-1);
	}

	if((pid = fork()) < 0)
	{
		perror("fork");
		exit(-1);
	}

	else if(pid == 0) //子进程实现消息转发
	{
		linklist h;
		creat_linklist(&h); //创建链表

		while(1)		
		{
			if(msgrcv(msgid,&msg,MSG_LEN,TYPE_SRV,0) < 0) //msgrcv最后一个参数表示无消息时函数一直阻塞
			{
				perror("msgrcv CHILD");
				exit(-1);
			}

			switch(msg.subtype)
			{
				case REGISTER:
					if(insert(h,msg.pid) != 0)	
					{
						printf("insert to link failed,register failed\n");
						exit(1);
					}
					printf("%s has registered successfully\n",msg.alias_name);
					broadcast(h,msgid,&msg);
					break;
				default:
					break;

			}

		}
	}
	else //父进程用于服务器控制台
	{
		msg.mtype = TYPE_SRV;
		msg.subtype = PUBLIC_TALK;
		while(1)
		{
			printf("[server:]\n");
			fgets(msg.mtext,512,stdin);
			if(strncmp(msg.mtext,"quit",4) == 0)
			{
				msgsnd(msgid,&msg,MSG_LEN,0);
				sleep(2);
				msgctl(msgid,IPC_RMID,NULL);
				kill(pid,SIGKILL);//给pid为pid的进程发退出信号
				exit(0);
			}
		}
	}

	return 0;
}
