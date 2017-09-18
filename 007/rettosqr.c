#include <stdlib.h>

typedef struct Data Data;
struct Data {
    int *array;
    int sz;
};

static void cswap(int *p0, int *p1) {
    if (*p1 > *p0) {
        int t = *p0;
        *p0 = *p1;
        *p1 = t;
    }
    return;
}

Data* sqInRect(int lng, int wdth) {
    Data *res = malloc(sizeof(Data));

    (*res).array = NULL;
    (*res).sz = 0;

    if (lng ^ wdth) {
        int *pi_0;

        cswap(&lng, &wdth);
        (*res).array = malloc(lng*sizeof(int));
        pi_0 = (*res).array;

        while (wdth) {
            lng -= wdth;
            *(pi_0++) = wdth;
            cswap(&lng, &wdth);
            (*res).sz++;
        } 
    }
    return res;
}

