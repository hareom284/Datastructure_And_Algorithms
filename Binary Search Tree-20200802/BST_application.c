#include <stdlib.h>
#include <stdio.h>
#include "BST.h"

BSTNODE* readData(BSTNODE*);

int main() {

   BSTNODE *root, *node, *parentNode;
    ITEM key;

    key = 0;
    root = createBSTree();
    root = readData(root);

    printf("\nPrinting the elements in ascending order\n");
    inOrderTraversal(root);
    printf("\n");

    printf("Enter key t/o search in BST: ");
    scanf("%d",&key);

    if (findNode(root,key))
    	printf("%d found in BST!\n", key);
	else
		printf("%d not found in BST!\n",key);

    node = root;
    printf("Left child of [%d] is [%d]\n",node->key, getLeftChild(node)->key);

    node = root->right;
    printf("Right20 child of [%d] is [%d]\n",node->key, getRightChild(node)->key);

    if (isLeftChild(root, node))
    	printf("Node with key %d is a left child\n",node->key);
    else
    	if (node != NULL)
    		printf("Node with key %d is not a left child\n",node->key);
    	else
    		printf("Node cannot be a left child as it is a null node!");

    printf("Size of tree is %d\n\n",sizeTree(root));

    inOrderTraversal(root);

    deleteNode(root,6);
    printf("Size of tree is %d\n\n",sizeTree(root));

    inOrderTraversal(root);

    deleteNode(root,18);
    printf("Size of tree is %d\n\n",sizeTree(root));

    inOrderTraversal(root);

    //node = root;
    //node = root->right;
    //node = root->left;
    //node = root->right->left->right;
    node = root->left->left->left;
    if (node != root) {
    	parentNode = parent(root, node);
        if (parentNode == NULL)
        	printf("Node is not part of this BST\n\n");
        else
        	printf("Parent of [%d] is [%d]\n\n",node->key, parentNode->key);
    }
    return 1;

    return 1;
}

BSTNODE* readData(BSTNODE *root) {

	    int i, key;
		FILE *fp;

		i = 0;
		//Opening the file for reading
		fp =  fopen("numbers.txt", "r");
		if (fp == NULL)
			printf("\nError opening file.\n");
		 else {
		    // Checking for empty by going to the end of the file
		    fseek(fp, 0, SEEK_END);
		    if (ftell(fp) == 0)
		    	printf("\nFile is empty!\n");
		    else {
		    	// Getting back to the beginning of the file
		    	fseek(fp, 0, SEEK_SET);
		    	// Reading data from the file
		    	do {
		    		fscanf(fp, "%d", &key);
		    		root = insertItem(root,key); // To make root point to the root of the tree
		    		i++;
		    	} while (!feof(fp));
		    }
		 }
		 fclose(fp);
		 printf("Number of elements is %d\n",i);
		 return root;
}
