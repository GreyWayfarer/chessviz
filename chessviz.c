#include <stdio.h>

int main()
{
    char board[9][9]={
        {'R', 'H', 'B', 'Q', 'K', 'B', 'H', 'R'},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'r', 'h', 'b', 'k', 'q', 'b', 'h', 'r'}
    };
    int i, j;
    
    for (i = 0; i < 8; i++){
        printf("%d|", i+1);
        for (j = 0; j < 8; j++){
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf(" ");
    
    for (i = 0; i < 8; i++){
        printf(" %c", i + 65);
    }
    printf("\n");
    return 0;
    }