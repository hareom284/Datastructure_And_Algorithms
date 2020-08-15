#ifndef BST_H_
#define BST_H_

#include <stdio.h>
#include <stdbool.h>

typedef int ITEM;

typedef struct node {
    ITEM key;
    struct node *left;
    struct node *right;
} BSTNODE;

BSTNODE* createNode(ITEM); // Create a new node
BSTNODE* createBSTree(); // Create a binary search tree
BSTNODE* insertItem(BSTNODE*, ITEM); // Insert an item into the binary search tree
BSTNODE* deleteNode(BSTNODE*, ITEM); // Removes the node that contains the item

void inOrderTraversal(BSTNODE*); // Traversal of tree using inorder method
void postOrderTraversal(BSTNODE*); // Traversal of tree using postorder method
void preOrderTraversal(BSTNODE*); // Traversal of tree using preorder method

bool isInternal(BSTNODE*); // Returns true if the node is an internal node, esle false
bool isLeaf(BSTNODE*); // Returns true if the node is a leaf node, else false

bool hasLeftChild(BSTNODE*); // Returns true if the node has a left node, else false
bool hasRightChild(BSTNODE*); // Returns true if the node has a right node, else false

BSTNODE* getLeftChild(BSTNODE*); // Returns the left node, if it exists, of the node
BSTNODE* getRightChild(BSTNODE*); // Returns the right node, if it exists, of the node

bool isLeftChild(BSTNODE*, BSTNODE*); // Returns true if the node is a left node, else false
bool isRightChild(BSTNODE*, BSTNODE*); // Returns true if the node is a left node, else false

BSTNODE* findMin(BSTNODE*); // Find the node with the minimum key in the binary search tree
BSTNODE* findNode(BSTNODE*, ITEM); // Returns the node when the item is found in the binary search tree

int sizeTree(BSTNODE*); // Returns the number of nodes in the tree, tree may be a subtree

#endif /* BST_H_ */
