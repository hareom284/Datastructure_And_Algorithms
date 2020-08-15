/*
 * hashing_main.c
 *
 *  Created on: Feb 13, 2020
 *      Author: usha
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "hashing.h"
#include "singly_LL_header.h"
#include <time.h>

void display(ITEM[],int);

// Main program that tests all sorting functions
int main() {

    ITEM openAddrHashTable[SIZE*2], key;
    LinkedList *chainedHashTable[SIZE];
    int i, j, hashedValue, countCollision, hashedValueChaining;
	clock_t time;
	float elapsed[2];
	char searchNames[2][50];
	KEY searchKey;

	bool found, stored, counted;

	FILE *fp1;

	// Initializing the hash table for open addressing
	for (i = 0; i < SIZE*2; i++)
		openAddrHashTable[i].employeeNumber = -1; // Assuming list of keys are positive integers

	// Initializing the hash table for chaining
		chainedHashTable[i] = createList(); // Creating a list for every slot in the hash table

	for (i = 0; i < 2; i++)
		elapsed[i] = 0;

	countCollision = 0;

	fp1 = fopen("employees.txt", "r");
	if (fp1 == NULL)
		printf("\nError opening employees.txt\n");
	else {
		// Checking for empty by going to the end of the file
		fseek(fp1, 0, SEEK_END);
		if (ftell(fp1) == 0)
			printf("\nFile is empty!\n");
		else {
			// Getting back to the beginning of the file
			fseek(fp1, 0, SEEK_SET);
			// Reading data from the file
			do {
				fscanf(fp1, "%d%s%s", &key.employeeNumber, key.employeeName, key.jobCode);
				hashedValue = hash(key.employeeNumber);
				hashedValueChaining = hashedValue;
				stored = false;
				counted = false;
				// To illustrate open addressing technique for hashing
				do {
					if (openAddrHashTable[hashedValue].employeeNumber == -1) {
						openAddrHashTable[hashedValue] = key;
						stored = true;
					}
					else {
						hashedValue++;
						if (!counted) {
							countCollision++;
							counted = true;
						}
					}
				// To illustrate separate chaining technique for hashing
				/*do {
					if ((chainedHashTable[hashedValue])->head == NULL) {
						addNode(chainedHashTable[hashedValue], key);
						displayList(chainedHashTable[hashedValue]);
						stored = true;
					}
					else {
						hashedValue++;
						if (!counted) {
							countCollision++;
							counted = true;
						}
					}*/
				} while (!stored);
				addNode(chainedHashTable[hashedValueChaining], key);
			} while (!feof(fp1));
		}
		printf("Number of collisions: %d\n", countCollision);
	}
	fclose(fp1);

	for (j = 0; j < SIZE; j++) {
		printf("%d: ",j);
		displayList(chainedHashTable[j]);
	}

	printf("Enter the item to be searched: ");
	scanf("%d",&searchKey);
	printf("\n");

	j = 0;
	time = clock();
	found = hashBasedSearchOpen(openAddrHashTable,searchKey,SIZE*2);
	elapsed[j] = ((float)(clock() - time));
	if (found)
		printf("Hash-based Search-Using Open Addressing: %d found in the list!\n",searchKey);
	else
		printf("Hash-based Search-Using Open Addressing: %d not found in the list\n",searchKey);

	j++;
	time = clock();
	found = hashBasedSearchChaining(chainedHashTable,searchKey);
	elapsed[j] = ((float)(clock() - time));
	if (found)
		printf("Hash-based Search-Using Chaining: %d found in the list!\n",searchKey);
	else
		printf("Hash-based Search-Using Chaining: %d not found in the list\n",searchKey);

	strcpy(searchNames[0],"Hash-based Search-Open Addressing");
	strcpy(searchNames[1],"Hash-based Search-Chaining");

	printf("\n");
    for (i = 0; i < 2; i++)
        printf("Elapsed time of %s is %f\n", searchNames[i],elapsed[i]);
	return 1;
}




