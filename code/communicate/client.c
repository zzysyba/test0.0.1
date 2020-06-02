/*##############################
Author:zzy                  
Create_Time:2020-05-19
Versios:1.0
##############################*/
#include "zhaizy.h" 
#define SERVER_PORT 9527
void perr(char* str) 
{
	perror(str);
	exit(1);
}

int main(int argc, char* argv[])
{
	char buf[BUFSIZ];
	char client_ip[1024];
	struct sockaddr_in laddr;
	struct sockaddr_in taddr;
	laddr.sin_family = AF_INET;
	laddr.sin_port = htons(SERVER_PORT);
	laddr.sin_addr.s_addr = htonl(INADDR_ANY);
	socklen_t laddr_len;

	int lfd = socket(AF_INET,SOCK_STREAM,0);
	if(lfd == -1)
	{
		perr("socket error");
	}
	laddr_len = sizeof(laddr);
	int ret = connect(lfd,(struct sockaddr*)&laddr,laddr_len);
	if(ret != 0)
	{
		perr("connect error");
	}
	printf(" communicate with ip:%d,port:%d\n",INADDR_ANY,SERVER_PORT);	
	while(1){
		ret = read(STDIN_FILENO,buf,BUFSIZ);
		write(lfd,buf,ret);
		if(buf[0]=='\n')
			break;
		ret = read(lfd,buf,sizeof(buf));
		write(STDOUT_FILENO,buf,ret);
	

	}


/*	int ret = bind(lfd,(struct sockaddr*)&laddr,sizeof(laddr));
	if(ret != 0)
	{
		perr("bind error");
	}
	ret = listen(lfd,128);
	if(ret != 0)
	{
		perr("listen error");
	}
	laddrlen = sizeof(laddr);
	int	tfd = accept(lfd,(struct sockaddr*)&taddr,&laddrlen);
	if(tfd == -1)
	{
		perr("accept error");
	}
	for(int j = 0; j < 5;++j)
	{
		ret = read(tfd,buf,sizeof(buf));
		write(STDOUT_FILENO,buf,ret);
		for(int i = 0;i < ret;++i)
		{
			buf[i] = toupper(buf[i]);
		}
		write(tfd,buf,ret);
	}
*/
	close(lfd);
//	close(tfd);
	return 0; 
}



