#include<stdio.h>

long long* gap(int g, long long m, long long n);

int main(void) {
    int g = 8;
    int m = 300;
    int n = 400;
    long long *res = gap(g, m, n);

    printf("%lld %lld\n", *(res+0), *(res+1));
    return 0;
}

/*
dotest(2,100,110, "101, 103");
    dotest(4,100,110, "103, 107");
        dotest(6,100,110, "0, 0");
            dotest(8,300,400, "359, 367");*/
