#include <stddef.h>

#include <stdlib.h>
#define LEN 4 /* counter size */

struct Node
{
    int value;
    struct Node *next;
};

struct Node * counter_effect(const char *hit_count, 
                             size_t *p_result_count)
{
    struct Node *res, *ptr;
    int digit;
    const char *ptr_ch;
 
    /* allocate memory for first nodes */ 
    res = malloc(LEN*sizeof(struct Node));

    for (int i=0;i<LEN;i++) {
        (*(res+i)).value = 0;
        (*(res+i)).next = NULL;
    }

    ptr_ch = hit_count;
    for (int i=0;i<LEN;i++) { 
        /* char to int */
        digit = *ptr_ch++ - '0'; 
     
        /* allocate memory for the remaining nodes */
        ptr = res+i;
        for (int j=1;j<digit+1;j++) {
            (*ptr).next = malloc(sizeof(struct Node));
            ptr =  (*ptr).next;
            (*ptr).value = j;
            (*ptr).next = NULL;
        }
    }

    *p_result_count = LEN;
    return res;
}

