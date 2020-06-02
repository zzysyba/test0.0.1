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
	bufferevent_read(bev, buf, sizeof(buf));

	printf("client say: %s\n",buf);
	
	char *p = "read done\nspeak next:\n";
	bufferevent_write(bev, p, strlen(p) + 1);


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

 
void cb_listener(struct evconnlistener* listener,
				evutil_socket_t fd,
				struct sockaddr* addr,
				int len, void *ptr)
{
	struct event_base* base = (struct event_base*)ptr;
	//3.监听到事件后建立连接，设置属性位关闭时释放底层套接字
	struct bufferevent* bev;
	bev = bufferevent_socket_new(base, fd, BEV_OPT_CLOSE_ON_FREE);
	//4.建立链接后，设置读监听，写监听的回调和事件异常的回调
	bufferevent_setcb(bev, read_cb,write_cb, event_cb,NULL);
	//5.设置回调函数使能，默认位read：EV_ENABLE
	bufferevent_enable(bev, EV_READ);	

}				




int main(int argc, char* argv[])
{
 	struct sockaddr_in serv;
 	//ser的ip和port结构体
 	memset(&serv, 0, sizeof(serv));
 	serv.sin_family = AF_INET;
 	serv.sin_port = htons(9527);
 	serv.sin_addr.s_addr = htonl(INADDR_ANY);
 	//1.创建基座base
 	struct event_base* base;
 	base = event_base_new();
 	//2创建监听listener，和回调函数cb_listener
 	struct evconnlistener* listener;
 	listener = evconnlistener_new_bind(base, cb_listener, base, 
 										LEV_OPT_CLOSE_ON_FREE | LEV_OPT_REUSEABLE,
 										-1, (struct sockaddr*)&serv, sizeof(serv));
 	//6.循环监听，阻塞等
 	event_base_dispatch(base);
 	//7.回收资源
 	evconnlistener_free(listener);
 	event_base_free(base);

 	return 0;

}
 

