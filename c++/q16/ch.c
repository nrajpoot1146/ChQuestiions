#include<stdio.h>
#include<string.h>

//my_pow function to calculate b to the power of e
int my_pow(int b, int e){
    int pow = 1;
    while(e>0){
        pow*=b;
        e--;
    }
    return pow;
}

//count_digits function to count the number of digits of any number
int count_digits(int n){
    int c_digits = 0;
    while(n>0){
        c_digits++;
        n /= 10;
    }
    return c_digits;
}

//sum_digits function to calculate the sum of digits of any number
int sum_digits(int n){
    int s_digits = 0;
    while(n>0){
        int digits = n % 10;
        s_digits += digits;
        n /= 10;
    }
    return s_digits;

}

//is_prime check given number is prime or not
int is_prime(int n){
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    int prime[n+1];
    for(int i=0; i<n+1;i++){
        prime[n]=1;
    }
    for (int p=2; p*p<=n; p++)
	{
		// If prime[p] is not changed, then it is a prime
		if (prime[p] == 1)
		{
			// Update all multiples of p greater than or
			// equal to the square of it
			// numbers which are multiple of p and are
			// less than p^2 are already been marked.
			for (int i=p*p; i<=n; i += p)
				prime[i] = 0;
		}
	}

    return prime[n];
}

//function to print fibonacci numbers
void fibonacci(int nterms){
    int i, n, t1 = 0, t2 = 1, nextTerm;
    printf("Fibonacci Numbers: ");
    for (i = 1; i <= nterms; ++i) {
        printf("%d, ", t1);
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }

    return 0;
}

int main(){
    int p = my_pow(2,3);
    if(p == 8){
        printf("my_power function test passed.\n\n");
    }else{
        printf("my_power function test failed.\n\n");
    }

    int c_digits = count_digits(7865);
    if(c_digits == 4){
        printf("count_digits function test passed.\n\n");
    }else{
        printf("count_digits function test failed.\n\n");
    }

    int s_digits = sum_digits(7865);
    if(s_digits == 26){
        printf("sum_digits function test passed.\n\n");
    }else{
        printf("sum digits function test failed.\n\n");
    }

    int ip = is_prime(13);
    if(ip == 1){
        printf("is_prime function test passed.\n\n");
    }else{
        printf("is_prime function test failed.\n\n");
    }

    fibonacci(10);
    printf("\n\n");
}
