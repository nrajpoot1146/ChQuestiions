#include <stdio.h>

/*
* find nearest index of given key in given array
* @param ptr_array, array of float numbers
* @param size, size of array
* @param key to be search
* @param tolerance
*/
int search_nearest(float *ptr_array, int size, float key, float tolerance){
	int i=0; // declare and initialize variable i
	
	// search for exact match
	for (i=0; i<size; i++){
		if(ptr_array[i] == key){ // if exact match is present
			return i; // return current index
		}
	}
	
	// if exact match is not present
	// then search with given tolerance
	
	// search for key with given tolerance
	int searchIndex = -1;
	float dis = 0.0;
	for(i=0; i<size; i++){
		// calculate absolute difference
		float diff = (ptr_array[i] - key) < 0? -1 * (ptr_array[i] - key) : (ptr_array[i] - key);
		if (diff < tolerance){
			// if key is present with given tolerance
			// return current index
			if (searchIndex == -1){
				searchIndex = i;
				dis = diff;
			}else if ( diff < dis){
				searchIndex = i;
				dis = diff;
			}
		}
	}
	
	return searchIndex;
}

int main(){
	
	// declare and initialize array of float numbers
	float nums[] = {1.5, -6.7, 7.8, 3.25, 5.0, 6.8};
	
	// find index of key
	int index = search_nearest(nums, 6, 3.2, .1);
	
	// print index of key;
	printf("index = %d",index);
}
