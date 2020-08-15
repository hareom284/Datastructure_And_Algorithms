/*
 * sorting_main.c
 *
 *  Created on: Jan 31, 2020
 *      Author: usha
 */
#include<stdio.h>
#include<string.h>
#include"singly_LL_header.h"
#include "sorting.h"
#include<time.h>

#define SIZE 1000

void display(ITEM[],int);

// Main program that tests all sorting functions
int main() {

    ITEM number, numbers1[SIZE], numbers2[SIZE], numbers3[SIZE];
    LinkedList* list1, *list2, *list3;
    int i, j;
	clock_t time;
	float elapsed[6];
	char sortNames[6][30];

	FILE *fp;

	list1 = createList();
	list2 = createList();
	list3 = createList();
	i = 0;
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
				fscanf(fp, "%d", &number);
				addNode(list1,number);
				addNode(list2,number);
				addNode(list3,number);
				numbers1[i] = number;
				numbers2[i] = number;
				numbers3[i] = number;
				i++;
			} while (!feof(fp));
		}
	}
	fclose(fp);
	printf("Number of elements is %d\n",i);

	j = 0;
	time = clock();
	bubbleSort_O(numbers1,i);
	elapsed[j] = ((float)(clock() - time)) / CLOCKS_PER_SEC;

	j++;
	time = clock();
	selectionSort(numbers2,i);
	elapsed[j] = ((float)(clock() - time)) / CLOCKS_PER_SEC;

	j++;
	time = clock();
	insertionSort(numbers3,i);
	elapsed[j] = ((float)(clock() - time)) / CLOCKS_PER_SEC;

	j++;
	time = clock();
	bubbleSort_LL(list1);
	elapsed[j] = ((float)(clock() - time)) / CLOCKS_PER_SEC;

	j++;
	time = clock();
	insertionSort_LL(list2);
	elapsed[j] = ((float)(clock() - time)) / CLOCKS_PER_SEC;

	j++;
	time = clock();
	selectionSort_LL(list3);
	elapsed[j] = ((float)(clock() - time)) / CLOCKS_PER_SEC;

	strcpy(sortNames[0],"Bubble Sort-Array");
	strcpy(sortNames[1],"Selection Sort-Array");
	strcpy(sortNames[2],"Insertion Sort-Array");
	strcpy(sortNames[3],"Bubble Sort-LL");
	strcpy(sortNames[4],"Selection Sort-LL");
	strcpy(sortNames[5],"Insertion Sort-LL");
	printf("\n");
    for (i = 0; i < 6; i++)
        printf("Elapsed time of %s is %f\n", sortNames[i],elapsed[i]);
	return 1;
}


