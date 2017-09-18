#include <stddef.h>
#include <string.h>
#include <stdio.h>

#define BUF_SZ 30

int find_longest(int *numbers, size_t numbers_size)
{
    char buffer[BUF_SZ];
    int *ptr, abs;
    size_t max = 0;
    size_t len;

    for (size_t i=0;i<numbers_size;i++) {
        abs = *(numbers++);
        if (abs<0) abs=-abs;
        sprintf(buffer, "%d", abs);
        len = strlen(buffer);
        if (len > max) {
            max = len;
            ptr = numbers-1;
        }
    }

    return *ptr;
}

