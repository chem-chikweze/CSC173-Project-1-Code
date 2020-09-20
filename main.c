#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "dfa.h"
#include "State.h"


extern DFA new_DFA(int nstates);
extern void DFA_free(DFA dfa);
extern int DFA_get_size(DFA dfa);
extern int DFA_get_transition(DFA dfa, int src, char sym);
extern void DFA_set_transition(DFA dfa, int src, char sym, int dst);
extern void DFA_set_transition_str(DFA dfa, int src, char *str, int dst);
extern void DFA_set_transition_all(DFA dfa, int src, int dst);
extern void DFA_set_accepting(DFA dfa, int state, bool value);
extern bool DFA_get_accepting(DFA dfa, int state);
extern bool DFA_execute(DFA dfa, char *input);
extern void DFA_print(DFA dfa);

bool happyDFA(char *str){
    DFA happy = new_DFA(6);
    DFA_set_transition(happy, 0, 'h',1);
    DFA_set_transition_str(happy, 0, str, 1);
    DFA_get_transition(happy, 0, 'h');
    DFA_set_accepting(happy, 0, true);
    return true;
}






int main(){
    printf("Project 1");
    happyDFA("hello");
    // DFA happyDFA = new_DFA(2);
    // DFA_set_transition(happyDFA, 0, 'h',1);
    // DFA_get_transition(happyDFA, 0, 'h');
    // DFA_print(happyDFA);

    return 0;
}
extern DFA new_DFA(int nstates);



