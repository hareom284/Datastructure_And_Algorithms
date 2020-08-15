#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "binarytree.h"

// Create a new tree node
BSTNODE* createNode(ITEM key) {

    BSTNODE *temp = (BSTNODE*) malloc(sizeof(BSTNODE));
    temp->key = key;
    temp->left = NULL;
    temp->right = NULL;
    temp->parent = NULL;
    return temp;
}

// Create the binary search tree
BSTNODE* createBSTree() {
    return NULL;
}

// Insert an item in the tree
BSTNODE* insertItem(BSTNODE *root, ITEM key) {

    if (root == NULL)
        root = createNode(key);
    else {
        if (key <= root->key) {
            root->left = insertItem(root->left, key);
            root->left->parent = root; // Parent added to the node
        }
        else {
            root->right = insertItem(root->right, key);
            root->right->parent = root; // Parent added to the node
        }
    }
    return root;
}

// Traversal of tree using inorder method
void inOrderTraversal(BSTNODE *root) {

    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("\t%d\n", root->key);
        inOrderTraversal(root->right);
    }
}

// Returns the parent of the node; root and node are passed as arguments
BSTNODE* parent(BSTNODE* node) {

    if (node != NULL)
        return node->parent;
    else
        return NULL;
}

// Returns true if the node is a left node, else false
bool isLeftChild(BSTNODE* node) {
    BSTNODE* temp;

    if (node == NULL)
        return false;
    temp = node->parent;
    if (temp == NULL)
        return false; // Root node does not have a parent
    if (temp->left == node)
        return true; // If the left node of the parent is equal to node then it is the left child
    else
        return false; // If the left node of the parent is not equal to node then it is the left child
}

bool sibling(BSTNODE* node) {
    BSTNODE* temp;

    if (node == NULL)
        return false;

    temp = node->parent;
    if (temp == NULL)
        return false; // Root node does not have a parent
    if (temp->left == node)
        if (temp->right != NULL)
            return true;
        else
            return false;
    else
        if (temp->left != NULL)
            return true;
        else
            return false;
}
