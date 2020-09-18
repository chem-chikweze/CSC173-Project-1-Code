/*
 * File: dfa.h
 * Creator: George Ferguson
 * Created: Thu Sep  1 17:45:52 2016
 * Time-stamp: <Tue Aug  8 11:30:46 EDT 2017 ferguson>
 * 
 * The header file is from George Ferguson but Chukwubuikem Chikweze implemented the header file.
 * Time-stamp: <Saturday Sep 9 2:43pm 2020 >
 */

#include <stdbool.h>
#include "dfa.h"
#include "State.h"
#include <stdlib.h>
#include <stdio.h>

/* typedef instantly creates a  looks good */
/**
 * The data structure used to represent a deterministic finite automaton.
 * @see FOCS Section 10.2
 * Note that YOU must specify this data structure, although you can hide
 * (encapsulate) its implementation behind the declared API functions and
 * only provide a partial declaration in the header file.
 */
typedef struct DFA* DFA;
struct DFA 
{
    int nstates; //default value
    State myStates;
    // int transitionTable[][];
};

/**
 * Allocate and return a new DFA containing the given number of states.
 **/
extern struct DFA new_DFA(int nstates)
{
    DFA this = (DFA)malloc(sizeof(struct DFA));
    if (this == NULL) {
        return NULL; // Out of memory...
    }
    this->nstates = nstates; // number of states
    // create an array of states of length nstates

    this->myStates = (State*) calloc(nstates , sizeof(struct State));
    // for each state, set acceptingState state to be false

    for (int i = 0; i < nstates; i++)
    {
        this->myStates[i] = new_State(i);
        this->myStates[i].acceptingState = false;
        for (int j = 0; j < 128; j++)
        {
            // set each transition on each state to be null. nextTransitionStateBasedOnCurrentSymbol to be null 
            this-> myStates[i].nextTransitionStateBasedOnCurrentSymbol[j].stateNumber = -1;
        }
    }
    return this;
};

// void DFA_Print(struct DFA* this){
//     printf("States: \t%d\n",  this -> nstates);
// }

/**
 * Free the given DFA.
 */
extern void DFA_free(DFA this){
    if (this) {
        free(this -> myStates);
		free(this);
	}
// }

 /**
 * Return the number of states in the given DFA.
 */
extern int DFA_get_size(DFA this){
    return this -> nstates;
}

/**
 * Return the state specified by the given DFA's transition function from
 * state src on input symbol sym.
//  */
extern int DFA_get_transition(DFA dfa, int src, char sym){
    return dfa-> myStates[src].stateNumberToTransitionToBasedOnCharacterInput[sym];
}



// /**
//  * For the given DFA, set the transition from state src on input symbol
//  * sym to be the state dst.
//  */
extern void DFA_set_transition(DFA dfa, int src, char sym, int dst){
       
}

int main() {
   
   
    return 0;
}
// /**
//  * Set the transitions of the given DFA for each symbol in the given str.
//  * This is a nice shortcut when you have multiple labels on an edge between
//  * two states.
//  */
// extern void DFA_set_transition_str(DFA dfa, int src, char *str, int dst);

// // /**
// //  * Set the transitions of the given DFA for all input symbols.
// //  * Another shortcut method.
// //  */
// extern void DFA_set_transition_all(DFA dfa, int src, int dst){

// }

// // /**
// //  * Set whether the given DFA's state is accepting or not.
// //  */
// extern void DFA_set_accepting(DFA dfa, int state, bool value){
//     dfa->myStates[state].acceptingState = true;
// }

// /**
//  * Return true if the given DFA's state is an accepting state.
//  */
// extern bool DFA_get_accepting(DFA dfa, int state){
//     //if state is accepting return true
// }

// /**
//  * Run the given DFA on the given input string, and return true if it accepts
//  * the input, otherwise false.
//  */
// extern bool DFA_execute(DFA dfa, char *input){
//     while (input != '\0')
//     {
//         DFA_set_transition_str(DFA dfa, int src, char *str, int dst);
//     }
    
//     // load input 
//     // input 1 to transition function 
//     // if(DFA_get_accepting) return true
//     // else return false;
// }

// /**
//  * Print the given DFA to System.out.
//  */
// extern void DFA_print(DFA dfa);


//dfa set transitions 