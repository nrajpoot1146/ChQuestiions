#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<cmath>

// function for law of sin when two sides and one angle is given
double twoSidesOneAngle(){
   float a, b, A;
   double x;
   printf("Enter side a: ");
   scanf("%f", &a);
   printf("Enter side b: ");
   scanf("%f", &b);
   printf("Enter angle A: ");
   scanf("%f", &A);

	A = A * (3.14 / 180);
   x = (sin(A) / a) * b;
   x = asin(x);
   
   x = x * (180 * 3.14);
   
   return x;
}

// function for law of sin when two angle and one side is given
float twoAngleOneSide(){
   float a, A, B;
   float b;
   printf("Enter side a: ");
   scanf("%f", &a);
   printf("Enter angle A: ");
   scanf("%f", &A);
   printf("Enter angle B: ");
   scanf("%f", &B);
  
   A = A * (3.14 / 180);
   B = B * (3.14 / 180);
   
   A = sin(A);
   B = sin(B);
   
   float deg = A / a;
   b = B/deg;
   
   return b;
}

int main(){
   int o;
   int n,i=0;
   printf("Enter size of array: ");
   scanf("%d",&n);
   // array of size n to store result
   float *arr = (float*) malloc(n * sizeof(float));
   lab:
       printf("\nchoose one\n");
       printf("1. two sides one angle\n");
       printf("2. two angle one side\n");
       
       scanf("%d", &o);
       if( o == 1){
           float res = twoSidesOneAngle();
           arr[i] = res; // stored result in array
       }else if( o == 2){
           float res = twoAngleOneSide();
           arr[i] = res; // stored result in array
       }
       i++;
       if(i == n){
       	 goto ext;
	   }
   goto lab;
   ext:
	for(i=0; i<n; i++){
		printf("%f, \n", floor(arr[i])); // print floor value of array element
	}
   printf("exit");          
}
