#include <stdio.h>
#include <string.h>
#include <inttypes.h>

int main(void) {
    char *str[0] = {};
   
    if (str == NULL) {
       printf("NULL!\n");
    }

    if (!strcmp(str, "")) {
        printf("empty!\n");
    }
    
    return 0;
}

