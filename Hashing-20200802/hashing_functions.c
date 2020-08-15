/*
 * hashing_functions.c
 *
 *  Created on: Feb 13, 2020
 *      Author: usha
 */

#include <stdio.h>
#include <stdbool.h>
#include "hashing.h"
#include "singly_LL_header.h"

int hash(KEY key) {

	return (key % SIZE);
}

bool hashBasedSearchOpen(ITEM list[], KEY key, int size) {

	int hashedValue;
	bool found;

	hashedValue = hash(key);
	found = false;
	do {
		if (list[hashedValue].employeeNumber == key)
			found = true;
		else
			if (list[hashedValue].employeeNumber == -1)
				break;
			else
				hashedValue++;
	} while (!found && hashedValue != size);
	return found;
}

bool hashBasedSearchChaining(LinkedList *list[], KEY key) {

	int hashedValue;
	bool found;

	hashedValue = hash(key);
	found = find(list[hashedValue],key);
	return found;
}

