/*
*用消息队列实现的简单聊天室程序(client)
*实现的功能：
*1。上线提醒
*2。下线提醒
*3。服务器断线后子进程都退出
* */
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define _DEBUG_
#define TYPE_SRV 10 //send 10是server的消息类
#define N 128

struct msgbuf{
    long mtype;
    int subtype;    //1->register 2->broadcast 3->unregister
    int pid;
    char nick_name[N];
    char mtext[N];
};

//定义消息正文大小的宏
#define MSG_LEN (sizeof(struct msgbuf) - sizeof(long))

int main(int argc,char *argv[])
{
    key_t key;
    int msgid;
    pid_t pid;
    int TYPE_ME;    //由getpid()来指定唯一该进程才有的mtype
    struct msgbuf msg;

    TYPE_ME = getpid(); //用自己进程的进程号作为自己收消息的消息类型
    //argv[1]用于接收昵称
    if(argc < 2){
        printf("Usage:%s <nick_name>\n",argv[0]);
        exit(-1);
    }

    //生成消息队列的key
    if((key = ftok("./",'s')) < 0){
        perror("ftok error.");
        exit(-1);
    }
   
    //如果服务器已创建消息队列才可打开，客户端无权创建
    if((msgid = msgget(key,0666)) < 0){
        printf("[server maybe not on line...]\n");
        exit(-1);
    }
    //每启动一个客户端要先实现一个注册操作
    msg.mtype = TYPE_SRV;  
    msg.subtype = 1;
    msg.pid = getpid();
    strcpy(msg.nick_name,argv[1]);
    msgsnd(msgid,&msg,MSG_LEN,0);   //MSG_LEN是消息正文大小
       
    //客户端双进程实现读和写操作
    if((pid = fork()) < 0){
        perror("fork error.");
        exit(-1);
    }
    else if(pid == 0){ //子进程专门负责读消息
        while(1)
        {
            //msgid为消息队列的队列ID
            //&msg为消息类型为TYPE_ME的消息缓冲区首地址
            //0指定了阻塞式等待
            msgrcv(msgid,&msg,MSG_LEN,TYPE_ME,0);
           
            //判断接收到的消息是否为quit
            if(strncmp(msg.mtext,"quit",4) == 0){
                printf("[server will close in 3 seconds...]\n");
                kill(getppid(),SIGUSR1);//若收到quit通知父进程并自己退出
                exit(0);
            }

            if(strncmp(msg.mtext,"exit",4) == 0){
                msg.subtype = 3;
            }
               
            //写成switch方便以后扩展
            switch(msg.subtype)
            {
            case 1 :
                printf("[%s on line]\n",msg.nick_name);
                break;

            case 2 :
                printf("[%s]\n",msg.nick_name);
                printf("%s",msg.mtext);
                break;

            case 3 :
                printf("[%s off line]",msg.nick_name);
                break;

            default :
                break;
            }
        }
    }
    else{   //父进程专门负责写消息
        msg.mtype = TYPE_SRV;   //设定服务器的发送类型
        msg.subtype = 2;    //设为广播模式
        while(1)
        {
            printf("[%s]\n",msg.nick_name);
            fgets(msg.mtext,N,stdin);
            msgsnd(msgid,&msg,MSG_LEN,0);
            //当此进程输入exit时，表示该进程退出聊天
            //由服务器通知其他进程，该进程已下线   
            if(strncmp(msg.mtext,"exit",4) == 0){
                msg.subtype = 3;
                msgsnd(msgid,&msg,MSG_LEN,0);
                sleep(1);
                kill(pid,SIGKILL);
                exit(0);
            }
        }
    }

    return 0;
}
