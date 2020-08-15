/*
 * binary_heap_application.c
 *
 *  Created on: Mar 10, 2020
 *      Author: usha
 */

#include <stdio.h>
#include <stdbool.h>
#include "binary_heap.h"

void readData(ITEM[]);

int main() {

	ITEM binaryHeap[SIZE];

	for (int i = 0; i < SIZE; i++)
		binaryHeap[i] = 0; // Assumed that no key has a value zero

	readData(binaryHeap);

	printf("Size of heap is %d\n\n",sizeHeap(binaryHeap));

	displayHeap(binaryHeap);

	delete(binaryHeap);
	displayHeap(binaryHeap);

	delete(binaryHeap);
	displayHeap(binaryHeap);

	return 1;
}

void readData(ITEM binaryHeap[]) {

	    int count, key;
		FILE *fp;

		count = 0;
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
		    		insert(binaryHeap,key);
		    		count++;
		    	} while (!feof(fp));
		    }
		 }
		 fclose(fp);
		 printf("Number of elements is %d\n",count);
}
