#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define ALPH_SZ 26 /* num of letters in the alphabet */
#define RUNNERS 5  /* num of runners */

/* compute output substring lengths */
static size_t* computeShare(size_t n) {
    size_t quo = n/RUNNERS;
    size_t rem = n-RUNNERS*quo;
    size_t *shr = malloc(RUNNERS*sizeof(size_t));

    for (int i=0;i<RUNNERS;i++) *(shr+i) = quo;
    *(shr+RUNNERS-1) += rem;

    if (rem) { /* if n mod 5 != 0 */
        int max = (*(shr+RUNNERS-1) > RUNNERS-1) 
                  ? RUNNERS-1 : *(shr+RUNNERS-1);
        for (int i=0;i<max;i++) (*(shr+i))++;
        *(shr+RUNNERS-1) -= max;
    }
    return shr;
}

/* shift is an integer mod ALPH_SZ */
static int updateShift(int shift) {
    return (++shift == ALPH_SZ) ? 0 : shift;
}

static char caesarEnc(char chr, int* shift) {
    if (isalpha(chr)) {
        unsigned char aux = chr+*shift;
        const char limit = (chr >= 'a') ? 'z' : 'Z';
        chr = (aux > limit) ? aux-ALPH_SZ : aux;
    }
    *shift = updateShift(*shift);
    return chr;
}

static char caesarDec(char chr, int* shift) {
    if (isalpha(chr)) {
        unsigned char aux = chr-*shift;
        const char limit = (chr <= 'Z') ? 'A' : 'a';
        chr = (aux < limit) ? aux+ALPH_SZ : aux;
    }
    *shift = updateShift(*shift);
    return chr;
}

char** movingShift(char* strng, int shift) {
    /* input str and output substr length  */
    const size_t len = strlen(strng); 
    const size_t *share = computeShare(len);
    char **res = malloc(RUNNERS*sizeof(char *));
    char *ptr_0 = strng;

    /* walk through main string and encrypt into substrings */
    for (int i=0;i<RUNNERS;i++) {
        char *ptr_1 = NULL;
        size_t limit = *(share+i);

        *(res+i) = malloc(limit+1);
       
        ptr_1=*(res+i); 
        for (size_t j=0;j<limit;j++) {
            *(ptr_1++) = caesarEnc(*(ptr_0++), &shift);
        }
        *ptr_1 = '\0'; 
    }
    return res;
}

char* demovingShift(char** s, int shift) {
    const size_t len = strlen(*s);      /* first string length */
    char *res = malloc(RUNNERS*len+1);  /* result string */
    char *ptr_0 = res;

    /* walk through strings and decrypt */
    for (int i=0;i<RUNNERS;i++) {
        char *ptr_1 = *(s+i);
        while (*ptr_1) *ptr_0++ = caesarDec(*(ptr_1++), &shift); 
    }
    *ptr_0 = '\0';
    return res;
}

