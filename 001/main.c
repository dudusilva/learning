#include <stddef.h>

struct Node
{
    int value;
    struct Node *next;
};

struct Node * counter_effect(const char *hit_count, 
                             size_t *p_result_count);

int main(void)
{
    {
        struct Node node0_1 = { .value = 1, .next = NULL };

        struct Node node1_2 = { .value = 2, .next = NULL };
        struct Node node1_1 = { .value = 1, .next = &node1_2 };

        struct Node node2_5 = { .value = 5, .next = NULL };
        struct Node node2_4 = { .value = 4, .next = &node2_5 };
        struct Node node2_3 = { .value = 3, .next = &node2_4 };
        struct Node node2_2 = { .value = 2, .next = &node2_3 };
        struct Node node2_1 = { .value = 1, .next = &node2_2 };

        struct Node expected[4] = {
            { .value = 0, .next = &node0_1 },
            { .value = 0, .next = &node1_1 },
            { .value = 0, .next = &node2_1 },
            { .value = 0, .next = NULL },
        };

        struct Node *res;
        size_t count;
        res = counter_effect("1250", &count);
    }
    return 0;
}

