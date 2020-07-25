#include <stdio.h>
#include <ctype.h>

/**
* fucntion to encrypt an message
* use substitution method
*/
void encrypt(char map[], char msg[], char enc[]){
	int i=0;

	while(msg[i] != '\0'){
		if(isspace(msg[i])){ // if character is space
			enc[i] = ' ';
		}else if (isupper(msg[i])){ // if character has upper case
			int num = msg[i] - 'A';
			char c = map[num];
			enc[i] = toupper(c);
		}else{ // if character has lower case
			int num = msg[i] - 'a';
			char c = map[num];
			enc[i] = c;
		}
		i++;
	}
	enc[i] = '\0';
}

int main(){
	char map[27]; // character array to store mapping string
	char msg[200]; // character array to store plain text
	char enc[200]; // character array to store encrypted text
	int i=0;
	gets(map); // read mapping string
	gets(msg); // read plain text
	
	encrypt(map, msg, enc);
	printf("%s", enc); // print encrypted message
}
