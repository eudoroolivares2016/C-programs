#include <stdio.h>
#include <stdlib.h>
//#include <unistd.h>

// creates the node structure
struct node {

int data;
struct node*next;

};

typedef struct node _node;

void INSERT(_node*(*head)){ // this is the adress of head becasue we are going to store the first location of the list in head

int i;
_node*current; //creates temporary pointer the the linked list 

    for(i =9; i>=0;i--)
        {
            current = (_node *)malloc(sizeof(_node)); //creates a pointer object an allocates space
            current->data =i;
            current->next = (*head);
          (*head) = current;
            }

}

int TRANSVERSE(_node*head){ //this passes the actual variable head
_node*current;
current = head; // sets current the new temporary pointer equal to the head of the list. 
    //printf("got here");
    while(current != NULL)
    {
        printf("%d\n", current ->data);
        current = current -> next;        
            
   
     }
if(current == NULL){
printf("The end ");
}
//printf("This is the size:%d",size);
return 0;

}


_node* SEARCH(_node *head,int searched){
_node * current;
current = head;
printf("%d",searched);
while(current!=NULL) // stuck in an infinete loop because head must be equal to NULL right
    {
       if(current->data == searched)
        {
            //printf("\nThe value %d was found here it is",searched);            
                
           return current;
         }     
          
         current = current->next;
       
                
     
     }  
    if(current == NULL){
                  printf(" The value was not found in the list");
                      }
            exit(0);
        }


int main()
{
char buffer[10];
_node* head;
head = NULL; // just in case
INSERT(&head);// makes head the pointer to the first element in the array
TRANSVERSE(head);
int searched;
printf("\nPlease enter the value you are looking for");
fgets(buffer,50,stdin); // takes in whatever the user watns 
searched = atoi(buffer);
//printf("\nTHIS IS SEARCHED!%d",searched);
//printf("%d",SEARCH(head,searched));
printf("You searched:[%d %d]\n", searched, SEARCH(head, searched)->data);
//link*SEARCH(int value, link *head);
return 0;

}




