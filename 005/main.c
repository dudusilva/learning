#include <stdio.h>

unsigned long long finance(unsigned long long n);

int main(void) {
    unsigned long long n = 5000;
    unsigned long long r;

    r = finance(n);

    printf("%llu\n", r);

    return 0;
}

