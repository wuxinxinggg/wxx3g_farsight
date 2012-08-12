#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

struct msgbuf
		{
			long mtype; //消息类型
			char mtext[100]; //消息正文
		};

int main()
{
	FILE *fp;
	key_t key;
	pid_t pid;
	int msgid; //队列ID
	struct msgbuf msg1,msg2;
	char wbuf[800]="",my_name[20]="",others_name[20]="";
	key=ftok(".",0xFF);
	if((msgid=msgget(key,IPC_CREAT|0666))<0)
		{
				//创建队列
				perror("msgger error");
				exit(0);	
		}
		printf("plese input you name:");
		msg1.mtype=4;     //消息类型为3,此消息接受对方的姓名
		memset(msg1.mtext,0,100);// 设置缓冲区的内容
		fgets(wbuf,100,stdin);//将标准输入到wbuf缓冲区
		wbuf[strlen(wbuf)-1]='\0';
		strcpy(msg1.mtext,wbuf);
		strcpy(my_name,wbuf);
		
		msgsnd(msgid,&msg1,sizeof(msg1.mtext),0);
		msgrcv(msgid,&msg2,100,3,0);

		strcpy(others_name,msg2.mtext);
		fflush(stdout);
		if((pid=fork())<0)
		{
			printf("erro");
			exit(0);

		}
		if(pid==0)
		{
				while(1)
					{
						msgrcv(msgid,&msg2,100,1,0);
						if((fp=fopen("data.txt","a+"))==NULL)
							{
								perror("打开失败记录");
								return 0;
							}	
				fprintf(fp,"%s:%s\n",others_name,msg2.mtext);
				fclose(fp);
				printf("\r%s:%s\n%s:",others_name,msg2.mtext,my_name);
				fflush(stdout);
					}


		}else
				{
					while(1)
							{

								msg1.mtype=2;
								memset(msg1.mtext,0,100);//刷新
								printf("%s:",my_name);
								fgets(wbuf,100,stdin);
								wbuf[strlen(wbuf)-1]='\0';
								strcpy(msg1.mtext,wbuf);
								msgsnd(msgid,&msg1,sizeof(msg1.mtext),0);
							}
				}				
}
