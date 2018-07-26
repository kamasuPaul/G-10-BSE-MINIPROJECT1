#include <stdio.h>
#include <string.h>

	main()
	{
		char fel[80], hil[80];
		int t;

		printf("\nInput the first string and a blank to exit:\n");
		gets(fel);
		
		printf("\nInput the second string:\n");
		gets(hil);

		t = strcmp(fel,hil);

		printf("\nstrcmp(%s,%s) returns %d\n",fel,hil,t);
	}