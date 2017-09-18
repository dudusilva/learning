#include <string.h>
#include <stdlib.h> /* malloc */
#include <stdio.h>

#define SQUARES_N 64
#define IDX(x,y) (y<<3)+x

typedef struct Game_tag {
    char board[SQUARES_N];
    char movements[SQUARES_N][2];
    char *ptr_movements;
} Game;

static int advPointer(Game *res) {
    if (res->ptr_movements - (char*)res->movements == 126) {
        res->ptr_movements+=2;
        return 1;
    } else {
        res->ptr_movements+=2;
        return 0;
    }
}

static void retPointer(Game *res) {
    if (res->ptr_movements != (char*) res->movements) {
        res->ptr_movements-=2;
    }
    return;
}

static void horseTour(const int x, const int y, Game* res) {
    if ( x>7 || x<0 || y>7 || y<0 ) {
        return;
    } else {
        if (res->board[IDX(x,y)] == 0) {
            res->board[IDX(x,y)] = 1;
            res->ptr_movements[0] = x;
            res->ptr_movements[1] = y;

            if (advPointer(res)) {
                return;
            } else {
                char* ptr_prev = res->ptr_movements;

                horseTour(x+1,y+2,res);
                if (res->ptr_movements != ptr_prev) { return; }
                horseTour(x+2,y+1,res);
                if (res->ptr_movements != ptr_prev) { return; }
                horseTour(x+1,y-2,res);
                if (res->ptr_movements != ptr_prev) { return; }
                horseTour(x+2,y-1,res);
                if (res->ptr_movements != ptr_prev) { return; }
                horseTour(x-1,y+2,res);
                if (res->ptr_movements != ptr_prev) { return; }
                horseTour(x-2,y+1,res);
                if (res->ptr_movements != ptr_prev) { return; }
                horseTour(x-1,y-2,res);
                if (res->ptr_movements != ptr_prev) { return; }
                horseTour(x-2,y-1,res);
                if (res->ptr_movements != ptr_prev) { return; }
                
                res->board[IDX(x,y)] = 0;
                retPointer(res);

                return;
            }
        } else {
            return;
        }
    }
}

Game* initHorseTour(const int x, const int y) {
    Game* res = malloc(sizeof(Game));

    memset(res->board, 0, SQUARES_N);
    res->ptr_movements = (char*) res->movements;

    horseTour(x, y, res);
    return res;   
}

