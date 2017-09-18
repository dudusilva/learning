#include <stdlib.h>
#include <math.h>

#define MAX 50

typedef struct Pair Pair;

struct Pair {
    long long first;
    long long snd;
};

// fill length with the number of pairs in your array of pairs
Pair** solEquaStr(long long n, int* length) {
    long long n_sqrt = (long long) sqrt(n);
    Pair** res = calloc(MAX, sizeof(Pair));
    *length = 0;

    for (long long i=1;i<=n_sqrt;i++) {
        long long div = n/i;
        long long rem = n - div*i; 

        if (!rem) {
            long long al = i;
            long long be = div;

            if (!((al+be) & 0x1)) {
               long long x = al+be >> 1;

                if (!((be-x) & 0x1)) {
                    Pair *ptr;     
                    long long y = be-x >> 1;
                    
                    ptr = malloc(sizeof(Pair));
                    (*ptr).first = x;
                    (*ptr).snd = y;
                    *(res+*length) = ptr;
                    (*length)++;
               }
            }
        }
    }
    
    return res;
}

