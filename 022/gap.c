#include <math.h> /* sqrt */
#include <stdlib.h> /* calloc */

/* marks non-primes in [m, n] with '1' */
static char* mark(long long base, long long offset, 
                  long long limit) {
    char* res = calloc(offset, sizeof(char));

    for (long long i=2;i<=limit;i++) {
        long long ini = base%i;

        if (ini) ini = i-ini;

        if (i>=base && i<=(base+offset-1) && !*(res+ini)) {
            ini = i+ini;
        }

        for (long long j=ini;j<offset;j+=i) *(res+j) = 1;
    }

    return res;
}

/* searches for a gap of size "gap" */
long long* searchGaps(int gap, const char *isprime, 
                      long long base, long long offset) {
    const char *ptr = isprime;
    long long* res = calloc(2, sizeof(long long));
    int prime_found=0;
    int count=0;

    for (long long i=0;i<offset;i++) {
        if (*ptr==1) {
            count++;
        } else {
            if (prime_found) {
                count++;

                if (count==gap) {
                    *(res+0) = base+(ptr-count-isprime);
                    *(res+1) = base+(ptr-isprime);
                    break;
                }
            } else {
                prime_found++;
            }
            count = 0;
        }
        ptr++;
    }
   
    return res;
}

long long* gap(int g, long long m, long long n) {
    long long diff = n-m+1;
    long long sqt = (long long) sqrt(n);
    const char* isprime = mark(m, diff, sqt);

    return searchGaps(g, isprime, m, diff);
}

