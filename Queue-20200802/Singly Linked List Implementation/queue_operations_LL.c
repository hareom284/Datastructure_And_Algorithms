#include <stdlib.h>
#include <stdio.h>
#include "queue_LL.h"

// To create a new node dynamically and set its data part to the value of the argument
QNODE* createNode(ITEM item) {

    QNODE *temp = (QNODE*) malloc(sizeof(QNODE));
    if (temp != NULL) { // temp will be NULL if malloc cannot return requested memory
    	temp->item = item;
    	temp->next = NULL;
    }
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
    if (temp == NULL)
	return -1; // Indicates no memory was allocated to create a new node
    // When queue is empty, front and rear of the queue is set to the new node
    if (isEmpty(queue)) {
        queue->front_queue = temp;
        queue->rear_queue = temp;
        return 1;
    }
    else { // When queue is not empty, add the new node at the end of the queue and change the rear pointer
        queue->rear_queue->next = temp;
        queue->rear_queue = temp;
        return 1;
    }

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

