#include<stdio.h>
#include<netinet/in.h>
#include<netinet/ip.h>
#include<arpa/inet.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>
void main(int argc,char ** argv)
{
	int sfd,slen,num,snum,i=0;
	sfd=socket(AF_INET,SOCK_DGRAM,0);
	if(sfd<0)
	{
		perror("socket");
		return;
	}
	perror("socket");
	struct sockaddr_in server_id;
	server_id.sin_family=AF_INET;
	server_id.sin_port=htons(atoi(argv[1]));
	server_id.sin_addr.s_addr=inet_addr(argv[2]);
	slen=sizeof(server_id);
	if(bind(sfd,(struct sockaddr *)&server_id,slen)<0)
	{
		perror("bind");
		return;
	}
	perror("bind");
	struct sockaddr_in client_id;
	recvfrom(sfd,&num,sizeof(num),0,(struct sockaddr *)&client_id,&slen);
	perror("recvfrom");
	printf("num=%d\n",num);
	for(i=num,snum=0;i;i=i/10)
	{
		snum=snum+i%10;
	}
	sendto(sfd,&snum,sizeof(snum),0,(struct sockaddr *)&client_id,slen);
	perror("sendto");
	
}

