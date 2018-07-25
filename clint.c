#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include<netinet/in.h>
#include <netdb.h>

void error(const char *msg)
{
  perror(msg);
  exit(0);

}

int main(int argc, char *argv[])
{
	int sockfd,portno,n;
	struct sockaddr_in serv_addr;
	struct hostent *server;
    char userInput[1024], target[1024], task[1024];
	char buffer[256];
	char colon = ';';
	if (argc < 3 )
	{
		fprintf(stderr, "usage %s hostname port\n" , argv[0]);
		exit(0);
	}
	portno = atoi(argv[2]);
	sockfd = socket(AF_INET ,SOCK_STREAM,0 );
	if(sockfd < 0)
		error("ERROR opening socket");
	    server = gethostbyname(argv[1]);
	    if (server == NULL)

	    {
	    	fprintf(stderr, "Error , no such host" );
	    }

	    bzero((char *) &serv_addr , sizeof(serv_addr));
	    serv_addr.sin_family = AF_INET;
	    bcopy((char *) server->h_addr ,(char *) &serv_addr.sin_addr.s_addr ,server->h_length);
	    serv_addr.sin_port = htons(portno);
	    if(connect(sockfd , (struct sockaddr *) &serv_addr , sizeof(serv_addr))<0)
	           error("connection failed");
		char ans[1024];
		int  choice ;

	S:bzero(buffer,256);
	  n = read(sockfd,buffer,255);
	  if(n < 0)
	      error("ERROR reading from socket");
	  printf("Server - %s\n",buffer);
	  gets(userInput);
	 // scanf("%s" ,str1); 
	 //write(sockfd, userInput, sizeof(char *));
      send(sockfd, userInput , 1024 , 0);
    // printf("%s\n",userInput);

	  /* n = read(sockfd,buffer,255);
	  if(n < 0)
	      error("ERROR reading from socket");
	  printf("Server - %s\n",buffer);
	  scanf("%d" ,&choice);
	  write(sockfd, &choice, sizeof(int));	

	  	if(choice == 5)
	  	goto Q;*/

	  	//read(sockfd , &ans , sizeof(char *));
	  	recv(sockfd, ans , 1024 , 0);
	  	printf("server- The answer is: %s\n", ans);

	  /*	if(choice != 5)
	  		  goto S;*/


	  	/*Q :
	  	printf("You have selected to exit. Exit successful.");*/

		close(sockfd);
		return 0;

}
	
