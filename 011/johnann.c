#include <stdlib.h>

static void computeAll(long long n, long long** A, long long** J,
                      long long *sum_a, long long *sum_j) {
    *A = malloc(n*sizeof(long long));
    *J = malloc(n*sizeof(long long));
    *sum_a = 1;
    *sum_j = 0;
    *(*A+0) = 1;
    *(*J+0) = 0;

    for (long long i=1;i<n;i++) {
        *(*J+i) = i - *(*A+*(*J+i-1));
        *(*A+i) = i - *(*J+*(*A+i-1));
        *sum_j += *(*J+i);
        *sum_a += *(*A+i);
    }
    return;
}

long long* john(long long n) {
    long long *A, *J, sum_a, sum_j;
    computeAll(n, &A, &J, &sum_a, &sum_j);
    free(A);
    return J;
}

long long sumJohn(long long n) {
    long long *A, *J, sum_a, sum_j;
    computeAll(n, &A, &J, &sum_a, &sum_j);
    free(A); free(J);
    return sum_j;
}

long long* ann(long long n) {
    long long *A, *J, sum_a, sum_j;
    computeAll(n, &A, &J, &sum_a, &sum_j);
    free(J);
    return A;
}

long long sumAnn(long long n) {
    long long *A, *J, sum_a, sum_j;
    computeAll(n, &A, &J, &sum_a, &sum_j);
    free(A); free(J);
    return sum_a;
}  

