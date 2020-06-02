#include "zhaizy.h"

#define SERV_PORT 9527

struct s_info {     
    struct sockaddr_in cliaddr;
    int connfd;
};

int main(void)
{
    struct sockaddr_in servaddr, cliaddr;
    socklen_t cliaddr_len;
    int listenfd, connfd;
    struct s_info ts[256];     
    int i = 0;

    listenfd = Socket(AF_INET, SOCK_STREAM, 0);         
    bzero(&servaddr, sizeof(servaddr));         
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);       
    servaddr.sin_port = htons(SERV_PORT);           
    Bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)); 
    Listen(listenfd, 128);
    printf("Accepting client connect ...\n");

	fd_set rset,allset;
	int ret;
	int ter, maxfd = 0;
	maxfd = listenfd;
	char buf[BUFSIZ];
    char str[INET_ADDRSTRLEN];

	FD_ZERO(&allset);
	FD_SET(listenfd, &allset);
	while(1)
	{
		rset = allset;
		cliaddr_len = sizeof(cliaddr);
		ret = select(maxfd + 1,&rset,NULL,NULL,NULL);
		if(ret < 0)
		{
			perr_exit("select error");
		}
		if(FD_ISSET(listenfd,&rset))
		{
			connfd = Accept(listenfd,(struct sockaddr *)&cliaddr,&cliaddr_len);
			FD_SET(connfd,&allset);
			if(maxfd < connfd)
			{
				maxfd = connfd;
			}
			if(ret = 1)
			{
				continue;
			}

		}
		for(i = listenfd + 1; i <= maxfd; i++)
		{
			if(FD_ISSET(i,&rset))
			{
				ret = Read(i,buf,BUFSIZ);
				if(ret > 1)
				{
					printf("received from %s at PORT %d\n",
						    inet_ntop(AF_INET, &cliaddr.sin_addr, str,sizeof(str)),ntohs(cliaddr.sin_port));
				}
				if(buf[1] == '\n')
				{
					Close(i);
					FD_CLR(i,&allset);
					break;
				}
				for(int j = 0;j < ret;j++ )
				{
					buf[j] = toupper(buf[j]);
				}
				Write(STDOUT_FILENO,buf,ret);
				Write(i, buf ,ret);
			}
		
		}

	}

    return 0;
}

