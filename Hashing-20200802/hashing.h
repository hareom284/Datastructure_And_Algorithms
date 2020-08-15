/*
 * hashing.h
 *
 *  Created on: Feb 13, 2020
 *      Author: usha
 */

#include "singly_LL_header.h"

#ifndef HASHING_H_
#define HASHING_H_

#define SIZE 1000

typedef int ELEMENT;

int hash(KEY);
bool hashBasedSearchOpen(ITEM [], KEY, int);
bool hashBasedSearchChaining(LinkedList *[], KEY);

#endif /* HASHING_H_ */
