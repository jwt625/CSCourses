/*****************************************************************
methods.h

This file contains methods useful in solving sudoku.
Including depth first search and breadth first search algorithms.
Realized in methods.cpp
*****************************************************************/
#pragma once
/*****************************************************************
methods.h

This file contains methods useful in solving sudoku.
Including depth first search and breadth first search algorithms.

Realized in methods.cpp
*****************************************************************/

#ifndef METHODS_H_
#define METHODS_H_
#include"GameState.h"
#include"graph.h"
//This is useless, written for testing.
class doSweep
{
private:
	GameState gamestate;
	OprtStack Operations;
	GameState finalState;
public:
	doSweep(iMAT startState)
	{
		gamestate.getCurrentState() = startState;
		GameState tempState(gamestate);
		Operations = tempState.sweep();
		finalState = tempState;
	}
	doSweep(GameState tempGS)
	{
		gamestate = tempGS;
		GameState tempState(gamestate);
		Operations = tempState.sweep();
		finalState = tempState;
	}
	doSweep(doSweep & solve)
	{
		gamestate = solve.getGamestate();
		GameState tempState(gamestate);
		Operations = tempState.sweep();
		finalState = tempState;
	}
	GameState getGamestate(){return gamestate;}
	GameState getFinalState(){return finalState;}
	OprtStack getOperations(){return Operations;}
};

//This is useless, written for testing.
class doSweep2
{
private:
	GameState gamestate;
	OprtStack Operations;
	GameState finalState;
public:
	doSweep2(iMAT startState)
	{
		gamestate.getCurrentState() = startState;
		GameState tempState(gamestate);
		Operations = tempState.sweep2();
		finalState = tempState;
	}
	doSweep2(GameState tempGS)
	{
		gamestate = tempGS;
		GameState tempState(gamestate);
		Operations = tempState.sweep2();
		finalState = tempState;
	}
	doSweep2(doSweep2 & solve)
	{
		gamestate = solve.getGamestate();
		GameState tempState(gamestate);
		Operations = tempState.sweep2();
		finalState = tempState;
	}
	GameState getGamestate(){return gamestate;}
	GameState getFinalState(){return finalState;}
	OprtStack getOperations(){return Operations;}
};

//ordinary depth first search, returning the changed GameState
GameState depthFirstSearch(GameState startingGS);
//depth first search aided by function "sweep" --see GameState.h
GameState depthFirstSearchWithSweep(GameState startingGS);
//depth first search aided by function "sweep2" --see GameState.h
GameState depthFirstSearchWithSweep2(GameState startingGS, int maxStates = 500);
//breadth first search aided by function "sweep2", in order to find all possible solutions, 
//returns the amount of the possible solutions
int breadthFirstSearchWithSweep2(GameState startingGS);

int depthFirstSearchForJudge(GameState startingGS, int num = 10);
//breadth first search for path search in graph
OprtStack breadthFirstSearchForPath(sudokuLoopSearchProblem problem);
//not running correctly
OprtStack breadthFirstSearchForPath(sudokuPathSearchProblem problem);

OprtStack breadthFirstSearchForPath(sudokuPathSearchProblemV2 problem);

//template<class PROBLEM>
//class SEARCH
//{
//private:
//	PROBLEM problem;
//public:
//	SEARCH(PROBLEM tempP):problem(tempP){}
//	bool Search();
//};
//
//template<class PROBLEM>
//bool SEARCH<PROBLEM>::Search()
//{
//	if(problem.isSolveable())
//	{
//		problem.exploredState.push(problem.startingState());
//		while(1)
//		{
//			if(problem.exploredState.getLen() == 1)
//				return false;
//			problem.currentState = problem.exploredState.pop();
//			if(problem.isGoalState())
//			{
//				problem.goalArrived();
//				break;
//			}
//			int numOfSuccessors = problem.getSuccessors().getLen();
//			for(int i = 1; i < numOfSuccessors; i++)
//				problem.exploredState.push(problem.getSuccessors()[i]);
//		}
//	}
//}

#endif //METHODS_H_