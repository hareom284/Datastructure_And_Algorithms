#include <stdlib.h>
#include <stdio.h>
#include "binarytree.h"

#define SIZE 12

int main() {

    BSTNODE *root, *node, *temp;
    int numbers[SIZE] = {14, 12, 10, 8, 28, 24, 32, 36, 24, 16, 20, 99};
    int i, item;

    root = createBSTree();

    i = 0;

    while (i < SIZE) {
        if (root == NULL)
            root = insertItem(root, numbers[i]);
        else
            insertItem(root, numbers[i]);
        i++;
    }

    printf("\nItems in ascending order:\n");
    inOrderTraversal(root);

    node = root->right;

    if (node == NULL)
        printf("No parent!");
    else
        printf("The parent of the node is %d\n", parent(node)->key);

    printf("\n");

    node = root;

    if (isLeftChild(node))
        printf("The node is a left child!\n");
    else
        if (node == root)
            printf("Root does not have a parent!\n");
        else
            printf("The node is not a left child!\n");
    printf("\n");

    node = root->right->right->left;

    if (sibling(node))
        printf("YES\n");
    else
        printf("NO\n");

    return 1;
}
