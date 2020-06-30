#include <iostream>

using namespace std;

struct pos{
	int i;
	int j;
};

void printBoard(int board[3][3]){
	for (int i=0; i<3; i++){
		cout<<i+1<<" ";
		for (int j=0; j<3; j++){
			if (board[i][j] == 1){
				cout<<"W"<<" ";
			}else if(board[i][j] == 0){
				cout<<"B"<<" ";
			}else{
				cout<<"  ";
			}
		}
		cout<<endl;
	}
	cout<<"  ";
	for (int i=0; i<3; i++){
		cout<<i+1<<" ";
	}
}

void initialize(int *board){
	for (int i=0; i<3; i++){
		for (int j=0; j<3; j++){
			if (i == 0){
				*((board+i*3) + j) = 0;
			}else if(i == 1){
				*((board+i*3) + j) = -1;
			}else{
				*((board+i*3) + j) = 1;
			}
		}
	}
}

bool isCorrectMove(int board[][3], bool turn, pos currentPos, pos newPose){
	
	if(turn && board[currentPos.i][currentPos.j] != 1){
		return false;
	}else if(!turn && board[currentPos.i][currentPos.j] != 0){
		return false;
	}
	
	if(currentPos.i == newPose.i){
		return false;
	}else if(turn && newPose.i > newPose.i){
		return false;
	}else if(!turn && newPose.i < newPose.i){
		return false;
	}
	
	if (currentPos.j == newPose.j){
		if(board[newPose.i][newPose.j] == -1){
			return true;
		}
	}else{
		if (turn){
			if(board[newPose.i][newPose.j] == 0){
				return true;
			}
		}else{
			if(board[newPose.i][newPose.j] == 1){
				return true;
			}
		}
	}
	
	return false;
}

bool hasLegalMoves(int board [][3],bool turn){
	for (int i=0; i<3; i++){
		for (int j=0; j<3; j++){
			if (turn){
				if (board[i][j] == 1){
					if (board[i-1][j] == -1){
						return true;
					}
					if (j == 0){
						if (board[i-1][j+1] == 0){
							return true;
						}
					}else if(j == 2){
						if (board[i-1][j-1] == 0){
							return true;
						}
					}else{
						if (board[i-1][j+1] == 0 || board[i-1][j-1] == 0){
							return true;
						}
					}
				}
			}else{
				if (board[i][j] == 0){
					if (board[i+1][j] == -1){
						return true;
					}
					if (j == 0){
						if (board[i+1][j+1] == 1){
							return true;
						}
					}else if(j == 2){
						if (board[i-1][j-1] == 1){
							return true;
						}
					}else{
						if (board[i+1][j+1] == 1 || board[i+1][j-1] == 1){
							return true;
						}
					}
				}
			}
		}
	}
	
	return false;
}

int move(int board[][3], bool turn, pos curr, pos newPos){
	if(isCorrectMove(board, turn, curr, newPos)){
		board[newPos.i][newPos.j] = board[curr.i][curr.j];
		board[curr.i][curr.j] = -1;
		return true;
	}else{
		cout<<"Incorrect Position"<<endl;
		return false;
	}
	return 1;
}

bool isLose(int board[][3], bool turn){
	if (turn){
		if (board[2][0] == 0 || board[2][1] == 0 || board[2][2] == 0){
			return true;
		}else{
			if(!hasLegalMoves(board, turn)){
				return true;
			}
		}
	}else{
		if (board[0][0] == 1 || board[0][1] == 1 || board[0][2] == 1){
			return true;
		}else{
			if(!hasLegalMoves(board, turn)){
				return true;
			}
		}
	}
	
	return false;
}

bool isCorrectPos(pos p){
	if(p.i>=0 && p.j>=0 && p.i<3 && p.j<3){
		return true;
	}
	return false;
}

int main(){
	int board[3][3];
	initialize((int *)board);
	printBoard(board);
	
	bool turn = true;
	
	while (true){
		cout<<endl;
		
		if (isLose(board, turn)){
			cout<<"player with black pawns win: "<<endl;
			break;
		}
		
		if (turn == true)
			cout<<"Player with white pawn turn: "<<endl;
		else{
			cout<<"Player with black pawn turn: "<<endl;
		}
		
		cout<<"Please enter postion of pawn which you want to move: (x y): ";
		pos curr, newPos;
		cin>>curr.i>>curr.j;
		curr.i -= 1;
		curr.j -= 1;
		if(isCorrectPos(curr)){
			cout<<"Enter new position for selected pawn: (x y): ";
			cin>>newPos.i>>newPos.j;
			newPos.i -= 1;
			newPos.j -= 1;
			if(isCorrectPos(newPos)){
				if(move(board, turn, curr, newPos)){
					turn = !turn;
				}
				cout<<endl;
				printBoard(board);
			}
		}else{
			cout<<"invalid position"<<endl;
		}
	}
}
