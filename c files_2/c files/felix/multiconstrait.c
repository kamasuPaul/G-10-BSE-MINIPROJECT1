#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
void ProcessMain(int servSock);
int main(int argc, char *argv[]){
	int servSock;
unsigned short echoServPort;
pid_t processlD;
unsigned int processLimit;
unsigned int processCt;
 if (argc != 3){
 fprintf(stderr, "Usage: %s <SERVER PORT> <FORK LIMIT>\n", argv[0]) ;
exit(1);

 }
  echoServPort = atoi(argv[1]);
  processLimit = atoi(argv[2]);

  servSock = CreateTCPServerSocket (echoServPort) ;

  for (processCt=0; processCt < processLimit; processCt++)
   if ((processlD = fork()) < 0)
   	error("fork() failed");
     else if (processlD == 0)
      ProcessMain(servSock);
      exit(0);
}
void ProcessMain(int servSock)
{
int clntSock;
  for (;;){
  clntSock = AcceptTCPConnection(servSock);
  printf("with child process:%d\n", (unsigned int) getpid());
  HandleTCPClient(clntSock);
}}
