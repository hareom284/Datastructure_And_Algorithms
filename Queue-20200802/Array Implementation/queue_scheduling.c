#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue.h"

// Scheduling of applicants for an interview
int main() {
    QUEUE *applicantQueue;
    ITEM item;
    FILE *file_pointer;
    int numberOfApplicants, i;

    int inserted, deleted;

    inserted = 0;
    deleted = 0;

    file_pointer = fopen("Applicant_Data.txt","r");
    numberOfApplicants= 0;

    // Creating a stack of characters
    applicantQueue = (QUEUE *) create(applicantQueue);

    while (true) {
        fscanf(file_pointer,"%s",item.appln_number);
        fscanf(file_pointer,"%s",item.appln_name);
        if (!isFull(applicantQueue)) {
            for (i = 1; i <=100; i++)
                ;
            add(applicantQueue,item);
            inserted++;
            printf("%d: New applicant arrived!\n",inserted);
            numberOfApplicants++;
            for (i = 1; i <=100; i++)
                ;
            if (!isEmpty(applicantQueue)) {
                item = delete(applicantQueue);
                deleted++;
                printf("Deleted: %d\t - Interview of %s is over!\n", deleted,item.appln_name);
            }
            else
                printf("Interviews over!\n");
            if (feof(file_pointer))
                break;
        }
        else {
            printf("All applicants arrived!\n\n");
            break;
        }
    }
    printf("Applicants - %d\n",numberOfApplicants);
    printf("%d\t%d\n",inserted,deleted);
}
