#include <stdio.h>

int zeroes(int base, int number);

int main(void) {
    int res = zeroes(16, 16);
  
    printf("nz: %d\n", res);

    /* 
    for (int i=240;i<257;i++) {
        zeroes(i, 6);
    }
    */

    return 0;
}

