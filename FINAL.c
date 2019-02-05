#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct myTree {
    char* name;
    int val;
    struct myTree *right, *left;
}; 

typedef struct myTree _node;
//**************************************************************************************************************************************************
void insert(_node*(*tree), _node* item) {
    if (!(*tree)) {
        *tree = item;
        return;
    }
    if (item->val < (*tree)->val) {
        insert(&(*tree)->left, item);
    }

    else if (item->val > (*tree)->val) {
        insert(&(*tree)->right, item);
    }

}
//*************************************************************************************************************************************
void inOrder(_node* tree) {
    if (tree->left != NULL) {
        inOrder(tree->left);
    }

     printf("%d %s \n", tree->val, tree->name);
    if (tree->right != NULL){
        inOrder(tree->right);
    }

}
//******************************************************************************************************************************************
void preOrder(_node* tree) {
    printf("%d %s \n", tree->val, tree->name);

    if (tree->left != NULL) {
        preOrder(tree->left);
    }

    if (tree->right != NULL) {
        preOrder(tree->right);
    }

}
//*************************************************************************************************************************************************
void postOrder(_node* tree) {
    if (tree->left != NULL) {
         postOrder(tree->left);
    }

    if (tree->right != NULL) {
        postOrder(tree->right);
    }
      printf("%d %s \n", tree->val, tree->name);
}
//**********************************************************************************************************************
void FREE(_node *node){
       if (node != NULL) {
        FREE(node->right);
        FREE(node->left);
        free(node);
     }
}
//***************************************************************************************************************************************************
void main(int argv, char**argc) {


if (argv < 2){
      printf("Please enter a file to be opened.\n");
      exit(0);
   }
   if (argv > 2){
      printf("Please do not load more than a single file.\n");
      exit(0);
   } 
   _node *current, *root; //declare root and current
    char* buffer;
    char* number;//this will be the number and I will use atoi afterwards
    int x = 0;
    size_t datasize;
    char* ptr;
    char* stateName;
    root = NULL;
    FILE *stream = fopen(argc[1], "r"); // changed this so that it takes in a user argument
  while(1){
      buffer = NULL;
      getline(&buffer, &datasize, stream); //get each line of the code
      number = strtok(buffer, " "); //get the number as a character pointer which we will then cast
      stateName = strtok(NULL, "\n"); //get the name of the state up until the \n character 
      //printf("%s",stateName);
      if(number == NULL && stateName == NULL){
         free(buffer);
         break;} //once the user runs out of information          
        x = atoi(number); //change the string in strtoken into an integer
        current = (_node*)malloc(sizeof(_node));
        current->left = current->right = NULL;
       // printf(">>>>>>>>>%d<<<<<<<<<<<<<<<<",x); //test to see if the value was cast correctly
        current->val = x;
// take the string and use strncpy on it but, only take in the fist 3 characters 
        ptr = (char*)calloc(strlen(stateName),sizeof(char)+100);
        current->name = ptr;
        strncpy(current->name,stateName,2);
        insert(&root, current); //pass root which is a null pointer, and pass each line of hte new pointer
    }

    printf("\nInorder:\n");
    inOrder(root);

    printf("\nPreorder:\n");
    preOrder(root);

    printf("\nPostorder:\n");
    postOrder(root);
//*********************************************************************************************************
//avoid memory leak by calling setting the root to NULL
    FREE(root);
    fclose(stream);
    root = NULL;
}



