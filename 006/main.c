#include <stdio.h>

int find_longest(int *numbers, size_t numbers_size);

int main(void) {
    size_t size = 3;
    int numbers[] = {1, 100, 200};
    int result;

    result = find_longest(numbers, size);

    printf("%d\n", result);

    return 0;
}

