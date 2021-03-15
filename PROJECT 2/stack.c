#include <stdlib.h>
#include <stdio.h>


typedef struct stack *plate;
struct stack
{
    char *label;
    plate next;
};

plate top = NULL;

plate newPlate(char* data){
    plate temp = (plate)malloc(sizeof(struct stack));
    temp->label = data;
    temp->next = NULL;
    return temp;
}

int isEmpty(){
    if(top== NULL){
        printf("\nisEmpty: 1");
        return 1;
    }else{
        return 0;
        printf("\nisEmpty: 0");
    }
}

char* peek(){
    if(isEmpty() == 0){
        printf("\nPeek: 1 %s", top->label);
        return top->label;
    }else{
        printf("\nPeek: 0 empty");
        return NULL;
    }
    
}

void pop(){
    if(isEmpty()){
        printf("\nPop: 0 empty");
    }else{
        printf("\nPop: 1 pop: %s", top->label);
        top = top->next;
        printf("\nPop: 1 newtop: %s", top->label);
    }
}

void push(char* data){
    plate new = newPlate(data);
    if(new == NULL || data == NULL){
        printf("\nPush: 0 null arg");
        return ;
    }
    new->next = top;
    top = new;
    printf("\nPush: 1 %s", top->label);
}

void display(){
    plate temp = top;
    while( temp != NULL){
        printf("\nDIS: %s", temp->label);
        temp = temp->next;
    }
    printf("\nDIS: done?");
}


// int main(){
//     top = newPlate("ET");
//     push("E");
//     push("S");
//     push("ST");
//     display();
// }