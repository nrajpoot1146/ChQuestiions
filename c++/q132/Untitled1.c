#include <stdio.h>

// function to calculate value of sin(x)
// where x is in deg
double sin(int deg) {
    double x = (22.0 * deg)/(7.0 * 180.0);

    double temp=x;
    double sum=x;

    for(int i = 1; i <= 10; i++) {
        temp = (temp * ( -1 ) * x * x ) / ( 2 * i * ( 2 * i + 1 ) );
        sum=sum + temp;
    }
    return sum;
}

void main() {
    double res, x;
    printf("Enter the value of x in deg: ");
    scanf("%lf", &x); // read value of x in deg
    res = sin(x);
    printf("res = %10.5lf%", sin(x)); // print result
}
