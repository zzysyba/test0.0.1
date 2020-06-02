#include "zhaizy.h"

int main(int argc,char* argv[])
{
	pid_t pid = fork();

	if(pid < 0)
	{
		perror("fork error\n");
		exit(1);
	
	}
	else if(pid == 0)
	{
		execl("./a.out", "./a.out" , NULL);
		perror("exec error");
		exit(1);
	}
	else
	{	
		sleep(1);
		printf("im parent\n");
	}
	
	
	return 0;
}

