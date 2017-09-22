#include <stdio.h>
#include <stdlib.h> /* malloc */
#include <string.h> /* strlen */
#include <ctype.h> /* isalpha */

#define RUNNERS 5 /* num. of runners */
#define ALPH 26 /* num. of letters in the alphabet */

size_t* computeSizes(size_t len) {
    size_t div = len/RUNNERS;
    size_t mod = len - div*RUNNERS;
    size_t* res = malloc(RUNNERS*sizeof(size_t));

    /* init */
    for (int i=0;i<RUNNERS;i++) { *(res+i) = div; }

    /* correct sizes if mod != 0 */
    {
        if (mod) {
            len -= (div << 2);

            for (int i=0;i<RUNNERS-1;i++) {
                if (len) {
                    (*(res+i))++;
                    len--;
                }
            }

            *(res+RUNNERS-1) = len;
        }
    }

    return res;
}

char shiftForward(char val, int shift) {
    if (isalpha(val)) {
        unsigned char aux = val+shift;
        const char limit = (val >= 'a') ? 'z' : 'Z';
        val = (aux > limit) ? aux-ALPH : aux;
    }
    return val;
}

char shiftBackward(char val, int shift) {
    if (isalpha(val)) {
        unsigned char aux = val-shift;
        const char limit = (val <= 'Z') ? 'A' : 'a';
        val = (aux < limit) ? aux+ALPH : aux;
    }
    return val;
}

char** encode(char* strng, int shift, int* lg) {
    size_t len = strlen(strng);
    size_t* sizes = computeSizes(len+2);
    char* prefix = malloc(2);
    char** res = malloc(RUNNERS*sizeof(char*));

    /* init */
    {
        char* ptr = strng;

        while (!isalpha(*ptr)) { ptr++; }
        *(prefix+0) = tolower(*(ptr+0));
        *(prefix+1) = shiftForward(*(prefix+0), shift);
    }

    /* encode and copy to substrings */
    {
        char* ptr_0 = prefix;

        for (int i=0;i<RUNNERS;i++) {
            *(res+i) = malloc(*(sizes+i)+1);
            char* ptr_1 = *(res+i);

            for (size_t j=0;j<*(sizes+i);j++) {
                if (ptr_0 == prefix) {
                    *ptr_1++ = *ptr_0++;
                } else if (ptr_0 == prefix+1) {
                    *ptr_1++ = *ptr_0;
                    ptr_0 = strng;
                } else {
                    *ptr_1++ = shiftForward(*ptr_0++, shift);
                }
            }
            *ptr_1 = '\0';
        }
    }

    /* array size */
    {
        for (int i=0;i<RUNNERS;i++) {
            if (*(sizes+i) != 0) { 
                *lg = i+1;
            } else {
                break;
            }
        }
    }

    /* free */
    {
        free(prefix);
        free(sizes);
    }

    for (int i=0;i<RUNNERS;i++) { printf("%s \n", *(res+i)); }

    return res;
}


char* decode(char** s, int sz) {
    char* res = NULL;
    int shift = 0;

    /* compute result string length and allocate memory */
    {
        size_t len = 0;

        for (int i=0;i<sz;i++) { len += strlen(*(s+i)); }
        res = malloc(len-2+1);
    }

    /* copy s to result sting */
    {
        char* ptr_0 = res;

        for (int i=0;i<sz;i++) {
            char* ptr_1 = *(s+i);    

            while (*ptr_1) { *ptr_0++ = *ptr_1++; }
        }
        *ptr_0 = '\0';
    }

    /* compute shift */
    {
        int sign = 0;

        shift = *(res+1) - *(res+0);
        if (shift < 0) { shift += ALPH; }
    }

    //printf("s: %d\n", shift);

    /* decode */
    {
        char* ptr_0 = res;
        char* ptr_1 = res+2;

        while (*ptr_1) {*ptr_0++ = shiftBackward(*ptr_1++,shift);}
        *ptr_0 = '\0';
    }

    //printf("r: %s\n", res);

    return res;
 }

