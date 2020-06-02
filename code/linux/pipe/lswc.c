#include "zhaizy.h"

/*========================================
//  lswc.c
// 2020年05月13日 星期三 09时57分22秒
========================================*/
void perr(char* str)
{
	printf("%s\n",str);
	exit(0);
}


int main(int argc,char* argv [])
{
	int ret;
	pid_t pid;
	int buf[1024];
	int fd[2];
	
	ret = pipe(fd);
	if(ret != 0)
	{
		perr("pipe error");
	}

	pid =fork();
	if(pid < 0)
	{
		perr("fork error");
	}
	else if(pid > 0)
	{
		close(fd[0]);
		dup2(fd[1],STDOUT_FILENO);
		execlp("ls","ls",NULL);
	}
	else if(pid == 0)
	{
		close(fd[1]);
		dup2(fd[0],STDIN_FILENO);
		execlp("wc","wc","-l",NULL);	
	}

	return 0;
}
 
