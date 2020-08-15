/*
 * avl_tree_operations.c
 *
 *  Created on: Mar 3, 2020
 *      Author: Usha
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "avl_tree.h"
#include <stdbool.h>

// Create a new AVL Tree node
AVLNODE* createNode(ITEM key) {
    AVLNODE* temp = (AVLNODE*)malloc(sizeof(AVLNODE));
    temp->key = key;
    temp->right = NULL;
    temp->left = NULL;
    return temp;
}

// Create the AVL Tree
AVLNODE* createAVLTree() {
    return NULL;
}

//Returns the balance factor for a node
int getBalanceFactor(AVLNODE* node) {
    return (getHeight(node->left) - getHeight(node->right));
}

//Returns the height of the tree rooted at 'node'
int getHeight(AVLNODE* node) {
    int left_height = 0;
    int right_height = 0;

    if(node == NULL)
        return -1;
    else {
        left_height = getHeight(node->left);
        right_height = getHeight(node->right);

        if (left_height > right_height)
        	return left_height + 1;
        else
        	return right_height + 1;
    }
}

//Right rotates the sub-tree rooted at y
AVLNODE* rightRotate(AVLNODE* node) {

    // Saving the nodes that will be lost
    AVLNODE* leftChild = node->left;
    AVLNODE* rightChild = leftChild->right;

    //Performing the rotation
    leftChild->right = node;
    node->left = rightChild;

    return leftChild;
}

//Left rotates the sub-tree rooted at x
AVLNODE* leftRotate(AVLNODE* node) {
    //printf("\tImplementing a left rotate on %d\n", x->key);

    //First saving the nodes which will be lost
    AVLNODE* rightChild = node->right;
    AVLNODE* leftChild = rightChild->left;

    //Performing the rotation
    rightChild->left = node;
    node->right = leftChild;

    return rightChild;
}

//Inserts a new node in the tree rooted at 'root' and balances the tree
AVLNODE* insertItem(AVLNODE* root, ITEM key) {
    int balance = 0;

    //Performing normal insertion in a binary search tree first
    if(root == NULL)
        root = createNode(key);
    else {
        if(key <= root->key)
            root->left = insertItem(root->left, key);
        else
            root->right = insertItem(root->right, key);
    }

    //Now, if the tree is not balanced, we must balance it accordingly

    balance = getHeight(root->left) - getHeight(root->right);

    //Left Left Case
    if(balance > 1 && key < root->left->key) {
        return(rightRotate(root));
    }

    //Right Right Case
    if(balance < -1 && key > root->right->key) {
        return(leftRotate(root));
    }

    //Left Right Case
    if(balance > 1 && key > root->left->key) {
        root->left = leftRotate(root->left);
        return(rightRotate(root));
    }

    //Right Left Case
    if(balance < -1 && key < root->right->key) {
        root->right = rightRotate(root->right);
        return(leftRotate(root));
    }
    return root;
}

// Traversal of tree using inorder method
void inOrderTraversal(AVLNODE *root) {
    if(root != NULL) {
        inOrderTraversal(root->left);
        printf("\tKey: %d\t%d\n", root->key, getHeight(root));
        inOrderTraversal(root->right);
    }
}

//Displays a BST like a tree
void displayBST(AVLNODE* root, int space) {
    int i;
    if(root == NULL)
        return;
    else {
        displayBST(root->right, space + HORIZONTAL_GAP);
        printf("\n");
        for(i = 1; i <= space; i++)
            printf(" ");
        printf("%d\n", root->key);
        displayBST(root->left, space + HORIZONTAL_GAP);
    }
}

int sizeTree(AVLNODE *root) {

	if (root == NULL)
		return 0;
	else
		return (sizeTree(root->left) + 1 + sizeTree(root->right));
}

AVLNODE* findMin(AVLNODE* root) {
    if (root == NULL)
        return NULL;
    else
        if (root->left == NULL)
            return root;
        else
            return findMin(root->left);
}

// Removes the node that contains the item and returns the node of the parent, if found
AVLNODE* deleteNode(AVLNODE* root, ITEM key) {
	AVLNODE *temp;

	int bfRoot, bfRootLeft, bfRootRight;

	bfRoot = 0;

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

    	if (root == NULL)
    		return root;

    	bfRoot = getBalanceFactor(root);
    	if (root->left != NULL)
    		bfRootLeft = getBalanceFactor(root->left);
    	if (root->right != NULL)
    		bfRootRight = getBalanceFactor(root->right);

        // If this node becomes unbalanced, then there are 4 cases

        // Left Left Case
        if (bfRoot > 1 && bfRootLeft >= 0) {
        	printf("Left Left case found\n\n");
            return rightRotate(root);
        }

        // Right Right Case
        if (bfRoot < -1 && bfRootRight <= 0) {
        	printf("Right Right case found\n\n");
            return leftRotate(root);
        }

        // Left Right Case
        if (bfRoot > 1 && bfRootLeft < 0) {
        	printf("Left Right case found\n\n");
            root->left =  leftRotate(root->left);
            return rightRotate(root);
        }

        // Right Left Case
        if (bfRoot < -1 && bfRootRight > 0) {
        	printf("Right Left case found\n\n");
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
    return root;
}

/* Function to print level order traversal a tree*/
void breadthWise(AVLNODE* root)
{
    int i, height;

    height = getHeight(root);
    for (i = 1; i <= height+1; i++)
        displayBreadthWise(root, i);
}

//Displays a BST like a tree
void displayBreadthWise(AVLNODE* root, int level) {

	    if (root == NULL)
	        return;

	    if (level == 1)
	        printf("%d ", root->key);
	    else if (level > 1) {
	    	displayBreadthWise(root->left, level-1);
	    	displayBreadthWise(root->right, level-1);
	    }
}
