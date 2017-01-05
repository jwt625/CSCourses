#include "StdAfx.h"
#include"graph.h"

bool NonDirGraph::hasEdge(int v1, int v2, int e)
{
	Node* temppVertex = vertexes[v1];
	while(1)
	{
		while((temppVertex != NULL)&&(temppVertex->vertex != v2))
		{
			temppVertex = temppVertex->nextVertex;
		}
		if(temppVertex == NULL)
			break;
		if(temppVertex->edge != e)
			temppVertex = temppVertex->nextVertex;
		else
			return true;
	}
	return false;
}
void NonDirGraph::addEdge(int v1, int v2, int edge)
{
	if(v1 == v2)
		cout<<"ERROR: wrong index of vertex!\n";
	else if((v1 > numOfV)||(v2 > numOfV))
	{
		int v;
		v = v1 > v2 ? v1 : v2;
		Node ** tempVs = new Node*[v+1];
		if(vertexes != NULL)
		{
			for(int i = 0; i <= numOfV; i++)
				tempVs[i] = vertexes[i];
			for(int i = numOfV + 1; i <= v; i++)
				tempVs[i] = NULL;
		}
		else
		{
			for(int i = 0; i <= v; i++)
			{
				tempVs[i] = NULL;
			}
		}
		delete [] vertexes;
		vertexes = tempVs;
		Node*temp = new Node(v1, edge);
		temp->nextVertex = vertexes[v2];
		vertexes[v2] = temp;
		temp = new Node(v2, edge);
		temp->nextVertex = vertexes[v1];
		vertexes[v1] = temp;
		numOfV = v;
		numOfE +=1;
	}
	else
	{
		if(!NonDirGraph::hasEdge(v1, v2, edge))
		{
			Node*temp = new Node(v1, edge);
			temp->nextVertex = vertexes[v2];
			vertexes[v2] = temp;
			temp = new Node(v2, edge);
			temp->nextVertex = vertexes[v1];
			vertexes[v1] = temp;		
			numOfE +=1;
		}
	}
}
graphSuccessorStack NonDirGraph::getSuccessorsOfVertex(int v)
{
	graphSuccessorStack tempStack;
	if(v > numOfV)
	{
		cout<<"ERROR: wrong index of vertex!\n";
		return tempStack;
	}
	Node* temp = vertexes[v];
	while(temp != NULL)
	{
		intGraphSuccessor tempGS(temp->vertex, temp->edge);
		tempStack.push(tempGS);
		temp = temp->nextVertex;
	}
	return tempStack;
}

//bool sudokuPathProblem::isGoalState()
//{
//	Coord2D beginCO(bilocationGraph.getCoordOfIndex(startingVertex));
//	Coord2D endCO(bilocationGraph.getCoordOfIndex(currentVertex));
//	int x1 = beginCO.getX();
//	int x2 = endCO.getX();
//	int y1 = beginCO.getY();
//	int y2 = endCO.getY();
//
//	if(x1 == x2)
//		return true;
//	if(y1 == y2)
//		return true;
//
//	int pos1, pos2;
//#pragma region DETERMINE_BLOCK_POS_1
//	switch(x1/3)
//	{
//	case 0:
//		switch(y1/3)
//		{
//		case 0:
//			pos1 = UP_LEFT; break;
//		case 1:
//			pos1 = UP_MID; break;
//		case 2:
//			pos1 = UP_RIGHT; break;
//		}
//		break;
//	case 1:
//		switch(y1/3)
//		{
//		case 0:
//			pos1 = MID_LEFT; break;
//		case 1:
//			pos1 = MID_MID; break;
//		case 2:
//			pos1 = MID_RIGHT; break;
//		}
//		break;
//	case 2:
//		switch(y1/3)
//		{
//		case 0:
//			pos1 = DOWN_LEFT; break;
//		case 1:
//			pos1 = DOWN_MID; break;
//		case 2:
//			pos1 = DOWN_RIGHT; break;
//		}
//		break;
//	}
//#pragma endregion
//#pragma region DETERMINE_BLOCK_POS_2
//	switch(x2/3)
//	{
//	case 0:
//		switch(y2/3)
//		{
//		case 0:
//			pos2 = UP_LEFT; break;
//		case 1:
//			pos2 = UP_MID; break;
//		case 2:
//			pos2 = UP_RIGHT; break;
//		}
//		break;
//	case 1:
//		switch(y2/3)
//		{
//		case 0:
//			pos2 = MID_LEFT; break;
//		case 1:
//			pos2 = MID_MID; break;
//		case 2:
//			pos2 = MID_RIGHT; break;
//		}
//		break;
//	case 2:
//		switch(y2/3)
//		{
//		case 0:
//			pos2 = DOWN_LEFT; break;
//		case 1:
//			pos2 = DOWN_MID; break;
//		case 2:
//			pos2 = DOWN_RIGHT; break;
//		}
//		break;
//	}
//#pragma endregion
//	if(pos1 == pos2)
//		return true;
//
//	return false;
//}
//numStack sudokuPathProblem::getSuccessors()
//{
//	numStack successors;
//	graphSuccessorStack tempSuccessors = bilocationGraph.getSuccessorsOfVertex(currentVertex);
//	int numOfS = tempSuccessors.getLen() - 1;
//	for(int i = 1; i <= numOfS; i++)
//	{
//		if(tempSuccessors[i].getE() != previousEdge)
//			successors.push(tempSuccessors[i].getV());
//	}
//	return successors;
//}

