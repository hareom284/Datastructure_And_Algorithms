#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "stack.h"

STACK* create(STACK *s) {
    // Pointer to the top of the stack is set to -1
    // Stack is empty when top is -1
    s = (STACK *) malloc(sizeof(STACK));
    if (s != NULL) {
        s->top = -1;
        return s;
    }
    else
        return NULL;
}

int push(STACK *s, ITEM item) {
    // Checking if stack is full
    // No item can be pushed into a stack if it's already full
    if (!isFull(s)) {
        s->top = s->top + 1;
        s->stack[s->top] = item;
        return 1; // When pushing an element is successful
    }
    else
        return 0; // When stack is full
}

ITEM pop(STACK *s) {
    // Checking if stack is empty
    // No item can be popped from an empty stack
    ITEM poppedItem;

    if (!isEmpty(s)) {
        poppedItem = s->stack[s->top];
        s->top = s->top - 1;
        return poppedItem; // When popping an element is successful
    }
    else
        return '$'; // $ incidcates that the stack is empty and there is no meaningul element to return
}

ITEM topOfStack(STACK *s) {
    // Checking if stack is empty
    // Item at the top of the stack cannot be returned if the stack is empty

    if (!isEmpty(s))
        return s->stack[s->top];
    else {
        return '$'; // $ incidcates that the stack is empty and there is no meaningul element to return
    }
}
bool isEmpty(STACK *s) {
    // Return true if stack is empty else false
    if (s->top == -1)
        return true;
    else
        return false;
}

bool isFull(STACK *s) {
    // Return true if stack is full else false
    if (s->top == SIZE)
        return true;
    else
        return false;
}
