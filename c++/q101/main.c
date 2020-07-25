#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "sum.c"
#include "subtract.c"
#include "s_multipy.c"
#include "print.c"

int main(int argc, char *argv[]){
	/* check arguments */
	assert(argc == 3);
	int r = atoi(argv[1]);
	int c = atoi(argv[2]);
	printf("row = %d and column = %d\n", r, c);
	
	int i, j;
	/* **************************************METHOD 1 */
	/* single pointer method array 1 */
	int *a = malloc(sizeof(int) * r * c);
	for (i = 0; i<r; i++)
		for (j = 0; j < c; j++)
			*(a + (c * i) + j) = (i * c) +j;
	
	printf("Array a is :\n");
	print_array(r, c, a);
	
	/* single pointer method array 2 */
	int *b = malloc(sizeof(int) * r * c);
	for (i=0; i<r; i++)
		for (j=0; j<c; j++)
			*(b + (c * i) + j) = (i * c) + j;
	
	printf("Array b is :\n");
	print_array(r, c, b);
	
	/* single pointer method result array */
	int *res = malloc (sizeof(int) * r * c);
	printf("Sum is :\n");
	sum(r, c, a, b, res);
	print_array(r, c, res);
	
	printf("Difference is :\n");
	subtract(r, c, a, b, res);
	print_array(r, c, res);
	
	/* ***********************************METHOD 3 */
	
	/* double pointer method array 1 */
	int **f = malloc(sizeof(int*) * r);
	for (i=0; i<r; i++)
		f[i] = malloc(sizeof(int) * c);
	
	/* assign values to f */
	for (i=0; i<r; i++)
		for(j=0; j<c; j++)
			f[i][j] = (i * r) + j;
	
	/* create a matrix to store the result */
	int **g = malloc(sizeof(int *) *r);
	for (i=0; i<r; i++)
		g[i] = malloc(sizeof(int) * c);
	
	printf("Scalar product is: \n");
	s_multiply(r, c, f, g, 100);
	
	/* print array won't work here ..why ? */
	// because print_array accept single pointer parameter
	// and g is double pointer variable
	for (i=0; i<r; i++){
		for (j=0; j<c; j++)
			printf("%3d\t\t", g[i][j]);
		printf("\n");
	}
	
	return 0;
}
