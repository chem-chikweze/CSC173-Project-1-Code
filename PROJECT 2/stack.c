#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tree.c"
#include "stack.h"


plate newPlate(char* data, int t){
    plate temp = (plate)malloc(sizeof(struct stack));
    temp->label = data;
    temp->next = NULL;
    temp->terminal = t;
    return temp;
}

int isEmpty(plate top)
{
    if(top== NULL){
        printf("\nisEmpty: 1");
        return 1;
    }else{
        return 0;
        printf("\nisEmpty: 0");
    }
}

char* peek(plate top)
{
    if(isEmpty(top) == 0){
        printf("\nPeek: 1 %s", top->label);
        return top->label;
    }else{
        printf("\nPeek: 0 empty");
        return NULL;
    }
    
}

void pop(plate top)
{
    if(isEmpty(top)){
        printf("\nPop: 0 empty");
    }else{
        printf("\nPop: 1 pop: %s", top->label);
        top = top->next;
        printf("\nPop: 1 pop: %s", top->label);
        // printf("\nPop: 1 newtop: %s", top->label);
    }
}

// plate push(char* data, plate top){
//     plate new = newPlate(data);
//     if(new == NULL || data == NULL){
//         printf("\nPush: 0 null arg");
//         return NULL;
//     }
//     plate temp = top;
//     top = new;
//     top->next = temp;
//     // printf("\nPush: 1 %s", top->next->label);
//     return top;
// }

plate push(plate new, plate top)
{
    if(new == NULL ){
        printf("\nPush: 0 null arg");
        return NULL;
    }
    if(top == NULL)
    {
        printf("damn");
        return NULL;
    }
    plate temp = top;
    top = new;
    // top->next = (plate) malloc(sizeof(struct stack));
    top->next = temp;
    // printf("\nPush: 1 %s", top->next->label);
    return top;
}

void display(plate top)
{
    plate temp = top;
    while( temp != NULL){
        printf("\nDIS: %s", temp->label);
        temp = temp->next;
    }
}


plate Stack;
tree parsetree;


void syntactic()
{
    E_table = newPlate("C", 0);
    E_table = push(newPlate("ET", 0), E_table);
    
    ET_table = newPlate("|", 1);
    ET_table = push(newPlate("E", 0), ET_table);

    C_table = newPlate("S", 0);
    C_table = push(newPlate("CT", 0), C_table);

    CT_table = newPlate(".", 1);
    CT_table = push(newPlate("C", 0), CT_table);

    S_table = newPlate("A", 0);
    S_table = push(newPlate("ST", 0), S_table);

    ST_table = newPlate("*", 1);
    ST_table = push(newPlate("ST", 0), ST_table);

    A_table = newPlate("(", 1);
    A_table = push(newPlate("E", 0), A_table);
    A_table = push(newPlate(")", 1), A_table);

    printf("syntactic");
}
plate table(char* label, char next)
{
    if(strcmp (label, "E") != 0)
    {
        if(next == '(' || (next >= 'a' && next <= 'z'))
        {
            return E_table;
        }
        else
        {
            return NULL;
        }
    }

    if(strcmp (label, "ET") != 0)
    {
        if(next == '|' )
        {
            return ET_table;
        }
        else if (next == ')' || next == '$')
        {
            plate empty = newPlate("e", 0);
            return empty;
        }
        else
        {
            return NULL;
        }
    }

    if(strcmp (label, "C") != 0)
    {
        if(next == '(' || (next >= 'a' && next <= 'z'))
        {
            return C_table;
        }
        else
        {
            return NULL;
        }
    }

    if(strcmp (label, "CT") != 0)
    {
        if(next == '.' )
        {
            return CT_table;
        }
        else if (next == ')' || next == '$')
        {
            plate empty = newPlate("e", 0);
            return empty;
        }
        else
        {
            return NULL;
        }
    }

    if(strcmp (label, "S") != 0)
    {
        if(next == '(' || (next >= 'a' && next <= 'z'))
        {
            return S_table;
        }
        else
        {
            return NULL;
        }
    }

    if(strcmp (label, "ST") != 0)
    {
        if(next == '*' )
        {
            return ST_table;
        }
        else if (next == ')' || next == '$')
        {
            plate empty = newPlate("e", 0);
            return empty;
        }
        else
        {
            return NULL;
        }
    }

    if(strcmp (label, "A") != 0)
    {
        if(next == '(' || (next >= 'a' && next <= 'z'))
        {
            return A_table;
        }
        else
        {
            return NULL;
        }
    }
    
    return NULL;
}

int parsertable(char* terminal){
    Stack = newPlate("$", 0);
    Stack = push(E_table, Stack);
    display(Stack);

    parsetree = makeNode0(Stack->label);
    // char* terminal;
    char next =  *terminal;
    while (strcmp (Stack->label, "$") != 0)
    {
        if(strcmp (Stack->label, "e") == 0){
            pop(Stack);
        }
        else if(Stack->terminal)
        {
            char *ptr = malloc(2*sizeof(char));
            ptr[0] = next;
            ptr[1]= '\0';
            if(strcmp (Stack->label, ptr) == 0)
            {
                pop(Stack);
                next = *terminal + 1;
            }else 
            {
                printf("Failed parsing: different terninals");
                return 0;
            }
        }
        else if(!Stack->terminal)
        {
            if(table(Stack->label, next) == NULL)
            {
                printf("Failed parsing: no table entry");
                return 0;
            }else
            {
                plate syn = table(Stack->label, next);
                pop(Stack);
                while (syn != NULL)
                {
                    Stack = push(syn, Stack);
                    syn = syn->next;
                    printf("\ntest: %s", Stack->label);
                    printf("\nBtest: %s", syn->label);
                    if(syn == NULL) break;
                    
                }
            }   
        }
    }
    printf("\nHappily parsed");
    return 1;
}



int main(){

    syntactic();
    char* terminal = "a|b.c*";
    // int parse = parsertable(terminal);

    // printf("%d", parse);
    // printf("\n%s", parsetree->label);
    display(E_table);
    // // display(ET);
    // // display(C);
    // // display(CT);
    // // display(S);
    // // display(ST);
    // // display(A);
    // // display(ET);
    return 1;
}