/* Uses the system command within C to take advantage of the linux shell and use its commands 
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main (void) {
char command[100000];
strcpy(command, "touch CombinedTextFile.txt"); // creates a new blank text file called CombinedTextFile (the .txt part does not seem to make a difference), 
system(command); // puts it into the linux command line
strcpy(command, "cat HW2-American0 HW2-American1 HW2-American2 > CombinedTextFile "); // concatanates all the words in the three text documents into the new CombinedTextFile file.
system(command); // puts it into the linux command line
strcpy(command, "sort CombinedTextFile" ); // prints out the words in CombinedTextFile in a sorted manner into the shell
system(command);// puts it into the linux command line
 
} 
