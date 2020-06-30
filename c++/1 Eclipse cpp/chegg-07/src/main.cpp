/*
 * main.cpp
 *
 *  Created on: 26-Jun-2020
 *      Author: naren
 */

#include <iostream>
#include "Hexapawn.h"

using namespace std;

int main(){

	Hexapawn *hexapawn = new Hexapawn();
	hexapawn->initialize();

	cout<<"Choose first chance: ";
	cout<<"\n 1. for white pawn player: ";
	cout<<"\n 2. for black pawn player: "<<endl;
	int op;
	cin>>op;

	if (op == 1){
		hexapawn->setTurn(true);
	}else{
		hexapawn->setTurn(false);
	}

	hexapawn->printBoard();

	while (true){
		cout<<endl;

		if (hexapawn->getTurn() && hexapawn->isLose()){
			cout<<"player with black pawns win: "<<endl;
			break;
		}

		if(!hexapawn->getTurn() && hexapawn->isLose()){
			cout<<"player with white pawns win: "<<endl;
			break;
		}

		if (hexapawn->getTurn())
			cout<<"Player with white pawn turn: "<<endl;
		else{
			cout<<"Player with black pawn turn: "<<endl;
		}

		cout<<"Please enter position of pawn which you want to move: (x y): ";
		pos curr, newPos;
		cin>>curr.i>>curr.j;
		curr.i -= 1;
		curr.j -= 1;
		if(hexapawn->isCorrectPos(curr)){
			cout<<"Enter new position for selected pawn: (x y): ";
			cin>>newPos.i>>newPos.j;
			newPos.i -= 1;
			newPos.j -= 1;
			if(hexapawn->isCorrectPos(newPos)){
				if(hexapawn->move(curr, newPos)){
					hexapawn->updateTurn();
				}
				cout<<endl;
				hexapawn->printBoard();
			}
		}else{
			cout<<"invalid position"<<endl;
		}
	}
}


