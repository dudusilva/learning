#include <stdlib.h> /* malloc */

static int* createChain(int n) {
    int *res = malloc(n*sizeof(int));
    *(res+0) = 1;
    *(res+1) = 1;

    for (int i=2;i<n;i++) {
        int idx_0 = i-*(res+i-1);
        int idx_1 = i-*(res+i-2);
        *(res+i) = *(res+idx_0)+*(res+idx_1);
    }

    return res;
}

int lengthSupUK(int n, int k) {
    int *chain = createChain(n);
    int count = 0;

    for (int i=0;i<n;i++) {
        if (*(chain+i) >= k) {
            count++;
        }
    }

    free(chain);
    return count;
}

int comp(int n) {
    int *chain = createChain(n);
    int count = 0;

    for (int i=1;i<n;i++) {
        if (*(chain+i) < *(chain+i-1)) {
            count++;
        }
    }

    free(chain);
    return count;
}

