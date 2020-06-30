/*
 * Hexapawn.cpp
 *
 *  Created on: 26-Jun-2020
 *      Author: naren
 */

#include "Hexapawn.h"

Hexapawn::Hexapawn() {
	this->initialize();
}


bool Hexapawn::isCorrectPos(pos p){
	if(p.i>=0 && p.j>=0 && p.i<3 && p.j<3){
		return true;
	}
	return false;
}

bool Hexapawn::move(pos curr, pos newPos){
	if(isCorrectMove(curr, newPos)){
		board[newPos.i][newPos.j] = board[curr.i][curr.j];
		board[curr.i][curr.j] = -1;
		return true;
	}else{
		cout<<"Incorrect Position"<<endl;
		return false;
	}
}

bool Hexapawn::hasLegalMoves(){
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

bool Hexapawn::isCorrectMove(pos currentPos, pos newPose){

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

void Hexapawn::initialize(){
	for (int i=0; i<3; i++){
		for (int j=0; j<3; j++){
			if (i == 0){
				board[i][j] = 0;
			}else if(i == 1){
				board[i][j] = -1;
			}else{
				board[i][j] = 1;
			}
		}
	}
}

void Hexapawn::printBoard(){
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
	cout<<endl;
}

bool Hexapawn::isLose(){
	if (turn){
		if (board[2][0] == 0 || board[2][1] == 0 || board[2][2] == 0){
			return true;
		}else{
			if(!this->hasLegalMoves()){
				return true;
			}
		}
	}else{
		if (board[0][0] == 1 || board[0][1] == 1 || board[0][2] == 1){
			return true;
		}else{
			if(!this->hasLegalMoves()){
				return true;
			}
		}
	}

	return false;
}

void Hexapawn::updateTurn(){
	this->turn = !this->turn;
}

void Hexapawn::setTurn(bool turn){
	this->turn = turn;
}

bool Hexapawn::getTurn(){
	return this->turn;
}

Hexapawn::~Hexapawn() {
}

