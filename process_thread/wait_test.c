#include "wxx3g.h"

int main(void)
{
	pid_t pid;
	pid = fork();

	if(pid == 0)
	{
		tprintf("hello from the child process!\n");
		tprintf("the child is exiting now.\n");
	}
	else if(pid != -1)
	{
		tprintf("hello from parent,pid %d\n",getpid());
		tprintf("The parent has forked process %d \n",pid);
		waitpid(pid,NULL,0);
		tprintf("the child has stopped.Sleeping for 60 seconds.\n");
		sleep(60);
		tprintf("the parent is exiting now.\n");
	}
	else 
	{
		tprintf("There was an error with forking.\n");
	}
	
	return 0;
}
