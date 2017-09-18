#include <stdio.h>

double going(int n);

int main(void) {
    double res;
    int d = 1750;

    //for (int i=d;i<d+20;i++) {
    int i = 1755;
        res = going(i);
        printf("(%d) %f\n", i, res);
    //}
    return 0;
}

