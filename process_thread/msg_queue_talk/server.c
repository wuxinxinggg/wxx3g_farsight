#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>         
//以上为程序所必须的头文件
struct msgbuf         
		{
			long mtype; //消息类型
			char mtext[100]; //消息正文
		};
//定义一个结构体msgbuf用来存放消息的类型和消息的正文
int main(void)
{
	FILE *fp;               //定义文件变量指针
	key_t key;               
	pid_t pid;
	int msgid;            //队列ID号
	struct msgbuf msg1,msg2;      //定义两个结构体变量
	char wbuf[800]="",my_name[20]="",others_name[20]="";  
   // 消息内容，本地名字，对方名字
	key=ftok(".",0xFF);        //调用ftok函数，产生标准的key
	if((msgid=msgget(key,IPC_CREAT|0666))<0)  
     //调用msgget函数，创建和打开消息队列
	{
			perror("msgger error");
	     	exit(0);	
	}
		printf("plese input you name:");
		msg1.mtype=3;     //消息类型为3,此消息接受让对方对方接受的对应的消息类型的姓名
		memset(msg1.mtext,0,100);// 设置缓冲区的内容
		fgets(wbuf,100,stdin);//将标准输入到wbuf缓冲区
		wbuf[strlen(wbuf)-1]='\0';
		strcpy(my_name,wbuf);//把wbuf里的内容复制到my_name

		strcpy(msg1.mtext,wbuf);//
		msgsnd(msgid,&msg1,sizeof(msg1.mtext),0);//把消息添加到消息队列中
		msgrcv(msgid,&msg2,100,4,0);//根据消息队列的消息类型接受对方的消息对方的姓名

		strcpy(others_name,msg2.mtext);//根据上面获得的数据把对方的的名字存储到others_name，存储是根据消息号存储
		fflush(stdout);
	if((pid=fork())<0)//创建一个子进程
	{
		printf("erro");
		exit(0);

	}
	if(pid==0)
	{

		while(1)
			{

					msg1.mtype=1;
					memset(msg1.mtext,0,100);//刷新
					printf("%s:",my_name);
					fgets(wbuf,100,stdin);
					wbuf[strlen(wbuf)-1]='\0';
					strcpy(msg1.mtext,wbuf);
					msgsnd(msgid,&msg1,sizeof(msg1.mtext),0);

			}				

	}else
	{
				while(1)
			{
					msgrcv(msgid,&msg2,100,2,0);
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

	}

	return 0;
}

