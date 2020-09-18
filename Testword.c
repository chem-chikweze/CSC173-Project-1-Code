#include <stdio.h>
#define TRUE 1
#define FALSE 0
typedef int BOOLEAN;

BOOLEAN findChar(char **pp, char c)
{
    while( **pp != c && **pp != '\0')
        (*pp)++;
    if(**pp == '\0'){
        return FALSE;
    }
    else
    {
        (*pp) ++;
        return TRUE;
    } 
}
            /* char *p is the pointer that stores the 
            address of the first val
            ue in the chaaracter.I.e a pointer to a pointer */
BOOLEAN testWord(char *p){
    /* state 0*/
    if(findChar(&p, 'a'))
        /* state 1*/
        if(findChar(&p, 'e'))
            /* state 2*/
            if(findChar(&p, 'i'))
                /* state 3*/
                if(findChar(&p, 'o'))
                    /* state 4*/
                    if(findChar(&p, 'u'))
                    /* state 5*/
                     return TRUE;
    return FALSE;
}

/*Bounce between states until you finesse the end*/
/*Use of goto statements here. Can it be refactored?*/
void bounce()
{
    char x;

    /* state a*/
a:  putchar('0');
    x = getchar();
    if(x == '0') goto a;/* transition to state a */
    if(x == '1') goto b ; /* transition to state  b*/
    if(x != '0' && x != '1') goto finis;


b:  putchar('0');
    x = getchar();
    if(x == '0') goto a;/* transition to state a */
    if(x == '1') goto c;/* transition to state  b*/
    if(x != '0' && x != '1') goto finis;

c:  putchar('1');
    x = getchar();
    if(x == '0') goto d;/* transition to state a */
    if(x == '1') goto c;/* transition to state  b*/
    goto finis;
    if(x != '0' && x != '1') goto finis;


d:  putchar('1');
    x = getchar();
    if(x == '0') goto a;/* transition to state a */
    if(x == '1') goto c;/* transition to state  b*/
    goto finis;
    if(x != '0' && x != '1') goto finis;


finis:  printf("End");
}

int main()
{
    printf("%d\n", testWord("absteio"));
    bounce();
}