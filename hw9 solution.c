include<stdlib.h> 
#include<stdio.h> 

struct myTree { 
   int value; 
   struct myTree *right, *left; 
}; 

struct myList {
   struct myList *next;
   struct myTree *tree;
};

typedef struct myTree _tree; 
typedef struct myList _list; 

/************************************************/
/* Insert into binary tree.			*/
/************************************************/
void INSERT(_tree *(*tree), _tree *item) { 
  if (!(*tree)) { 
     *tree = item;
     return; 
  } 
  if (item->value < (*tree)->value)      INSERT(&(*tree)->left, item); 
  else if (item->value > (*tree)->value) INSERT(&(*tree)->right, item); 
} 

/************************************************/
/* Pre-order tree traversal.			*/
/************************************************/
void PRE_TRAVERSE(_tree *tree) { 
  printf("%d ",tree->value); 
  if (tree->left != NULL) PRE_TRAVERSE(tree->left); 
  if (tree->right != NULL) PRE_TRAVERSE(tree->right); 
} 

/************************************************/
/* In-order tree traversal.			*/
/************************************************/
void IN_TRAVERSE(_tree *tree) { 
  if (tree->left != NULL) IN_TRAVERSE(tree->left); 
  printf("%d ",tree->value); 
  if (tree->right != NULL) IN_TRAVERSE(tree->right); 
} 

/************************************************/
/* Post-order tree traversal.			*/
/************************************************/
void POST_TRAVERSE(_tree *tree) { 
  if (tree->left != NULL) POST_TRAVERSE(tree->left); 
  if (tree->right != NULL) POST_TRAVERSE(tree->right); 
  printf("%d ",tree->value); 
} 

/************************************************/
/* Linked list traversal.			*/
/************************************************/
void LIST_TRAVERSE(_list *head) { 
_list *current;
  current = head;
  while (current != NULL) {
     printf("%d ",current->tree->value); 
     current = current->next;
  }
} 

/************************************************/
/* Linked list & tree free.			*/
/************************************************/
void FREE(_list *head) { 
_list *current, *temp;
  current = head;
  while (current != NULL) {
     temp    = current;
     current = current->next;
     free(temp->tree);
     free(temp);
  }
} 

/************************************************/
/* Main.					*/
/************************************************/
void main() { 
int data;
FILE *stream;
_tree *current, *root; 
_list *pointer, *head;
  root = NULL; 
  head = NULL;
  stream = fopen("hw9.data", "r");
  while (1) {
      fscanf(stream, "%d", &data);
      if (feof(stream)) break;
      // Here we build the tree as normal.
      current = (_tree *)malloc(sizeof(_tree)); 
      current->left = current->right = NULL; 
      current->value = data; 
      INSERT(&root, current);
      // Here we build a linked list and point each node to a leaf in the tree.
      pointer = (_list *)malloc(sizeof(_list)); 
      pointer->tree = current;
      pointer->next = head;
      head    = pointer;
  } 
  fclose(stream);
  // Tree traversals.
  printf("Pre order:\t");
  PRE_TRAVERSE(root); 
  printf("\nIn order:\t");
  IN_TRAVERSE(root); 
  printf("\nPost order:\t");
  POST_TRAVERSE(root); 
  // Linked list traversal.
  printf("\nLinked list:\t");
  LIST_TRAVERSE(head);
  printf("\n");
  FREE(head);
  root = NULL;	// Not really required, but good practice.
  head = NULL;	// Not really required, but good practice.
} 

