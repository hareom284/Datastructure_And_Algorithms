#include <stdio.h>
#include <stdbool.h>

#define SIZE 50

typedef struct applicant {
    char appln_number[12];
    char appln_name[40];
} APPLICANT;

typedef APPLICANT ITEM;

typedef struct node {
    ITEM item;
    struct node *next;
} QNODE;

typedef struct queue {
  QNODE *front_queue;
  QNODE *rear_queue;
} QUEUE;

QUEUE* createQueue();
QNODE* createNode(ITEM);
int add(QUEUE*, ITEM);
ITEM delete(QUEUE*);
ITEM front_queue(QUEUE*);
bool isEmpty(QUEUE*);
bool isFull(QUEUE*);


