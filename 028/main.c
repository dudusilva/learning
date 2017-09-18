#include <stdio.h>

char* replaceNth(const char* text, int n, char oldValue, 
                 char newValue);

int main(void) {
    char* res = replaceNth("lalo ma oa qua to", 3, 'a', 'k');
    printf("%s\n", res);
    return 0;
}
