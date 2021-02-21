/*
#include "list.h"
#include "list.c"

bool checker(char *string, char c){           // function checker
    if (*string == c){
        // string++;
        return true;    
    // }else if(*string == '\0'){
    //     return true;
    }
    else{
        return false;
    }
}
char state = '0';
// char *state_ptr = &state;
bool check(char *string, char c, char s, char state){
    if (*string == c && s == state){
        return true;    
    }else{
        return false;
    }
}


// DFAs
bool Turing(char *str){
    char *ptr =  str;
    if(checker_ptr(ptr, 'T')){
        // printf("T");
        // go to state u
        ptr = ptr +1;
        if(checker_ptr(ptr, 'u')){
            // printf("u");
            ptr = ptr +1;
            if(checker_ptr(ptr, 'r')){
                // printf("r");
                ptr = ptr +1;
                if(checker_ptr(ptr, 'i')){
                    // printf("i");
                    ptr = ptr +1;
                    if(checker_ptr(ptr, 'n')){
                        // printf("n");
                        ptr = ptr +1;
                        if(checker_ptr(ptr, 'g')){
                            // printf("g");
                            ptr = ptr +1;
                            if(checker_ptr(ptr, '\0')){
                                ptr = ptr +1;
                                return true;
                            }else{return false;}
                        }else{return false;}
                    }else{return false;}
                }else{return false;}
            }else{return false;}
        }else{return false;}
    }else{return false;}
}
bool four4(char *str){
    char *ptr =  str;
    if(checker_ptr(ptr, '4')){
        // printf("4");
        ptr = ptr +1;
        if(checker_ptr(ptr, '4')){
            // printf("%s","4");
            ptr = ptr +1;
            if(checker_ptr(ptr, '4')){
                // printf("%s","4");
                ptr = ptr +1;
                if(checker_ptr(ptr, '4')){
                    // printf("%s","4");
                    return true;
                }else {return  false;}
            }else {return  false;}
        }else {return  false;}
    }else {return  false;}
}
bool binary(char *str){
    char *ptr = str;
    while (*ptr != '\0') {
        //if ptr is arg 2 and argument 3  equals arg 4
        if(check(ptr, '0', '0', state)){
            *ptr++;
        }else if(check(ptr, '1', '0', state)){
            // if next char is 1 and we are in 'state' 0
            // go to next character
            *ptr++;
            // go to state 1
            state = '1';
        }else if(check(ptr, '0', '1', state)){
            *ptr++;
        }else if(check(ptr, '1', '1', state)){
            *ptr++;
            state = '0';
        }
    }
    if(state == '1'){
        return true;
    }else {
        return false;   
    }
}
char state1 = '0';
char state2 = '0';
bool bin0odd1(char *str){
    char *ptr = str;
    while (*ptr != '\0'){
        if(*ptr == '0'){
            // if ptr is 0 and state1 is 0 go to 1 of state1
            if(check(ptr, '0', '0', state1)){
                *ptr++;
                state1 = '1';
            }else if(check(ptr, '0', '1', state1)){
                *ptr++;
                state1 = '0';
            }
        }else if (*ptr == '1'){
            if(check(ptr, '1', '0', state2)){
                *ptr++;
                state2 = '1';
            }else if(check(ptr, '1', '1', state2)){
                *ptr++;
                state2 = '0';
            }  
        }    
    }
    if(state1 == '0' && state2 == '1'){
        return true;
    }else{
        return false;
    }
    
}
bool even01(char *str){
    char *ptr = str;
    while (*ptr != '\0'){
        if(*ptr == '0'){
            // if ptr is 0 and state1 is 0 go to 1 of state1
            if(check(ptr, '0', '0', state1)){
                *ptr++;
                state1 = '1';
            }else if(check(ptr, '0', '1', state1)){
                *ptr++;
                state1 = '0';
            }
        }else if (*ptr == '1'){
            if(check(ptr, '1', '0', state2)){
                *ptr++;
                state2 = '1';
            }else if(check(ptr, '1', '1', state2)){
                *ptr++;
                state2 = '0';
            }  
        }    
    }
    if(state1 == '0' && state2 == '0'){
        return true;
    }else{
        return false;
    }  
}

// NFAs
/*
    sets
    going through 'set states'
    // create set states? on input 'x' current state 'z' go through set 'z'
    // high big O

    at the end of all state iterations, if an accepting state was reached for the input string, accept.
    // how do I optimize this for the algorithm that transforms NFAs to DFAs?
*/
// set
// 

nfa class{
    state 0 
        on input x = return {set}
        on input v = return {zet}
        on anything except x and v = return set {remain at state 0}
    state x 
        on input y = {z}
}


state class{
    value: true or false;
    state set return function:
        if x return {}
        if y return {}
        if z return {}
        if a return {}
}

bool command(char *str){
    char *ptr = &str;
    set c;
    while (*ptr != '\0'){
        while(setParentIsempty != true){
            stateNext = setParent.nextState;
            c.addWithNodDoubles(getSetOfStatesStateNextLeadstoWithPtr(stateNext, ptr));
        }
        setParent.addWithNoDoubles(c);
        *ptr++;
    }

    {walkthrough setParent:// if any is accepting accepts "str", else reject str}
    
}
bool eback(char *str){}
bool cback(char *str){}
bool washington(char *str){}

int main(){
    // char str[7] = "Turing";
    // char *ptr =  str;
    // bool a = Turing_ptr(ptr);
    // if(a == 1){
    //     printf("Turing\n");
    // }

    // char* st = "4444cc";
    // char *ptr1 =  st;

    // int b = four4_ptr(ptr1);
    // if(b == 1){
    //     printf("Four.\n");
    // }else{
    //     printf("Does not start with four.\n");
    // }
    // bool a = binary_ptr("0110011");
    // printf("%i\n", a);
    
    // bool a = bin0odd1_ptr("11");
    // printf("%i\n", a);

    // bool a = even01_ptr("1001");
    // printf("%i\n", a);

    // state1();
    // return 0;
}


*/