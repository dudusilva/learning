#include <stdio.h>

int tour(char** arrFriends, int szArrFriends, 
         char** ftwns, char** townsDist,
         int szFTwns);

int main(void) {
    char* friends1[2] = { "B1", "B2" };
    char* fTowns1[10] =  {"B1", "Y1", "B2", "Y2", "B3", "Y3", "B4", "Y4", "B5", "Y5"};
    char* distTable1[10] = {"Y1", "50.0", "Y2", "70.0", "Y3", "90.0", "Y4", "110.0", "Y5", "150.0"};
    int res;

    res = tour(friends1, 2, fTowns1, distTable1, 10);

    printf("%d\n", res);

    return 0;
}

    /*
    */
