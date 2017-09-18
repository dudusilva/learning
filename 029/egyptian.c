#include <stdlib.h> /* calloc, free */
#include <stdio.h> /* strtol */

#define MAX_SZ 50
#define MAX_ST 200

typedef unsigned long long ull;

static int decompositionStep(ull* num, ull *den, ull idx) {
    ull new_num = *num * idx;
    ull sub_num = *den;

    if (new_num >= sub_num) {
        *num = new_num - sub_num;
        *den = *den * idx;
        return 1;
    } else {
        return 0;
    }
}

static char* resultToString(ull* frac) {
    char* res = malloc(MAX_ST+1);
    char* ptr = res;

    /* integers */
    if (*frac) {
        int offset = sprintf(ptr, "%lld,", *frac);
        ptr += offset; 
    }
    frac++;

    /* decimals */
    while (*frac) {
        int offset = sprintf(ptr, "1/%lld,", *frac);
        ptr += offset;
        frac++;
    }

    if (ptr != res) ptr--;
    *ptr = '\0';

    return res;
}

char* decompose(char* nrStr, char* drStr) {
    ull *frac = calloc(MAX_SZ, sizeof(int));
    ull *ptr = frac+1;
    ull num = strtol(nrStr, NULL, 10);
    ull den = strtol(drStr, NULL, 10);
    ull div = num/den;
    ull mod = num - div*den;
    ull idx = 2;
    char *res = NULL;

    /* integers */
    *(frac+0) = div;
    num = mod;

    /* decimals */
    while (num) {
        if (decompositionStep(&num, &den, idx)) {
            *ptr++ = idx;
        }
        idx++;
    }

    res = resultToString(frac); 

    free(frac);
    return res;
}

    /*
    printf("int: %d\n", *(frac+0));
    printf("num: %d\n", num);
    printf("den: %d\n", den);

    printf("%s\n", nrStr);
    printf("%s\n", drStr);
    */
