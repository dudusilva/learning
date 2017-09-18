#include <stdio.h>
#include <stddef.h> /* ptrdiff_t */

long long* smallest(long long n);

int main(void) {
    long long* res;
    long long n = 296837; 

    res = smallest(n);

    printf("%lld %lld %lld\n", *(res+0), *(res+1), *(res+2));
    return 0;
}

/*
dotest(261235, "126235, 2, 0");
    dotest(209917, "29917, 0, 1");
        dotest(285365, "238565, 3, 1");
            dotest(296837, "239687, 4, 1");
            
    char inp[] = "123456";
    char *from, *to;
    ptrdiff_t to_int, from_int;
    long long out;

    from = inp+0;
    from_int = from-inp;

    printf("org: %s\n", inp);
    for (int i=0;i<6;i++) {
        to = inp+i;
        to_int = to-inp;
        out = moveDigit(from, to, inp);
        printf("%lld f:%d t:%d\n", out, (int)from_int, (int)to_int);
    }
    return 0;
    */

