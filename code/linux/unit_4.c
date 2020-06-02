#include "zhaizy.h"
/***************************************************************
            			linux系统编程学习--2020/5/11
						系统调用函数学习            		
*****************************************************************/
int main(void)
{
	
	int fd;
	
	fd = open("./opes.c", O_RDONLY );	
	
	printf("fd = %d,errno=%d:%s\n", fd, errno , strerroe(errno));
	
	close(fd);	


	return 0;
}



