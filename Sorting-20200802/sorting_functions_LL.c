/*
 * sorting_functions_LL.c
 *
 *  Created on: Jan 31, 2020
 *      Author: usha
 */

// Bubble sort algorithm using linked list

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "singly_LL_header.h"
#include "sorting.h"

void display(ITEM numb[], int size) {
   int i;

   // Navigate through all items
   for(i = 0;i < size; i++) {
      printf("%d\n",numb[i]);
   }

   printf("\n");
}

// Using an array - original algorithm
void bubbleSort_O(ITEM numb[], int size) {

	int i, j;
	ITEM temp;
	int noIter, noSwap;

	noIter = 0;
	noSwap = 0;
	for (i = 0; i < size-1; i++)
       for (j = 0; j < size-i-1; j++) {
    	   noIter++;
           if (numb[j] > numb[j+1]) {
                temp = numb[j];
                numb[j] = numb[j + 1];
                numb[j + 1] = temp;
                noSwap++;
           }
       }
    printf("Bubble Sort-Original: iterations - %d and swaps - %d\n",noIter, noSwap);
}

// Using an array - with boolean variable
void bubbleSort(ITEM numb[], int size) {

    int i;
    ITEM temp;
 	bool interchange;
	int noIter, noSwap;

	noIter = 0;
	noSwap = 0;
	interchange = true;
	while (interchange) { // Outer iteration
		interchange = false;
		for (i = 0; i < size-1; i++) // Inner iteration
			noIter++;
			if (numb[i] >= numb[i+1]) {
				temp = numb[i];
				numb[i] = numb[i+1];
				numb[i+1] = temp;
				interchange = true;
				noSwap++;
			}
	}
    printf("Bubble Sort-Modified: iterations - %d and swaps - %d\n",noIter, noSwap);
}

// Using linked list
void bubbleSort_LL(LinkedList *list) {

    bool interchange;
    ListNode *currentNode, *nextNode;
    ITEM temp;

    currentNode = list->head; // Setting to head of the list
	interchange = true;
	while (interchange) { // Outer iteration
		interchange = false;
		nextNode = currentNode->next; // Getting the next node to the current node
		while (nextNode != NULL) { // Inner iteration, equivalent to going until size - 1 in the array implementation
			if (currentNode->key > nextNode->key) { // Checking item at current node with the item at the next node
				// Perform swap of the elements, not the nodes
				temp = currentNode->key;
				currentNode->key = nextNode->key;
				nextNode->key = temp;
				interchange = true;
			}
			currentNode = nextNode; // To move forward in the list
			nextNode = nextNode->next;
		}
		currentNode = list->head;
	}
}

void insertionSort(ITEM numb[], int size) {

	ITEM value;
	int position, i;
	int noIter, noSwap;

	noIter = 0;
	noSwap = 0;
	for(i = 1; i < size; i++) {
		value = numb[i];
		position = i;
		while (position > 0 && numb[position-1] > value) {
			noIter++;
			numb[position] = numb[position-1];
			position--;
		}
		if(position != i) {
			numb[position] = value;
			noSwap++;
		}
	}
    printf("Insertion sort: iterations - %d and swaps - %d\n",noIter, noSwap);
}

void insertionSort_LL(LinkedList *list) {

	ITEM value;
	ListNode *node, *posNode, *prevNode, *tNode;

	node = list->head->next;
	prevNode = list->head;
	while (node != NULL) {
		value = node->key;
		posNode = node;
		while (posNode != list->head && prevNode->key > value) {
			posNode->key = prevNode->key;
			posNode = prevNode;
			if (prevNode != list->head) {
				tNode = list->head;
				while (tNode->next != prevNode)
					tNode = tNode->next;
				prevNode = tNode;
			}
		}
		if (posNode != node)
				posNode->key = value;
		prevNode = node;
		node = node->next;
	}
}

void selectionSort(int numb[], int size) {

	int indexMin, i, j;
	ITEM temp;
	int noIter, noSwap;

	noIter = 0;
	noSwap = 0;
	for(i = 0; i < size-1; i++) {
		indexMin = i;
		for(j = i+1; j < size; j++) {
			noIter++;
			if(numb[j] < numb[indexMin])
				indexMin = j;
		}
		if(indexMin != i) {
			temp = numb[indexMin];
			numb[indexMin] = numb[i];
			numb[i] = temp;
			noSwap++;
		}
	}
    printf("Selection sort: iterations - %d and swaps - %d\n",noIter, noSwap);
}

void selectionSort_LL(LinkedList *list) {

	ListNode *nodeOuter, *nodeInner, *nodeMin;
	ITEM temp;

	nodeOuter = list->head;
	while (nodeOuter != NULL) {
		nodeMin = nodeOuter;
		nodeInner = nodeOuter->next;
		while (nodeInner != NULL) {
			if (nodeInner->key < nodeMin->key)
				nodeMin = nodeInner;
			nodeInner = nodeInner->next;
		}
		if (nodeMin != nodeOuter) {
			temp = nodeMin->key;
			nodeMin->key = nodeOuter->key;
			nodeOuter->key = temp;
		}
		nodeOuter = nodeOuter->next;
	}
}

