#include <stdio.h>

extern char board[8][8];

void printboard()
{
    int i, j;

    for (i = 0; i < 8; i++) {
        printf("%d|", i + 1);
        for (j = 0; j < 8; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf(" ");

    for (i = 0; i < 8; i++) {
        printf(" %c", i + 65);
    }
    printf("\n");
}
