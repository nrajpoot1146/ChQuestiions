
#include <stdio.h>

int main(){
	int temperature[12];
	int i;
	
	// loop read temperature from user
	for (i=0; i<12; i++){
		printf("Enter the average temperature in month %d and press ENTER ", i);
		scanf("%d", &temperature[i]);
	}
	
	// loop print temprature
	printf("The temperatures over the past 12 months are:\n");
	for (i=0; i<12; i++){
		printf(" %d",temperature[i]);
	}
}
