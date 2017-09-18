#include<stdio.h>

long long** convertFrac(long long lst[][2], int row);

int main(void) {
    long long **ou0;
    long long *ptr;
    long long in0[3][2] = { {69,138}, {80, 1310}, {30, 40} };
    int in1 = 3;

    ou0 = convertFrac(in0, in1);
    ptr = (long long*) ou0;

    for (int i=0;i<in1;i++) {
        printf("{%lld, %lld}", *(ptr+2*i+0), *(ptr+2*i+1));
    }
    printf("\n");

    return 0;
}

