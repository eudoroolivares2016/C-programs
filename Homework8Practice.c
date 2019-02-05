// A complete working C program to demonstrate all insertion methods
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 

struct Node
{
    char name[42];
    struct Node *next;
    struct Node *prev;
};

int SCAN(FILE *(*stream)) {			// We want to pass stream by reference (a pointer to a pointer).
int size = 0;
size_t chrCount;
char *text;
   // Open the file and make sure it was opened.
   if ((*stream = fopen("./hw8.data", "r")) == NULL) {
      printf("ERROR - Could not open hw8.data file.\n");
      exit(0);
   }
   // Use getline to read in a full line of data/text.
   while (1) {
      text = NULL;
      getline(&text, &chrCount, *stream);	// getline expects 3 pointer arguments.
      free(text);
      if (feof(*stream)) break;
      size++;
   }
   return size;
}



struct Node *LOAD(FILE *stream, int size) {	// Here we can just pass stream by value (we're not changing it).
int i;
size_t chrCount;
char *text, *in_name, *cmd;
struct Node *linkedlisthead == NULL;
   rewind(stream);
   for (i = 0; i < size; i++) {
      text  = NULL;
      getline(&text, &chrCount, stream);
      in_name  = strtok(text, " ");		// strtok extracts all characters to " ".
      cmd = strtok(NULL, "\n");		// strtok extracts all characters to "\n".
      // Allocate memory for name part of struct.
            if(cmd == 'a'){

            if(linkedlisthead == NULL){

                linkedlisthead = GetNewNode(in_name);
                        break;
                }
                struct Node* current = linkedListhead;
                while(current!=NULL){
                    if(strcmp(in_name > current->name) == 1){
                        
                        new_node = GetNewNode(in_name);
                        new_node ->next = current->next;
                        new_node ->prev = current;
                        if(current->next!=NULL){
                         current->next->prev = new_node; 
                        current->next = new_node;
                                                  
                                                                            
                            }
                            current->next = new_node;
                        
                           }
                        
                            current = current->next;
                    }                

            }



      strcpy(BlackBox[i].name, name);		// copy name into struct.
      free(text);
   }
   fclose(stream);
   return BlackBox;				// Return pointer to dynamic array.
}


void InsertAtHead(char n[]) {
	struct Node* newNode = GetNewNode(n);
	current->prev = newNode;
	newNode->next = current; 
	newNode->prev = NULL; // this should be redundent but, C can be fucking stupid
}







struct Node* GetNewNode(char n[]) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->name = n;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}



/* add another node based off of whether it is alaphabetically further foward can add the last location */
void insertAfter(struct Node* prev_node, char newName[])
{
Node*current;
current = head;
    /*1. check if the given prev_node is NULL */
    if (prev_node == NULL)
    {
        printf("the given previous node cannot be NULL");
        return;
    }
 





    /* 2. allocate new node */
    struct Node* new_node =(struct Node*) malloc(sizeof(struct Node));
while( current != NULL ){
if(strcmp(current->name,newName) == 1){
    /* 3. put in the data  */
    new_node->name  = newName;
 
    /* 4. Make next of new node as next of prev_node */
    new_node->next = prev_node->next;
 
    /* 5. Make the next of prev_node as new_node */
    prev_node->next = new_node;
 
    /* 6. Make prev_node as previous of new_node */
    new_node->prev = prev_node;
 
    /* 7. Change previous of new_node's next node */
    if (new_node->next != NULL)
   new_node->next->prev = new_node;
}
     /* 7. Change previous of new_node's next node */
    if (new_node->next != NULL){
   new_node->next->prev = new_node;}
current = current ->next;

}

// create the first one 
void append(struct Node** head_ref, int new_data)
{
    /* 1. allocate node */
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
 
    struct Node *last = *head_ref;  /* used in step 5*/
 
    /* 2. put in the data  */
    new_node->data  = new_data;
 
    /* 3. This new node is going to be the last node, so
          make next of it as NULL*/
    new_node->next = NULL;
 
    /* 4. If the Linked List is empty, then make the new
          node as head */
    if (*head_ref == NULL)
    {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }
 
    /* 5. Else traverse till the last node */
    while (last->next != NULL)
        last = last->next;
 
    /* 6. Change the next of last node */
    last->next = new_node;
 
    /* 7. Make last node as previous of new node */
    new_node->prev = last;
 
    return;
}
 

 
/* Drier program to test above functions*/
int main()
{





  
    return 0;
}
