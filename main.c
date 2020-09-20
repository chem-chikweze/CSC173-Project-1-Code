#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "State.h"
#include "dfa.h"




int main(){
    printf("Project 1");
    DFA happyDFA = new_DFA(2);
    DFA_set_transition(happyDFA, 0, 'h',1);
    DFA_get_transition(happyDFA, 0, 'h');

    return 0;
//    DFA_print(happyDFA);
}