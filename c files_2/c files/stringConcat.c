
#include <stdio.h>
#include <string.h>

	char fel[27] = "a";
	char hil[2];

	main()
	{
		int n;

		hil[1]= '\0'; //Makes the last figure constantly the null character

		//The first figure is switched throught= the loop
		for (n = 98; n< 123; n++)
		{
			hil[0] = n;
			strcat(fel,hil);
			puts(fel);
		}

		return 0;
	}

