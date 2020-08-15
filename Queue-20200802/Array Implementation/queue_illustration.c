#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

// Scheduling of applicants for an interview
int main() {
    QUEUE *applicantQueue;
    ITEM item;
    FILE *file_pointer;

    file_pointer = fopen("Applicant_Data.txt","r");

    // Creating a stack of characters
    applicantQueue = (QUEUE *) create(applicantQueue);

    while (true) {
        fscanf(file_pointer,"%s",item.appln_number);
        fscanf(file_pointer,"%s",item.appln_name);
        printf("\n\t%s\n\t%s\n", item.appln_number, item.appln_name);
        //printf("Before insert: %d\t%d\n", applicantQueue->front_queue,applicantQueue->rear_queue);
        if (!isFull(applicantQueue)) {
            add(applicantQueue,item);
            //printf("After insert:  %d\t%d\n", applicantQueue->front_queue,applicantQueue->rear_queue);
            if (feof(file_pointer))
                break;
        }
        else
		break;
    }

    while (true) {
        if (!isEmpty(applicantQueue)) {
            //printf("Before delete: %d\t%d\n", applicantQueue->front_queue,applicantQueue->rear_queue);
            item = delete(applicantQueue);
            printf("\t%s\t%s\n", item.appln_number, item.appln_name);
            //printf("After delete: %d\t%d\n", applicantQueue->front_queue,applicantQueue->rear_queue);
        }
        else {
            printf("Queue is empty\n");
            break;
        }
    }
}
