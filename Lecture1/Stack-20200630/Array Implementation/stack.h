#include <stdio.h>
#include <stdbool.h>

#define SIZE 100

typedef char ITEM;

typedef struct stack {
   ITEM stack[SIZE];
   int top;
} STACK;

STACK* create(STACK*);
int push(STACK*, ITEM);
ITEM pop(STACK*);
ITEM topOfStack(STACK*);
bool isEmpty(STACK*);
bool isFull(STACK*);
