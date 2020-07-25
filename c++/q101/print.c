#include "main.h"

void print_array(int r, int c, int *res){
	int i,j;
	for (i=0; i<r; i++){
		for (j=0; j<c; j++){
			printf("%3d\t\t", *(res + (c * i) + j));
		}
		printf("\n");
	}
}
