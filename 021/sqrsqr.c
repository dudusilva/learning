#include <math.h> /* sqrt */
#include <stdlib.h> /* malloc */
#include <stdio.h> /* sprintf */

#define MAX_SEQ 50
#define MAX_OUT 200

static long long max(long long n) {
    return (long long) sqrt(n);
}

static long long min(long long n) {
    long long i = 0;
    long long sum = 0;

    while (sum < n) sum += ++i*i;
    return i; 
}

static int buildSeq(long long sum, long long mx, 
                    long long mn, long long* ptr,
                    long long sz) {
    for (long long i=mx;i>=mn;i--) {
        long long sum_nxt = sum - i*i;
        *ptr = i;

        if (sum_nxt) {
            long long mx_nxt = max(sum_nxt);
            long long mn_nxt = min(sum_nxt);
            long long sz_nxt = 0;

            if (mx_nxt==i) mx_nxt--;

            sz_nxt = buildSeq(sum_nxt, mx_nxt, mn_nxt, ptr+1, sz+1);

            if (sz_nxt) return sz_nxt;
        } else {
            return sz+1;
        }
    }

    *ptr = 0;
    return 0;
}

static char* output(long long* seq, long long size) {
    char* res = malloc(MAX_OUT);
    char* ptr = res;

    *ptr++ = '[';

    if (size) {
        for (long long i=size-1;i>=0;i--) {
            ptr += sprintf(ptr, "%lld,", *(seq+i));
        }
        ptr--;
    }

    *ptr++ = ']';
    *ptr = '\0';

    return res;
}

char* decompose(long long n) {
    long long seq[MAX_SEQ] = {0};
    long long *ptr = seq;
    long long size = buildSeq(n*n, n-1, min(n*n), ptr, 0);

    return output(seq, size); 
}

