#include "StdAfx.h"
#include"methods.h"

GameState depthFirstSearch(GameState startingGS)
{	
	GameState currentState = startingGS;
	int numOfExploredStates = 0;
	int wrongTime = 0;
	gameStateStack exploredState;
	exploredState.push(currentState);
	GameState tempState;
	numStack tempNumSuccessors;
	Coord2D tempCO;
	while(1)
	{
		if(exploredState.getLen() == 1)
		{
			cout<<"No Solution!\n";
			break;
		}
		//currentState.getCurrentState().freeMat();
		currentState = exploredState.pop();
		if(currentState.isGoalState())
			break;
		tempCO = currentState.getCoordOfLeastNumSuccessor();
		tempNumSuccessors = currentState.getNumSuccessorsOfPos(tempCO);
		for(int i = 1; i < tempNumSuccessors.getLen(); i++)
		{
			tempState = currentState;
			OPERATION tempOP(tempCO, tempNumSuccessors[i]);
			tempState.doOPRT(tempOP);
			if(!tempState.isContradiction())	
			{
				numOfExploredStates++;
				exploredState.push(tempState);
			}
			else
				wrongTime++;
		}
	}
	cout<<" by DFS:\n";
	currentState.getCurrentState().print();
	cout<<"\n num of states explored:  "<<numOfExploredStates
		<<"\twrong time:  "<<wrongTime<<endl<<endl;
	return currentState;
}
GameState depthFirstSearchWithSweep(GameState startingGS)
{	
	GameState currentState = startingGS;
	currentState.sweep();
	int numOfExploredStates = 0;
	int wrongTime = 0;
	gameStateStack exploredState;
	exploredState.push(currentState);
	GameState tempState;
	numStack tempNumSuccessors;
	Coord2D tempCO;
	while(1)
	{
		if(exploredState.getLen() == 1)
		{
			cout<<"No Solution!\n";
			break;
		}
		//currentState.getCurrentState().freeMat();
		currentState = exploredState.pop();
		if(currentState.isGoalState())
			break;
		tempCO = currentState.getCoordOfLeastNumSuccessor();
		tempNumSuccessors = currentState.getNumSuccessorsOfPos(tempCO);
		for(int i = 1; i < tempNumSuccessors.getLen(); i++)
		{
			tempState = currentState;
			OPERATION tempOP(tempCO, tempNumSuccessors[i]);
			tempState.doOPRT(tempOP);
			tempState.sweep();
			if(!tempState.isContradiction())
			{
				numOfExploredStates++;
				exploredState.push(tempState);
			}
			else
				wrongTime++;
		}
	}
	cout<<" by DFS with sweep:\n";
	currentState.getCurrentState().print();
	cout<<"\n num of states explored:  "<<numOfExploredStates
		<<"\twrong time:  "<<wrongTime<<endl<<endl;
	currentState.getCurrentState().outputToFile("DFS with sweep.txt");
	return currentState;
}
GameState depthFirstSearchWithSweep2(GameState startingGS, int maxStates)
{	
	GameState currentState = startingGS;
	currentState.sweep2();
	int numOfExploredStates = 0;
	int wrongTime = 0;
	gameStateStack exploredState;
	exploredState.push(currentState);
	GameState tempState;
	numStack tempNumSuccessors;
	Coord2D tempCO;
	while(1)
	{
		if(numOfExploredStates > maxStates)
			break;
		if(exploredState.getLen() == 1)
		{
			cout<<"No Solution!\n";
			break;
		}
		//currentState.getCurrentState().freeMat();
		currentState = exploredState.pop();
		if(currentState.isGoalState())
			break;
		tempCO = currentState.getCoordOfLeastNumSuccessor();
		tempNumSuccessors = currentState.getNumSuccessorsOfPos(tempCO);
		for(int i = 1; i < tempNumSuccessors.getLen(); i++)
		{
			tempState = currentState;
			OPERATION tempOP(tempCO, tempNumSuccessors[i]);
			tempState.doOPRT(tempOP);
			tempState.sweep2();
			if(!tempState.isContradiction())
			{
				numOfExploredStates++;
				exploredState.push(tempState);
			}
			else
				wrongTime++;
		}
	}
	cout<<" by DFS with sweep2:\n";
	currentState.getCurrentState().print();
	cout<<"\n num of states explored:  "<<numOfExploredStates
		<<"\twrong time:  "<<wrongTime<<endl<<endl;
	currentState.getCurrentState().outputToFile("DFS2 with sweep2.txt");
	return currentState;
}