bool sudokuLoopSearchProblem::isGoalState()
{
	if((goalVertexes.findItem(currentState.getV()))&&(currentState.getE() != startingState.getE()))
		return true;
	return false;
}
int & sudokuLoopSearchProblem::setStartingState(int searchTime)
	{
		startingState.getV() = startingStates[searchTime].getV();
		startingState.getE() = startingStates[searchTime].getE();
		currentState.getE() = startingState.getE();
		graphSuccessorStack tempSuccessors = bilocationGraph.getSuccessorsOfVertex(startingState.getV());
		int numOfS = tempSuccessors.getLen() - 1;
		numStack tempNumStack;
		graphSuccessorStack Empty;
		exploredVertexes = Empty;
		numQueue tempEmptyQueue;
		goalVertexes = tempEmptyQueue;
		visitedVertexes = tempEmptyQueue;
		for(int i = 1; i <= numOfS; i++)
		{
			if(tempSuccessors[i].getE() == currentState.getE())
			{
				tempNumStack.push(tempSuccessors[i].getV());
			}
		}
		startingState.getV() = tempNumStack[1];
		for(int i = 2; i < tempNumStack.getLen(); i++)
			goalVertexes.push(tempNumStack[i]);
		return startingState.getV();
	}
graphSuccessorStack sudokuLoopSearchProblem::getSuccessors()
{	
	graphSuccessorStack successors;
	graphSuccessorStack tempSuccessors = bilocationGraph.getSuccessorsOfVertex(currentState.getV());
	int numOfS = tempSuccessors.getLen() - 1;
	for(int i = 1; i <= numOfS; i++)
	{
		if((tempSuccessors[i].getE() != currentState.getE())&&(!visitedVertexes.findItem(tempSuccessors[i].getV())))
		{
			successors.push(tempSuccessors[i]);
		}
	}
	return successors;
}

bool sudokuPathSearchProblem::isGoalState()
{
	if(leftCurrentState.getE() != rightCurrentState.getE())
		return false;
	Coord2D beginCO(bilocationGraph.getCoordOfIndex(leftCurrentState.getV()));
	Coord2D endCO(bilocationGraph.getCoordOfIndex(rightCurrentState.getV()));
	int x1 = beginCO.getX();
	int x2 = endCO.getX();
	int y1 = beginCO.getY();
	int y2 = endCO.getY();

	if(x1 == x2)
		return true;
	if(y1 == y2)
		return true;

	int pos1, pos2;
#pragma region DETERMINE_BLOCK_POS_1
	switch(x1/3)
	{
	case 0:
		switch(y1/3)
		{
		case 0:
			pos1 = UP_LEFT; break;
		case 1:
			pos1 = UP_MID; break;
		case 2:
			pos1 = UP_RIGHT; break;
		}
		break;
	case 1:
		switch(y1/3)
		{
		case 0:
			pos1 = MID_LEFT; break;
		case 1:
			pos1 = MID_MID; break;
		case 2:
			pos1 = MID_RIGHT; break;
		}
		break;
	case 2:
		switch(y1/3)
		{
		case 0:
			pos1 = DOWN_LEFT; break;
		case 1:
			pos1 = DOWN_MID; break;
		case 2:
			pos1 = DOWN_RIGHT; break;
		}
		break;
	}
#pragma endregion
#pragma region DETERMINE_BLOCK_POS_2
	switch(x2/3)
	{
	case 0:
		switch(y2/3)
		{
		case 0:
			pos2 = UP_LEFT; break;
		case 1:
			pos2 = UP_MID; break;
		case 2:
			pos2 = UP_RIGHT; break;
		}
		break;
	case 1:
		switch(y2/3)
		{
		case 0:
			pos2 = MID_LEFT; break;
		case 1:
			pos2 = MID_MID; break;
		case 2:
			pos2 = MID_RIGHT; break;
		}
		break;
	case 2:
		switch(y2/3)
		{
		case 0:
			pos2 = DOWN_LEFT; break;
		case 1:
			pos2 = DOWN_MID; break;
		case 2:
			pos2 = DOWN_RIGHT; break;
		}
		break;
	}
#pragma endregion
	if(pos1 == pos2)
		return true;

	return false;
}
void sudokuPathSearchProblem::setStartingState(int searchTime)
{
		/*startingState.getV() = startingStates[searchTime].getV();
		startingState.getE() = startingStates[searchTime].getE();*/
		/*graphSuccessorStack tempSuccessors = bilocationGraph.getSuccessorsOfVertex(startingState.getV());
		int numOfS = tempSuccessors.getLen() - 1;*/
		numQueue tempEmptyQueue;
		visitedVertexes = tempEmptyQueue;
		leftCurrentState = leftStarts[searchTime];
		rightCurrentState = rightStarts[searchTime];
		startingVertex = startingVertexes[searchTime];
		startingEdge = leftStarts[searchTime].getE();
		/*for(int i = 1; i <= numOfS; i++)
		{
			if(tempSuccessors[i].getE() == startingState.getE())
			{
				tempNumStack.push(tempSuccessors[i].getV());
			}
		}
		startingState.getV() = tempNumStack[1];
		for(int i = 2; i < tempNumStack.getLen(); i++)
			goalVertexes.push(tempNumStack[i]);*/
}
graphSuccessorStack sudokuPathSearchProblem::getSuccessors(intGraphSuccessor currentState)
{	
	graphSuccessorStack successors;
	graphSuccessorStack tempSuccessors = bilocationGraph.getSuccessorsOfVertex(currentState.getV());
	int numOfS = tempSuccessors.getLen() - 1;
	for(int i = 1; i <= numOfS; i++)
	{
		if((tempSuccessors[i].getE() != currentState.getE())&&(!visitedVertexes.findItem(tempSuccessors[i].getV())))
		{
			successors.push(tempSuccessors[i]);
		}
	}
	return successors;
}

