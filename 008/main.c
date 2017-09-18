#include <stdio.h>

char* vertMirror(char* strng);
char* horMirror(char* strng);
typedef char* (*generic_func_t) (char*);
char* oper(generic_func_t f, char* s);

int main(void) {
    char *c = "abcd\nefgh\nijkl\nmnop";
    char *r;

    r = oper(vertMirror, c);

    printf("%s\n", r);

    return 0;
}

