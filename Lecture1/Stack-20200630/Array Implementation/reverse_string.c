#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define STRINGSIZE 26

// Program to reverse a string
int main() {
    STACK *stackOfChar;
    char string[STRINGSIZE] ="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char poppedItem;
    int i;

    // Creating a stack of characters
    stackOfChar = (STACK *) create(stackOfChar);

    for (i = 0; i < STRINGSIZE; i++)
        push(stackOfChar,string[i]);

    printf("\n\tItem at top of stack, after pushing characters, is %c\n",topOfStack(stackOfChar));

    printf("\n\tOriginal string is %s\n", string);

    printf("\n\tReversed string is ");
    while ((poppedItem = pop(stackOfChar)) != '$') // You can also call the isEmpty function here (try it out!)
	printf("%c",poppedItem);
    
    printf("\n");

    printf("\n\tStack is now empty!\n\n"); // Ideally check for isEmpty condition before printing this statement (try it out!)
}
