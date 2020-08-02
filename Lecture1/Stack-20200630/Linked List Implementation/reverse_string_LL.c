#include <stdio.h>
#include <stdlib.h>
#include "stack_LL.h"

#define STRINGSIZE 26

// Program to reverse a string
int main() {
    STACK *stackOfChar;
    char string[STRINGSIZE] ="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char poppedItem;
    int i;

    // Creating a stack of characters
    stackOfChar = (STACK *) createStack(stackOfChar);

    for (i = 0; i < STRINGSIZE; i++)
        push(stackOfChar,string[i]);

    printf("\n\tItem at top of stack, after pushing characters, is %c\n",topOfStack(stackOfChar));

    printf("\n\tOriginal string is %s\n", string);

    printf("\n\tReversed string is ");
    for (i = 0; i < STRINGSIZE; i++) {
        poppedItem = pop(stackOfChar);
        if (poppedItem != '\0')
            printf("%c",poppedItem);
    }

    printf("\n");
    if (isEmpty(stackOfChar))
	printf("\n\tNo more items in the stack!\n\n");
    else
	printf("\n\tStack is not empty!\n\n");
}
