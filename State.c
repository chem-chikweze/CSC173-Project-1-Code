#include <stdbool.h>
#include <stdlib.h>
#include "dfa.h"
#include <stdbool.h>
#include "dfa.h"
#include "State.h"
#include <stdlib.h>
#include <stdio.h>


struct State 
{
   int stateNumber;
   bool acceptingState;

   // array of stateNumbers this state transitions to based on inputs ranging from char values of 0 to 128
   int* nextStateNumbers;
};
typedef struct State* State;

extern State new_State(int stateNumber){
    State this = (State)malloc(sizeof(struct State));
    if (this == NULL) {
        return NULL; // Out of memory...
    }
    // default values
    this -> stateNumber = stateNumber;  // state Number
    this -> acceptingState = false;   // accepting value: false
    // initialize all 128 transitions from this state to -1
    int* nextStateNumbers = (int*) malloc(128 * sizeof(int));
    for (int i = 0; i < 128; i++)
    {
        nextStateNumbers[i] = -1;
    }
    return this;
}

extern State transitionToNextState(DFA dfa, State src, char x){
    //what does DFA say?
    int inputDecimal = x;
    int currentStateNumber = src -> stateNumber;
    int stateToTransitionTo = dfa->  *(arrayOfStatesInTheDFA + currentStateNumber)-> *(nextStateNumbers+ inputDecimal);
    return (State) dfa -> *(arrayOfStatesInTheDFA + stateToTransitionTo);
}

// returns true if current state is the accepting state
extern bool areWeInTheAcceptingState(State s){
    if (s-> acceptingState == true )
    {
        return true;
    } 
    return false;
}
//returns the accepting state
extern int returnTheAcceptingState(){
    return 1;
}

