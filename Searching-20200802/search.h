/*
 * searching.h
 *
 *  Created on: Feb 10, 2020
 *      Author: usha
 */

#include <stdbool.h>

#define SIZE 1000

typedef int ITEM;

#ifndef SEARCH_H_
#define SEARCH_H_

bool linearSearch(ITEM [], ITEM, int);
bool binarySearch(ITEM [], ITEM, int);
bool jumpSearch(ITEM [], ITEM, int, int);
int hash(ITEM);
bool hashBasedSearch(ITEM [], ITEM, int);

#endif /* SEARCH_H_ */
