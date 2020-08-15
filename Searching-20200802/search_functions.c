/*
 * searching_functions.c
 *
 *  Created on: Feb 10, 2020
 *      Author: usha
 */

#include <stdio.h>
#include <stdbool.h>
#include "search.h"

bool linearSearch(ITEM list[], ITEM item, int size) {

	bool found;
	int i;

	found = false;
	for (i = 0; i < size; i++)
		if (list[i] == item)
			found = true;

	return found;
}

bool binarySearch(ITEM list[], ITEM item, int size) {

	int low, high, mid;

	bool found;

	found = false;
	low = 0;
	high = size;

	while ((!found) && (low <= high)) {

		mid = (low + high) / 2;
		if (list[mid] == item)
			found = true;
		else if (list[mid] < item)
				low = mid + 1;
			else
				high = mid - 1;
	}
	if (found)
		return true;
	else
		return false;
}

bool jumpSearch(ITEM list[], ITEM item, int blockSize, int size) {

	int i, j, blockEnd;
	bool found;

	found = false;
	i = 0;
	blockEnd = blockSize - 1;
	while (!found && i < size) {
		if (item == list[blockEnd]) {
			found = true;
		}
		else {
			if (item > list[blockEnd]) {
				blockEnd = blockEnd + blockSize;
				if (blockEnd > size - 1)
					blockEnd = size - 1;
				i = i + blockSize;
			}
			else {
				for (j = i; j < blockEnd; j++)
						if (item == list[j])
							found = true;
						if (!found)
							break;
			}
		}
	}
	return found;
}

int hash(ITEM key) {

	return (key % SIZE);
}

bool hashBasedSearch(ITEM list[], ITEM item, int size) {
	int hashedValue;
	bool found;

	hashedValue = hash(item);
	found = false;
	do {
		if (list[hashedValue] == item)
			found = true;
		else
			if (list[hashedValue] == -1)
				break;
			else
				hashedValue++;
	} while (!found && hashedValue != SIZE);
	return found;
}
