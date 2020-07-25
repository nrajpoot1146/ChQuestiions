#include <stdio.h>
#include <ctype.h>

/**
* find index of any character in tcharacter string
* return index if character is found otherwise return -1
*/
int indexOf(char str[], char c){
	int i=0;
	while(str[i] != '\n'){
		if (str[i] == c){
			return i;
		}
		i++;
	}
	return -1;
}

/*
* decrypt given encrypted msg
*/
void decrypt(char map[], char msg[], char dec[]){
	int i=0;

	while(msg[i] != '\0'){
		if(isspace(msg[i])){ // if character is space
			dec[i] = ' ';
		}else if (isupper(msg[i])){ // if character is upper case
			char lc = tolower(msg[i]);
			int ind = indexOf(map, lc);
			dec[i] = 'A' + ind;
		}else{ // if character is lower case character
			int ind = indexOf(map, msg[i]);
			char c = 'a' + ind;
			dec[i] = c;
		}
		i++;
	}
	dec[i] = '\0';
}

// mainn function
int main(){
	char map[27]; // charater array to store mapping
	char msg[200]; // character array to store encrypted message
	char dec[200];
	int i=0;
	gets(map); // read mapping string
	gets(msg); // read encrypted message
	
	decrypt(map, msg, dec);
	printf("%s", dec); // print decrypted message
}
