#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool array_lookup(int value, int *array, int size);
char * convertToString(char ch);
main(){
	int sizeR,i,j,num_location[100];
	char userInput[1024], target[1024], task[1024],final[1024], positions[100],positions_dup[100],*char_to_replace,**tempR_num,**tempR_char;
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
	
	
	for(;(token != NULL);(token = strtok(NULL,delimeter))){ //findng how many items are in picked at the end of the loop
		i++;
	}
	
	token = strtok(positions_dup,delimeter); //token is re-initialized using the duplicate
	
	const int MAX = i;
	char *locationArray[MAX];
	for (j=0;(token != NULL);(token = strtok(NULL,delimeter))){
		locationArray[j] = token;
		j++;
	}
	locationArray[j] = NULL;
	
	sizeR = sizeof(locationArray);
	
	tempR_num = malloc(sizeR);
	tempR_char = malloc(sizeR);
	char_to_replace = (char *)malloc(MAX+1);
	memset(final, '\0', sizeof(target));
	
	for (i = 0; i < MAX; i++)
	{
		char * token2 = strtok(locationArray[i],"-");	//Second Token dividing between either sides of "-" is declared
		tempR_num[i] = token2;							//The integers are stored in the tempR_num pointer
		token2 = strtok(NULL,"-");
		tempR_char[i] = token2;							//The characters are stored in the tempR_char pointer
	}
	tempR_char[i] = NULL; 
	tempR_num[i] = NULL;
	//Convert the integer positions in tempR_num from charcaters to integers and store into new array
	for (j = 0; j < MAX; j++)
	{
		num_location[j] = atoi(tempR_num[j]);
		printf("%d\n",num_location[j]);
	}
	for(i=0;i<strlen(target);i++){
		if((array_lookup(i+1,num_location,MAX))==0){
			
			char *finalPtr = convertToString(target[i]);
			strcat(final,finalPtr);
		}else if(i<MAX){
			strcat(final,tempR_char[i]);
		}
	}
	puts(final);
//replace kamasu 1-l,2-u,3-k,5-k	
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