#include <stdio.h>
#include <stdlib.h>



int main(){
char* buffer;
size_t size = 0;
FILE* stream;
stream = fopen("./hw8.data,w");
int op1;
int op2;
int rand(void);

// go through and for each of the lines have a 50 percent chance of adding in a or adding in d with a space after the thing you add in
// go through each line allocate that much space that name takes up and then add in a char pointer for all of the lines append a letter either a or d at the end of each one.  
while(stream != EOF){

getline(buffer,size,stream);











}







return 0;
}
