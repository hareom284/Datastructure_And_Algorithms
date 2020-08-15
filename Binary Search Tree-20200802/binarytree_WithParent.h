#include <stdio.h>
#include <stdbool.h>

typedef int ITEM;

typedef struct node {
    ITEM key;
    struct node *left;
    struct node *right;
    struct node *parent;
} BSTNODE;

BSTNODE* createNode(ITEM); // Create a new node
BSTNODE* createBSTree(); // Create a binary search tree
BSTNODE* insertItem(BSTNODE*, ITEM); // Insert an item into the binary search tree

void inOrderTraversal(BSTNODE*); // Traversal of tree using inorder method

BSTNODE* parent(BSTNODE*); // Returns the parent of the node

bool isLeftChild(BSTNODE*); // Returns true if the node is the left child

bool sibling(BSTNODE*); // Returns the sibling of the node - either right or left, else NULL
