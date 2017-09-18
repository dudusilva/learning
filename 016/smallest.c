#include <stdio.h> /* snprintf() */
#include <stdlib.h> /* malloc(), strtoll() */
#include <string.h> /* strlen() */

#define MAX_SZ 100
#define NUM_ANS 3

static long long moveDigit(char *from, char *to, char *inp) {
    char out[MAX_SZ];
    char *ptr_s = inp;
    char *ptr_d = out;

    if (from == to) {
        while (*ptr_s) *ptr_d++ = *ptr_s++;
    } else {
        while (*ptr_s) {
            if (ptr_s == to) {
                if (from < to) {
                    *ptr_d++ = *ptr_s++;
                }
                *ptr_d++ = *from;
                to = NULL;
            } else if (ptr_s == from) {
                ptr_s++;
            } else {
                *ptr_d++ = *ptr_s++;
            }
        }
    } 
    *ptr_d = '\0';

    return strtoll(out, (char**) NULL, 10);
}

long long* smallest(long long n) {
    char n_chr[MAX_SZ];
    long long *res = calloc(NUM_ANS, sizeof(long long));
    size_t len;
    
    snprintf(n_chr, MAX_SZ, "%lld", n);
    *(res+0) = n;
    len = strlen(n_chr);

    for (size_t i=0;i<len;i++) {
        for (size_t j=0;j<len;j++) {
            long long num = moveDigit(n_chr+i, n_chr+j, n_chr);

            if (num<*(res+0)) {
                *(res+0) = num;
                *(res+1) = i;
                *(res+2) = j;
            }
        }
    }
    return res;
}

