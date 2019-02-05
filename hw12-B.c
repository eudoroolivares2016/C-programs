#include "hw12-B.h"


void inOrder(_node* tree) {
    if (tree->left != NULL) {
        inOrder(tree->left);
    }

    printf("%d\n", tree->val);
    if (tree->right != NULL){
        inOrder(tree->right);
    }

}
