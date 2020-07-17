
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

/**
* print tic tac toe board
* @param dt array
*/
void displayBoard(char dt[][3]){
	cout<<"  __1___2___3_"<<endl<<endl;
	cout<<"1|  "<<dt[0][0]<<" | "<<dt[0][1]<<" | "<<dt[0][2]<<" "<<endl;
	cout<<" | ___|___|___"<<endl;
	cout<<"2|  "<<dt[1][0]<<" | "<<dt[1][1]<<" | "<<dt[1][2]<<" "<<endl;
	cout<<" | ___|___|___"<<endl;
	cout<<"3|  "<<dt[2][0]<<" | "<<dt[2][1]<<" | "<<dt[2][2]<<" "<<endl;
	cout<<" |    |   |   "<<endl;
}

/**
* check if any player is win or not
* if any player (computer or user) win then return true otherwise return false
*/
bool isWin(char dt[][3]){
	for (int i = 0; i<3; i++){
		// condition of row
		if ((dt[i][0] == 'o' && dt[i][1] == 'o' && dt[i][2] == 'o')
			|| (dt[i][0] == 'x' && dt[i][1] == 'x' && dt[i][2] == 'x')){
			return true;
		}
		
		// condition for colomn
		if ((dt[0][i] == 'o' && dt[1][i] == 'o' && dt[2][i] == 'o')
			|| (dt[0][i] == 'x' && dt[1][i] == 'x' && dt[2][i] == 'x')){
			return true;
		}
	}
	
	// condition for first diagnol
	if ((dt[0][0] == 'o' && dt[1][1] == 'o' && dt[2][2] == 'o')
		|| (dt[0][0] == 'x' && dt[1][1] == 'x' && dt[2][2] == 'x')){
		return true;
	}
	
	// condition for second diagnol
	if ((dt[0][2] == 'o' && dt[1][1] == 'o' && dt[2][0] == 'o')
		|| (dt[0][2] == 'x' && dt[1][1] == 'x' && dt[2][0] == 'x')){
		return true;
	}
	return false;
}

/**
* check board has at least one empty cell
* @return true if at least one empty cell is available 
*/
bool isEmpty(char dt[][3]){
	for (int i = 0; i<3; i++){
		for (int j=0; j<3; j++){
			if (dt[i][j] == ' '){
				return true;
			}
		}
	}
	
	return false;
}

/*
* switch turn between computer and user
*/
bool switchTurn(bool turn){
	return !turn;
}

/*
* perform user move
* read x y value from user
*/
bool userMove(char dt[][3]){
	if (isEmpty(dt)){
		cout<<"Your turn: \n";
		cout<<"Enter pos (row col): ";
		int x, y;
		cin>>x>>y;
		while (dt[x-1][y-1] != ' '){
			cout<<"Wrong position!"<<endl;
			cout<<"Enter pos (row col): ";
			cin>>x>>y;
		}
		
		dt[x-1][y-1] = 'o';
		return true;
	} else{
		return false;
	}
}

/**
* perform computer move
* generate x and y randomly
*/
bool compMove(char dt[][3]){
	if (isEmpty(dt)){
		cout<<"Computer Turn: \n";
		srand(time(0));
		int pos = (rand() % 9) +1;
		int x = pos / 3;
		int y = pos % 3;
		
		while (dt[x][y] != ' '){
			pos = (rand() % 9) +1;
			x = pos / 3;
			y = pos % 3;
		}
		
		dt[x][y] = 'x';
		return true;
	} else{
		return false;
	}
}

// main driver function
int main(){
	// initialize initial cell value
	char dt[][3] = {' ', ' ', ' ',
					' ', ' ', ' ',
					' ', ' ', ' '};
					
	cout<<"-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+- Welcome to tic tac toe game -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-"<<endl;
	cout<<"-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+- Game Started -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-"<<endl<<endl;
	bool turn = true; // initialize user turn
	displayBoard(dt); // show initial game board
				
	while (true){
		cout<<endl<<endl;
		if (turn){
			if (!userMove(dt)){ // make user move
				cout<<"Game Over!\n";
				break;
			}
			displayBoard(dt);
			if (isWin(dt)){ // check is user win
				cout<<"You win!\n";
				break;
			}
			turn = switchTurn(turn);
		}else {
			if (!compMove(dt)){ // make computer move
				cout<<"Game Over!\n";
				break;
			}
			displayBoard(dt);
			if (isWin(dt)){ // check is computer win
				cout<<"Computer win!\n";
				break;
			}
			turn = switchTurn(turn);
		}
		
	}
	cout<<"Press any key to exit: ";
	getch();
					 
}
