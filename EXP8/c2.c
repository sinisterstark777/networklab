#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#define PORT 4960

void main()
{
	int clientsocket;
	char ti[100];
	struct sockaddr_in clientaddr;
	char buffer[1024];
	clientsocket=socket(PF_INET,SOCK_STREAM,0);
	memset(&clientaddr,'\0',sizeof(clientaddr));
	clientaddr.sin_family=AF_INET;
	clientaddr.sin_port=htons(PORT);
	clientaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	connect(clientsocket,(struct sockaddr *)&clientaddr,sizeof(clientaddr));
	recv(clientsocket,ti,100,0);
	printf("Data recevied: %s\n",ti);
	close(clientsocket);
}
