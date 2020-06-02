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

void write_fifo(evutil_socket_t fd ,short what, void* arg)
{
	char buf[BUFSIZ];
	int len = read(STDIN_FILENO,buf,BUFSIZ);
	write(fd, buf, len);
	sleep(1);

}


int main(int argc, char* argv[])
{
	int fd = open("myfifo",O_RDWR|O_NONBLOCK);
	if(fd == -1)
	{
		perr("open error");
	}

	struct event_base* base = event_base_new();
	
	struct event* ev = event_new(base, fd, EV_READ|EV_PERSIST, write_fifo, NULL  );
	
	int	ret = event_add(ev,NULL);
	if(ret == -1)
	{
		perr("event add error");
	}
	
	event_base_dispatch(base);
	
	event_free(ev);

	return 0; 
}
 

