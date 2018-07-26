#include <stdio.h>
#include <string.h>

	char fel[] = "The first string";
	char hil[] = "The second string";

	main()
	{
		size_t n,g;

		puts(fel);
		puts(hil);

		printf("\nEnter the number of characters to compare: \n");

		scanf("%d",&n);

		g = strncmp(fel,hil,n);

		printf("\nComparison of '%d' characters between '%s' and '%s' returns '%d' \n",n,fel,hil,g);

	}