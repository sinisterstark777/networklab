#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<time.h>
#define PORT 4960

void main()
{
	int sockfd;
	time_t curtime;
	time(&curtime);
	char ti[100];
	strcpy(ti,ctime(&curtime));
	printf("%s", ti);
	struct sockaddr_in serveraddr;
	int newsocket;
	struct sockaddr_in newaddr;
	socklen_t addr_size;
	char buffer[20];
	sockfd=socket(PF_INET,SOCK_STREAM,0);
	if(sockfd == -1)
	{
		printf("Colud not create socket");
	}
	memset(&serveraddr,'\0',sizeof(serveraddr));
	serveraddr.sin_family=AF_INET;
	serveraddr.sin_port=htons(PORT);
	serveraddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	bind(sockfd,(struct sockaddr *)&serveraddr,sizeof(serveraddr));
	listen(sockfd,5);
	addr_size=sizeof(newsocket);
	newsocket=accept(sockfd,(struct sockaddr *)&newaddr,&addr_size);
	send(newsocket,ti,100,0);
	close(sockfd);
}
	
