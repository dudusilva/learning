#include <stdio.h>

double doubles(int maxk, int maxn);

int main(void) {
    double res = doubles(10, 10000);

    printf("res: %.16f\n", res);
}

