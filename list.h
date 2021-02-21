#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#define true 1
#define false 0
typedef int bool;

// DFA Functions
bool checker(char *string, char c);
bool Turing(char *str);
bool four4(char *str);
bool binary(char *str);
bool bin0odd1(char *str);
bool even01(char *str);

// DFA Function pointers
bool (*checker_ptr)(char*, char) = &checker;    
bool (*Turing_ptr)(char*) = &Turing;            
bool (*four4_ptr)(char*) = &four4;            
bool (*binary_ptr)(char*) = &binary;            
bool (*bin0odd1_ptr)(char*) = &bin0odd1;            
bool (*even01_ptr)(char*) = &even01;            


// NFA Functions
bool command(char *str);
bool eback(char *str);
bool cback(char *str);
bool washington(char *str);

// NFA function pointers
bool (*command_ptr)(char*) = &command;            
bool (*eback_ptr)(char*) = &eback;            
bool (*cback_ptr)(char*) = &cback;            
bool (*washington_ptr)(char*) = &washington;            



// void state1();
// void state2();


#endif 

