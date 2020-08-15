#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "BST.h"

// Create a new tree node
BSTNODE* createNode(ITEM key) {

    BSTNODE *temp = (BSTNODE*) malloc(sizeof(BSTNODE));
    temp->key = key;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Create the binary search tree
BSTNODE* createBSTree() {
    return NULL;
}

// Insert a node in the tree
BSTNODE* insertItem(BSTNODE *root, ITEM key) {

    if (root == NULL)
        root = createNode(key);
    else {
        if (key <= root->key)
            root->left = insertItem(root->left, key);
        else
            root->right = insertItem(root->right, key);
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

// Traversal of tree using postorder method
void postOrderTraversal(BSTNODE *root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("\t%d\n", root->key);
    }
}

// Traversal of tree using preorder method
void preOrderTraversal(BSTNODE *root) {
    if (root != NULL) {
        printf("\t%d\n", root->key);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

// Returns true if the node is an internal node, esle false
bool isInternal(BSTNODE* node) {
    if (node->left != NULL || node->right != NULL)
        return true;
    else
        return false;
}

// Returns true if the node is a leaf node, else false
bool isLeaf(BSTNODE* node) {
    if (node->left == NULL && node->right == NULL)
        return true;
    else
        return false;
}

// Returns true if the node has a left node, else false
bool hasLeftChild(BSTNODE* node) {
    if (node->left != NULL)
        return true;
    else
        return false;
}

// Returns true if the node has a right node, else false
bool hasRightChild(BSTNODE* node) {
    if (node->right != NULL)
        return true;
    else
        return false;
}

// Returns the left node, if it exists, of the node
BSTNODE* getLeftChild(BSTNODE* node) {
    return node->left;
}

// Returns the right node, if it exists, of the node
BSTNODE* getRightChild(BSTNODE* node) {
    return node->right;
}

// Find the node with the minimum key in the binary search tree
BSTNODE* findMin(BSTNODE* root) {
    if (root == NULL)
        return NULL;
    else
        if (root->left == NULL)
            return root;
        else
            return findMin(root->left);
}

int sizeTree(BSTNODE *root) {

	if (root == NULL)
		return 0;
	else
		return (sizeTree(root->left) + 1 + sizeTree(root->right));
}

// Returns the number of nodes in the tree, tree may be a subtree
/*int sizeTree(BSTNODE *root) {
    int count = 1;

    if (root->left != NULL)
        count = count + sizeTree(root->left);
    if (root->right != NULL)
        count = count + sizeTree(root->right);

    return count;
}*/

// Returns true if the node is a left node, else false (when parent node is not available)
bool isLeftChild(BSTNODE* root, BSTNODE* node) {

	if (node == NULL)
		return false;
	if (root == NULL)
		return false;
	if (root->left == node)
		return true;
	else
		if (node->key <= root->key)
			return(isLeftChild(root->left,node));
		else
			return(isLeftChild(root->right,node));
}

bool isRightChild(BSTNODE* root, BSTNODE* node) {

	if (node == NULL)
		return false;
	if (root == NULL)
		return false;
	if (root->right == node)
		return true;
	else
		if (node->key <= root->key)
			return(isLeftChild(root->left,node));
		else
			return(isLeftChild(root->right,node));
}



// Returns the node when the item is found in the binary search tree, otherwise NULL
BSTNODE* findNode(BSTNODE* root, ITEM key){
    BSTNODE *temp;

    temp = root;
    while (temp != NULL)
        if (key == temp->key)
            return temp;
        else
            if (key <= temp->key)
                temp = temp->left;
            else
                temp = temp->right;
    return temp;
}

// Removes the node that contains the item and returns the node of the parent, if found
BSTNODE* deleteNode(BSTNODE* root, ITEM key) {
    BSTNODE *temp;

    if (root == NULL)
        return NULL;

    if (key < root->key)
        root->left = deleteNode(root->left,key);
    else
        if (key > root->key)
            root->right = deleteNode(root->right,key);
        else {// This is the node to be deleted
            if (root->left == NULL) {
                temp = root->right;
                free(root);
                return temp;
            }
            else if (root->right == NULL) {
                temp = root->left;
                free(root);
                return temp;
            }
            temp = findMin(root->right);
            root->key = temp->key;

            root->right = deleteNode(root->right, temp->key);
        }
        return root;
}