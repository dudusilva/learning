#include<stdlib.h> /* malloc */
#include<string.h> /* strlen */
#include<stdio.h>

#define MAX_FACT 20
#define MAX_STR 100

typedef unsigned long long ull;

static ull charToInt(char digit) {
    if (digit <= '9') {
        return digit-'0';
    } else {
        return digit-'A'+10;
    }
}

static char intToChar(ull digit) {
    if (digit <= 9) {
        return digit+'0';
    } else {
        return digit+'A'-10;
    }
}

static void fillTable(ull *tbl) {
    ull fact = 1;

    for (int i=0;i<MAX_FACT+1;i++) {
        *(tbl+i) = fact;
        fact *= i+1;
    }
    return;
}

static void trimZeros(char *str) {
    char *ptr_0 = str;
    char *ptr_1 = str;

    while (*ptr_0++ == '0');
    ptr_0--;

    while (*ptr_0) *ptr_1++ = *ptr_0++;
    *ptr_1 = '\0';
    return;
}

char* dec2FactString(ull nb) {
    char *res = malloc(MAX_STR);
    ull *tbl_fact = malloc((MAX_FACT+1)*sizeof(ull));
    char *ptr = res;

    fillTable(tbl_fact); 

    for (int i=MAX_FACT;i>=0;i--) {
        ull div = nb / (*(tbl_fact+i));
        nb -= div*(*(tbl_fact+i));
        *ptr++ = intToChar(div);
    }
    *ptr = '\0';

    trimZeros(res);

    free(tbl_fact);
    return res;
}

ull factString2Dec(char* str) {
    size_t len = strlen(str);
    char *ptr = str+len-1;
    ull fact = 1;
    ull res = 0;

    for (size_t i=0;i<len;i++) {
        res += fact*charToInt(*ptr--);
        fact *= (i+1);
    }
    return res;
}

