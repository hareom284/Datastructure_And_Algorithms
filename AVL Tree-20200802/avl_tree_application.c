/*
 * avl_tree_application.c
 *
 *  Created on: Mar 3, 2020
 *      Author: usha
 */

#include <stdio.h>
#include "avl_tree.h"

#define SIZE 12

int main() {
    AVLNODE *root;
    int key;

    root = createAVLTree();

    do {
        printf("Enter the key you want to add. -1 to exit.\n\n");
        scanf("%d", &key);
        if(key != -1) {
            root = insertItem(root, key);
            printf("\nAll the elements in the tree are:\n");
            displayBST(root, 0);
            printf("\n");
        }
    } while(key != -1);

    printf("\nPrinting the final tree:\n\n");
    displayBST(root, 0);
    printf("\n");

    return 1;
}
