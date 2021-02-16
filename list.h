#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#define true 1
#define false 0
typedef int bool;

// #define st int;

bool checker(char *string, char c);
bool Turing(char *str);
bool four4(char *str);
bool binary(char *str);
bool (*checker_ptr)(char*, char) = &checker;    //function pointer
bool (*Turing_ptr)(char*) = &Turing;            //function pointer
bool (*four4_ptr)(char*) = &four4;            //function pointer
bool (*binary_ptr)(char*) = &binary;            //function pointer


void state1();
// void state2();


#endif 

