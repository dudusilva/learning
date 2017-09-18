#include <stdlib.h>

#define NUM_ANSWERS 2

int* seven(long long m) {
    int* ans = malloc(NUM_ANSWERS*sizeof(int));
    long long d10; 
   
    for(*(ans+1)=0;m>99;(*(ans+1))++) {
        d10 = m / 10;           /* div */
        m = m - 10*d10;         /* mod */
        m = d10 - (m << 1);     /* m = x - 2y */
    }
    *(ans+0) = (int) m;

    return ans;
}

