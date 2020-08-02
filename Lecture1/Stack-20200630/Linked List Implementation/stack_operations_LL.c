#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "stack_LL.h"

SNODE* createNode(ITEM item) {

	SNODE *temp = (SNODE *) malloc(sizeof(SNODE));

	if (temp != NULL) {
        	temp->item = item;
        	temp->next = NULL;
	}
	return temp;
}

STACK* createStack(STACK *stack) {

    stack = (STACK*) malloc(sizeof(STACK));
    stack->top = NULL;
    return stack;
}






int push(STACK *stack, ITEM item) {

    SNODE *temp = createNode(item);

    if (temp != NULL) { // If createNode returns a NULL it means there is no space to allocate a new node
        // When stack is empty, top of stack is set to the new node
        if (stack->top == NULL) {
            stack->top = temp;
            return 1;
        }
        else {// When stack is not empty, add the new node before the current top of stack and change top of stack to point to the new node
            temp->next = stack->top;
            stack->top = temp;
            return 1;
        }
    }
    else
        return 0;
}

ITEM pop(STACK *stack) {
    ITEM tempItem;
    SNODE *temp;

    if (isEmpty(stack))
        tempItem = '\0';
    else { // Assign the item at the top of stack before removing the node
        temp = stack->top;
        tempItem = temp->item;
        stack->top = temp->next;
        free(temp);
    }
    return tempItem;
}


bool isEmpty(STACK *stack) {

	if (stack->top == NULL)
		return true;
	else
		return false;
}

ITEM topOfStack(STACK *stack) {

	if (isEmpty(stack))
		return '\0';
	else
		return stack->top->item;
}
