/*##############################
Author:zzy                  
Create_Time:2020-05-23
Versios:1.0
##############################*/
#include "zhaizy.h" 
#define	SERV_ADDR "serv.socket" 


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
	
	lfd = socket(AF_UNIX,SOCK_STREAM, 0);

	bzero(&servaddr,sizeof(servaddr));
	servaddr.sun_family = AF_UNIX;
	strcpy(servaddr.sun_path,"srv_socket");

	len = offsetof(struct sockaddr_un,sun_path) + strlen("srv_socket");
	unlink(SERV_ADDR);
	bind(lfd,(struct sockaddr_un *)&cliaddr, len );
	
	listen(lfd,20);

	while(1)
	{
		len = sizeof(cliaddr);

		cfd = accept(lfd,(struct sockaddr_un *)&cliaddr,len);
		len -= offsetof(struct sockaddr_un , sun_path);
		cliaddr.sun_path[len] = '\0';

		printf("client bind filename %s\n",cliaddr.sun_path);
		while((size = read(cfd,buf,BUFSIZ)) > 0)
		{
			for(i = 0;i < size ;++i)
			{
				buf[i] = toupper(buf[i]);
			}
			write(cfd, buf, size);
		}
		close(cfd);
		
		
	}
	close(lfd);


 
	return 0; 
}
 

