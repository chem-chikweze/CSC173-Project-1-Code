#include <stdbool.h>
#include <stdlib.h>
#include "dfa.h"

typedef struct State *State;

struct State 
{
   int stateNumber;
   bool acceptingState;
   int *nextTransitionStateBasedOnCurrentSymbol;
};

extern State new_State(int stateNumber){
    struct State* this = (struct State*)malloc(sizeof(struct State));
    if (this == NULL) {
        return NULL; // Out of memory...
    }
    this -> stateNumber = stateNumber; // number of states
    // create transition tables for each state on the number of units
    this->nextTransitionStateBasedOnCurrentSymbol = (int) malloc(128 * sizeof(int));
    // for each state, set default transition to null
    for (int i = 0; i < 128; i++)
    {
        this->nextTransitionStateBasedOnCurrentSymbol[i] = 0;
    }
    return this;
}

extern State transitionToNextState(DFA dfa, State src, char x){
    //what does DFA say?
    int inputCharDecimalEquivalence = x;
    int currentStateNumber = src -> stateNumber;
    int stateNumberToTransitionToBasedOnInputCharacter = dfa -> myStates[currentStateNumber].nextTransitionStateBasedOnCurrentSymbol[inputCharDecimalEquivalence];
    return (State) dfa -> myStates[stateToTransitionTo];
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

int main(int argc, char* argv[]) {}