#include <stdio.h>
#include <string.h>
	
	main()
	{
		char *pos, lookup[80];
		char actual[] = "This is the main string that is to be looked up from, select the desired word";
		printf("\nThis is the main string '%s'\n\nEnter the target string: ",actual);
		gets(lookup);
		
		pos = strstr(actual,lookup);

		if (pos == NULL)
			printf("\nYour word was not found\n");
		else
			printf("%s was found at position %d\n", lookup, pos-actual);
		return (0);
	}