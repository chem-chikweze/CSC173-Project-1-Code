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
char *state_ptr = &state;
bool check(char *string, char c, char s){
    if (*string == c && s == state_ptr){
        return true;    
    }else{
        return false;
    }
}

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
    state_ptr = '0';
    while (*ptr != '\0') {
        if(check(ptr, '0', '0')){
            *ptr++;
            *state_ptr = '0';
        }else if(check(ptr, '1', '0')){
            *ptr++;
            *state_ptr = '1';
        }else if(check(ptr, '0', '1')){
            *ptr++;
        }else if(check(ptr, '1', '1')){
            *ptr++;
            *state_ptr = '0';
        }

    }
    return *state_ptr;
}

int main(){

    // char str[7] = "Turing";
    // char *ptr =  str;
    // int a ;
    // a = Turing_ptr(ptr);
    // if(a == 1){
    //     printf("Turing\n");
    // }

    // char* st = "4444";
    // char *ptr1 =  st;

    // int b = four4_ptr(ptr1);
    // if(b == 1){
    //     printf("Four.\n");
    // }else{
    //     printf("Does not start with four.\n");
    // }

    bool a = binary_ptr("0001");
    printf("%i", a);
    
    // state1();
    // return 0;
}