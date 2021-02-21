#include "list.h"
// #include "list.c"
#include "tree.h"
// #include "tree.c"

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

// struct nfa{
    
//     // state 0 
//     //     on input x = return {set}
//     //     on input v = return {zet}
//     //     on anything except x and v = return set {remain at state 0}
//     // state x 
//     //     on input y = {z}
// }

// void changes(int state, char input){
// }


// state class{
//     value: true or false;
//     state set return function:
//         if x return {}
//         if y return {}
//         if z return {}
//         if a return {}
// }

bool eback(char *str){
    char *ptr = str;
    node *set = newSet();

    while (*ptr != '\0'){
        // printf("%c", *ptr);
        char choice = *ptr;
        switch (choice){
            case 'b':
                insertf(0, set);
                if(searchf(set, 0)){
                    insertf(1, set);
                    // printf("\nWoo%c", choice);
                }
                *ptr++;
                break;
            case 'a':
                insertf(0, set);
                if(searchf(set, 1)){
                    insertf(2, set);
                    // printf("\nWoo%c", choice);
                }
                *ptr++;
                break;
            case 'c':
                insertf(0, set);
                if(searchf(set, 2)){
                    insertf(3, set);
                    // printf("\nWoo%c", choice);
                }
                *ptr++;
                break;
            case 'k':
                insertf(0, set);
                if(searchf(set, 3)){
                    insertf(4, set);
                    // printf("\nWoo%c", choice);
                    // printf("%c", *ptr+1);
                    if(*ptr+1 == 'l' && searchf(set, 4)){
                        insertf(5, set);
                    }
                }
                *ptr++;
                break;
            default:
                insertf(0, set);
                *ptr++;
                break;
        }
    }

    inorderf(set);
    if(searchf(set, 5)){
        return true;
    }else{
        return false;
    }
}

bool containsback(char *str){
    char *ptr = str;
    node *set = newSet();

    while (*ptr != '\0'){
        // printf("%c", *ptr);
        char choice = *ptr;
        switch (choice){
            case 'b':
                insertf(0, set);
                if(searchf(set, 0)){
                    insertf(1, set);
                    // printf("\nWoo%c", choice);
                }
                *ptr++;
                break;
            case 'a':
                insertf(0, set);
                if(searchf(set, 1)){
                    insertf(2, set);
                    // printf("\nWoo%c", choice);
                }
                *ptr++;
                break;
            case 'c':
                insertf(0, set);
                if(searchf(set, 2)){
                    insertf(3, set);
                    // printf("\nWoo%c", choice);
                }
                *ptr++;
                break;
            case 'k':
                insertf(0, set);
                if(searchf(set, 3)){
                    insertf(4, set);
                    // printf("\nWoo%c", choice);
                    // printf("%c", *ptr+1);
                }
                *ptr++;
                break;
            default:
                insertf(0, set);
                *ptr++;
                break;
        }
    }

    inorderf(set);
    if(searchf(set, 4)){
        return true;
    }else{
        return false;
    }
}

bool washington(char *str){
    char *ptr = str;
    node *set = newSet();
    node *reject = newSet();
    while (*ptr != '\0'){
        // printf("\t%c", *ptr);
        char choice = *ptr;
        switch (choice){
            case 'w':
                if(searchf(set, 18)){
                    insertf(19, set);
                    insertf(19, reject);
                    // printf("\nWoo%c", choice);
                }
                insertf(0, set);
                insertf(18, set);
                // printf("%c", choice);
                *ptr++;
                break;
            case 'a':
                if(searchf(set, 1)){
                    insertf(2, set);
                    insertf(2, reject);
                    // printf("\nWoo%c", choice);
                }
                insertf(0, set);
                insertf(1, set);
                // printf("%c", choice);
                *ptr++;
                break;
            case 's':
                if(searchf(set, 14)){
                    insertf(15, set);
                    insertf(15, reject);
                    // printf("\nWoo%c", choice);
                }
                insertf(0, set);
                insertf(14, set);
                // printf("%c", choice);
                *ptr++;
                break;
            case 'h':
                if(searchf(set, 5)){
                    insertf(6, set);
                    insertf(6, reject);
                    // printf("\nWoo%c", choice);
                }
                insertf(0, set);
                insertf(5, set);
                // printf("%c", choice);
                *ptr++;
                break;
            case 'i':
                if(searchf(set, 7)){
                    insertf(8, set);
                    insertf(8, reject);
                }
                insertf(0, set);
                insertf(7, set);
                // printf("%c", choice);
                *ptr++;
                break;
            case 'n':
                if(searchf(set, 10)){
                    insertf(11, set);
                    insertf(11, reject);
                }
                if(searchf(set, 9)){
                    insertf(10, set);
                    insertf(10, reject);
                }
                insertf(0, set);
                insertf(9, set);
                // printf("%c", choice);
                *ptr++;
                break;
            case 'g':
                if(searchf(set, 3)){
                    insertf(4, set);
                    insertf(4, reject);
                }
                insertf(0, set);
                insertf(3, set);
                // printf("%c", choice);
                *ptr++;
                break;
            case 't':
                if(searchf(set, 16)){
                    insertf(17, set);
                    insertf(17, reject);
                }
                insertf(0, set);
                insertf(16, set);
                // printf("%c", choice);
                *ptr++;
                break;
            case 'o':
                if(searchf(set, 12)){
                    insertf(13, set);
                    insertf(13, reject);
                }
                insertf(0, set);
                insertf(12, set);
                // printf("%c", choice);
                *ptr++;
                break;
            default:
                insertf(0, set);
                *ptr++;
                break;
        }
    }

    inorderf(reject);
    if(reject->left != NULL || reject->right != NULL){
        return true;
    }else{
        return false;
    }
}

bool containsChem(char *str){
    char *ptr = str;
    node *set = newSet();
    while (*ptr != '\0'){
        char choice = *ptr;
        switch (choice){
            case 'c':
                insertf(0, set);
                if(searchf(set, 0)){
                    insertf(1, set);
                }
                *ptr++;
                break;
            case 'h':
                insertf(0, set);
                if(searchf(set, 1)){
                    insertf(2, set);
                }
                *ptr++;
                break;
            case 'e':
                insertf(0, set);
                if(searchf(set, 2)){
                    insertf(3, set);
                }
                *ptr++;
                break;
            case 'm':
                insertf(0, set);
                if(searchf(set, 3)){
                    insertf(4, set);
                }
                *ptr++;
                break;
            default:
                insertf(0, set);
                *ptr++;
                break;
        }
    }

    inorderf(set);
    if(searchf(set, 4)){
        return true;
    }else{
        return false;
    }
}

int main(){
    // int a = eback("abackback");
    // printf("\n true of false: %i",a);

    // int b = containsback("bckales");
    // printf("\ntrue of false: %i",b);

    int c = washington("washi");
    printf("\nWash");
    printf("\ntrue of false: %i", c);

    printf("\nDoes it have chem ?: %i", containsChem("chm"));

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
    return 0;
}


