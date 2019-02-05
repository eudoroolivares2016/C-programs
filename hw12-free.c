

#include "hw12-free.h"
struct myTree {
    int val;
    struct myTree *right, *left;
}; 

void FREE(_node *node){
       if (node != NULL) {
        FREE(node->right);
        FREE(node->left);
        free(node);
     }
}
