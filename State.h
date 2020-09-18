#include <stdbool.h>
#include <stdlib.h>
#include "dfa.h"
#include "nfa.h"

typedef struct State *State;
/**
 * Allocate and return a new state.
 */

extern State new_State(int stateNumber);

// go to next state from transition function
extern State transitionToNextState(DFA dfa, State s, char x);

// returns true if current state is the accepting state
extern bool areWeInTheAcceptingState(State s);

//returns the accepting state
extern int returnTheAcceptingState();
