#include "zhaizy.h"

int main(int argc, char* argv[])
{
	int fd = open("out.txt",O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if(fd == -1)
	{
		perror("open error");
		exit(1);
	}

	dup2(fd,STDOUT_FILENO);
	execlp("ps","ps","aux",NULL);
	return 0;
}




