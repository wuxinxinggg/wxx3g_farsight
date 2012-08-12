#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <signal.h>

#define N 128
#define TYPE_SRV 10
#define SIZE 512
#define MSG_LEN (sizeof(struct msgbuf) - sizeof(long)) //正文长度

typedef struct msgbuf
{
	long mtype; //消息类型
	long subtype; //消息子类型
	char alias_name[N]; //用户网名
	pid_t pid; //用户进程号
	char mtext[SIZE]; //正文
}msg;

enum subtype_list
{
	REGISTER = 0, //注册
	ONLINE, //上线
	OFFLINE, //下线
	PUBLIC_TALK, //群聊
	PERSONAL_TALK, //私聊
}st_list;

typedef struct node
{
	pid_t data; //保存用户进程
	struct node *next;
}linknode,*linklist;

//function declartion

void creat_linklist(linklist *h);
int insert(linklist h,pid_t pid);
void broadcast(linklist h,int msgid,struct msgbuf *msg);
int Length(linklist h);
