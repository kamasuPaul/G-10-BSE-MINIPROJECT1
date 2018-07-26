//Double
strcat(str1,str1);


//Reverse

	size = strlen(str1);

 	void reverse(char str1[], int index, int size){      
        char temp;
        temp = str1[index];
        str1[index] = str1[size - index];
        str1[size - index] = temp;
          if (index == size / 2){    
             return;
            }
       reverse(str1, index + 1, size);
	}
	   reverse(str1, 0, size - 1);

//Replace
     void replfun(char taskstring[],char optionstring[]){ 
        int i,ii=0,pos; char shortAr[3];
           while(ii<strlen(optionstring)){
            if(optionstring[ii]==' '){
              break;
            } 
            sprintf(shortAr,"%c",optionstring[ii]);
      pos=atoi(shortAr); 
      taskstring[pos-1]=optionstring[ii+2]; 
      ii=ii+4;
  } 
      printf("\n\nresult string after replacement = %s\n\n\n",taskstring);

  }

//Delete
struct task delproc(struct task deletef){

char dbf[10]="Delete";

char arr2[20];
int com[15];
char b[20];

//new code1CODECHEF=================================================================================================================================================

int l,i=0,d,f,g,h,n,j=0,k;


char z[20];
char ll[20];

char r[8][3];
int x[20],we;

l = strlen(taskob.taskstroptions);

for(i=0,j=0; i<l; i++,j++){

if(i%2==0){

 z[i/2] = taskob.taskstroptions[i];
 ll[0] = taskob.taskstroptions[i];
 strcpy(r[i/2],ll);

 } if(i==(l-1)){

 we = i/2;
 }

}

int len = l-we;
int e = atoi(z);
for(d=0;d<len;d++){
 x[d] = atoi(r[d]);

}

//========================================================================================================================new code
int rn = strlen(taskob.taskStringwd);

int ww = sizeof(x)/sizeof(int);

int fr = rn-len+1;

int flag=0;
int nop=0;

//...............................................................................
for(i=0; i<fr+1; i++){
flag=0;
    for(j=0; j<(l-we); j++){
      if(i==(x[j]-1)){ flag++;    i++; nop++; }
                        }

          arr2[i-nop]= taskob.taskStringwd[i];


}
strcpy(taskob.resultStr,arr2);
//printf("STSS server processes \t::..%s\n\n",taskob.resultStr);
//=======================================

return taskob;
}


//Encrypt

//Decrypt