/*
 * avl_tree.h
 *
 *  Created on: Mar 3, 2020
 *      Author: usha
 */

#ifndef AVL_TREE_H_
#define AVL_TREE_H_

#include <stdio.h>
#include <stdbool.h>

#define HORIZONTAL_GAP 10

typedef int ITEM;

typedef struct avlnode
{
    ITEM key;
    struct avlnode *left;
    struct avlnode *right;
} AVLNODE;

AVLNODE* createNode(ITEM); // Creates a new node
AVLNODE* createAVLTree(); // Creates a binary search tree
AVLNODE* insertItem(AVLNODE*, ITEM); // Inserts an item into the binary search tree

int getHeight(AVLNODE*); // Returns the height of the tree rooted at the node
int getBalanceFactor(AVLNODE*); // Gets the balance factor for a node
int maximum(int, int); // Returns the maximum of two integers

AVLNODE* rightRotate(AVLNODE*); // Right rotates the sub-tree rooted at y
AVLNODE* leftRotate(AVLNODE*); // Left rotates the sub-tree rooted at x

void inOrderTraversal(AVLNODE*); // Traversal of tree using inorder method
void displayBST(AVLNODE*, int); //Displays a tree like a tree
int sizeTree(AVLNODE*); // Finding size of tree = number of nodes in the tree

#endif /* AVL_TREE_H_ */
