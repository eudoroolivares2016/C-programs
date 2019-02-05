#include "hw12-main.h"
#include <dlfcn.h>
int main() {

//****************
void* handle;

void (*INSERT)(_node*(*tree), _node* item);
handle = dlopen("libmy-4.so",RTLD_LAZY);
if(!handle) printf("%s\n",dlerror());
INSERT = dlsym(handle,"insert");

//***********


      
    _node *current, *root;
    int x;
    root = NULL;
    FILE *stream = fopen("hw9.data", "r");
    while (fscanf(stream, "%d", &x) == 1) {
        current = (_node*)malloc(sizeof(_node));
        current->left = current->right = NULL;
        current->val = x;
        (*INSERT)(&root, current);
    }

 

void (*INORDER)(_node* tree);
if(!handle) printf("%s\n",dlerror());
INORDER = dlsym(handle,"inOrder");
   printf("\nInorder:\n");
    (*INORDER)(root);

//*******************************************************************
void (*PREORDER)(_node* tree);
if(!handle) printf("%s\n",dlerror());
PREORDER = dlsym(handle,"preOrder");
printf("\nPreorder:\n");
(*PREORDER)(root);    
//*******************************************************

void (*POSTORDER)(_node*tree);
if(!handle) printf("%s\n",dlerror());
POSTORDER = dlsym(handle,"postOrder");
printf("\nPostorder:\n");
(*POSTORDER)(root);
//*********************************************************************************************************
//avoid memory leak by calling setting the root to NULL
    //FREE(root);
    fclose(stream);
    root = NULL;
dlclose(handle);
return 0;
}


