#include "main.h"

int subtract(int row, int col, int a[10][10], int b[10][10], int c[10][10]){
	int i,j;
	for (i=0; i<row; i++){
		for (j=0; j<col; j++){
			c[0][col * i + j] = a[0][col * i + j] - b[0][col * i + j];
		}
	}
}

