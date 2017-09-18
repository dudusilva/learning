#include <stdlib.h>

#define ALPHABET 26
#define BASE 'a'

char* longest(char* s1, char* s2) {
    int S[ALPHABET] = {0};
    char *ptr;
    char *str = malloc(ALPHABET+1);

    while (*s1) S[*(s1++)-BASE]++; 
    while (*s2) S[*(s2++)-BASE]++; 

    ptr = str;
    for (int i=0;i<ALPHABET;i++) {
        if (*(S+i)) *(ptr++) = BASE+i;
    }
    *ptr = '\0';

    return str;
}

