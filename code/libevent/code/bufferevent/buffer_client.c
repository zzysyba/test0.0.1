/*##############################
Author:zzy                  
Create_Time:2020-05-25
Versios:1.0
##############################*/
#include "zhaizy.h" 
 
void perr(char* str) 
{
		perror(str);
		exit(1);
}

void read_cb (struct bufferevent *bev, void *arg)
{
	char buf[BUFSIZ] = {0};
	int n = bufferevent_read(STDIN_FILENO, buf, BUFSIZ);
	
	char *p = "read done\nspeak next:\n";
	bufferevent_write(bev, buf, n);


}

void write_cb(struct bufferevent *bev, void *arg)
{
	printf("write done\n");
}


void event_cb(struct bufferevent *bev, short events, void *arg)
{
	if(events & BEV_EVENT_EOF)
	{
		printf("close\n");
	}
	else if (events & BEV_EVENT_ERROR)
	{
		printf("error\n");
	}

	bufferevent_free(bev);

	printf("free\n");
}


void read_terminal(evutil_socket fd, short what, void* arg)
{
	char rbuf[BUFSIZ] = {0};
	int n = read(fd, rbuf, BUFSIZ);
	
	struct bufferevent* bev = (struct bufferevent*)arg;

	bufferevent_write(bev, rbuf, n+1);

}



int main(int argc, char* argv[])
{	
	//1.创建基座base
 	struct event_base* base = NULL;
 	base = event_base_new();
 	//2.创建套接字
 	int fd = socket(AF_INET, SOCK_STREAM, 0);
 	//3.创建buffer socket
 	struct bufferevent* bev = NULL;
 	bev = bufferevent_socket_new(base, fd, BEV_OPT_CLOSE_ON_FREE);

 	struct sockaddr_in serv;
 	//ser的ip和port结构体
 	memset(&serv, 0, sizeof(serv));
 	serv.sin_family = AF_INET;
 	serv.sin_port = htons(9527);
 	inet_pton(AF_INET, "127.0.0.1", &serv.sin_addr.s_addr);

 	//4。建立链接
 	bufferevent_socket_connect(bev, (struct sockaddr*)&serv,sizeof(serv));
 	//5.建立链接后，设置读监听，写监听的回调和事件异常的回调
 	bufferevent_setcb(bev, read_cb, write_cb, event_cb, NULL);
	//6.设置回调函数使能，默认位read：EV_ENABLE
 	bufferevent_enable(bev, EV_READ);

 	struct event* ev = event_new(base, STDIN_FILENO,
 							 EV_READ|EV_PERSIST, read_terminal, bev);
 	//添加事件
 	event_add(ev,NULL);
 	//循环监听
 	event_base_dispatch(base);

 	event_free(ev);
 	event_base_free(base);

	return 0; 
}
 


