#include <stdio.h>
#include <stdlib.h>
#include "queue_LL.h"

// Scheduling of applicants for an interview
int main() {
    QUEUE *applicantQueue;
    ITEM item;
    FILE *file_pointer;
    int k;

    file_pointer = fopen("Applicant_Data.txt","r");

    // Creating a stack of characters
    applicantQueue = createQueue();

    printf("\nAdding items to the queue...\n");
    printf("\n\t\tfront_queue\t\trear_queue\t\tAppln Number\tAppln_Name\tAppln Number\tAppln_Name\n");
    printf("\t\t-----------\t\t----------\t\t------------\t----------\t------------\t----------\n");
    printf("\t\t\t\t\t\t\t\t\tFront of Queue\t\t\tRear of Queue\n\n");
    k = 1;
    while (true) {
        if (k <= SIZE) { /* Simulating queue is full */
            fscanf(file_pointer,"%s",item.appln_number);
            fscanf(file_pointer,"%s",item.appln_name);

            add(applicantQueue,item);
            printf("\t\t%p\t\t%p",applicantQueue->front_queue,applicantQueue->rear_queue);
            printf("\t\t%s\t%s",applicantQueue->front_queue->item.appln_number,applicantQueue->front_queue->item.appln_name);
            printf("\t\t%s\t%s\n",applicantQueue->rear_queue->item.appln_number,applicantQueue->rear_queue->item.appln_name);
            if (feof(file_pointer)) {
                printf("\n\nAll items from the input file added to the queue\n");
                break;
            }
            else
                k++;
        }
        else {
            printf("\n\nQueue is full\n");
            break;
        }
    }

    item = front_queue(applicantQueue);
    printf("\nItem at front of the queue: \t\t%s\t%s\n",item.appln_number,item.appln_name);

    printf("\nDeleting items from the queue...\n");
    printf("\n\t\tfront_queue\t\trear_queue\t\tAppln Number\tAppln_Name\tAppln Number\tAppln_Name\n");
    printf("\t\t-----------\t\t----------\t\t------------\t----------\t------------\t----------\n");
    printf("\t\t\t\t\t\t\t\t\tFront of Queue\t\t\tRear of Queue\n\n");
    while (true) {
        if (!isEmpty(applicantQueue)) {
            printf("\t\t%p\t\t%p",applicantQueue->front_queue,applicantQueue->rear_queue);
            item = delete(applicantQueue);
            printf("\t\t%s\t%s",item.appln_number,item.appln_name);
            if (applicantQueue->rear_queue != NULL)
                printf("\t\t%s\t%s\n",applicantQueue->rear_queue->item.appln_number,applicantQueue->rear_queue->item.appln_name);
        }
        else {
            printf("\n\nQueue is empty\n\n");
            break;
        }
    }
}
