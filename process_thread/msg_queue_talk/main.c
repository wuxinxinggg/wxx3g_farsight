#include "my_type.h"

MSG data_snd,data_rcv;
char master_name[10];
int type=0;
pthread_mutex_t mutex;
pthread_t th_snd,th_rcv;
int msg_id;
int main(void)
{
    pthread_mutex_init(&mutex,NULL);
    puts("init mutex ok \n");
    msg_id=get_msg_id(); //get msg_id

    printf("msg_id = %d\n",msg_id);
    printf("input your nickname:\n");
    scanf("%s",master_name);
    pthread_create(&th_snd,NULL,msg_snd,NULL); //创建子线程
    pthread_create(&th_rcv,NULL,msg_rcv,NULL);
    pthread_join(th_snd,NULL);
    pthread_join(th_rcv,NULL);  //等待结束信号
    return 0;
}