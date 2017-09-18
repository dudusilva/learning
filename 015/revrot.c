#include <string.h>
#include <stdlib.h>

static void reverse(char *dst, const char *src, int sz) {
    src = src+sz-1;
    while (sz--) *dst++ = *src--;
    return;
}

static void rotate(char *dst, const char *src, int sz) {
    char aux = *src++;

    sz--;
    while (sz--) *dst++ = *src++;
    *dst = aux;
    return;
} 

static int isOddSumCubes(const char *str, int sz) {
    int sum = 0;

    while (sz--) sum += (*str++)-'0';
    return sum & 0x1;
}

char* revrot(char* s, int sz) {
    size_t len = strlen(s);
    char *res;

    if (len>0 && sz>0 && sz<=len) {
        size_t chunk = len/sz;
        char *ptr_s = s;
        char *ptr_d = NULL;

        res = malloc(chunk*sz+1);
        *(res+chunk*sz) = '\0';
        ptr_d = res;

        for (size_t i=0;i<chunk;i++) {
            if (isOddSumCubes(ptr_s, sz)) {
                rotate(ptr_d, ptr_s, sz);
            } else {
                reverse(ptr_d, ptr_s, sz);
            }
            ptr_d += sz;
            ptr_s += sz;
        }
    } else {
        res = malloc(1);
        *res = '\0';
    }
    return res;
}

/*
static void reverse(char *str, int sz) {
    char *ptr = str+sz-1;

    while (ptr>str) {
        char aux = *str;
        *str++ = *ptr;
        *ptr-- = aux; 
    }
    return;
}

static void rotate(char *str, int sz) {
    char aux = *str;

    while (--sz) {
        *str = *(str+1);
        str++;
    }
    *str = aux;
    return;
}

static int isOddSumCubes(const char *str, int sz) {
    int sum = 0;

    for (int i=0;i<sz;i++) {
        int cube = *(str+i)-'0';
        cube = cube*cube*cube;
        sum += cube;
    }
    return sum & 0x1;
}

char* revrot(char* s, int sz) {
    size_t len = strlen(s);
    char *res;

    if (len>0 && sz>0 && sz<=len) {
        size_t chunk = len/sz;
        char *ptr = NULL;

        res = malloc(chunk*sz+1);
        strncpy(res, s, chunk*sz);
        *(res+chunk*sz) = '\0';
        ptr = res;

        for (size_t i=0;i<chunk;i++) {
            if (isOddSumCubes(ptr, sz)) {
                rotate(ptr, sz);
            } else {
                reverse(ptr, sz);
            }
            ptr += sz;
        }
    } else {
        res = malloc(1);
        *res = '\0';
    }
    return res;
}
*/

