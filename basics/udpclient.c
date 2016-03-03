#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <sys/time.h>   
#include <time.h>

#define PASS 0
#define FAIL 1

#define SERVER_UDP_PORT 1207

#define MAX_SLEN 512 
#define BUFF_SIZE 10000       

struct info
{ 
	char lastname[25];
	int studentid;
	char hostname[25];
	int processid;
	char emailid[32];
}; 
struct info personalInfo;

int main( int argc, char *argv[ ])
{
	int server_udp_port, client_udp_port;
	int sd,rc,i, server_len,datasize;
	struct sockaddr_in server,client;
	struct hostent *hptr;
	char hname[]="chaoshorizon.selfip.net";
	char lname[]="Kudipudi";
	int sid=0x6890;
	char empty[]="null";
	char eid[]="bhavana.279@gmail.com";
	int port= SERVER_UDP_PORT; 
	char rbuf[MAX_SLEN];
	strncpy(personalInfo.lastname,"Kudipudi",strlen(lname));
	personalInfo.studentid=htons(sid);
	personalInfo.processid=0x00;
	strncpy(personalInfo.hostname,"null",strlen(hname));
	strncpy(personalInfo.emailid,"bhavana.279@gmail.com",strlen(eid)); 

	if ( argc!=1)
	{
		printf("\n Usage: udpclient \n");
		exit(FAIL);
	}

	printf("\n\n--> Creating socket...    ");
	sd = socket(AF_INET, SOCK_DGRAM, 0);
	printf("\nvalue of socket descriptor : %d\n",sd);
	if(sd<0) 
	{
		perror("cannot open socket ");
		exit(FAIL);
	}

	bzero((char *)&server, sizeof(server));
	server.sin_family=AF_INET;
	server.sin_port=htons(port); 
	hptr = gethostbyname(hname);
	if(hptr == NULL) 
	{
		printf("Host not known : %s \n ", hname);
		exit(FAIL);
	}
	bcopy(hptr->h_addr,(char *)&server.sin_addr, hptr->h_length);
/*	printf("\n--> Binding port number...  ");
	bzero((char *)&client, sizeof(client));
	client.sin_family = AF_INET;
	client.sin_addr.s_addr = htonl(INADDR_ANY);
	client.sin_port = htons(0);

	rc = bind(sd, (struct sockaddr *) &client, sizeof(client));
	if(rc<0) 
	{
		printf("%s: cannot bind name to port \n"); 
		perror("error ");
		exit(FAIL);
	}
*/
	printf("\nMembers of structure : ");
	printf("sin_family = %d, sin_port = %d, sin_address = %d\n", client.sin_family, client.sin_port, client.sin_addr.s_addr);

	server_len=sizeof(server);
	datasize= sizeof(personalInfo);
	rc = sendto(sd,&personalInfo,datasize,0,(struct sockaddr *)&server, server_len);
	if(rc<0) 
	{   
		perror("cannot send data ");
		close(sd);
		exit(FAIL);  
	}
	if (recvfrom(sd,rbuf,MAX_SLEN,0,(struct sockaddr *)&server, &server_len) < 0)
		perror("cannot recieve data ");
	else
		printf("recieved data %s\n", rbuf);

	close(sd);
	return PASS;
}

