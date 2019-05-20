#include <stdio.h>
#include "board.h"
#include "printboard.h"

char simb[11];
int X1, Y1, X2, Y2;
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
    int stat = 0;
    printboard();
    printf("Example of step:'A1-A3' or 'A1xA3' for catch.\nPlease input a "
           "Step: ");
    while (1) {
	  printf("Whites' step(big):");
        simb_scan(1);
        move();
        printboard();
        stat = check(1);
        if (stat != 0) {
            break;
	   }

	printf("Blacks' step(litle):");
        simb_scan(2);
        move();
        printboard();
        stat = check(2);
        if (stat != 0) {
            break;
        }
    }
    printf("Player %d win\n", stat);

    return 0;
}
