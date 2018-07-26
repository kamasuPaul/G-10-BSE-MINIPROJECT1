#include <stdio.h>
#include <string.h>
#include <stdlib.h>


main(){
	int i;
	char *target = "felix";
/*	printf("Initially it is %s\n",target);
	printf("Enter the position you wan to delete");
	scanf("%d",&i);
	memmove((target + i),(target + i + 1),1);	
	target[i] = '\0';*/
	printf("%s\n",target+1);
}
