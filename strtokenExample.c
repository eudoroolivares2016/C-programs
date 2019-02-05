#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>



void SCAN(FILE(*stream)){
   char tempstr[50];
char *cptr = NULL;
char * next;
size_t chSize;
char * getLinePtr = NULL;
   while(1){
       getline(&getLinePtr,&chSize,stream);
      //fscanf (stream, "%s", tempstr);
      
      cptr = strtok(getLinePtr, " ");
   // next = strtok(NULL,"\n");


    printf("\n%s",cptr);

        if(feof(stream)){
         break;
      }

   }
  
} 

int main(int argv,char**argc)
{
FILE * fp;
 if (argv < 2){
      printf("Please enter a file to be opened.\n");
      exit(0);
   }
    if(argv==2)
    {
          fp = fopen(argc[1],"r");  

            SCAN(fp);


  

    }
return 0;

}



