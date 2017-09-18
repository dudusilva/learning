#include <stdio.h> /* print */

typedef struct Hand Hand;

typedef enum { Win, Loss, Tie } Result;

Hand* PokerHand (const char *cards);
Result compare (Hand* player, Hand* opponent);

int main(void) {
    Hand *pl = PokerHand("AD 5D 4D 3D 2D");
    Hand *op = PokerHand("KS QS JS TS 9D");
    Result res;

    res = compare(pl, op);

    printf("res: %d\n", res);

    return 0;
}

