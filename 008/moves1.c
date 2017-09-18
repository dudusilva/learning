#include <string.h>
#include <stddef.h>
#include <stdlib.h>

#define SEP '\n'

ptrdiff_t getSize(char* str) {
    char *ptr = strchr(str, SEP);
    return (ptr-str)+1;
}

char* vertMirror(char* strng) {
    ptrdiff_t size = getSize(strng); 
    char *res = malloc((size-1)*size);
    char *ptr_0 = res;
    char *ptr_1 = strng+(size-2); 

    for (ptrdiff_t i=0;i<(size-1);i++) {
        for (ptrdiff_t j=0;j<(size-1);j++) *(ptr_0++) = *(ptr_1--);
        *(ptr_0++) = SEP;
        ptr_1 += (size << 1) - 1;
    }
    *(--ptr_0) = '\0';
    return res;
}

char* horMirror(char* strng) {
    ptrdiff_t size = getSize(strng); 
    char *res = malloc((size-1)*size);
    char *ptr_0 = res;
    char *ptr_1 = strng + (size)*(size-2); 
 
    for (ptrdiff_t i=0;i<(size-1);i++) {
        for (ptrdiff_t j=0;j<size;j++) *(ptr_0++) = *(ptr_1++);
        ptr_1 -= (size << 1);
    }
    *(--ptr_0) = '\0';
    *(res+size-1) = SEP;
    return res;
}

typedef char* (*generic_func_t) (char*);

char* oper(generic_func_t f, char* s) {
    return f(s);
}

