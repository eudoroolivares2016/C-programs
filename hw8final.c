
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//declare structure
struct node {
   char* name;
   struct node *next;
   struct node *prev;
};
typedef struct node _node;
//************************************************************************************************************************* compare
int compare(char* a, char * b){
int result = strcmp(a,b);  
return result;

}

//********************************************************************************************************************* get new node
_node *GETNEWNODE(char *data){
   _node *new_node;
    char* ptr;
   new_node = (_node*)malloc(sizeof(_node));
   ptr = (char*)calloc(strlen(data),sizeof(char)+10);
   new_node->name = ptr;
   strncpy(new_node->name,data,strlen(data)); 
   new_node->next = NULL;
   new_node->prev = NULL;
}
//*******************************************************************************************************************************************************
void ADD(char *data, _node *(*head), _node *(*tail)){
   _node *current,*newNode,*temp,*newtail;
   newNode = GETNEWNODE(data);
   current = (*head);
   if((*head) == NULL){//*****************************************************************************************if list is empty
      (*head) = newNode;
   }
   else{//************************************************************************************if list containes values 
      if(compare(current->name, data) > 0){//************************************************************************ and if new name is the new head
         temp = (*head);
         newNode->next = temp;
         temp->prev = newNode;
         (*head) = newNode;
      }
    
      //***********************************************************************************************run through the linked list until you find a word that is further along the alphabet than the word you are on    
      else{ 
            current = (*head);
         while(current != NULL && compare(current->name,data) < 0 || current != NULL && compare(current->name,data) == 0 ){ //if the names are the same
            if(current->next == NULL){
               newtail = current; //this will be the tail node
            }//********************************************************************************** if you try to put in duplicate names
            if(compare(current->name,data) == 0){
               free(newNode); // if you don't free this you will get a memory leak 
               return;
            }
           
            current = current->next;
         }
         if(current != NULL){//***********************************************************add middle
            
            temp = current;
            newNode->next = temp;
            newNode->prev = temp->prev;
            temp->prev->next = newNode;
            temp->prev = newNode;
         }
   
         else{//********************************************************************************************add end
            
            newNode->next = NULL;
            newNode->prev = newtail;
            newtail->next = newNode;
         }
      }
   }
   return;
}

//*****************************************************************************************************************************
void DELETE(char *data, _node *(*head), _node *(*tail),_node *(*trhead), _node *(*trtail)){
   _node *current;
   current = (*head);
   while(current != NULL){
      if (current->next == NULL){//resets tail
         (*tail) = current;
      }
      current = current->next;
   }
   current = (*head);

   while (current != NULL){
      if (compare(current->name, data) == 0){//*****************************************************delete Head
         ADD(data,&(*trhead),&(*trtail));
         if (current == (*head)){ 
            _node *temp;
            temp = (*head);
            (*head) = (*head)->next;
            (*head)->prev = NULL;
            free(temp);
         }//*****************************************************delete tail
         else{
            if(current == (*tail)){
               _node *temp;
               temp = (*tail);
               (*tail) = (*tail)->prev;
               (*tail)->next = NULL;
               free(temp);
            }//****************************************************delete in the middle
            else{
               _node *temp;
               temp = current;
               current->prev->next = current->next;
               current->next->prev = current->prev;
               current = current->next;
               free(temp);
            }
         }  
      }
      current = current->next;
   }
}


//***********************************************************************************************************************FREE

void FREE(_node *(*head),_node*(*trhead)){
   _node *current;   
   while((*head)->next != NULL){
 current = (*head)->next;
(*head)->next = (*head)->next->next;
              
        free(current); // free        

       }
   free(*head);



_node*current2;

while((*trhead)->next != NULL){
 current2 = (*trhead)->next;
(*trhead)->next = (*trhead)->next->next;
              
        free(current2); // free        

       }
   free(*trhead);
}






//****************************************************************print
void printList(_node* (head))
{
    _node*temp = head;
    _node *last;
    printf("\nTraversal in forward direction \n");
    while (temp != NULL)
    {
        printf(" \n %s ", temp->name);
        last = temp;
        temp = temp->next;
    }
 
    printf("\nTraversal in reverse direction \n");
    while (last != NULL)
    {
        printf(" \n %s ", last->name);
        last = last->prev;
    }

/*printf("\n>>>>>>>>>>>>>>>>>>>TRASH<<<<<<<<<<<<<<<<<<<<<<<<<: \n");
     _node*temp2 = trhead;
    _node *last2;
    if(trhead = NULL){
        exit(0);
   }
    printf("\nTraversal in forward direction \n");    
    while (temp2 != NULL)
    {  
        printf(" \n %s ", temp->name);
        last2 = temp2;
        temp2 = temp2->next;
    }
 
    printf("\nTraversal in reverse direction \n");
    while (last2 != NULL)
    {
        printf(" \n %s ", last2->name);
        last2 = last2->prev;
    }*/


}
 
//**************************************************************************main
void main(void){
   //populate _node list from file
   FILE *stream;
   stream = fopen("./hw8.data", "r");

   size_t datasize;
   char *data,*op,*buffer; 

   _node *head = NULL; 
   _node **hp;
   hp = &head;
   _node *tail = NULL;
   _node **tp;
   tp = &tail;






//TRASH*****************************************************
    _node *trhead = NULL; 
   _node **trhp;
   trhp = &trhead;
   _node *trtail = NULL;
   _node **trtp;
   trtp = &trtail;
//******************************************************************** 
  while(1){
      buffer = NULL;
      getline(&buffer, &datasize, stream);
      data = strtok(buffer, " ");
      op = strtok(NULL, "\n");
      if(data == NULL && op == NULL){
         free(buffer);
         break;
      }//when you get to the end of the file
         if(op[0] == 'a' ||op[0] == ' '){
                 if(head == NULL){ // when you find the fist instance of 'a'
                    ADD(data, hp, tp);
                 }
         else{
         ADD(data, hp, tp);
                 }
              }
  if(op[0] == 'd'){
 DELETE(data, hp, tp,trhp,trtp);
 }
      free(buffer);
   }
   fclose(stream); //close file
   printList(head); //print list 
   printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>TRASH<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
   printList(trhead);
   FREE(hp,trhp); //free list 

}