int depthFirstSearchForJudge(GameState startingGS, int num)
{	
	ofstream outFile("BFS.txt");
	outFile.close();
	GameState currentState = startingGS;
	currentState.sweep2();
	int numOfExploredStates = 0;
	int wrongTime = 0;
	gameStateStack exploredState;
	exploredState.push(currentState);
	GameState tempState;
	numStack tempNumSuccessors;
	Coord2D tempCO;
	int numOfSln = 0;
	while(1)
	{
		if(exploredState.getLen() == 1)
		{
			//cout<<"No Solution!\n";
			break;
		}
		//currentState.getCurrentState().freeMat();
		currentState = exploredState.pop();
		if(currentState.isGoalState())
		{
			currentState.getCurrentState().outputToFile("BFS.txt");
			numOfSln++;
		}
		if(numOfSln > num)
			break;
		tempCO = currentState.getCoordOfLeastNumSuccessor();
		tempNumSuccessors = currentState.getNumSuccessorsOfPos(tempCO);
		for(int i = 1; i < tempNumSuccessors.getLen(); i++)
		{
			tempState = currentState;
			OPERATION tempOP(tempCO, tempNumSuccessors[i]);
			tempState.doOPRT(tempOP);
			tempState.sweep2();
			if(!tempState.isContradiction())
			{
				numOfExploredStates++;
				exploredState.push(tempState);
			}
			else
				wrongTime++;
		}
	}
	/*cout<<" by DFS with sweep2:\n";
	currentState.getCurrentState().print();
	cout<<"\n num of states explored:  "<<numOfExploredStates
		<<"\twrong time:  "<<wrongTime<<endl<<endl;
	currentState.getCurrentState().outputToFile("DFS2 with sweep2.txt");*/
	return numOfSln;
}

int breadthFirstSearchWithSweep2(GameState startingGS)
{	
	ofstream outFile("BFS.txt");
	outFile.close();
	GameState currentState = startingGS;
	currentState.sweep2();
	int numOfExploredStates = 0;
	int wrongTime = 0;
	int numOfSlns = 0;
	gameStateQueue exploredState;
	exploredState.push(currentState);
	GameState tempState;
	numStack tempNumSuccessors;
	Coord2D tempCO;
	//char ch[6] = "0.txt";
	while(1)
	{
		if(exploredState.getLen() == 1)
			break;
		//currentState.getCurrentState().freeMat();
		currentState = exploredState.pop();
		while(currentState.isGoalState())
		{
			/*cout<<"by BFS with sweep2:\n";
			currentState.getCurrentState().print();*/
			//ch[0]++;
			numOfSlns++;
			currentState.getCurrentState().outputToFile("BFS.txt");
			if(exploredState.getLen() == 1)
				break;
			//currentState.getCurrentState().freeMat();
			currentState = exploredState.pop();
		}
		tempCO = currentState.getCoordOfLeastNumSuccessor();
		tempNumSuccessors = currentState.getNumSuccessorsOfPos(tempCO);
		for(int i = 1; i < tempNumSuccessors.getLen(); i++)
		{
			tempState = currentState;
			OPERATION tempOP(tempCO, tempNumSuccessors[i]);
			tempState.doOPRT(tempOP);
			tempState.sweep2();
			if(!tempState.isContradiction())
			{
				numOfExploredStates++;
				//tempState.getCurrentState().print();
				exploredState.push(tempState);
			}
			else
				wrongTime++;
		}
	}
	cout<<"\n num of states explored:  "<<numOfExploredStates
		<<"\twrong time:  "<<wrongTime<<endl<<endl;
	return numOfSlns;
}

OprtStack breadthFirstSearchForPath(sudokuLoopSearchProblem problem)
{
	OprtStack OPs;
	graphSuccessorStack tempSuccessors;
	if(!problem.isSolveable())
		return OPs;
	int totalSearchTime = problem.numOfPossibleStartingState();
	for(int searchTime = 1; searchTime <= totalSearchTime; searchTime++)
	{
		problem.setStartingState(searchTime);
		problem.currentState.getV() = problem.startingState.getV();
		problem.exploredVertexes.push(problem.currentState);
		while(1)
		{
			if(problem.exploredVertexes.getLen() == 1)
				break;
			problem.currentState = problem.exploredVertexes.pop();
			if(problem.isGoalState())
			{
				OPERATION tempOP(problem.getCoordOfVertex(problem.startingState.getV()), problem.startingState.getE());
				OPs.push(tempOP);
				break;
			}
			tempSuccessors = problem.getSuccessors();
			for(int i = 1; i < tempSuccessors.getLen(); i++)
			{
				problem.currentState = tempSuccessors[i];
				problem.exploredVertexes.push(problem.currentState);
				problem.visitedVertexes.push(problem.currentState.getV());
			}
		}
	}
	return OPs;
}

