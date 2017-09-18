#include <stdio.h>
#include <string.h>

char* revrot(char* s, int sz);

int main(void) {
    char str[] = "73304991087281576455176044327690580265896";
    char exr[] = "1994033775182780067155464327690480265895";
    int sz = 8;
    char *res;

    res = revrot(str, sz);
    
    if(strcmp(res, exr) != 0) {
        printf("no way\n");
    } else {
        printf("that way\n");
    }

    printf("%s\n", res);
    return 0;
}

