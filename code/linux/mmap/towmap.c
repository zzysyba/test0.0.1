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
	fd = open("a.txt",O_RDWR | O_TRUNC | O_CREAT, 0777);
	if(fd == -1)
	{
		perr("open file error");
	}
	ftruncate(fd,10);
	int	len = lseek(fd,0,SEEK_END);
	p = mmap(NULL, len ,PROT_READ|PROT_WRITE ,MAP_SHARED ,fd,0 );
	
	if(p == MAP_FAILED)
	{
		perr("mmap error");
	}
	for(int i = 0;1;++i)
	{
		printf("-%s\n",p);
		sleep(2);
	}
	return 0;
}
 
