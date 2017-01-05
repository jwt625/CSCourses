/*****************************************************************
GameState.h

This file contains GameState class and its function members
Realized in GameState.cpp
*****************************************************************/
#pragma once
/*****************************************************************
GameState.h

This file contains GameState class and its function members

Realized in GameState.cpp
*****************************************************************/

#ifndef GAMESTATE_H_
#define GAMESTATE_H_
#include"DataStruct.h"
typedef int BLOCK_POS;
#ifndef _BLOCK_POS
#define _BLOCK_POS
#define UP_LEFT 0
#define UP_MID 1
#define UP_RIGHT 2
#define MID_LEFT 3
#define MID_MID 4
#define MID_RIGHT 5
#define DOWN_LEFT 6
#define DOWN_MID 7
#define DOWN_RIGHT 8
#endif  //_BLOCK_POS

//class GameState describes the current puzzle and its function members
//WITH METHODS:
//iMAT & getCurrentState()
//iMAT getBlock(BLOCK_POS pos)
//iMAT getCol(int col), iMAT getRow(int row)
//bool isGoalState()
//bool isContradiction()
//bool isNumAcceptable(int num, int x, int y)
//bool isNumAcceptable(int num, Coord2D coord)
//bool isOprtAcceptable(OPERATION OP)
//numStack getNumSuccessorsOfPos(int x, int y)
//numStack getNumSuccessorsOfPos(Coord2D coord)
//numStack getNumSuccessorsOfPosOfLeastNumSuccessor()
//Coord2D getCoordOfLeastNumSuccessor()
//coordStack getCoordSuccessorsOfNumInBlock(int num, BLOCK_POS pos)
//coordStack getCoordSuccessorsOfNumInRow(int num, int row)
//coordStack getCoordSuccessorsOfNumInCol(int num, int col
//int numOfPosSuccessorOfNum(int num)
//int numOfItem(int item)
//OprtStack sweep()
//OprtStack sweep2()
//void doOPRT(OPERATION OP)
//void doOPRT(OprtStack OPs)
//void undoOPRT(OPERATION OP)
//void undoOPRT(OprtStack OPs)
//void operator=(GameState tempState)
//bool operator==(GameState tempState)
class GameState
{
private:
	iMAT currentState;
	//see DataStruct.h
public:
	GameState(){}
	//Initialize by an iMAT
	GameState(iMAT startState){currentState = startState;}
	//Initialize by copying
	GameState(GameState & tempGS){currentState = tempGS.currentState;}
	//returns an iMAT object
	iMAT & getCurrentState(){return currentState;}
	//returns the block by the given block order
	iMAT getBlock(BLOCK_POS pos);
	iMAT getCol(int col);
	iMAT getRow(int row);
	//returns whether the puzzle is completed
	bool isGoalState(){return !currentState.findItem(0);}
	//returns whether a contradiction occured in the current puzzle
	bool isContradiction();
	bool isNumAcceptable(int num, int x, int y);
	bool isNumAcceptable(int num, Coord2D coord);
	//for OPERATION see DataStruct.h
	bool isOprtAcceptable(OPERATION OP);
	//returns a numStack object containing the possible numbers of position (x, y)
	numStack getNumSuccessorsOfPos(int x, int y);
	//for Coord2D see DataStruct.h
	numStack getNumSuccessorsOfPos(Coord2D coord);
	//written for testing
	numStack getNumSuccessorsOfPosOfLeastNumSuccessor()
	{return GameState::getNumSuccessorsOfPos(GameState::getCoordOfLeastNumSuccessor());}
	//returns a coordStack object containing the possible positions in the chosen Block of number num
	coordStack getCoordSuccessorsOfNumInBlock(int num, BLOCK_POS pos);
	//returns a coordStack object containing the possible positions in the chosen Row of number num
	coordStack getCoordSuccessorsOfNumInRow(int num, int row);
	//returns a coordStack object containing the possible positions in the chosen Col of number num
	coordStack getCoordSuccessorsOfNumInCol(int num, int col);
	int numOfPosSuccessorOfNum(int num);
	//returns the number of item in currentState
	int numOfItem(int item);
	//function manipulating the current state according to basic rules as much as possible, returning operations done
	//for OprtStack see DataStruct.h
	OprtStack sweep();
	//function manipulating the current state according to basic row/col/block deductions as much as possible, returning operations done
	OprtStack sweep2();
	//do operation OP
	void doOPRT(OPERATION OP);
	//do operations OPs
	void doOPRT(OprtStack OPs);
	//undo operation OP
	void undoOPRT(OPERATION OP);
	//undo operations OPs
	void undoOPRT(OprtStack OPs);
	void operator=(GameState tempState){currentState = tempState.getCurrentState();}
	bool operator==(GameState tempState)
	{
		if(currentState == tempState.getCurrentState())
			return true;
		return false;
	}
	//returns the position with least possible numbers
	Coord2D getCoordOfLeastNumSuccessor();
};

typedef Stack<GameState> gameStateStack;
typedef Queue<GameState> gameStateQueue;
#endif // GAMESTATE_H_