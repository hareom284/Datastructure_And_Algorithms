/*
 * searching_main.c
 *
 *  Created on: Feb 10, 2020
 *      Author: usha
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "search.h"
#include <time.h>

void display(ITEM[],int);

// Main program that tests all sorting functions
int main() {

	// Input data set is available in two files - one is ordered and the other unordered
	// In applications, lists are not expected to be sorted-one of the sort functions should be called on the unordered input dataset
    ITEM unorderedList[SIZE], orderedList[SIZE],numberHashTable[SIZE*2];
    int i, j, number, blockSize, hashedValue, countCollision, orderedListSize, unorderedListSize;
	clock_t time;
	float elapsed[4];
	char searchNames[4][30];
	ITEM input;
	bool found, stored, counted;

	FILE *fp1, *fp2;

	// Initializing the hash table
	for (i = 0; i < SIZE*2; i++)
		numberHashTable[i] = -1; // Assuming list of keys are positive integers

	countCollision = 0;
	i = 0;
	//Opening the file for reading
	fp1 = fopen("numbers.txt", "r");
	if (fp1 == NULL)
		printf("\nError opening numbers.txt\n");
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
				fscanf(fp1, "%d", &number);
				orderedList[i] = number;
				i++;
			} while (!feof(fp1));
		}
	}
	fclose(fp1);
	orderedListSize = i;
	i = 0;
	fp2 = fopen("forhashing.txt", "r");
	if (fp2 == NULL)
		printf("\nError opening forhashing.txt\n");
	else {
		// Checking for empty by going to the end of the file
		fseek(fp2, 0, SEEK_END);
		if (ftell(fp2) == 0)
			printf("\nFile is empty!\n");
		else {
			// Getting back to the beginning of the file
			fseek(fp2, 0, SEEK_SET);
			// Reading data from the file
			do {
				fscanf(fp2, "%d", &number);
				unorderedList[i] = number;
				hashedValue = hash(number);
				stored = false;
				counted = false;
				do {
					if (numberHashTable[hashedValue] == -1) {
						numberHashTable[hashedValue] = number;
						stored = true;
					}
					else {
						hashedValue++;
						if (!counted) {
							countCollision++;
							counted = true;
						}
					}
				} while (!stored);
				i++;
			} while (!feof(fp2));
		}
		printf("Number of collisions: %d\n", countCollision);
	}
	fclose(fp2);
	unorderedListSize = i;
	printf("Number of elements is %d\n",i);

	printf("Enter the item to be searched: ");
	scanf("%d",&input);
	printf("\n");

	j = 0;
	time = clock();
	found = linearSearch(unorderedList,input,unorderedListSize);
	elapsed[j] = ((float)(clock() - time));
	if (found)
		printf("Linear Search: %d found in the list!\n",input);
	else
		printf("Linear Search: %d not found in the list\n",input);

	j++;
	time = clock();
	found = binarySearch(orderedList,input,orderedListSize);
	elapsed[j] = ((float)(clock() - time));
	if (found)
		printf("Binary Search: %d found in the list!\n",input);
	else
		printf("Binary Search: %d not found in the list\n",input);

	j++;
	printf("For jump search, enter the block size:");
	scanf("%d",&blockSize);
	time = clock();
	found = jumpSearch(orderedList,input, blockSize,orderedListSize);
	elapsed[j] = ((float)(clock() - time));
	if (found)
		printf("Jump Search: %d found in the list!\n",input);
	else
		printf("Jump Search: %d not found in the list\n",input);

	j++;
	time = clock();
	found = hashBasedSearch(numberHashTable,input,unorderedListSize);
	elapsed[j] = ((float)(clock() - time));
	if (found)
		printf("Hash-based Search: %d found in the list!\n",input);
	else
		printf("Hash-based Search: %d not found in the list\n",input);

	strcpy(searchNames[0],"Linear Search");
	strcpy(searchNames[1],"Binary Search");
	strcpy(searchNames[2],"Jump Search");
	strcpy(searchNames[3],"Hash-based Search");

	printf("\n");
    for (i = 0; i < 4; i++)
        printf("Elapsed time of %s is %f\n", searchNames[i],elapsed[i]);
	return 1;
}



