#include <string.h> /* strlen, strchr */
#include <stdlib.h> /* malloc */
#include <stddef.h> /* ptrdiff_t */

#define MAX_SZ 100

typedef unsigned long long ull;

static ull srcToInt(const char* input, const char* alph) {
    size_t base = strlen(alph);
    size_t len = strlen(input);
    ull res = 0;
    ull var = 1;
    const char* ptr = input+len-1;
    
    while (len--) {
        const char* pos = strchr(alph, *ptr);
        ptrdiff_t digit = pos-alph;

        res += digit*var;

        var *= base;
        ptr--;
    } 
    return res;
}

static char* intToTar(ull num, const char* alph) {
    size_t base = strlen(alph);
    char *res = malloc(MAX_SZ+1);
    char *ptr = res;

    while (num) {
        int digit = num % base;

        *ptr++ = *(alph+digit);
        num /= base;
    }

    if (ptr == res) { *ptr++ = *(alph+0); }
    *ptr = '\0';

    return res;
}

static void revert(char *str) {
    size_t len = strlen(str);
    char* ptr_b = str;
    char* ptr_e = str+len-1;

    while (ptr_b < ptr_e) {
        *ptr_b ^= *ptr_e;
        *ptr_e ^= *ptr_b;
        *ptr_b ^= *ptr_e;

        ptr_b++;
        ptr_e--;
    }
    return;
}

char* convert(const char * input, const char * source, 
              const char * target)
{
    ull num = srcToInt(input, source);
    char *res = intToTar(num, target);
    revert(res);

    return res;
}

