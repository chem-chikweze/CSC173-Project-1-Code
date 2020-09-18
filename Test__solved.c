#include <stdio.h>
#define TRUE 1
#define FALSE 0
typedef int BOOLEAN;

BOOLEAN findChar(char **pp, char c)
{
    while (**pp != c && **pp != '\0')
        (*pp)++;
    if (**pp == '\0')
        return FALSE;
    else 
    {
        (*pp)++;
        return TRUE;
    }
}

BOOLEAN testWord(char *p){
    /* state 0 */
    if (findChar(&p, 'h'))
        /* state 1 */
        if (findChar(&p, 'a'))
            /* state 2 */
                if (findChar(&p, 'p'))
                    /* state 3 */
                        if (findChar(&p, 'p'))
                            /* state 4 */
                                if (findChar(&p, 'y'))
                                /* state 5 */
                                return TRUE;
    return FALSE;
}
int main()
{
    printf("%d\n", testWord("happy"));
}