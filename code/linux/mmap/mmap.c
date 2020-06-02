#include "zhaizy.h"

/*=========================================
  mmap.c
  2020年05月13日 星期三 17时38分18秒
  =========================================*/
void perr(char* str)
{
		perror(str);
		exit(1);
}

int main(int argc,char* argv [])
{
		char* p;
		int fd;
		pid_t pid;

		fd = open("a.txt",O_RDWR | O_TRUNC | O_CREAT,0777);
		if(fd == -1)
		{
				perr("open file error");
		}
		ftruncate(fd,20);
		int len = lseek(fd,0,SEEK_END);
		printf("%d\n",len);
		p = mmap(NULL, len ,PROT_READ|PROT_WRITE ,MAP_SHARED ,fd,0 );
		if(p == MAP_FAILED)
		{
				perr("mmap error");
		}

		pid = fork();
		if(pid < 0)
		{
				perr("fork error");
		}
		else if(pid == 0)
		{	
				printf("-%s\n",p);
		}
		else if(pid > 0)
		{	
				strcpy(p,"hello mmap");
				wait(NULL);
				printf("in\n");
		}
		return 0;
}

