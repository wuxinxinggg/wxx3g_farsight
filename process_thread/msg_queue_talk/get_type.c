#include "my_type.h"
// get type

/*   获得消息队列描述，如果是首次加入信息队列，则等待下一个节点加入，并记录其节点号 */
int get_msg_id(void)
{
    int id_tmp;
    int status=0;
    MSG    tmp;
    key_t key;
    if( (key=ftok(".",0xff))==-1 )  //
    {
        perror("ftok error");
        exit(1);
    }
    if( (id_tmp=msgget(key,IPC_CREAT|0666))==-1 ) //创建消息队列
    {
        perror("msgget error");
        exit(1);
    }
    else
    {
        printf("id_tmp = %d \n",id_tmp);
        if(msgrcv(id_tmp,&tmp,sizeof(MSG),10,IPC_NOWAIT)==-1)//获取消息队列信息，该信息存储在节点号为10的节点，tmp.m_data.type 为消息队列中总的节点数
        {
            type=1;
            tmp.mtype=10;
            tmp.m_data.type=type;
            msgsnd(id_tmp,&tmp,sizeof(MSG),0);//获得总节点数后在存储10号节点
            printf("wait in: \n");
            while( (pthread_mutex_lock(&mutex)) && ( msgrcv(id_tmp,&tmp,sizeof(MSG),10,0)!=-1 ) && ( tmp.m_data.type==1 ) )
            { //如果只有一个节点，则等待第二个节点加入
                msgsnd(id_tmp,&tmp,sizeof(MSG),0);
                pthread_mutex_unlock(&mutex); 
                usleep(50);
                status=1;
            }
            if(status==1)//在while中，有一次加锁，while退出时，缺少一次解锁
                pthread_mutex_unlock(&mutex);
                
            printf("wait out : \n");
        }
        else
        {
            type=tmp.m_data.type+1;//获得总结点数，则自己节点号为总结点数加1，更新总结点数
            tmp.m_data.type=type;
            tmp.mtype=10;
            pthread_mutex_lock(&mutex);
            msgsnd(id_tmp,&tmp,sizeof(MSG),0);            
            pthread_mutex_unlock(&mutex);
        }
    }
    return id_tmp;
}
// msg send

void *msg_rcv(void *arg)
{    
    MSG tmp;
    int nail;
    data_snd.mtype=type;
    sleep(1);
    printf("type = %d \n",type);
    while(1)  //首节点，接受尾节点信息，判断是否为自己信息，否则输出，同时写入自己节点号，是则忽略。
    {
        pthread_mutex_lock(&mutex);
        msgrcv(msg_id,&tmp,sizeof(MSG),10,IPC_NOWAIT);
        nail=tmp.m_data.type;
        printf("nail:%d type: %d ",nail,type);
        msgsnd(msg_id,&tmp,sizeof(MSG),0);
        pthread_mutex_unlock(&mutex);
        if(type==1)
        {
            puts("type1 in \n");
            data_rcv.mtype=tmp.m_data.type;
            msgrcv(msg_id,&data_rcv,sizeof(MSG),nail,0);        
            puts("type1 out \n");
        }
        else //各节点操作流程为:读取前一个节点信息，判断是否自己发送，否，则输出显示，同时写入自己的节点处，是则忽略本次。信息呈环状流动，流动一圈后，停止。
        {
            msgrcv(msg_id,&data_rcv,sizeof(MSG),type-1,0);        
        }
        if(data_rcv.m_data.type!=type)
        {
            printf("[%s] : %s \n",data_rcv.m_data.name,data_rcv.m_data.msg);
            data_rcv.mtype=type;
            msgsnd(msg_id,&data_rcv,sizeof(MSG),0);
        }
    //    pthread_mutex_lock(&mutex);

    //    pthread_mutex_unlock(&mutex);

    }
    pthread_exit(0);
}
//msg receive

void *msg_snd(void *arg)
{
//    sleep(1);

//    pthread_mutex_lock(&mutex);
//发送数据
    while(1)
    {
    //    pthread_mutex_lock(&mutex);

        data_snd.mtype=type;
        data_snd.m_data.type=type;
        strcpy(data_snd.m_data.name,master_name);
        printf("%s say: ",master_name);
        scanf("%s",data_snd.m_data.msg);
        msgsnd(msg_id,&data_snd,sizeof(MSG),0);
    //    pthread_mutex_unlock(&mutex);

    //    pthread_mutex_unlock(&mutex);

    }
    pthread_exit(0);
}