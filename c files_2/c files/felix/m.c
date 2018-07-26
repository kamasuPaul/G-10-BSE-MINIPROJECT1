#include <sys/wait.h>

 int main(int argc, char *argv[]){
 int servSock;
int clntSock;
unsigned short echoServPort;
pid_t processID;
unsigned int childProcCount = 0;    /* Number of child processes */
  if (argc != 2){
  fprintf(stderr, "Usage: %s <Server Port>\n", argv[0]) ;
exit(l);
  }
  echoServPort = atoi(argv[1]);     /* F i r s t arg' local port */
  servSock = CreateTCPServerSocket (echoServPort);
   for (;;){                        /* Run forever */
   clntSock = AcceptTCPConnection(servSock);
   if ((processlD = fork()) < 0)    /* Fork child process and report any errors */
DieWithError("fork() failed");
else if (processlD == 0){           /* This is the child process */
	close(servSock);                /* Child closes listening socket */
	HandleTCPClient(clntSock);
	exit(O);                        
}
 printf("with child process:%d\n", (int) processlD);
  close(clntSock);                 /* Parent closes child socket descriptor */
  childProcCount++;                /* Increment number of outstanding child processes */
  while (childProcCount){          /* Clean up all zombies */
    processID = waitpid((pid_t) -i, NULL, WNOHANG);     /* Nonblocking wait */
     if (processID < O)            /* waitpid() error? */
     DieWithError("waitpid() failed");
    else if (processID == O)        /* No zombie to wait on */
     break;
    else
     childProcCount--;              /* Cleaned up after a child */
  }
   }
 }