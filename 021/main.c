#include <stdio.h>

char* decompose(long long n);

int main(void) {
    char *res = decompose(50);

    printf("%s\n", res);

    return 0;
}

/*
 *         testing(50, "[1,3,5,8,49]");
 *                 testing(44, "[2,3,5,7,43]");
 *                         testing(625, "[2,5,8,34,624]");
 *                                 testing(2, "[]");
 */
