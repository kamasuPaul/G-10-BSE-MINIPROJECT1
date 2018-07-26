#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


bool array_lookup(int value, int *array, int size);
char * convertToString(char ch);
main(){
	int array_positions[100],size,j;
	char userInput[1024], target[1024], task[1024], positions[100],positions_dup[100],final[100],**tempD;
	printf("\nEnter your task: \n");
	gets(userInput);
	
	sscanf(userInput, "%s %s %s", task, target, positions);//Divide the two sections of the job
	sscanf(positions,"%s",positions_dup);
	printf("In task there is '%s'\n",task );
	printf("In target there is '%s'\n",target );
	printf("In positions there is '%s'\n",positions );
	printf("In positions_dup there is '%s'\n",positions_dup);

	const char delimeter[2] = ",";
	char * token = strtok(positions,delimeter);
	
	int i=0;
	for(;(token != NULL);(token = strtok(NULL,delimeter))){ //findng how many items are in picked at the end of the loop
		i++;
	}
	
	token = strtok(positions_dup,delimeter); //token is re-initialized using the duplicate

	const int MAX = i;
	char *positionArray[MAX];	// the array is assigned the actual number of items
	for(j=0;(token != NULL);(token = strtok(NULL,delimeter))){
		positionArray[j]=token;
		j++;
	}
	positionArray[j] = NULL; //null terminator is appended

	size = sizeof(positionArray);
	
	tempD = malloc(size);
	memcpy(tempD,positionArray,sizeof(positionArray));
	memset(final, '\0', sizeof(target));	//small change here
	for (i = 0; i < MAX; i++)
	{
		array_positions[i] = atoi(tempD[i]);
	}
	
	for(i=0;i<strlen(target);i++){
		if((array_lookup(i+1, array_positions, MAX ))==0){
			
			char *finalPtr = convertToString(target[i]);
			strcat(final,finalPtr);
		}
	}
	puts(final);
}

bool array_lookup(int value, int *array, int size){
    int i;
    for (i=0; i < size; i++) {
        if (array[i] == value)
            return true;
    }
    return false;
}

char * convertToString(char ch) {
    char *str = malloc(2 * sizeof (char));
    str[0] = ch;
    str[1] = '\0';
    return str;
}