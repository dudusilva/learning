#include <stdio.h>

#define SQUARES_N 64

typedef struct Game_tag {
    char board[SQUARES_N];
    char movements[SQUARES_N][2];
    char *ptr_movements;
} Game;

Game* initHorseTour(const int x, const int y);

static int order(Game *res, int x, int y) {
    char* ptr = res->movements[0];
    
    for (int i=0;i<SQUARES_N;i++) {
        if (*ptr == x && *(ptr+1) == y) {
            return i;
        }
        ptr += 2;
    }
}

int main(void) {
    Game* res = initHorseTour(0, 0);

    if (res->ptr_movements == (char*) res->movements) {
        printf("no path\n");
    } else {
        for (int i=0;i<8;i++) {
            for (int j=0;j<8;j++) {
                printf("%2d ", order(res, i, j));
            }
            printf("\n");
        }         

        printf("path\n");
    }

    return 0;
}
