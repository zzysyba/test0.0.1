#include "zhaizy.h"

int main(int argc,char* argv[])
{
	pid_t pid =-1;
	printf("--1\n");
	for(int i = 0;i < 5;++i)
	{	
		if(pid != 0)
		{
			pid = fork();
		}

	if(pid < 0)
	{
		perror("fork error\n");
		exit(1);
	}
	else if(pid == 0)
	{
	}
	else if (pid > 0)
	{
	}
	}
	printf("my pid:%d\t,my ppid:%d\n",getpid(),getppid());
	
	return 0;
}

