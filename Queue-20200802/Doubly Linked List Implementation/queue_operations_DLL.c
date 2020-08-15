#include <stdlib.h>
#include <stdio.h>
#include "queue_DLL.h"

// To create a new node dynamically and set its data part to the value of the argument
QNODE* createNode(ITEM item) {

    QNODE *temp = (QNODE*) malloc(sizeof(QNODE));
    temp->item = item;
    temp->prev = NULL;
    temp->next = NULL;
    return temp;
}

// To create an empty queue
QUEUE* createQueue() {
    QUEUE *queue = (QUEUE*) malloc(sizeof(QUEUE));
    queue->front_queue = NULL;
    queue->rear_queue = NULL;
    return queue;
}

// Adding an item to the queue

int add(QUEUE *queue, ITEM item) {

    QNODE *temp = createNode(item);

    if (!isFull(queue)) {
    	// When queue is empty, front and rear of the queue is set to the new node
    	if (isEmpty(queue)) {
        	queue->front_queue = temp;
        	queue->rear_queue = temp;
    	}
    	else { // When queue is not empty, add the new node at the end of the queue and change the rear pointer
        	temp->prev = queue->rear_queue;
        	queue->rear_queue->next = temp;
        	queue->rear_queue = temp;
    	}
	return 1;
     }
     else
	return 0; // When Queue is full
}

// Removing an item from the queue

ITEM delete(QUEUE *queue) {
    ITEM tempItem;

    // Checking if QUEUE is empty
    // No item can be removed from an empty QUEUE
    if (isEmpty(queue))
        tempItem.appln_name[0] = '\0';
    else {
        // Store previous front and move front one node ahead
        QNODE *tempNode;
        tempNode = queue->front_queue;
        tempItem = queue->front_queue->item;
        queue->front_queue = queue->front_queue->next;
        if (queue->front_queue != NULL)
            queue->front_queue->prev = NULL;
        free(tempNode); // Free the node that contained the item at the front of the queue

        // If front becomes NULL, then change rear also as NULL
        if (queue->front_queue == NULL)
            queue->rear_queue = NULL;
    }
    return tempItem;
}

ITEM front_queue(QUEUE* queue) {
     ITEM tempItem;
    // Checking if QUEUE is empty before returning the item
    if (isEmpty(queue))
        tempItem.appln_name[0] = '\0';
    else
        return queue->front_queue->item;

    return tempItem;
}

bool isEmpty(QUEUE* queue) {

    if (queue->front_queue == NULL)
        return true;
    else
        return false;
}

bool isFull(QUEUE* queue) {
    // Not implemented assuming there's enough space availability
    // But one can simulate full condition by checking for the value of SIZE
    // Above method is only to simulate the full queue
    return false; // Returning false assuming there is enough space
}
