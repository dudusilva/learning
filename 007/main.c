#include <stdio.h>

typedef struct Data Data;
struct Data {
    int *array;
    int sz;
};

Data* sqInRect(int lng, int wdth);

int main(void) {
    Data *res;

    res = sqInRect(20,14);

    for (int i=0;i<(*res).sz;i++) {
        printf("%d \n", *((*res).array+i));
    }

    return 0;
}

