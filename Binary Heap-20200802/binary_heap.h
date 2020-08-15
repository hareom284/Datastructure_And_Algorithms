/*
 * binary_heap.h
 *
 *  Created on: Mar 10, 2020
 *      Author: usha
 */

#ifndef BINARY_HEAP_H_
#define BINARY_HEAP_H_

#include <stdbool.h>

#define SIZE 20

typedef int ITEM;

void insert(ITEM[], ITEM);
ITEM delete(ITEM[]);
int sizeHeap(ITEM[]);
void displayHeap(ITEM[]);
bool isEmpty(ITEM[]);
int getLevels(ITEM[]);

#endif /* BINARY_HEAP_H_ */
