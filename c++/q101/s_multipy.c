#include "main.h"

int s_multiply(int row, int col, int **a, int **c, int scalar){
	int i,j;
	for (i=0; i<row; i++){
		for (j=0; j<col; j++){
			c[i][j] = a[i][j] * scalar;
		}
	}
}

