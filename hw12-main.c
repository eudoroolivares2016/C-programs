#include "hw12-main.h"

int  main() {
    _node *current, *root;
    int x;
    root = NULL;
    FILE *stream = fopen("hw9.data", "r");
    while (fscanf(stream, "%d", &x) == 1) {
        current = (_node*)malloc(sizeof(_node));
        current->left = current->right = NULL;
        current->val = x;
        insert(&root, current);
    }

    printf("\nInorder:\n");
    inOrder(root);

    printf("\nPreorder:\n");
    preOrder(root);

    printf("\nPostorder:\n");
   postOrder(root);
//*********************************************************************************************************
//avoid memory leak by calling setting the root to NULL
    //FREE(root);
    fclose(stream);
    root = NULL;
    return 0;
}


