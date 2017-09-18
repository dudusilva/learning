#include <stdio.h>

typedef struct Pair Pair;

struct Pair {
    long long first;
    long long snd;
};

Pair** removNb(long long n, int* length);

int main(void) {
    Pair** res;
    int len;

    res = removNb(26, &len);

    printf("len: %d\n", len);
   
    printf("{"); 
    for (int i=0;i<len;i++) {
        printf("{%lld, %lld}", (**(res+i)).first, (**(res+i)).snd);
    }
    printf("}\n");

    return 0;
}

