    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    
    const char *containers_1[] = {"1","2","3","4"};
    
    
    main() {
    
    char ** tmp1;
    int i, size, final[100];
    
    size = sizeof(containers_1);
    printf ("%d\n", size);
    tmp1 = malloc(size);
    memcpy(tmp1, containers_1, sizeof(containers_1));
    printf("%d\n", size/sizeof(char *));
    for (i=0; i< size/sizeof(char *); i++) {
        final[i] = atoi(tmp1[i]);
        }
    for (i=0; i<size/sizeof(int *); i++) {
        printf("%d\n",final[i]);
        }
    }
    