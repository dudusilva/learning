#include<stdio.h>

double exEuler(int nb);

int main(void) {
    double res = exEuler(10);

    printf("%.16f\n", res);

    return 0;
}

