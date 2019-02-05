#include "hw12-D.h"

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
