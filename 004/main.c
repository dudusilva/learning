#include <stdio.h>

int* seven(long long m);

int main(void) {
    long long a;
    int *res;

    a = 477557101;
    res = seven(a);
    printf("%d %d\n", *(res+0), *(res+1));

    return 0;
}

