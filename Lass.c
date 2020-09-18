#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
typedef int BOOLEAN;

/**
 * To run you have to enter the whole string at once
 * */
void LASS(){
    char x;

a:  
    x = getchar();
    if(x == 'm') {
        printf("m");
        goto b;
    }else if(x != 'm') {
        printf("e1");
        goto a;
    }
    

b:  
    x = getchar();
    if(x == 'a') {
        printf("a");
        goto c;
    }else if(x != 'a') {
        printf("e2");
        goto a;
    }
c:  
    x = getchar();
    if(x == 'n') {
        printf("n");
        goto finis;
    }else if(x != 'm') {
        printf("e3");
        goto a;
    }

finis:  putchar('Z');
   
}

struct Employee
{
    char* name;
    int id;
};

//constructor to create new instances of Employee
struct Employee* new_Employee(char *name, int id){
    struct Employee* this = (struct Employee*)malloc(sizeof(struct Employee));
    if(this == NULL) {
        return NULL; // out of memory
    }

    this->name = name;
    this->id = id;
    return this;
}

//create a new instance by calling the constructor
// struct Employee* e = new_Employee("Alan", 123);



main(){
    setbuf(stdout, NULL);     

    LASS();
}