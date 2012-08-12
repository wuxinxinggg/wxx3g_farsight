#include "../inc/msg_link.h"

void creat_linklist(linklist *h)
{
	*h = (linklist)malloc(sizeof(linknode)); 
	if(NULL == (*h))
	{
		perror("malloc");
		exit(1);
	}
	
	(*h)->next = NULL;
}

int insert(linklist h,pid_t pid)
{
	linklist p;
	p = (linklist)malloc(sizeof(linknode));
	if(NULL == p)
	{
		perror("malloc");
		exit(1);
	}
	p->data = pid;
	p->next = h->next;
	h->next = p;

	return 0;
}

void broadcast(linklist h,int msgid,struct msgbuf *msg)
{
	int i;
	for(i = 0;i < Length(h);i++)
	{
		msg->mtype = h->next->data;
		if(msg->mtype != msg->pid)
		{
			if(msgsnd(msgid,msg,MSG_LEN,0) < 0)
			{
				perror("msgsnd");
				exit(-1);
			}

		}
		
	}
}

int Length(linklist h)
{
	int n = 0;
	h = h->next;
	while(h)
	{
		h = h->next;
		n++;
	}

	return n;
}
#if 0
pid_t getvalue(linklist h,pid_t i)
{
	int j;

	while(h->next && j < i)
	{
		h = h->next;
		j++;
	}

	return h->data;
}
#endif
