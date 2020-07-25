#include "main.h"

int sum(int row, int col, int *a, int *b, int *c){
	int i,j;
	for (i=0; i<row; i++){
		for (j=0; j<col; j++){
			*(c + (i * col) + j) = *(a + (i * col) + j) + *(b + (i * col) + j);
		}
	}
}

