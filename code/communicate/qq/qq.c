/*##############################
Author:zzy                  
Create_Time:2020-05-19
Versios:1.0
##############################*/
#include "zhaizy.h" 
#define SERVER_PORT 9527
#define MAXENT  1024


void perr(char* str) 
{
	perror(str);
	exit(1);
}

int main(int argc, char* argv[])
{
	char buf[BUFSIZ];
	char sbuf[BUFSIZ];
	char client_ip[1024];
	struct sockaddr_in laddr;
	struct sockaddr_in taddr;
	laddr.sin_family = AF_INET;
	laddr.sin_port = htons(SERVER_PORT);
	laddr.sin_addr.s_addr = htonl(INADDR_ANY);
	int tfd;
	int mark,sn,n;
	socklen_t taddrlen = sizeof(taddr);

	int lfd = socket(AF_INET,SOCK_STREAM,0);
	if(lfd == -1)
	{
		perr("socket error");
	}
	int ret = bind(lfd,(struct sockaddr*)&laddr,sizeof(laddr));
	if(ret != 0)
	{
		perr("bind error");
	}
	ret = listen(lfd,128);
	if(ret != 0)
	{
		perr("listen error");
	}
	
	int epfd = epoll_create(MAXENT);
	if(ret == -1)
	{
		perr("epoll_creat error");
	}
	struct epoll_event tep,ep[MAXENT];
	tep.events = EPOLLIN;
	tep.data.fd = lfd;
		
	ret = epoll_ctl(epfd, EPOLL_CTL_ADD, lfd, &tep);
	if( ret == -1)
	{
		perr("epoll_ctl lfd error");
	}
	tep.data.fd = 0;
	mark = epoll_ctl(epfd, EPOLL_CTL_ADD, 0, &tep);
	if(ret == -1 )
	{
		perr("epoll_ctl stdin error");
	}
	while(1)
	{
		ret = epoll_wait(epfd, ep, MAXENT, -1);
		if(ret == -1)
		{
			perr("epoll wait error");
		}
		for(int i = 0; i < ret; ++i)
		{
			if(ep[i].data.fd == lfd)
			{
				tfd = accept(lfd,(struct sockaddr*)&taddr,&taddrlen);
				if(tfd == -1)
				{
					perr("accpet tfd error");
				}
				tep.events = EPOLLIN;
				tep.data.fd = tfd;
				mark = epoll_ctl(epfd, EPOLL_CTL_ADD, tfd, &tep);
				if(mark == -1)
				{
					perr("epoll_ctl cfd error");
				}
				printf("communicate with ip: %s,port: %d\n",
						inet_ntop(AF_INET,&taddr.sin_addr.s_addr,
						client_ip,sizeof(client_ip)),
						ntohs(taddr.sin_port));
			}
			else if(ep[i].data.fd == 0)
			{
				sn = read(STDIN_FILENO,sbuf,BUFSIZ);
				write(tfd,sbuf,sn);
			}
			else
			{	
				n = read(ep[i].data.fd,buf,BUFSIZ);
				if( n == 0 | buf[0] == '\n')
				{
					mark = epoll_ctl(epfd, EPOLL_CTL_DEL, ep[i].data.fd,NULL);
					if(mark == -1)
					{
						perr("spoll_ctl del error");
					}
					close(ep[i].data.fd);
					printf("client ip: %s,port: %d close.\n",
							inet_ntop(AF_INET,&taddr.sin_addr.s_addr,
							client_ip,sizeof(client_ip)),
							ntohs(taddr.sin_port));
				}
				else
				{
					write(STDOUT_FILENO,buf , n);
				}
			}
		}
	}

		




	/*
	laddrlen = sizeof(laddr);
	int	tfd = accept(lfd,(struct sockaddr*)&taddr,&laddrlen);
	if(tfd == -1)
	{
		perr("accept error");
	}
	printf("client ip: %s,port number: %d\n",
	inet_ntop(AF_INET,&taddr.sin_addr.s_addr,
			  client_ip,sizeof(client_ip)),
			  ntohs(taddr.sin_port));
	while(1)
	{
		ret = read(tfd,buf,sizeof(buf));
		if(buf[0]=='\n')
			break;
		write(STDOUT_FILENO,buf,ret);
		for(int i = 0;i < ret;++i)
		{
			buf[i] = toupper(buf[i]);
		}
		write(tfd,buf,ret);
	}

	close(lfd);
	close(tfd);
*/


	return 0; 
}



