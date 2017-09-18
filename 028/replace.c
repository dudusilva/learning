#include <stdlib.h> /* malloc */
#include <string.h> /* strcpy */

char* strchr_x(const char* string, char ch) {
    if (string) {
        char *ptr = strchr(string, ch);
        if (ptr) return ptr+1;
    } 

    return NULL;
}

char* replaceNth(const char* text, int n, char oldValue, 
                 char newValue) {
    size_t len = strlen(text);
    char* res = malloc(len+1);
    char* ptr = res;

    strcpy(res, text);

    if (n<1) return res;

    while (ptr) {
        for (int i=0;i<n;i++) {
            ptr = strchr_x(ptr, oldValue);
        }

        if (ptr) *(ptr-1) = newValue;
    }

    return res;
}

