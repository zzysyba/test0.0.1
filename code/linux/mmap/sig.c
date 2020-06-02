#include "zhaizy.h"

/*=========================================
  sig.c
  2020年05月14日 星期四 15时49分58秒
  =========================================*/
void perr(char* str)
{
		perror(str);
		exit(1);
}

int main(int argc,char* argv [])
{
		pid_t pid;
		pid = fork();
		printf("bengin\n");
		if(pid < 0)
		{
				perr("fork error");
		}
		else if(pid == 0)
		{
			sleep(2);
			kill(getppid(),11);
		
		}
		else if(pid > 0)
		{
				int i = 1;
				printf("--%d--\n",i);
				sleep(5);
		}
		return 0;
}

