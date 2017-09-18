#include <stdio.h>

long long* john(long long n);
long long sumJohn(long long n);
long long* ann(long long n);
long long sumAnn(long long n);

int main(void) {
    long long n = 78;
    long long *A, *J;
    long long sum_a, sum_j;

    sum_a = sumAnn(n); 

    printf("Ann ");
    //for (long long i=0;i<n;i++) printf("%lld ", *(A+i));
    printf("Ann sum %lld\n\n", sum_a);

    //printf("Joh ");
    //for (long long i=0;i<n;i++) printf("%lld ", *(J+i));
    //printf("Joh sum %lld\n\n", sum_j);
    return 0;
}

