/*##############################
Author:zzy                  
Create_Time:2020-05-23
Versios:1.0
##############################*/
#include "zhaizy.h" 
 
void perr(char* str) 
{
		perror(str);
		exit(1);
}

void read_fifo(evutil_socket_t fd ,short what, void* arg)
{
	char buf[BUFSIZ];
	int len = read(fd,buf,BUFSIZ);
	write(STDOUT_FILENO, buf, len);
	sleep(1);

}


int main(int argc, char* argv[])
{
	int ret = mkfifo("myfifo", 0664);
	if(ret == -1)
	{
		perr("mkfifo error");
	}
	int fd = open("myfifo",O_RDONLY|O_NONBLOCK);
	if(fd == -1)
	{
		perr("open error");
	}
	struct event_base* base = event_base_new();
	struct event* ev = event_new(base, fd, EV_READ|EV_PERSIST, read_fifo, NULL  );
	ret = event_add(ev,NULL);
	if(ret == -1)
	{
		perr("event add error");
	}
	event_base_dispatch(base);
	event_free(ev);


	return 0; 
}
 

