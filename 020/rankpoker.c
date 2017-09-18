#include <stdlib.h> /* malloc */

#define NUM_CARDS 5

typedef struct Hand Hand;
struct Hand { 
    int game[NUM_CARDS]; 
    int rank;
};

typedef enum { Win, Loss, Tie } Result;

Hand* PokerHand (const char *cards) {
    /* inits */
    Hand *pl = malloc(sizeof(Hand));

    /* orders */
    int order[13] = {0};
    int* scenario[4] = {order+0, order+2, order+4, order+7};
    int count[4] = {0};
    char symbols[] = " AKQJT98765432";

    /* computes the multiplicity of each possible card */
    for (char* ptr_0=symbols+1;*ptr_0;ptr_0++) {
        int mult = 0;

        for (const char* ptr_1=cards;*ptr_1;ptr_1++) {
            if (*ptr_1==*ptr_0) mult++;
        }

        if (mult) {
            int* ptr_int = *(scenario+4-mult);
            while (*ptr_int) ptr_int++;
            *ptr_int = ptr_0-symbols;
            (*(count+4-mult))++;
        }
    }

    /* places the cards in order */
    int *ptr_game = (*pl).game;
    for (int i=0;i<4;i++) {
        int* ptr_int = *(scenario+i); 
       
        while (*ptr_int) { 
            for (int j=0;j<4-i;j++) *ptr_game++ = *ptr_int;
            ptr_int++;
        }
    }

    /* ranks */
    if (*(count+0)) (*pl).rank = 7; /* four */
    else if (*(count+1) && *(count+2)) (*pl).rank = 6; /* full h */
    else if (*(count+1)) (*pl).rank = 3; /* three */
    else if (*(count+2)) (*pl).rank = *(count+2); /* two/one pair */
    else (*pl).rank = 0;

    if (!(*pl).rank) {
        int flush = 0;
        int straight = 4;

        /* flush? */
        if (*(cards+1)==*(cards+4) && *(cards+1)==*(cards+7) &&
            *(cards+1)==*(cards+10) && *(cards+1)==*(cards+13)) {
            flush = 5;
        }

        /* straight? */
        for (int i=1;i<NUM_CARDS-1;i++) {
            if ((*pl).game[i]!=(*pl).game[i+1]-1) straight = 0;
        }

        /* hack for Ace = (1 or Ace) in sequence */
        if ((*pl).game[4]==13) {
            if ((*pl).game[0]!=1 && (*pl).game[0]!=9) straight = 0;
        } else {
            if ((*pl).game[0]!=(*pl).game[1]-1) straight = 0;
        }

        /* hack for Ace = 1 for correct comparison */
        if (straight==4 && (*pl).game[0]==1 && (*pl).game[4]==13) {
            for(int i=0;i<NUM_CARDS-1;i++) {
                (*pl).game[i] = (*pl).game[i+1];
            }
            (*pl).game[4] = 0;
        }

        (*pl).rank = flush+straight;
    }

    return pl;
}

Result compare(Hand* player, Hand* opponent) {
    if ((*player).rank > (*opponent).rank) return Win;
    else if ((*player).rank < (*opponent).rank) return Loss;
    else {
        /* tie break */
        for (int i=0;i<NUM_CARDS;i++) {
            if ((*player).game[i] < (*opponent).game[i]) {
                return Win;
            } else if ((*player).game[i] > (*opponent).game[i]) {
                return Loss;
            }
        }
        return Tie;
    }
}

/*
    printf("c: %s\n", cards);
    printf("f: %2d\n", **(scenario+0));
    printf("t: %2d\n", **(scenario+1));
    printf("p: %2d %2d\n", *(*(scenario+2)+0), *(*(scenario+2)+1));
    printf("n: %2d %2d %2d %2d %2d\n", 
           *(*(scenario+3)+0), *(*(scenario+3)+1),
           *(*(scenario+3)+2), *(*(scenario+3)+3),
           *(*(scenario+3)+4));
    printf("R: %d\n", (*pl).rank);

    for (int i=0;i<NUM_CARDS;i++) {
        printf("%2d ", (*pl).game[i]);
    }
    printf("\n\n");
*/
