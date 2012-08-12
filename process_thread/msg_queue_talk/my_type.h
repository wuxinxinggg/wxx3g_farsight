#ifndef __msg__
#define __msg__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>
#include <sys/stat.h>

struct msg_tmp
{
    int type;
    char name[10];
    char msg[40];
};
typedef struct msgbuf
{
    long mtype;
    struct msg_tmp m_data;    
}MSG; 

extern int type;
extern pthread_t th_snd,th_rcv; 
extern char master_name[10];  //用户名
extern MSG data_snd,data_rcv;  //接受数据结构 发送数据结构
extern pthread_mutex_t mutex;   //互斥锁
extern int msg_id;

extern int get_msg_id(void);
extern void *msg_snd(void *arg);    //发送信息
extern void *msg_rcv(void *arg);    //接受信息

#endif