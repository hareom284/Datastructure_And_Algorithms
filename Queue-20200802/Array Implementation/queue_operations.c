#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "queue.h"

QUEUE* create(QUEUE *q) {
    // Front and rear pointers to the queue are initialized to -1
    q = (QUEUE *) malloc(sizeof(QUEUE));
    if (q != NULL) {
        q->front_queue = -1;
        q->rear_queue = -1;
        return q;
    }
    else
        return NULL;
}

int add(QUEUE *q, ITEM item) {
    // Checking if QUEUE is full
    // No item can be added into a QUEUE if it's already full
    if (!isFull(q)) {
        if (q->front_queue == -1)
            q->front_queue = 0;
        q->rear_queue = q->rear_queue + 1;
        q->queue[q->rear_queue] = item;
        return 1; // When inserting an element is successful
    }
    else
        return 0; // When QUEUE is full
}

ITEM delete(QUEUE *q) {
    // Checking if QUEUE is empty
    // No item can be removed from an empty QUEUE
    ITEM removedItem;

    if (!isEmpty(q)) {
        removedItem = q->queue[q->front_queue];
        q->front_queue = q->front_queue + 1;
    }
    else
        removedItem.appln_name[0] = '\0';
    return removedItem;
}

ITEM front(QUEUE *q) {
    // Checking if QUEUE is empty
    // Item at the front of the QUEUE cannot be returned if the QUEUE is empty

    if (!isEmpty(q))
        return q->queue[q->front_queue];
    else {
        ITEM temp;
        temp.appln_name[0] = '\0';
        return temp; // $ incidcates that the QUEUE is empty and there is no meaningul element to return
    }
}
bool isEmpty(QUEUE *q) {
    // Return true if QUEUE is empty else false
    if (q->front_queue == -1) // To check when the queue is empty initially
		return true;
    if ((q->rear_queue - q->front_queue) == -1)
        return true;
    else
        return false;
}

bool isFull(QUEUE *q) {
    // Return true if QUEUE is full else false
    if (q->rear_queue == SIZE-1)
        return true;
    else
        return false;
}