//Still have bugs
OprtStack breadthFirstSearchForPath(sudokuPathSearchProblem problem)
{
	OprtStack OPs;
	graphSuccessorStack tempLeftSuccessors;	
	graphSuccessorStack tempRightSuccessors;
	if(!problem.isSolveable())
		return OPs;
	int totalSearchTime = problem.numOfPossibleStartingState();
	for(int searchTime = 1; searchTime <= totalSearchTime; searchTime++)
	{
		problem.setStartingState(searchTime);
		graphSuccessorStack leftExplored;
		leftExplored.push(problem.leftCurrentState);
		while(1)
		{
			if(leftExplored.getLen() == 1)
				break;
			problem.leftCurrentState = leftExplored.pop();
			if(problem.isGoalState())
			{
				OPERATION tempOP(problem.getCoordOfVertex(problem.startingVertex), problem.startingEdge);
				OPs.push(tempOP);
				break;
			}

			graphSuccessorStack rightExplored;
			rightExplored.push(problem.rightCurrentState);
			while(1)
			{
				if(rightExplored.getLen() == 1)
					break;
				problem.rightCurrentState = rightExplored.pop();
				if(problem.isGoalState())
				{
					OPERATION tempOP(problem.getCoordOfVertex(problem.startingVertex), problem.startingEdge);
					OPs.push(tempOP);
				}
				tempRightSuccessors = problem.getSuccessors(problem.rightCurrentState);
				for(int i = 1; i < tempRightSuccessors.getLen(); i++)
				{
					problem.rightCurrentState = tempRightSuccessors[i];
					rightExplored.push(problem.rightCurrentState);
					problem.visitedVertexes.push(problem.rightCurrentState.getV());
				}
			}

			tempLeftSuccessors = problem.getSuccessors(problem.leftCurrentState);
			for(int i = 1; i < tempLeftSuccessors.getLen(); i++)
			{
				problem.leftCurrentState = tempLeftSuccessors[i];
				leftExplored.push(problem.leftCurrentState);
				problem.visitedVertexes.push(problem.leftCurrentState.getV());
			}
		}
	}
	return OPs;
}

//Still have bugs
OprtStack breadthFirstSearchForPath(sudokuPathSearchProblemV2 problem)
{
	OprtStack OPs;
	numQueue emptyQ;
	numQueue queueDenotingFindOrNot;
	graphSuccessorStack Successors;
	graphSuccessorStack tempSuccessors;
	intGraphSuccessor currentState;
	int numOfV = problem.getNumOfVertexes();
	for(int v = 1; v <= numOfV; v++)
	{
		problem.visitedVertexes = emptyQ;
		queueDenotingFindOrNot = emptyQ;
		problem.visitedVertexes.push(v);
		Successors = problem.getSuccessorsOfV(v);
		int numOfSOfv = Successors.getLen() - 1;
		for(int i = 1; i <= numOfSOfv; i++)
		{
			bool findedOrNot = UN_FINDED;
			intGraphSuccessor tempGrSr(v, Successors[i].getE());
			problem.startingState = tempGrSr;
			currentState = Successors[i];
			problem.visitedVertexes.push(currentState.getV());
			graphSuccessorStack exploredStates;
			exploredStates.push(currentState);
			queueDenotingFindOrNot.push(findedOrNot);
			while(1)
			{
				if(exploredStates.getLen() == 1)
					break;
				currentState = exploredStates.pop();
				findedOrNot = queueDenotingFindOrNot.pop();
				if(problem.isGoalState(currentState, findedOrNot))
				{
					OPERATION tempOP(problem.getCoordOfVertex(problem.vertexWithBiEdge), problem.edge);
					OPs.push(tempOP);
					break;
				}
				tempSuccessors = problem.getSuccessors(currentState, findedOrNot);
				int lastEdge = currentState.getE();
				int lastVertex = currentState.getV();
				for(int i = 1; i < tempSuccessors.getLen(); i++)
				{
					currentState = tempSuccessors[i];
					exploredStates.push(currentState);
					problem.visitedVertexes.push(currentState.getV());
					if(lastEdge == currentState.getE())
					{
						bool tempFindedOrNot = FINDED;
						problem.vertexWithBiEdge = lastVertex;
						problem.edge = lastEdge;
						queueDenotingFindOrNot.push(tempFindedOrNot);
					}
					else
						queueDenotingFindOrNot.push(findedOrNot);
				}
			}
			if(problem.isGoalState(currentState, findedOrNot))
				break;
		}
	}
	return OPs;
}
