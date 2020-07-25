#include <stdio.h>
/* Don't change the prototypes! */

#ifndef _MAIN_H
#define _MAIN_H

int sum(int row, int col, int *a, int *b, int *c);
int subtract(int row, int col, int a[10][10], int b[10][10], int c[10][10]);
int s_multiply(int row, int col, int **a, int **c, int scalar);
void print_array(int r, int c, int *res);

#endif

