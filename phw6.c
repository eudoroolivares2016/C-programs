/***************
* PARKER COMBS *
* CSCI 230     *
* ASSIGNMENT 6 *
***************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct _data {                                 
   char word[50]; 
   int times;
};

/*read the # of words in the file*/
int SCAN(FILE *(*stream)){
   int wordcount = 0;
   char tempstr[50];
   while(1){
      fscanf (*stream, "%s", tempstr);
      if(feof(*stream)){
         break;
      }
      wordcount++;
   }
   return wordcount;
}

// puts words in file to array of strucutes
struct _data *LOAD(FILE *stream, int wordcount) {
   struct _data *ptr;
   ptr = (struct _data*)calloc(wordcount, sizeof(struct _data));
   rewind(stream); //rewind to beginning of file
   int index = 0;
   int in = 0;
   int in2 = 0;
   int in3 = 0;
   char tempstr[50];
   for(index = 0; index < wordcount; index++){  
         fscanf (stream, "%s", tempstr);
         if (isalpha(tempstr[0]) == 0){ //if 1stchar is sym
            for (in3 = 0; in3 <  50; in3++){
               tempstr[in3] = tempstr[in3+1];
            }
         }
         for (in = 0; in < 50; in++){ //This removes punctuation & other symbols
            if (isalpha(tempstr[in])== 0&&tempstr[in]){
               tempstr[in] = '\0';
            }
         }
               tempstr[in2] = tolower(tempstr[in2]);
        
         strcpy(ptr[index].word, tempstr);
   }
   return ptr;
}

/*counts word frequency*/
void SEARCH(struct _data *words, int wordcount){
   struct _data *repeats;
   repeats = (struct _data*)calloc(wordcount, sizeof(struct _data));
   int isInList = 0;
   int index;
   int index2;
   int index3; 
   int index4;
   char tempstr[50];
   int realdex = 0;
   int repeatCt = 0; 
   for (index = 0; index < wordcount; index++){ //will load initial instances of words into REPEATS
      for (index2 = 0; index2 < wordcount; index2++){
         if (strcmp (words[index].word,repeats[index2].word) == 0){ //this is 2nd+ instance of a word
            isInList = 1;
            strcpy(tempstr,words[index].word);
            break;
         }
      }
      if (isInList == 0){
         strcpy(repeats[realdex].word,words[index].word);
         repeats[realdex].times = repeats[realdex].times + 1;
         repeatCt++;
         realdex++;
      }
      if (isInList == 1){
         for (index4 = 0; index4 < repeatCt; index4++){
            if (strcmp (repeats[index4].word,tempstr) == 0){
               repeats[index4].times = repeats[index4].times + 1;
            }
         }
      }
      isInList = 0;
   }

   //PRINTS
   int total = repeatCt;
   int i1; 
   int i2;  
   struct _data *swap;
   swap = (struct _data*)calloc(1, sizeof(struct _data));
   for (i1 = 0 ; i1 < ( total - 1 ); i1++){
      for (i2 = 0 ; i2 < total - i1 - 1; i2++){
         if (repeats[i2].times < repeats[i2+1].times){
            swap[0] = repeats[i2];
            repeats[i2] = repeats[i2+1];
            repeats[i2+1] = swap[0];
         }
      }
   }
   printf("Top 10 occurring words:\n");
   for (index3 = 0; index3 < 10; index3++){
      printf ("%-15s\t\t%d times\n", repeats[index3].word, repeats[index3].times);
   }
   free(swap);
   free(repeats);
}


/*frees all dynamically allocated data*/
void FREE(struct _data *words){
   free(words);
}

int main(int argv, char **argc) {
/******************************************
* argv: no. of arguments                  *
* argc: array holding arguments (strings) *
******************************************/
   if (argv < 2){
      printf("Error: you must enter a file to open.\n");
      exit(0);
   }
   if (argv > 2){
      printf("Error: please attempt to load only one file.\n");
      exit(0);
   }
   if (strcmp(argc[1], "hw6.data") != 0){
      printf("Error: invalid file.\n");
      exit(0);
   }
   FILE *fp;
   fp = fopen(argc[1], "r");
   FILE **fpp;
   fpp = &fp;
   int wordcount = SCAN(fpp);
   struct _data *ptr;
   ptr = LOAD(fp, wordcount);
   SEARCH(ptr, wordcount);
   FREE(ptr);
}


