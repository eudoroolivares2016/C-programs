#include "hw12-A.h"



void preOrder(_node* tree) {

    printf("%d\n", tree->val);

    if (tree->left != NULL) {
        preOrder(tree->left);
    }

    if (tree->right != NULL) {
        preOrder(tree->right);
    }

}
