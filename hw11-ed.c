#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc,char**argv){
char buffer[256];
/*if(argc!= 2){
exit(0);
}*/
FILE* stream;
stream = fopen("./hw11.data","r");
char* text = NULL;
size_t size =0;
getline(&text,&size,stream);
printf("File Contents: %s\n",text);
printf("Buffer: %p\n",buffer);
strncpy(buffer,text,sizeof(buffer));
buffer[sizeof(buffer)-1] = '\0'; //manpage of strncpy does not add a \0 character to it so this is needed.
printf("Buffer content: %s\n",buffer);
free(text);
return 0;
}


