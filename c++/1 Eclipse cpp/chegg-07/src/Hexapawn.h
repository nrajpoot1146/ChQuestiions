/*
 * Hexapawn.h
 *
 *  Created on: 26-Jun-2020
 *      Author:
 */

#ifndef SRC_HEXAPAWN_H_
#define SRC_HEXAPAWN_H_

#include <iostream>
using namespace std;

/**
 * structure to store coordinates of pawns on board
 * has two attribute
 * i => row;
 * j => col;
 */
struct pos{
	int i;
	int j;
};

class Hexapawn {
private:
	int board[3][3];
	bool turn;
public:
	Hexapawn();
	/**
	 * function to check entered coordinate have value between 0-3
	 * @return true if have otherwise return false
	 */
	bool isCorrectPos(pos p);

	/**
	 * function to move a pawn to new position
	 * @param curr current position of pawn
	 * @param new position of pawn
	 * @return true if pawn has successfully moved otherwise print error and return false
	 */
	bool move(pos curr, pos newPos);

	/**
	 * function to check legal move is available or not
	 * @return true if at least one legal move is available otherwise return false
	 */
	bool hasLegalMoves();

	/**
	 * function to check move is correct or not
	 * new position for current player is correct or not
	 * @param current position of pawn
	 * @param new position of pawn
	 *
	 * @return true if move is correct otherwise return false
	 */
	bool isCorrectMove(pos currentPos, pos newPose);

	/**
	 * function to initialize pawn with initial position
	 * initialize board array with initial values
	 *   0	=> black pawn
	 *   1	=> white pawn
	 *  -1	=> space
	 */
	void initialize();

	/**
	 * function to print board and pawn on board
	 * print row number
	 * print col number
	 */
	void printBoard();

	/**
	 * function to check current player is lose or not
	 * @return if current player is lose return true otherwise return false
	 */
	bool isLose();

	/**
	 * update turn
	 */
	void updateTurn();

	/**
	 * @return turn true if turn of white pawn player otherwise return false
	 */
	bool getTurn();

	/**
	 * set turn;
	 * @param turn true for white pawn player and false for black pawn player
	 */
	void setTurn(bool turn);
	virtual ~Hexapawn();
};

#endif /* SRC_HEXAPAWN_H_ */
