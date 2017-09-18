#include <stdio.h>

char* stockSummary(char** lstOfArt, int szlst, 
                   char** categories, int szcat);

int main(void) {
        char* art[5] = {"ABAR 200", "CDXE 500", "BKWR 250", 
                        "BTSQ 890", "DRTY 600"};
        char* cd[2] = {"A", "B"};

        char* result;
        //dotest(art, 5, cd, 2, "(A : 200) - (B : 1140)");

        result = stockSummary(art, 5, cd, 2);

        //char* art[0] = {};
        //char* cd[4] = {"B", "R", "D", "X"};
        //dotest(art, 0, cd, 4, "");

        printf("%s\n", result);
}

