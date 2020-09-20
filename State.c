#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "dfa.h"
#include "State.h"


struct State 
{
   int stateNumber;
   bool acceptingState;
   // array of stateNumbers this state transitions to based on inputs ranging from char values of 0 to 128
   // as the size is not dynamic(i.e fixed we implement normally)
   int nextStateNumbers[128];
};
typedef struct State* State;

extern State new_State(int stateNumber){
    State this = (State*)malloc(sizeof(struct State));
    if (this == NULL) {
        return NULL; // Out of memory...
    }
    // default values
    this -> stateNumber = stateNumber;  // state Number
    this -> acceptingState = false;   // accepting value: false

    // initialize all 128 transitions from this state to -1
    for (int i = 0; i < 128; i++)
    {
        this->nextStateNumbers[i] = -1;
    }
    return this;
}

extern void State_free(State this){
    if(this){
        free(this);
    }
}


extern State transitionToNextState(DFA dfa, State src, char x){
    //what does DFA say?
    int inD = x;
    int current = src -> stateNumber;
    int stateToTransitionTo = *((dfa -> arrayOfStatesInTheDFA) + current)-> nextStateNumbers[inD];
    return  *((dfa -> arrayOfStatesInTheDFA) + stateToTransitionTo);
}

// returns true if current state is the accepting state
extern bool areWeInTheAcceptingState(State s){
    if (s -> acceptingState == true )
    {
        return true;
    } 
    return false;
}

extern void State_print(State this){
    printf("State number is %i", this->stateNumber);
}

