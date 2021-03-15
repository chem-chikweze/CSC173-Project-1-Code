
#include "queue.h"




queue first = NULL;
queue last = NULL;
int count = 0;

queue newqueue(char* data){
    first = (queue)malloc(sizeof(struct QUEUE));
    last = (queue)malloc(sizeof(struct QUEUE));

    first->label = data;
    // last->label = data;

    first->next = NULL;
    first->prev = last;
    last->next = first;
    last->prev = NULL;
    last->label = NULL;

    count = count+1;
    return first;
}

queue dequeue(){
    if(isEmptyQ()){
        printf("\nDequeue: 0 empty");
        return NULL;
    }else{
        printf("\nDequeue: 1 pop: %s", first->label);
        queue temp = first;

        first = first->prev;
        first->next = NULL;
        printf("\nDequeue: 1 newfirst: %s", first->label);
        count = count-1;
        return first;
    }
}

void enqueue(char* data){
    queue new = (queue)malloc(sizeof(struct QUEUE));
    new->label = data;

    if(first ==  NULL){
        newqueue(data);
        count = count+1;
        return;
    }

    if(last->next != NULL && last->label == NULL){
        last->next->prev = new;
        new->next = last->next;
        new->prev = last;
        last->next = new;
        count = count+1;
        return;
    }
}

int isEmptyQ(){
    if(first== NULL){
        printf("\nq.isEmpty: 1");
        return 1;
    }else{
        return 0;
        printf("\nq.isEmpty: 0");
    }
}

char* firstQ(){
    if(isEmptyQ() == 0){
        printf("\nq.Peek: 1 %s", first->label);
        return first->label;
    }else{
        printf("\nq.Peek: 0 empty");
        return NULL;
    }
}

int size(){
    return count;
}

void displayQ(){
    queue temp = first;
    while( temp != NULL && temp->label != NULL){
        printf("\nq.DIS: %s", temp->label);
        temp = temp->prev;
    }
    printf("\nq.DIS: done?");
}

int main(){
    newqueue("ET");
    enqueue("E");
    enqueue("S");
    enqueue("ST");
    displayQ();
}