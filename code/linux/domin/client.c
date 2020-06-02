/*##############################
Author:zzy                  
Create_Time:2020-05-23
Versios:1.0
##############################*/
#include "zhaizy.h" 
#define	SERV_ADDR "serv.socket" 
#define CLIE_ADDR "clie.socket"

void perr(char* str) 
{
		perror(str);
		exit(1);
}
 
int main(int argc, char* argv[])
{
	int lfd, cfd, len, size, i;
	struct sockaddr_un servaddr;
	struct sockaddr_un cliaddr;
	char buf[BUFSIZ];
	
	cfd = socket(AF_UNIX,SOCK_STREAM, 0);

	/*************************************/
	bzero(&cliaddr,sizeof(cliaddr));
	servaddr.sun_family = AF_UNIX;
	strcpy(cliaddr.sun_path,CLIE_ADDR);

	len = offsetof(struct sockaddr_un,sun_path) + strlen(cliaddr.sun_path);
	
	unlink(CLIE_ADDR);
	bind(cfd,(struct sockaddr_un *)&cliaddr, len );
    /************************************/
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sun_family = AF_UNIX;
	strcpy(servaddr.sun_path,SERV_ADDR);

	len = offsetof(struct sockaddr_un,sun_path) + strlen(servaddr.sun_path);
	
	connect(cfd, (struct sockaddr*)&servaddr,len );
	/*************************************/
	while(fgets(buf,sizeof(buf),stdin) != NULL )
	{	
		write(cfd,buf, strlen(buf));
		len = read(cfd, buf,BUFSIZ);
		write(STDOUT_FILENO,buf, len);
		printf("client bind filename %s\n",cliaddr.sun_path);
	}
		close(cfd);
		
		
 
	return 0; 
}
 

