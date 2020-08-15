/*
 * binary_heap_operations.c
 *
 *  Created on: Mar 10, 2020
 *      Author: usha
 */

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "binary_heap.h"

// Insert an item in the binary heap
void insert(ITEM binaryHeap[], ITEM key) {
	int indexToInsert, parent, temp;

	indexToInsert = sizeHeap(binaryHeap); // Get the first open position in the heap
	binaryHeap[indexToInsert] = key; // Insert at the first open position in the heap

	while (indexToInsert > 0) { // As long the first node in the heap is reached
		if (indexToInsert % 2 == 0) // Checking whether right or left child to get the parent
			parent = (indexToInsert - 2) / 2;
		else
			parent = (indexToInsert - 1) / 2;
		if (binaryHeap[indexToInsert] > binaryHeap[parent]) { // Swap if the parent is smaller than the newly inserted node
			temp = binaryHeap[indexToInsert];
			binaryHeap[indexToInsert] = binaryHeap[parent];
			binaryHeap[parent] = temp;
		}
		indexToInsert = parent;
	}
}

// Since this is a max heap, deleting the item at root and adjusting the other nodes
ITEM delete(ITEM binaryHeap[]) {

	ITEM item, size, index, temp, j;
	bool kontinue;

	item = binaryHeap[0]; // Node to be deleted
	size = sizeHeap(binaryHeap);
	binaryHeap[0] = binaryHeap[size-1]; // Moving the last node to the root
	binaryHeap[size-1] = 0; // Setting to default value of 0

	size = size - 1; // Size has changed after deleting
	index = 0;
	kontinue = true;
	while (index < size - 1 && kontinue) {
		temp = binaryHeap[index];
		// Checking to trickle down the last node that was moved to the root
		if (temp < binaryHeap[2 * index + 1] || temp < binaryHeap[2 * index + 2]) {
			if (binaryHeap[2 * index + 1] < binaryHeap[2 * index + 2]) {
				binaryHeap[index] = binaryHeap[2 * index + 2];
				binaryHeap[2 * index + 2] = temp;
				index = 2 * index + 2;
			}
			else {
				binaryHeap[index] = binaryHeap[2 * index + 1];
				binaryHeap[2 * index + 1] = temp;
				index = 2 * index + 1;
			}
		}
		else
			kontinue = false; // If the node trickling down is greater than both its children, no more checks required
	}
	return item;
}

// Size of heap
int sizeHeap(ITEM binaryHeap[]) {

	int size, i;
	bool noMore;

	noMore = false;
	size = 0;
	for (i = 0; i < SIZE && !noMore; i++)
		if (binaryHeap[i] == 0)
			noMore = true;
		else
			size++;
	return size;
}

// Checking if the heap is empty
bool isEmpty(ITEM binaryHeap[]) {

	if (binaryHeap[0] == 0)
			return true;
		else
			return false;
}

// Getting the number of levels in the heap
int getLevels(ITEM binaryHeap[]) {
	int level, i, size;

	level = 0;
	if (!isEmpty(binaryHeap)) {
		size = sizeHeap(binaryHeap);
		i = 0;
		do {
			i = pow(2,level) - 1;
			level++;
		} while (i < size);
		level--; // Actual levels in the heap
		printf("Size: %d\tLevel: %d\n\n",size,level);
	}
	return level;
}

// Displaying the heap like a binary tree
// Will be limited by the space on the screen
void displayHeap(ITEM binaryHeap[]) {
	int level, i, j, k, m, index, horizontalSpace;

	level = getLevels(binaryHeap);
	i = 0;
	index = 0;
	horizontalSpace = 8;
	if (isEmpty(binaryHeap))
		printf("Heap is empty!");
	while (i < level) {
		for(k = 1; k <= horizontalSpace*(level-i); k++)
			printf(" ");
		m = pow(2,i);
		for (j = index; j < index + m; j++) {
			if (binaryHeap[j] != 0)
				printf("%d",binaryHeap[j]);
			for(k = 1; k <= horizontalSpace; k++)
				printf(" ");
		}
		index = index + m;
		i++;
		printf("\n\n\n");
	}
}
