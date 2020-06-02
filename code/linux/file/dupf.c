#include "zhaizy.h"


int main(int argc,char* argv[])
{
	int fd1 = open(argv[1],O_RDWR);
	int fd2 = open(argv[2],O_RDWR);

	int fdret = dup2(fd1, fd2);
	printf("fdret:%d\n",fdret);
	
	char buf[40];
	read(fd2,buf,5);

	printf("buf:%c\n",*buf);

	write(fd2,"123456",7);	
	

	return 0;

}
