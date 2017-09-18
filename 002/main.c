#include <stdio.h>

int nbYear(int p0, double percent, int aug, int p);
    
int main(void) {
    int result;

    /*
    dotest(1500, 5, 100, 5000,15);
    dotest(1500000, 2.5, 10000, 2000000, 10);
    dotest(1500000, 0.25, 1000, 2000000, 94);
    */

    result = nbYear(1500, 5, 100, 5000);
    printf("%d\n", result);
    result = nbYear(1500000, 2.5, 10000, 2000000);
    printf("%d\n", result);
    result = nbYear(1500000, 0.25, 1000, 2000000);
    printf("%d\n", result);

    return 0;
}

