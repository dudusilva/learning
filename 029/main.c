#include <stdio.h>

char* decompose(char* nrStr, char* drStr);

int main(void) {
    char *res = decompose("50", "4187");

    printf("%s\n", res);

    return 0;
}

