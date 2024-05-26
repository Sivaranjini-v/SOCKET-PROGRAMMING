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
	printf("enter num\n");
	scanf("%d",&num);
	sendto(sfd,&num,sizeof(num),0,(struct sockaddr *)&server_id,slen);
	perror("sendto");
	recvfrom(sfd,&snum,sizeof(snum),0,(struct sockaddr *)&server_id,&slen);
	perror("recvfrom");
	printf("snum=%d\n",snum);
	
}

