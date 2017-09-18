#include <stdio.h>

unsigned long long finance(unsigned long long n) {
    unsigned long long savings, base;

    base = n*(n+1) >> 1;
    savings = base;

    for (unsigned long long i=0;i<n;i++) {
        base += n - 3*i;
        savings += base;
    }

    return savings;
}

