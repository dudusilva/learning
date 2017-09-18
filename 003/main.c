#include <stdio.h>

char* longest(char* s1, char* s2);

int main(void) {
    char *a = "aretheyhere";
    char *b = "yestheyarehere";
    char *c;
    /* ans: aehrsty */ 

    c = longest(a, b);

    printf("%s\n", c);

    return 0;
}

