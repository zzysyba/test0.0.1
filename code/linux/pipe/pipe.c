#include "zhaizy.h"

void str_err(char* str)
{
	printf("%s\n",str);
	exit(1);
	
}


int main(int argc, char* argv[])
{
	
	int ret;
	int fd[2];
	pid_t pid;
	char* str = "this is parent give\n";
	char buf[1024];
	
	ret = pipe(fd);
	if(ret != 0)
	{
		str_err("pipe error");
	}
	
	pid = fork();
	if(pid > 0)
	{
		close(fd[0]);
		write(fd[1],str,strlen(str));
		close(fd[1]);

	}
	if(pid == 0)
	{
		close(fd[1]);
		ret = read(fd[0],buf,sizeof(buf));
		close(fd[0]);
		write(STDOUT_FILENO,buf,ret);
	}	

	return 0;
}


