/*##############################
Author:zzy                  
Create_Time:2020-05-15
Versios:1.0
##############################*/
#include "zhaizy.h" 
 
void perr(char* str) 
{
		perror(str);
		exit(1);
}

void catch_child(int signo)
{
	pid_t pid;
	printf("---------");
	pid = wait(NULL);
	printf("cath child:%d\n",pid);
	
	return;
}


int main(int argc, char* argv[])
{
	pid_t pid = 1;
	int i = 0;
	for(i = 1;i < 5;++i )
	{
		if(pid != 0)
		{
			pid = fork();
		}
		else break;
	}
	if(pid < 0)
	{
		perr("fork error");
	}
	else if(pid > 0)
	{
		struct sigaction act;
		act.sa_handler = catch_child;
		sigemptyset(&act.sa_mask);
		act.sa_flags = 0;

		sigaction(SIGCHLD,&act,NULL);

		printf("parent %d\n",getpid());
		while(1);
	}
	else if(pid == 0)
	{
		sleep(6-i);
		printf("child %d\n",getpid());
	}
	return 0; 
}
 

