#include <stdio.h>
#ifndef BOARD_H
#define BOARD_H
int trans(char simb[11]);
void move();
void simb_scan();
int white();
int black();
int checkY();
int checkX();
int checkD();
int check(int stat);
#endif
