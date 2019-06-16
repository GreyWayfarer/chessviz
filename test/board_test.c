#include "../src/board.h"
#include "../src/printboard.h"
#include "../thirdparty/ctest.h"
#include <stdio.h>
#include <string.h>

int status = 0, i, j;
int X1, X2, Y1, Y2;
char board[8][8] = {{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                   {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                   {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                   {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                   {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                   {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                   {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                   {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}};
char simb[11];

CTEST(inputdata, chartointer)
{
    strcpy(simb, "E2#E4"); // Wrong input
    int c1 = trans(simb);

    strcpy(simb, "E2xE4"); // Capture
    int c2 = trans(simb);

    strcpy(simb, "E2-E4"); // simb
    int c3 = trans(simb);

    strcpy(simb, "E2-E9"); // simb beyond limits
    int c4 = trans(simb);

    strcpy(simb, "hello!"); // Input not simb
    int c5 = trans(simb);

    const int exp1 = 0;
    const int exp2 = 0;
    const int exp3 = 1;
    const int exp4 = 0;
    const int exp5 = 0;

    ASSERT_EQUAL(exp1, c1);
    ASSERT_EQUAL(exp2, c2);
    ASSERT_EQUAL(exp3, c3);
    ASSERT_EQUAL(exp4, c4);
    ASSERT_EQUAL(exp5, c5);
}

CTEST(moving, movewhitepawn) // Test P
{
    strcpy(simb, "E2-E3"); // First simb on 1
    trans(simb);
    board[Y1][X1] = 'P';
    int c1 = white();

    strcpy(simb, "E2-E4"); // First simb on 2
    trans(simb);
    int c2 = white();

    board[Y1][X1] = ' ';

    strcpy(simb, "E3-E5"); // Not first simb on 2
    trans(simb);
    board[Y1][X1] = 'P';
    int c3 = white();

    strcpy(simb, "E3-F4"); // Diagonaly step
    trans(simb);
    int c4 = white();

    strcpy(simb, "E3-E2"); // Step back
    trans(simb);
    int c5 = white();

    strcpy(simb, "E3xF4"); // Capture
    trans(simb);
    board[Y2][X2] = 'p';
    int c6 = white();

    board[Y2][X2] = ' ';
    board[Y1][X1] = ' ';

    strcpy(simb, "E2-E4"); // First simb though figure 
    trans(simb);
    board[Y1][X1] = 'P';
    board[Y1 + 1][X1] = 'p';
    int c7 = white();

    board[Y1][X1] = ' ';
    board[Y1 + 1][X1] = ' ';

    const int exp1 = 1;
    const int exp2 = 1;
    const int exp3 = 0;
    const int exp4 = 0;
    const int exp5 = 0;
    const int exp6 = 1;
    const int exp7 = 0;

    ASSERT_EQUAL(exp1, c1);
    ASSERT_EQUAL(exp2, c2);
    ASSERT_EQUAL(exp3, c3);
    ASSERT_EQUAL(exp4, c4);
    ASSERT_EQUAL(exp5, c5);
    ASSERT_EQUAL(exp6, c6);
    ASSERT_EQUAL(exp7, c7);
}

CTEST(moving, moveblackpawn) // Test p
{
    strcpy(simb, "D7-D6"); // First simb on 1
    trans(simb);
    board[Y1][X1] = 'p';
    int c1 = black();

    strcpy(simb, "D7-D5"); // First simb on 2
    trans(simb);
    int c2 = black();

    board[Y1][X1] = ' ';

    strcpy(simb, "D6-D4"); // Not first simb on 2
    trans(simb);
    board[Y1][X1] = 'p';
    int c3 = black();

    strcpy(simb, "D6-C5"); // Diagonaly step
    trans(simb);
    int c4 = black();

    strcpy(simb, "D6-D7"); // Step back
    trans(simb);
    int c5 = black();

    strcpy(simb, "D6xC5"); // Catch
    trans(simb);
    board[Y2][X2] = 'P';
    int c6 = black();

    board[Y2][X2] = ' ';
    board[Y1][X1] = ' ';

    strcpy(simb, "D7-D5"); // First simb though figure 
    trans(simb);
    board[Y1][X1] = 'P';
    board[Y1 + 1][X1] = 'P';
    int c7 = black();

    board[Y1][X1] = ' ';
    board[Y1 + 1][X1] = ' ';

    const int exp1 = 1;
    const int exp2 = 1;
    const int exp3 = 0;
    const int exp4 = 0;
    const int exp5 = 0;
    const int exp6 = 1;
    const int exp7 = 0;

    ASSERT_EQUAL(exp1, c1);
    ASSERT_EQUAL(exp2, c2);
    ASSERT_EQUAL(exp3, c3);
    ASSERT_EQUAL(exp4, c4);
    ASSERT_EQUAL(exp5, c5);
    ASSERT_EQUAL(exp6, c6);
    ASSERT_EQUAL(exp7, c7);
}

CTEST(moving, moverook) // Test R
{
    strcpy(simb, "D4-D7"); // Step forward
    trans(simb);
    board[Y1][X1] = 'R';
    int c1 = white();

    strcpy(simb, "D4-D2"); // Step back
    trans(simb);
    int c2 = white();

    strcpy(simb, "D4-F4"); // Step right
    trans(simb);
    int c3 = white();

    strcpy(simb, "D4-B4"); // Step left
    trans(simb);
    int c4 = white();

    strcpy(simb, "D4-F6"); // Diagonaly step
    trans(simb);
    int c5 = white();

    strcpy(simb, "D4xD5"); // Catch
    trans(simb);
    board[Y2][X2] = 'r';
    int c6 = white();

    strcpy(simb, "D4-D6"); // simb though figure 
    trans(simb);
    int c7 = white();

    board[Y1][X1] = ' ';
    board[Y2 - 1][X2] = ' ';

    const int exp1 = 1;
    const int exp2 = 1;
    const int exp3 = 1;
    const int exp4 = 1;
    const int exp5 = 0;
    const int exp6 = 1;
    const int exp7 = 0;

    ASSERT_EQUAL(exp1, c1);
    ASSERT_EQUAL(exp2, c2);
    ASSERT_EQUAL(exp3, c3);
    ASSERT_EQUAL(exp4, c4);
    ASSERT_EQUAL(exp5, c5);
    ASSERT_EQUAL(exp6, c6);
    ASSERT_EQUAL(exp7, c7);
}

CTEST(moving, moveknight) // Test N
{
    strcpy(simb, "D4-D7"); // Step forward
    trans(simb);
    board[Y1][X1] = 'H';
    int c1 = white();

    strcpy(simb, "D4-D2"); // Step back
    trans(simb);
    int c2 = white();

    strcpy(simb, "D4-F4"); // Step right
    trans(simb);
    int c3 = white();

    strcpy(simb, "D4-B4"); // Step left
    trans(simb);
    int c4 = white();

    strcpy(simb, "D4-F6"); // Diagonaly step
    trans(simb);
    int c5 = white();

    strcpy(simb, "D4-C6"); // Knight simb forward-left
    trans(simb);
    int c61 = white();

    strcpy(simb, "D4-E6"); // Knight simb forward-right
    trans(simb);
    int c62 = white();

    strcpy(simb, "D4-F5"); // Knight simb right-forward
    trans(simb);
    int c63 = white();

    strcpy(simb, "D4-F3"); // Knight simb right-back
    trans(simb);
    int c64 = white();

    strcpy(simb, "D4-E2"); // Knight simb back-right
    trans(simb);
    int c65 = white();

    strcpy(simb, "D4-C2"); // Knight simb back-left
    trans(simb);
    int c66 = white();

    strcpy(simb, "D4-B5"); // Knight simb left-forward
    trans(simb);
    int c67 = white();

    strcpy(simb, "D4-B3"); // Knight simb left-back
    trans(simb);
    int c68 = white();

    strcpy(simb, "D4xE6"); // simb though figure 
    trans(simb);
    board[X1 + 1][Y1] = 'p';
    board[Y2][X2] = 'h';
    int c7 = white();

    board[Y1][X1] = ' ';
    board[X1 + 1][Y1] = ' ';
    board[Y2][X2] = ' ';

    const int exp1 = 0;
    const int exp2 = 0;
    const int exp3 = 0;
    const int exp4 = 0;
    const int exp5 = 0;
    const int exp61 = 1;
    const int exp62 = 1;
    const int exp63 = 1;
    const int exp64 = 1;
    const int exp65 = 1;
    const int exp66 = 1;
    const int exp67 = 1;
    const int exp68 = 1;
    const int exp7 = 1;

    ASSERT_EQUAL(exp1, c1);
    ASSERT_EQUAL(exp2, c2);
    ASSERT_EQUAL(exp3, c3);
    ASSERT_EQUAL(exp4, c4);
    ASSERT_EQUAL(exp5, c5);
    ASSERT_EQUAL(exp61, c61);
    ASSERT_EQUAL(exp62, c62);
    ASSERT_EQUAL(exp63, c63);
    ASSERT_EQUAL(exp64, c64);
    ASSERT_EQUAL(exp65, c65);
    ASSERT_EQUAL(exp66, c66);
    ASSERT_EQUAL(exp67, c67);
    ASSERT_EQUAL(exp68, c68);
    ASSERT_EQUAL(exp7, c7);
}

CTEST(moving, movebishop) // Test bishop
{
    strcpy(simb, "D4-D7"); // Forward
    trans(simb);
    board[Y1][X1] = 'B';
    int c1 = white();

    strcpy(simb, "D4-D2"); // Back
    trans(simb);
    int c2 = white();

    strcpy(simb, "D4-F4"); // Right
    trans(simb);
    int c3 = white();

    strcpy(simb, "D4-B4"); // Left
    trans(simb);
    int c4 = white();

    strcpy(simb, "D4-F6"); // D f-r
    trans(simb);
    int c51 = white();

    strcpy(simb, "D4-B6"); // D f-l
    trans(simb);
    int c52 = white();

    strcpy(simb, "D4-F2"); // D b-r
    trans(simb);
    int c53 = white();

    strcpy(simb, "D4xB2"); // D f-r catch
    trans(simb);
    board[Y2][X2] = 'p';
    int c54 = white();

    board[Y2][X2] = ' ';

    strcpy(simb, "D4-F6"); // D b-r through figure
    trans(simb);
    board[Y2 - 1][X2 - 1] = 'p';
    int c6 = white();

    board[Y1][X1] = ' ';
    board[Y2 - 1][X2 - 1] = ' ';

    const int exp1 = 0;
    const int exp2 = 0;
    const int exp3 = 0;
    const int exp4 = 0;
    const int exp51 = 1;
    const int exp52 = 1;
    const int exp53 = 1;
    const int exp54 = 1;
    const int exp6 = 0;

    ASSERT_EQUAL(exp1, c1);
    ASSERT_EQUAL(exp2, c2);
    ASSERT_EQUAL(exp3, c3);
    ASSERT_EQUAL(exp4, c4);
    ASSERT_EQUAL(exp51, c51);
    ASSERT_EQUAL(exp52, c52);
    ASSERT_EQUAL(exp53, c53);
    ASSERT_EQUAL(exp54, c54);
    ASSERT_EQUAL(exp6, c6);
}

CTEST(moving, moveking) // Test king
{
    strcpy(simb, "D4-D5"); // F
    trans(simb);
    board[Y1][X1] = 'K';
    int c1 = white();

    strcpy(simb, "D4-D3"); // B
    trans(simb);
    int c2 = white();

    strcpy(simb, "D4-C4"); // L
    trans(simb);
    int c3 = white();

    strcpy(simb, "D4-E4"); // R
    trans(simb);
    int c4 = white();

    strcpy(simb, "D4-E5"); // F-r
    trans(simb);
    int c5 = white();

    strcpy(simb, "D4-C5"); // F-l
    trans(simb);
    int c6 = white();

    strcpy(simb, "D4-E3"); // B-r
    trans(simb);
    int c7 = white();

    strcpy(simb, "D4xC3"); // B-l catch
    trans(simb);
    board[Y2][X2] = 'p';
    int c8 = white();

    board[Y2][X2] = ' ';

    strcpy(simb, "D4-D6"); // F 2
    trans(simb);
    int c9 = white();

    strcpy(simb, "D4-F2"); // B 2
    trans(simb);
    int c10 = white();

    board[Y1][X1] = ' ';

    const int exp1 = 1;
    const int exp2 = 1;
    const int exp3 = 1;
    const int exp4 = 1;
    const int exp5 = 1;
    const int exp6 = 1;
    const int exp7 = 1;
    const int exp8 = 1;
    const int exp9 = 0;
    const int exp10 = 0;

    ASSERT_EQUAL(exp1, c1);
    ASSERT_EQUAL(exp2, c2);
    ASSERT_EQUAL(exp3, c3);
    ASSERT_EQUAL(exp4, c4);
    ASSERT_EQUAL(exp5, c5);
    ASSERT_EQUAL(exp6, c6);
    ASSERT_EQUAL(exp7, c7);
    ASSERT_EQUAL(exp8, c8);
    ASSERT_EQUAL(exp9, c9);
    ASSERT_EQUAL(exp10, c10);
}

CTEST(moving, movequeen) // Test Q
{
    strcpy(simb, "D4-D7"); // F
    trans(simb);
    board[Y1][X1] = 'Q';
    int c1 = white();

    strcpy(simb, "D4-D1"); // B
    trans(simb);
    int c2 = white();

    strcpy(simb, "D4-A4"); // L
    trans(simb);
    int c3 = white();

    strcpy(simb, "D4-G4"); // R
    trans(simb);
    int c4 = white();

    strcpy(simb, "D4-G7"); // D f-r
    trans(simb);
    int c5 = white();

    strcpy(simb, "D4-A7"); // D f-l
    trans(simb);
    int c6 = white();

    strcpy(simb, "D4-A1"); // D b-l
    trans(simb);
    int c7 = white();

    strcpy(simb, "D4xG1"); // D f-r catch
    trans(simb);
    board[Y2][X2] = 'p';
    int c8 = white();

    board[Y2][X2] = ' ';

    strcpy(simb, "D4-G7"); // D f-r throuh figure
    trans(simb);
    board[Y2 - 1][X2 - 1] = 'p';
    int c9 = white();

    board[Y2 - 1][X2 - 1] = ' ';

    strcpy(simb, "D4-F7"); // Knight simb d f-r
    trans(simb);
    int c10 = white();

    board[Y1][X1] = ' ';

    const int exp1 = 1;
    const int exp2 = 1;
    const int exp3 = 1;
    const int exp4 = 1;
    const int exp5 = 1;
    const int exp6 = 1;
    const int exp7 = 1;
    const int exp8 = 1;
    const int exp9 = 0;
    const int exp10 = 0;

    ASSERT_EQUAL(exp1, c1);
    ASSERT_EQUAL(exp2, c2);
    ASSERT_EQUAL(exp3, c3);
    ASSERT_EQUAL(exp4, c4);
    ASSERT_EQUAL(exp5, c5);
    ASSERT_EQUAL(exp6, c6);
    ASSERT_EQUAL(exp7, c7);
    ASSERT_EQUAL(exp8, c8);
    ASSERT_EQUAL(exp9, c9);
    ASSERT_EQUAL(exp10, c10);
}
