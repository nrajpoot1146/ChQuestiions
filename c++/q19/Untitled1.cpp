#include<stdio.h>
#include<string.h>

int htoi(char *s){
	int len = strlen(s);
	int i=0;
	int dec_value = 0;
	int base = 1;
	while(i < len){
		char c = s[i];
		
		//condition to avoid ox or oX
		if( (i == 0 || i == 1) && (c == 'o' || c == 'x' || c == 'X')){
			i++;
			continue;
		}
		
		int num = 0;
		
		//condion to get an integer value with respect to character value
		//map '0' with 0 and  '9' with 9
		//map 'A' and 'a' with 10 and 'F' and 'f' with 15
		if(c >= '0' && c <= '9'){
			num = c - '0';
		}else if(c >= 'A' && c<='F'){
			num = 10 + c-'A';
		}else if(c>= 'a' && c <= 'f'){
			num = 10 + c - 'a';
		}else{
			printf("given number is not a hexadecimal number.");
		}
	
		dec_value += num * base;
		base = base * 16;
		i++;
	}
	
	return dec_value;
}

int main(){
	char str[20];
	int dec_value;
	printf("Enter a hexadecimal number: ");
	scanf("%s",str);
	dec_value = htoi(str);
	printf("Integer value: %d",dec_value);
}