bool sudokuPathSearchProblemV2::isGoalState(intGraphSuccessor currentState, bool finded)
{
	if(!finded)
		return false;
	if(startingState.getE() != currentState.getE())
		return false;

	Coord2D beginCO(bilocationGraph.getCoordOfIndex(startingState.getV()));
	Coord2D endCO(bilocationGraph.getCoordOfIndex(currentState.getV()));
	int x1 = beginCO.getX();
	int x2 = endCO.getX();
	int y1 = beginCO.getY();
	int y2 = endCO.getY();

	if(x1 == x2)
		return true;
	if(y1 == y2)
		return true;

	int pos1, pos2;
#pragma region DETERMINE_BLOCK_POS_1
	switch(x1/3)
	{
	case 0:
		switch(y1/3)
		{
		case 0:
			pos1 = UP_LEFT; break;
		case 1:
			pos1 = UP_MID; break;
		case 2:
			pos1 = UP_RIGHT; break;
		}
		break;
	case 1:
		switch(y1/3)
		{
		case 0:
			pos1 = MID_LEFT; break;
		case 1:
			pos1 = MID_MID; break;
		case 2:
			pos1 = MID_RIGHT; break;
		}
		break;
	case 2:
		switch(y1/3)
		{
		case 0:
			pos1 = DOWN_LEFT; break;
		case 1:
			pos1 = DOWN_MID; break;
		case 2:
			pos1 = DOWN_RIGHT; break;
		}
		break;
	}
#pragma endregion
#pragma region DETERMINE_BLOCK_POS_2
	switch(x2/3)
	{
	case 0:
		switch(y2/3)
		{
		case 0:
			pos2 = UP_LEFT; break;
		case 1:
			pos2 = UP_MID; break;
		case 2:
			pos2 = UP_RIGHT; break;
		}
		break;
	case 1:
		switch(y2/3)
		{
		case 0:
			pos2 = MID_LEFT; break;
		case 1:
			pos2 = MID_MID; break;
		case 2:
			pos2 = MID_RIGHT; break;
		}
		break;
	case 2:
		switch(y2/3)
		{
		case 0:
			pos2 = DOWN_LEFT; break;
		case 1:
			pos2 = DOWN_MID; break;
		case 2:
			pos2 = DOWN_RIGHT; break;
		}
		break;
	}
#pragma endregion
	if(pos1 == pos2)
		return true;

	return false;
}
graphSuccessorStack sudokuPathSearchProblemV2::getSuccessors(intGraphSuccessor currentState, bool finded)
{
	graphSuccessorStack successors;
	graphSuccessorStack tempSuccessors = bilocationGraph.getSuccessorsOfVertex(currentState.getV());
	int numOfS = tempSuccessors.getLen() - 1;
	for(int i = 1; i <= numOfS; i++)
	{
		if(finded)
		{
			if((tempSuccessors[i].getE() != currentState.getE())&&(!visitedVertexes.findItem(tempSuccessors[i].getV())))
			{
				successors.push(tempSuccessors[i]);
			}
		}
		else
		{
			if(!visitedVertexes.findItem(tempSuccessors[i].getV()))
			{
				successors.push(tempSuccessors[i]);
			}
		}
	}
	return successors;
}
