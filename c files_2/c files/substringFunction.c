#include <stdio.h>
#include <string.h>
	char *substring(char *original,char *additional, char *temporary);
	main()
	{
		char orig[100];
		char add[100];
		char temp[100];
		printf("Enter the original string: ");
		gets(orig);
		printf("\nEnter the string to add in the middle: \n");
		gets(add);
		printf("%s\n",substring(orig,add,temp));
	}
	char *substring(char *original,char *additional, char *temporary){  //Create Temporary Array to hold contents from both original and additional
		int n,length = strlen(original);
		if(length%2==0)				//If the length is an even value
			n = length/2;		
		else						//If the length is an odd value
			n = (length + 1)/2;
		strncpy (temporary,original,n);	//Copy the first n values from the original array into the temporary array
		temporary[n]='\0';				//Add the end of string
		strcat (temporary,additional);	//Concatenate the additional string to the temporary
		strcat (temporary, original + n); //Concatenate the the original string to the temporary starting from the nth index
		return temporary;
	}
