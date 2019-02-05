#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#ifndef _tree
#define _tree
struct myTree {
    int val;
    struct myTree *right, *left;
};
typedef struct myTree _node;
#endif
void insert(_node*(*tree), _node* item);

