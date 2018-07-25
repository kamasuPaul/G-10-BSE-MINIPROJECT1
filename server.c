#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>


void error (const char *msg)
{
       perror(msg);
       exit(1);
}


 int main(int argc ,char *argv[])
 {
              if(argc < 2)
  		{
			fprintf(stderr ,"port No. not provided, program terminated\n");
			exit(1);

		}
		int sockfd ,newsockfd ,portno ,n;
                char buffer[255];
    char userInput[1024], target[1024], task[1024];
 // printf("\nEnter your task: \n");
  //gets(userInput);
  char colon = ';';
                
		struct sockaddr_in serv_addr  , cli_addr;
		socklen_t clilen;

		sockfd = socket(AF_INET , SOCK_STREAM ,0);
		if(sockfd < 0)
		{
			error("Error opening Socket.");
			

		}

		bzero ((char *) &serv_addr , sizeof(serv_addr));
		portno = atoi(argv[1]);

		serv_addr.sin_family = AF_INET;
		serv_addr.sin_addr.s_addr = INADDR_ANY;
		serv_addr.sin_port = htons(portno);

		if(bind(sockfd , (struct sockaddr *) &serv_addr ,sizeof(serv_addr)) < 0)
		error("Binding Failed");

	    listen(sockfd ,5);
	    clilen = sizeof(cli_addr);
      int pid;
      char str1[50] , ans[1024];
    int  choice ;
    int size;
    while (1) {
       newsockfd = accept(sockfd ,(struct sockaddr *) &cli_addr ,&clilen);

      if (newsockfd < 0)
      error("Error on accept");
       pid = fork();
         if (pid < 0) {
              error("ERROR in new process creation");
         }
         if (pid == 0) {
           close(sockfd);
      

	   
		
	S :n = write(newsockfd,"Enter your string :",strlen("Enter your string"));
	   if(n < 0) error("ERROR writing to socket");
	  // read(newsockfd, userInput, sizeof(char *));
     recv(newsockfd, userInput , 1024 , 0);
	   //printf("Client - my string is :%s\n", userInput);
     if (strchr(userInput,colon)==NULL){
    sscanf(userInput, "%s %s", task, target);
    FILE * pp;
    pp = fopen ("busylist.txt", "a");
    fprintf(pp,"%s",target);
    fclose(pp);
   

    if (strcmp(task,"double")==0){
      
      strcat(target,target);
       strcpy(ans , target);
       printf("Your doubled  word is '%s'\n",ans);
      
    }else if (strcmp(task,"rev")==0){
      
       size = strlen(target);

     void reverse(char target[], int index, int size){      
        char temp;
        temp = target[index];
        target[index] = target[size - index];
        target[size - index] = temp;
          if (index == size / 2){    
             return;
            }
       reverse(target, index + 1, size);
     }
        reverse(target, 0, size - 1);
        strcpy(ans , target);
        printf("Your reversed  word is '%s'\n",ans);
        
      
    }else if (strcmp(task,"delete")==0){
      printf("You want to delete the word %s\n",target);
      
    }else if (strcmp(task,"replace")==0){
      printf("You want to replace the word %s\n",target);
      
    }else if (strcmp(task,"encrypt")==0){
      printf("You want to encrypt the word '%s'\n",target);
      
    }else if (strcmp(task,"decrypt")==0){
      printf("You want to decrypt the word '%s'\n",target);
      
    }else{
      printf("Your task has an error; Check it and try again\n");
    }
  }
  else{
    //Separation when there are multiple jobs
    const char delimeter[2] = ";";
    char * token = strtok(userInput,delimeter);
    char *store[1024];
    int i=0;
    for(;(token != NULL); (token = strtok(NULL,delimeter))){
    //Pointer array to store the individual jobs
      store[i]=token;
      i++;  
    }
    store[i]=NULL;
    for (i=0;store[i]!=NULL;i++){
      
      sscanf( store[i],"%s %s", task, target);
      printf("For Job No(%d) you want to:",(i+1));
      if (strcmp(task,"double")==0){
         strcat(target,target);
       strcpy(ans , target);
     // printf(" double the word '%s'\n",target);
      
      }else if (strcmp(task,"rev")==0){
        printf(" reverse the word '%s'\n",target);
        
      }else if (strcmp(task,"delete")==0){
        printf(" delete the word '%s'\n",target);
        
      }else if (strcmp(task,"replace")==0){
        printf(" replace the word '%s'\n",target);
        
      }else if (strcmp(task,"encrypt")==0){
        printf(" encrypt the word '%s'\n",target);
        
      }else if (strcmp(task,"decrypt")==0){
        printf(" decrypt the word '%s'\n",target);
        
      }else{
        printf(" 'unknown'\nYour task has an error; Check it and try again\n");
      }
    }
  }
FILE * fp;


   fp = fopen ("readyjobs.txt", "a");
   fprintf(fp, "%s",ans);
   fclose(fp);
   




	 
	   /*n = write(newsockfd,"Enter your choice : \n1.double\n2.Reverse\n3.Replace\n4.Delete\n5.Encrypt\n6.Decrypt\n7.Exit\n",strlen("Enter your choice : \n1.double\n2.Reverse\n3.Replace\n4.Delete\n5.Encrypt\n6.Decrypt\n7.Exit\n"));
       if(n < 0) error("ERROR writing to socket");
       read(newsockfd, &choice, sizeof(int));
       printf("Client choice is : %d\n", choice);

   switch(choice){
   
   case 1:
   	    strcat(str1,str1);
   	   strcpy(ans , str1);
   break;
   case 2:
          
       	 size = strlen(str1);

     void reverse(char str1[], int index, int size){      
        char temp;
        temp = str1[index];
        str1[index] = str1[size - index];
        str1[size - index] = temp;
          if (index == size / 2){    
             return;
            }
       reverse(str1, index + 1, size);
     }
        reverse(str1, 0, size - 1);
        strcpy(ans , str1);
			break;
   case 3:
      printf("\nOriginal String: %s\n", str1);
        char str2;
        char str3;
        int counter;
      printf("\nEnter Character in String To Be Replaced: ");
      scanf(" %c", &str2);
      printf("\nEnter The Character For Replacement: ");
      scanf(" %c", &str3);
     while(str1[counter] != '\0'){    
           if(str1[counter] == str2){      
                str1[counter] = str3;
     }
       counter++;
     }
      strcpy(ans , str1);
        
    return 0;
   break;
       	
   case 7:
    	goto Q;
   break;

}*/
	//write(newsockfd, &ans ,sizeof(char *));
  send(newsockfd, ans , 1024 , 0);
	if(choice != 5)
		goto S;


	Q:   close(newsockfd);}
  else{
      close(newsockfd);
  }}
	    //close(sockfd);
	    return 0; 
}



