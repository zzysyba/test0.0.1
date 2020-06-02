#include "zhaizy.h"

/*=========================================
        bother.c
 2020年05月13日 星期三 10时24分17秒
=========================================*/

void perr(char* str)
{
	printf("%s\n",str);
	exit(0);
}

int main(int argc,char* argv [])
{
	int ret;
	char buf[1024];
	int fd[2];
	pid_t pid;

	ret = pipe(fd);
	if(ret != 0)
	{
		perr("pipe error");
	}
	
	pid = 1;
	int i;
	for(i = 0;i < 2;++i)
	{
		if(pid > 0)
		{
		 	pid = fork();
			if(pid< 0 )
			{
				perr("fork error");
			}
			else if(pid == 0 )
			{
				break;
			}
		}
	}
	if(pid == 0 && i == 0)
	{
		close(fd[0]);
		dup2(fd[1],STDOUT_FILENO);
		execlp("ls","ls",NULL);
	}
	else if(pid == 0 && i == 1)
	{
		close(fd[1]);
		dup2(fd[0],STDIN_FILENO);
		execlp("wc","wc","-l",NULL);
	}
	else if(pid > 0)
	{
		close(fd[0]);
		close(fd[1]);
		int ki = wait(NULL);
		ki = wait(NULL);

	}

	return 0;
}
 
