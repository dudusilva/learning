#include <stdlib.h> /* malloc */
#include <string.h> /* strcmp */
#include <math.h> /* sqrt, floor */

/* given a (friend/town), finds the respective (town/distance) */
static char* findPair(char **src, char *item, int len) {
    for (int i=0;i<(len>>1);i++) {
        if (!strcmp(*src, item)) return *(src+1);
        src+=2;
    } 

    return NULL;
}

/* builds the array of distances */
static double* buildArray(char** arrFriends, int szArrFriends, 
                          char** ftwns, char** townsDist, 
                          int szFTwns) {
    double *res = malloc(szArrFriends*sizeof(double));

    for (int i=0;i<szArrFriends;i++) {
        /* searches for the town */
        char *ptr = findPair(ftwns, *(arrFriends+i), szFTwns);
        if (ptr) {
            /* searches for the distance */
            ptr = findPair(townsDist, ptr, szFTwns);
            /* stores in the array of distances */
            *(res+i) = strtod(ptr, (char **) NULL);
        } else {
            *(res+i) = -1;
        }
    }

    return res;
}

int tour(char** arrFriends, int szArrFriends, 
         char** ftwns, char** townsDist,
         int szFTwns) {
    double *dist = buildArray(arrFriends, szArrFriends, 
                             ftwns, townsDist, szFTwns);
    double sum = 0;
    double org = -1;

    for (int i=0;i<szArrFriends;i++) {
        if (*(dist+i) > 0) {
            if (org < 0) {
                sum += *(dist+i);
            } else {
                sum += sqrt((*(dist+i))*(*(dist+i))-org*org);
            }
            org = *(dist+i); 
        }   
    }
    if (org > 0) sum += org;

    return (int) floor(sum);
}

