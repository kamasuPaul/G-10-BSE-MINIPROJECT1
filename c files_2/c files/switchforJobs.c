#include <stdio.h>
#include <string.h>
#include <stdlib.h>
main(){
	char userInput[1024], target[1024], task[1024];
	printf("\nEnter your task: \n");
	gets(userInput);
	char colon = ';';
	if (strchr(userInput,colon)==NULL){	
	//If the string has no ';' character i.e single job
		
		sscanf(userInput, "%s %s", task, target);//Divide the two sections of the job
		
		// Check for what type of job it is
		if (strcmp(task,"double")==0){
			strcat(target,target);
			printf("The result is => %s\n",target);
			
		}else if (strcmp(task,"rev")==0){
			
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
				int size = strlen(target);
				reverse(target, 0, size - 1);
				printf("The result is => %s\n",target);
			
		}else if (strcmp(task,"delete")==0){
			printf("You want to delete the word '%s'\n",target);
			
		}else if (strcmp(task,"replace")==0){
			printf("You want to replace the word '%s'\n",target);
			
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
			printf("For Job No(%d); :",(i+1));
			if (strcmp(task,"double")==0){
				strcat(target,target);
				printf("The result is => %s\n",target);
			
			}else if (strcmp(task,"rev")==0){
			
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
				int size = strlen(target);
				reverse(target, 0, size - 1);
				printf("The result is => %s\n",target);
				
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
}
