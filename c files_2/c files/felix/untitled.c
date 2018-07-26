#include <stdio.h>
#include <string.h>

main(){
	char userInput[100];
	printf("Enter your job: \n");
	scanf("%s",userInput);
	
	const char delimeter[2] = " ";
	char * token = strtok(userInput,delimeter);
	printf("This is the function that has been picked '%s'\n",token);
	
}
