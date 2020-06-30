#include<stdio.h>
#include<math.h>


// function for law of sin when two sides and one angle is given
double twoSidesOneAngle(){
	int a, b, A;
	double x;
	printf("Enter side a: ");
	scanf("%d", &a);
	printf("Enter side b: ");
	scanf("%d", &b);
	printf("Enter angle A: ");
	scanf("%d", &A);
	
	x = sin(A) / a ;
	x = asin(x * b);
	if(x<0){
		x*=-1;
	}
	return x;
}

// function for law of sin when two angle and one side is given
double twoAngleOneSide(){
	int a, A, B;
	double b;
	printf("Enter side a: ");
	scanf("%d", &a);
	printf("Enter angle A: ");
	scanf("%d", &A);
	printf("Enter angle B: ");
	scanf("%d", &B);
	
	b = (sin(A) / a) * b;
	if(b<0){
		b*=-1;
	}
	return b;
}

int main(){
	int o;
	
	lab:
		printf("\nchoose one\n");
		printf("1. two sides one angle\n");
		printf("2. two angle one side\n");
		printf("3. for exist\n");
		scanf("%d", &o);
		if( o == 1){
			double res = twoSidesOneAngle();
			printf("Angle in radian %f", res);
		}else if( o == 2){
			double res = twoAngleOneSide();
			printf("Side %f", res);
		}else if( o == 3){
			goto ext;
		}
	goto lab;
	ext:
	printf("exit");			
}
