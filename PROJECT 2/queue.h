#ifndef QUEUE_H
#include <stdlib.h>
#include <stdio.h>

typedef struct QUEUE *queue;
struct QUEUE
{
    char *label;
    queue next;
    queue prev;
};

int isEmptyQ();
queue newqueue(char* data);
queue dequeue();
void enqueue(char* data);
int isEmptyQ();
char* firstQ();
int size();
void displayQ();

#endif // DEBUG