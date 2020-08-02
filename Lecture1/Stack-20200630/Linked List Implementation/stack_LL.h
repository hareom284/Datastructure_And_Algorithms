#include <stdio.h>
#include <stdbool.h>

typedef char ITEM;

typedef struct snode {
   ITEM item;
   struct snode *next;
} SNODE;

typedef struct stack {
    SNODE *top;
} STACK;

STACK* createStack(STACK*);
SNODE* createNode(ITEM);
int push(STACK*, ITEM);
ITEM pop(STACK*);
ITEM topOfStack(STACK*);
bool isEmpty(STACK*);
bool isFull(STACK*);

