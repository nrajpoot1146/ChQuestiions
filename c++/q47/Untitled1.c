#include<stdlib.h>
#include<stdio.h>

struct Int{
	int data;
};

/**
* free memory, assign to an arrays of pointers
*/
struct Int * freeMemoryOfArrayofPointers(struct Int **p){
	for (int i=0; i<5; i++){
		free(p[i]);
	}
	*p = NULL;
	return *p;
}

// free memory, assign to pointers to arrays
struct Int* freeMemoryOfPointerstoArray(struct Int *p){
	free(p);
	return NULL;
}

int main(){
	struct Int *p1[5];

	struct Int *p2;

	// assign memory one by one;
	// generate arrays of pointers
	for (int i=0; i<5; i++){
		p1[i] = (struct Int*) malloc(sizeof(struct Int));
		p1[i]->data = i;
	}

	// assign memory for arrays and store address in ponter p2
	p2 = (struct Int*) malloc(5 * sizeof(struct Int));

	// assign data value to pointer to array
	for (int i=0; i<5; i++){
		p2[i].data = i;
	}

	*p1 = freeMemoryOfArrayofPointers(p1);
	p2 = freeMemoryOfPointerstoArray(p2);

	printf ("All data memory seccessfully released");
}
