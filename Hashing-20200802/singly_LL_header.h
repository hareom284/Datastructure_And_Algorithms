/*
 * singly_LL_header.h
 *
 *  Created on: Jan 31, 2020
 *      Author: usha
 */
#include <stdbool.h>
#include <string.h>

#ifndef SINGLY_LL_HEADER_H_
#define SINGLY_LL_HEADER_H_

// Declarations for a singly linked list

#define NAMELENGTH 40
#define JOBCODELENGTH 10

typedef int KEY;

typedef struct item {
	KEY employeeNumber;
	char employeeName[NAMELENGTH];
	char jobCode[JOBCODELENGTH];
} ITEM;

typedef struct ListNode
{
    ITEM key;
    struct ListNode *next;
} ListNode;

typedef struct LinkedList
{
    ListNode* head;
} LinkedList;

LinkedList* createList(void);
ListNode* createNode(ITEM);

void addNode(LinkedList*, ITEM);
void displayList(LinkedList*);
int sizeList(LinkedList*);
ListNode* deleteNode(LinkedList*, ITEM);
bool isEmpty(LinkedList*);
bool find(LinkedList*, KEY);

#endif /* SINGLY_LL_HEADER_H_ */
