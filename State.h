#ifndef _State_h
#define _State_h

#include <stdbool.h>
#include <stdbool.h>
#include <stdlib.h>
#include "dfa.h"

typedef struct State *State;
/**
 * Allocate and return a new state.
 */

extern State new_State(int stateNumber);

/**
 * Free the given state.
 */
extern void State_free(State state);

// go to next state from transition function
extern State transitionToNextState(DFA dfa, State s, char x);

// returns true if current state is the accepting state
extern bool areWeInTheAcceptingState(State s);

extern void State_print(State s);

#endif
