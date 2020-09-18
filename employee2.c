/*
 * File: employee2.c
 * Creator: George Ferguson
 *
 * Second version of a type representing employees.
 * Incldues getters and setters for properties.
 */

#include <stdlib.h>
#include <stdio.h>

struct Employee {
    char* name;
    int id;
};

struct Employee* new_Employee(char *name, int id) {
    struct Employee* this = (struct Employee*)malloc(sizeof(struct Employee));
    if (this == NULL) {
        return NULL; // Out of memory...
    }
    this->name = name; // See text
    this->id = id;
    return this;
}

void Employee_print(struct Employee* this) {
    printf("Employee[%s,%d]", this->name, this->id);
}

char* Employee_get_name(struct Employee* this) {
    return this->name;
}

void Employee_set_name(struct Employee* this, char *name) {
    this->name = name; // See text
}

int Employee_get_id(struct Employee* this) {
    return this->id;
}

void Employee_set_id(struct Employee* this, int id) {
    this->id = id;
}

int main(int argc, char* argv[]) {
    struct Employee* e1 = new_Employee("Alan Turing", 123);
    Employee_print(e1);
    printf("\n");
    Employee_set_name(e1, "Steve Jobs");
    Employee_print(e1);
    printf("\n");
    Employee_set_id(e1, 666);
    Employee_print(e1);
    printf("\n");
}
