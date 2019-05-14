#include <stdio.h>
#include <string.h>
#include "board.h"

extern char board[8][8];

void trans(char *simb, int *X1, int *Y1, int *X2, int *Y2/*, int *W1, int *Z1, int *W2, int *Z2*/) {
        *X1 = (int)simb[0] - 'A';
        *Y1 = (int)simb[1] - '1';
        *X2 = (int)simb[3] - 'A';
        *Y2 = (int)simb[4] - '1';
        /**W1 = (int)simb[6] - 'A';
        *Z1 = (int)simb[7] - '1';
        *W2 = (int)simb[9] - 'A';
        *Z2 = (int)simb[10] - '1';*/
}

void move(int X1, int Y1, int X2, int Y2/*, int W1, int Z1, int W2, int Z2*/) {
        board[Y2][X2] = board[Y1][X1];
        board[Y1][X1] = ' ';/*
        board[W2][Z2] = board[W1][Z1];
        board[W1][Z1] = ' ';*/
}


