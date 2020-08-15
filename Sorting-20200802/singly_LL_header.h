/*
 * singly_LL_header.h
 *
 *  Created on: Jan 31, 2020
 *      Author: usha
 */
#include<stdbool.h>

#ifndef SINGLY_LL_HEADER_H_
#define SINGLY_LL_HEADER_H_

// Declarations for a singly linked list

typedef int ITEM;

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


#endif /* SINGLY_LL_HEADER_H_ */
