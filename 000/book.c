#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define ALPHABET 24     /* number of letters in the alphabet */
#define BUF_SZ 20       /* maximum buffer size */
#define BASE 10         /* base for str to int conversion */
#define FIRST_CAT 'A'   /* first book category */

char* stockSummary(char** lstOfArt, int szlst, 
                   char** categories, int szcat) {
    char *account;

    if (szlst != 0 && szcat != 0) {
        int amt;                        /* amount of books */
        int sum[ALPHABET] = {0};        /* accumulator */
        char buf[BUF_SZ], *ptr;         /* buffer and pointer */

        /* initializes result string */
        account = malloc(szcat*BUF_SZ*sizeof(char));
        *(account+0) = '\0';

        /* computes total amount of books per category */
        for (int i=0; i<szlst; i++) {
            ptr = *(lstOfArt+i);
            sscanf(ptr, "%*s %d", &amt);
            sum[*ptr-FIRST_CAT] += amt;
        }

        /* creates formatted result string */
        for (int i=0; i<szcat; i++) {
            ptr = *(categories+i);
            amt = sum[*ptr-FIRST_CAT];
            snprintf(buf, BUF_SZ, "(%c : %d) - ", *ptr, amt);
            strncat(account, buf, BUF_SZ);
        }

        ptr = account;
        while (*ptr) { ptr++; }
        *(ptr-3) = '\0';
    } else {
        /* initializes result string */
        account = malloc(1*sizeof(char));
        *(account+0) = '\0';
    }
    return account;
}

