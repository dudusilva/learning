#include <stddef.h>
#include <stdlib.h>

typedef struct Data Data;
struct Data {
    int *array;
    int sz;
};

typedef struct Square Square;
struct Square {
    int size;
    int times;
    Square *next;
};

static void swapPointers(int **p0, int **p1) {
    int* t = *p0;
    *p0 = *p1;
    *p1 = t;
    return;
}

Data* sqInRect(int lng, int wdth) {
    Data *res = malloc(sizeof(Data));

    if (lng ^ wdth) {
        int *max = &wdth;
        int *min = &lng;
        int count = 0;
        int *ptr_i0, *ptr_i1;
        Square *sqr = malloc(sizeof(Square));
        Square *ptr = sqr;

        if (lng > wdth) swapPointers(&max, &min);

        while (*min) {
            int quo;
            quo = (*max)/(*min);
            (*ptr).size = *min;
            (*ptr).times = quo;
            (*ptr).next = malloc(sizeof(Square));
            ptr = (*ptr).next;
            (*ptr).next = NULL;
            count += quo;
            *max = *max - quo*(*min);
            swapPointers(&max, &min);
        }

        ptr_i0 = malloc(count*sizeof(int));
        ptr_i1 = ptr_i0;

        ptr = sqr;
        while ((*ptr).next) {
            for (int i=0;i<(*ptr).times;i++) {
                *(ptr_i1++) = (*ptr).size;
            }
            ptr = (*ptr).next;
        }

        (*res).sz = count;
        (*res).array = ptr_i0;
    } else {
        (*res).sz = 0;
    }

    return res;
}

