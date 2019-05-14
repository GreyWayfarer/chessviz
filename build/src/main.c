#include <stdio.h>
#include "board.h"
#include "printboard.h"

char board[8][8] = {{'R', 'H', 'B', 'Q', 'K', 'B', 'H', 'R'},
                    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                    {'r', 'h', 'b', 'k', 'q', 'b', 'h', 'r'}};


int main()
{
    int X1, Y1, X2, Y2/*, W1, Z1, W2, Z2*/;
    char simb[15];
    
    printf("Input our step: ");
    fgets(simb, 12, stdin);
    trans(simb, &X1, &Y1, &X2, &Y2/*, &W1, &Z1, &W2, &Z2*/);
    move(X1, Y1, X2, Y2 /*W1, Z1, W2, Z2*/);
    printboard();
   return 0;
}
