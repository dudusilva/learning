#include <stdio.h>

char** movingShift(char* strng, int shift);
char* demovingShift(char** s, int shift);

int main(void) {
    char **res_0; 
    char *res_1;
    char inp[] = "-uoxIirmoveNreefckgieaoiEcooqo";

    res_0 = movingShift(inp, 1);
    res_1 = demovingShift(res_0, 1);
    printf("%s\n", res_1);

    return 0;
}

