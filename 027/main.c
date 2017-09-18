#include <stdlib.h> /* NULL */
#include <stdio.h> /* printf */

char* convert(const char * input, const char * source, 
              const char * target);

const char * bin = "01";
const char * oct = "01234567";
const char * dec = "0123456789";
const char * hex = "0123456789abcdef";
const char * allow = "abcdefghijklmnopqrstuvwxyz";
const char * alup = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char * alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char * alnum = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(void) {
    char *res = convert("codewars", allow, alup);
    printf("%s\n", res);

    return 0;
}
