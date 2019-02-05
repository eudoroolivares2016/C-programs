#include "hw12-C.h"


void postOrder(_node* tree) {
    if (tree->left != NULL) {
         postOrder(tree->left);
    }

    if (tree->right != NULL) {
        postOrder(tree->right);
    }
    printf("%d\n", tree->val);
}
