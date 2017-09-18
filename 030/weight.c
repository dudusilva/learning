#include <string.h> /* strlen, strchr */
#include <stdlib.h> /* malloc */
#include <stddef.h> /* size_t */
#include <stdio.h>

typedef struct Weight_tag {
    char value[32];
    int s_digits;
} Weight;

static int compare(const void* a, const void* b) {
    Weight *A = (Weight *) a;
    Weight *B = (Weight *) b;

    if ((*A).s_digits > (*B).s_digits) {
        return 1;
    } else if ((*A).s_digits < (*B).s_digits) {
        return -1;
    } else {
        return strcmp((*A).value, (*B).value);
    }
}

static int countValues(const char* s) {
    const char* ptr = s;
    int count = 0;

    while (*ptr) { if (*ptr++ == ' ') { count++; } }
    return count+1;
}

char* processValues(const char* s, int count, int len) {
    Weight* res = malloc(count*sizeof(Weight));
    char* res_str = malloc(len+1);
    
    *(res_str) = '\0';

    /* fill Weight struct */
    {
        const char* ptr_0 = s;
        const char* ptr_1 = strchr(ptr_0, ' ');
        char* ptr;
        int idx = 0;
        int len_last = 0;

        while (ptr_1) {
            ptrdiff_t len_cpy = ptr_1 - ptr_0;
            strncpy((*(res+idx)).value, ptr_0, len_cpy+1);
            (*(res+idx)).value[len_cpy+1] = '\0';
            ptr_0 = ptr_1+1;
            ptr_1 = strchr(ptr_0, ' ');
            idx++;
        }
        strcpy((*(res+idx)).value, ptr_0);
        len_last = strlen((*(res+idx)).value);

        ptr = (*(res+idx)).value + len_last;
        *ptr++ = ' ';
        *ptr = '\0';
    }

    /* compute value weights */
    {
        for (int i=0;i<count;i++) {
            int weight = 0;
            char* ptr = (*(res+i)).value;

            while (*ptr != ' ') { weight += *ptr++ - '0'; }
            (*(res+i)).s_digits = weight;
        }
    }

    /* sort */
    qsort(res, count, sizeof(Weight), compare);

    /* struct to string */
    {
        int len_str = 0;

        for (int i=0;i<count;i++) { 
            if ((*(res+i)).s_digits) {
                strcat(res_str, (*(res+i)).value); 
            }
        }
        len_str = strlen(res_str);
        *(res_str+len_str-1) = '\0';
    }

    /* print */
    for (int i=0;i<count;i++) {
        printf("%s : %d\n", (*(res+i)).value, (*(res+i)).s_digits);
    }
    
    printf("%sf\n", res_str);

    free(res);
    return res_str;
}

char* orderWeight(const char* s) {
    size_t len = strlen(s);
    char* res = NULL;

    if (len) {
        int count = countValues(s);
        res = processValues(s, count, len);
    } else {
        res = malloc(1);
        *res = '\0';
    }

    return res;
}

/*
    for (int i=0;i<count;i++) {
        printf("%s : %d\n", (*(res+i)).value, (*(res+i)).s_digits);
    }
    
    printf("%sf\n", res_str);
*/
