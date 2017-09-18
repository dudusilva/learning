#include <stdlib.h>

typedef struct Pair Pair;

struct Pair {
    long long first;
    long long snd;
};

Pair** removNb(long long n, int* length) {
    const long long sum = n*(n+1) >> 1;
    long long *num = calloc(n, sizeof(long long));
    Pair** res = NULL;
    Pair** ptr = NULL;

    *length = 0;

    for (long long i=2;i<=n;i++) {
        long long a = sum-i;
        long long b = i+1;
        long long div = a/b;
        long long mod = a - b*div;

        if (!mod && div<=n) {
           *(num+i-1) = div;
           (*length)++;
        } 
    }

    res = malloc((*length)*sizeof(Pair*));
    ptr = res;
    for (long long i=2;i<=n;i++) {
        long long cmp = *(num+i-1); 
        if (cmp) {
            *ptr = malloc(sizeof(Pair));
            (**ptr).first = i;
            (**ptr).snd = cmp;
            ptr++;
        }
    }

    return res;
}

