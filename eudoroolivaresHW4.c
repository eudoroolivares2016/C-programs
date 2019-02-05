#include<stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct _data {                    
   char *name;
   long number;
};


int SCAN(FILE *(*stream)) {            
int size = 0;
size_t chrCount;
char *text;
  *stream = fopen("./hw4.data", "r"); // open the file and read from the data
   while (1) {
      text = NULL;                
      getline(&text, &chrCount, *stream);    
      if (feof(*stream)){
 break;}
      size++;
   }
free(text);
return size;
}

//loads the function allocates space for the structure and the character arrays holding the names of the peopel
struct _data *LOAD(FILE *stream, int size) {
size_t chrCount = 0;
char *text = NULL; 
char *phone; 
char *name;
struct _data *BlackBox;
BlackBox = (struct _data*)malloc(size*sizeof(struct _data));
rewind(stream);
   for (int i = 0; i < size; i++) {              
       getline(&text, &chrCount, stream); // reades the line of the file with arguments 
       name  = strtok(text, " ");        
       phone = strtok(NULL, "\n");        
  
      BlackBox[i].name = (char*)malloc(strlen(name));  
       strcpy(BlackBox[i].name, name);  // copies output of the name token into the black box       
       BlackBox[i].number = atol(phone);} // changes the token string phone into a type int       
    free(text); // frees text since it is not used anymore
   fclose(stream);
   return BlackBox;                
}



// find the name
void SEARCH(struct _data *BlackBox, char *name, int size) {
        int found =0;    
    // if no argument
if(name == NULL){

printf("Sorry you must include a name to search");
exit(0);
}
// if found 
for (int i = 0; i < size; i++) {
       if (strcmp(name, BlackBox[i].name) == 0) {
          printf("The name was found at %d .\n", i);
          found = 1; 
    break;
       }
    }
//if its not found
if(found ==0){
      printf("Sorry, the name was not found.\n");
}

}

// frees all of the characters we malloced earlier and the strucutre
void FREE(struct _data *BlackBox, int size) {
   for (int i = 0; i < size; i++) {
       free(BlackBox[i].name); } 
   free(BlackBox);
   
}




//runs program 
int main(int argv, char **argc) {
int size;
FILE *stream;
struct _data *BlackBook; //creates a new instance of the structure 
   
       size = SCAN(&stream);
       BlackBook = LOAD(stream, size);
       SEARCH(BlackBook, argc[1], size);
       FREE(BlackBook, size);
  
   return 0;
}
