#include <stdio.h>

// structure to store piece color and symbol
struct piece{
	char color;
	char symbol;
};

typedef struct piece Piece;

//Return 1 if p1 and p2 have the same colour and symbol
//Return 0 otherwise
int areEqual(Piece p1, Piece p2);

// Prints out a piece in the following format
// colour/symbol eg. R/*
void printPiece(Piece p);

// Reads in a piece from stdin an checks it if valid
// if a valid piece was read in, it returns 1;
// Returns 0 otherwise
int readPiece(Piece *p);

// check color is valid or not
// return 1 if color is valid
// return 0 otherwise
int isValidColor(char c);

// check symbol is valid or not
// return 1 if symbol is valid
// return 0 otherwise
int isValidSymbol(char s);

void main(){
	Piece p1, p2;
	printf("Enter 2 pieces: ");
	int b1 = readPiece(&p1);
	int b2 = readPiece(&p2);
	if (b1 == 0 || b2 == 0){
		printf("Invalid Input\n");
	} else {
		int isEqual = areEqual(p1, p2);
		if(isEqual){
			printPiece(p1);
			printf(" equals ");
			printPiece(p2);
		} else {
			printPiece(p1);
			printf(" does not equal ");
			printPiece(p2);
		}
	}
}

int areEqual(Piece p1, Piece p2){
	if (p1.color == p2.color && p1.symbol == p2.symbol){
		return 1;
	}
	return 0;
}

void printPiece(Piece p){
	printf("%c/%c",p.color,p.symbol);
}

int readPiece(Piece *p){
	char cs[2];
	scanf("%s",cs); // read color and symbol value and store in array
	
	int isValidC = isValidColor(cs[0]); // check color is valid or not
	int isValidS = isValidSymbol(cs[1]);// check symbol is valid or not
	
	if (isValidC && isValidS){
		p->color = cs[0];
		p->symbol = cs[1];
		return 1;
	}
	return 0;
}

int isValidColor(char c){
	if (c == 'R' || c == 'B' || c == 'Y' || c == 'G')
		return 1;
	return 0;
}

int isValidSymbol(char s){
	if (s == '*' || s == '^' || s == '#' || s == '$')
		return 1;
	return 0;
}

