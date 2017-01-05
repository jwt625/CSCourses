/*****************************************************************
graph.h

This file contains class describing a nondirection graph by LinJieBiao
and the Bilocation graph generated from a GameState

Realized in graph.cpp
*****************************************************************/
#pragma once

#ifndef GRAPH_H_
#define GRAPH_H_
#include"DataStruct.h"
#include"GameState.h"
struct Node
{
	int vertex, edge;
	Node* nextVertex;
	Node(int v = 0, int e = 0):vertex(v), edge(e) {}
};

//class describing a graph successor
//include int vertex, int edge
//METHODS:
//void print()
//void operator=
//bool operator==
//int & getV()
//int & getE()
class intGraphSuccessor
{
private:
	int vertex;
	int edge;
public:
	intGraphSuccessor(int v = 0, int e = 0):vertex(v), edge(e){}
	intGraphSuccessor(intGraphSuccessor & tempIntGS):vertex(tempIntGS.getV()), edge(tempIntGS.getE()){}
	void print(){cout<<"v: "<<vertex<<", "<<"e: "<<edge<<endl;}
	void operator=(intGraphSuccessor tempGS){vertex = tempGS.getV(); edge = tempGS.getE();}
	bool operator==(intGraphSuccessor tempGS)
	{
		if((vertex == tempGS.getV())&&(edge == tempGS.getE()))
			return true;
		return false;
	}
	int & getV(){return vertex;}
	int & getE(){return edge;}
};

//Stack for intGraphSuccessor
typedef Stack<intGraphSuccessor> graphSuccessorStack;

//class describing a nonDirGraph by LinJieBiao
//include Node** vertexes, int numOfV, int numOfE
//METHODS:
//void addEdge(int v1, int v2, int edge)
//int getNumOfVertex()
//int getNumOfEdge()
//int getNumOfSuccessorsOfVertex(int v)
//graphSuccessorStack getSuccessorsOfVertex(int v)
//Node* getpSuccessorsOfVertex(int v)
//bool hasEdge(int v1, int v2, int e)
class NonDirGraph
{
private:
	Node** vertexes;
	int numOfV;
	int numOfE;
public:
	NonDirGraph(){numOfE = 0; numOfV = 0;vertexes = NULL;}
	NonDirGraph(int numV)
	{
		vertexes = new Node*[numV+1];
		for(int i = 0; i <= numV; i++)
			vertexes[i] = NULL;
		numOfV = numV; 
		numOfE = 0;
	}
	void addEdge(int v1, int v2, int edge);
	int getNumOfVertex(){return numOfV;}
	int getNumOfEdge(){return numOfE;}
	graphSuccessorStack getSuccessorsOfVertex(int v);
	Node* getpSuccessorsOfVertex(int v)
	{
		if((v == 0)||(v > numOfV))
		{
			cout<<"ERROR: wrong index of vertex!\n";
			return NULL;
		}
		return vertexes[v];
	}
	int getNumOfSuccessorsOfVertex(int v)
	{
		if((v == 0)||(v > numOfV))
		{
			cout<<"ERROR: wrong index of vertex!\n";
			return 0;
		}
		int count = 0;
		Node* ptempVertex = vertexes[v];
		while(ptempVertex != NULL)
		{
			ptempVertex = ptempVertex->nextVertex;
			count++;
		}
		return count;
	}
	bool hasEdge(int v1, int v2, int e);
	//~NonDirGraph(){delete [] vertexes;}
};

//class describing a bilocation graph generated from a sudoku puzzle, inherited from class NonDirGraph
//include coordStack coords,
//METHODS:
//Coord2D getCoordOfIndex(int n)
//METHODS OF NonDirGraph:
//void addEdge(int v1, int v2, int edge)
//int getNumOfVertex()
//int getNumOfEdge()
//int getNumOfSuccessorsOfVertex(int v)
//graphSuccessorStack getSuccessorsOfVertex(int v)
//Node* getpSuccessorsOfVertex(int v)
//bool hasEdge(int v1, int v2, int e)
class BilocationGraph:public NonDirGraph
{
private:
	coordStack coords;
public:
	BilocationGraph():NonDirGraph(){}
	BilocationGraph(GameState tempGS):NonDirGraph()
	{
		coordStack tempCoordStack;
		int CoordIndex;
		int CoordIndex2;
		for(int num = 1; num <=9; num++)
		{
			for(int row = 0; row < 9; row++)
			{
				tempCoordStack = tempGS.getCoordSuccessorsOfNumInRow(num, row);
				if(tempCoordStack.getLen() == 3)
				{
					CoordIndex = coords.findItem(tempCoordStack[1]);
					if(CoordIndex == 0)
					{
						coords.push(tempCoordStack[1]);
						CoordIndex = coords.getLen() - 1;
					}
					CoordIndex2 = coords.findItem(tempCoordStack[2]);
					if(CoordIndex2 == 0)
					{
						coords.push(tempCoordStack[2]);
						CoordIndex2 = coords.getLen() - 1;
					}
					NonDirGraph::addEdge(CoordIndex, CoordIndex2, num);
				}
			}
			for(int col = 0; col < 9; col++)
			{
				tempCoordStack = tempGS.getCoordSuccessorsOfNumInCol(num, col);
				if(tempCoordStack.getLen() == 3)
				{
					CoordIndex = coords.findItem(tempCoordStack[1]);
					if(CoordIndex == 0)
					{
						coords.push(tempCoordStack[1]);
						CoordIndex = coords.getLen() - 1;
					}
					CoordIndex2 = coords.findItem(tempCoordStack[2]);
					if(CoordIndex2 == 0)
					{
						coords.push(tempCoordStack[2]);
						CoordIndex2 = coords.getLen() - 1;
					}
					NonDirGraph::addEdge(CoordIndex, CoordIndex2, num);
				}
			}
			for(int block = 0; block < 9; block++)
			{
				tempCoordStack = tempGS.getCoordSuccessorsOfNumInBlock(num, block);
				if(tempCoordStack.getLen() == 3)
				{
					CoordIndex = coords.findItem(tempCoordStack[1]);
					if(CoordIndex == 0)
					{
						coords.push(tempCoordStack[1]);
						CoordIndex = coords.getLen() - 1;
					}
					CoordIndex2 = coords.findItem(tempCoordStack[2]);
					if(CoordIndex2 == 0)
					{
						coords.push(tempCoordStack[2]);
						CoordIndex2 = coords.getLen() - 1;
					}
					NonDirGraph::addEdge(CoordIndex, CoordIndex2, num);
				}
			}
		}
	}
	Coord2D getCoordOfIndex(int n)
	{
		if(n >= coords.getLen())
		{
			Coord2D tempCO;
			cout<<"ERROR: coord index beyond range!";
		}
		return coords[n];
	}
};

//class sudokuPathProblem
//{
//private:
//	BilocationGraph bilocationGraph;
//	numStack startingVertexes;
//public:
//	numStack exploredVertexes;
//	int startingVertex;
//	int currentVertex;
//	int previousEdge;
//	sudokuPathProblem(GameState tempGS):bilocationGraph(tempGS)
//	{
//		int startingVertex = 0;
//		if(bilocationGraph.getNumOfEdge() * 2 == bilocationGraph.getNumOfVertex())
//		{
//			startingVertex = 0;
//		}
//		else
//		{
//			int numOfV = bilocationGraph.getNumOfVertex();
//			for(int v = 1; v <= numOfV; v++)
//			{
//				Node* pSuccessor = bilocationGraph.getpSuccessorsOfVertex(v);
//				if(bilocationGraph.getNumOfSuccessorsOfVertex(v) == 1)
//					continue;
//				do
//				{
//					int tempEdge;
//					Node* ptempSuccessor = pSuccessor;
//					tempEdge = ptempSuccessor->edge;
//					while(1)
//					{
//						ptempSuccessor = ptempSuccessor->nextVertex;
//						if(ptempSuccessor == NULL)
//							break;
//						if(tempEdge == ptempSuccessor->edge)
//							break;
//					}
//					if(ptempSuccessor == NULL)
//					{
//						pSuccessor = pSuccessor->nextVertex;
//						if(pSuccessor == NULL)
//						{
//							startingVertex = 0;
//							break;
//						}
//					}
//					else
//					{
//						startingVertex = v;
//						break;
//					}
//				}while(1);
//				if(startingVertex == v)
//					startingVertexes.push(startingVertex);
//			}
//		}
//		currentVertex = startingVertexes[1];
//	}
//	int & getStartingState(int searchTime = 1)
//	{
//		return startingVertexes[searchTime];
//	}
//	//returns number of possible starting states
//	int numOfPossibleStartingState(){return startingVertexes.getLen() - 1;}
//	bool isSolveable()
//	{
//		if(startingVertexes.getLen()>1)
//			return true;
//		cout<<"Can\'t use Path Search!\n";
//		return false;
//	}
//	bool isGoalState();
//	numStack getSuccessors();
//};

class sudokuLoopSearchProblem
{
private:
	BilocationGraph bilocationGraph;
public:
	graphSuccessorStack exploredVertexes;
	graphSuccessorStack startingStates;
	numQueue visitedVertexes;
	intGraphSuccessor startingState;
	numQueue goalVertexes;
	intGraphSuccessor currentState;

	sudokuLoopSearchProblem(GameState tempGS):bilocationGraph(tempGS)
	{
			int numOfV = bilocationGraph.getNumOfVertex();
			for(int v = 1; v <= numOfV; v++)
			{
				int tempEdge;
				if(bilocationGraph.getNumOfSuccessorsOfVertex(v) == 1)
					continue;
				/*do
				{
					Node* ptempSuccessor = pSuccessor;
					tempEdge = ptempSuccessor->edge;
					while(1)
					{
						ptempSuccessor = ptempSuccessor->nextVertex;
						if(ptempSuccessor == NULL)
							break;
						if(tempEdge == ptempSuccessor->edge)
							break;
					}
					if(ptempSuccessor == NULL)
					{
						pSuccessor = pSuccessor->nextVertex;
						if(pSuccessor == NULL)
						{
							Vertex = 0;
							break;
						}
					}
					else
					{
						Vertex = v;
						break;
					}
				}while(1);*/
				for(tempEdge = 1; tempEdge<=9; tempEdge++)
				{
					Node* pSuccessor = bilocationGraph.getpSuccessorsOfVertex(v);
					while(1)
					{
						if(pSuccessor == NULL)
							break;
						if(pSuccessor->edge == tempEdge)
							break;
						pSuccessor = pSuccessor->nextVertex;
					}
					if(pSuccessor == NULL)
						continue;
					Node * temppSuccessor = pSuccessor->nextVertex;
					while(1)
					{
						if(temppSuccessor == NULL)
							break;
						if(temppSuccessor->edge == tempEdge)
							break;
						temppSuccessor = temppSuccessor->nextVertex;
					}
					if(temppSuccessor == NULL)
						continue;
					intGraphSuccessor tempS(v, tempEdge);
					startingStates.push(tempS);
				}
				/*if(Vertex == v)
				{
					intGraphSuccessor tempS(Vertex, tempEdge);
					startingStates.push(tempS);
				}*/
			}
	}
	int & setStartingState(int searchTime = 1);
	//returns number of possible starting states
	int numOfPossibleStartingState(){return startingStates.getLen() - 1;}
	Coord2D getCoordOfVertex(int v){return bilocationGraph.getCoordOfIndex(v);}
	bool isSolveable()
	{
		if(startingStates.getLen()>1)
			return true;
		cout<<"Can\'t use Loop Search!\n";
		return false;
	}
	bool isGoalState();
	graphSuccessorStack getSuccessors();
};

//not running correctly
class sudokuPathSearchProblem
{
private:
	BilocationGraph bilocationGraph;
public:
	graphSuccessorStack leftStarts;
	graphSuccessorStack rightStarts;
	numQueue startingVertexes;

	int startingVertex;
	int startingEdge;
	numQueue visitedVertexes;
	intGraphSuccessor leftCurrentState;
	intGraphSuccessor rightCurrentState;

	sudokuPathSearchProblem(GameState tempGS):bilocationGraph(tempGS)
	{
		graphSuccessorStack startingStates;
			int numOfV = bilocationGraph.getNumOfVertex();
			for(int v = 1; v <= numOfV; v++)
			{
				int tempEdge;
				if(bilocationGraph.getNumOfSuccessorsOfVertex(v) == 1)
					continue;
				for(tempEdge = 1; tempEdge<=9; tempEdge++)
				{
					Node* pSuccessor = bilocationGraph.getpSuccessorsOfVertex(v);
					while(1)
					{
						if(pSuccessor == NULL)
							break;
						if(pSuccessor->edge == tempEdge)
							break;
						pSuccessor = pSuccessor->nextVertex;
					}
					if(pSuccessor == NULL)
						continue;
					Node * temppSuccessor = pSuccessor->nextVertex;
					while(1)
					{
						if(temppSuccessor == NULL)
							break;
						if(temppSuccessor->edge == tempEdge)
							break;
						temppSuccessor = temppSuccessor->nextVertex;
					}
					if(temppSuccessor == NULL)
						continue;
					intGraphSuccessor tempS(v, tempEdge);
					startingStates.push(tempS);
				}
			}
			int num = startingStates.getLen() - 1;
			for(int i = 1; i <= num; i++)
			{
				graphSuccessorStack tempSuccessors = bilocationGraph.getSuccessorsOfVertex(startingStates[i].getV());
				graphSuccessorStack tempUsefulSuccessors;
				int numOfS = tempSuccessors.getLen() - 1;
				for(int j = 1; j <= numOfS; j++)
				{
					if(tempSuccessors[j].getE() == startingStates[i].getE())
					{
						tempUsefulSuccessors.push(tempSuccessors[j]);
					}					
				}
				int numOfUsefulS = tempUsefulSuccessors.getLen() - 1;
				for(int j = 1; j <= numOfUsefulS - 1; j++)
				{
					for(int k = j + 1; k <= numOfUsefulS; k++)
					{
						leftStarts.push(tempUsefulSuccessors[j]);
						rightStarts.push(tempUsefulSuccessors[k]);
						startingVertexes.push(startingStates[i].getV());
					}
				}
			}

	}
	void setStartingState(int searchTime = 1);
	//returns number of possible starting states
	int numOfPossibleStartingState(){return startingVertexes.getLen() - 1;}
	Coord2D getCoordOfVertex(int v){return bilocationGraph.getCoordOfIndex(v);}
	bool isSolveable()
	{
		if(startingVertexes.getLen()>1)
			return true;
		cout<<"Can\'t use Path Search!\n";
		return false;
	}
	bool isGoalState();
	graphSuccessorStack getSuccessors(intGraphSuccessor currentState);
	
};

#define FINDED 1
#define UN_FINDED 0

//class GraphSuccessorForPS:public intGraphSuccessor
//{
//private:
//	bool findedOrNot;
//public:
//	GraphSuccessorForPS():intGraphSuccessor(){findedOrNot = UN_FINDED;}
//	void operator=(GraphSuccessorForPS tempGS)
//	{
//		intGraphSuccessor::getE() = tempGS.getE();
//		intGraphSuccessor::getV() = tempGS.getV();
//		findedOrNot = tempGS.isFinded();
//	}
//	bool & isFinded(){return findedOrNot;}
//	bool operator==(GraphSuccessorForPS tempGS)
//	{
//		if(intGraphSuccessor::getE() != tempGS.getE())
//			return false;
//		if(intGraphSuccessor::getV() != tempGS.getV())
//			return false;
//		if(findedOrNot != tempGS.isFinded())
//			return false;
//		return true;
//	}
//};
//
//typedef Stack<GraphSuccessorForPS> GSforPSstack;

class sudokuPathSearchProblemV2
{
private:
	BilocationGraph bilocationGraph;
public:
	intGraphSuccessor startingState;
	numQueue visitedVertexes;
	int vertexWithBiEdge;
	int edge;

	sudokuPathSearchProblemV2(GameState tempGS):bilocationGraph(tempGS){}
	bool isGoalState(intGraphSuccessor currentState, bool finded);
	int getNumOfVertexes(){return bilocationGraph.getNumOfVertex();}
	Coord2D getCoordOfVertex(int n){return bilocationGraph.getCoordOfIndex(n);}
	graphSuccessorStack getSuccessors(intGraphSuccessor currentState, bool finded);
	graphSuccessorStack getSuccessorsOfV(int n){return bilocationGraph.getSuccessorsOfVertex(n);}
};

#endif  //GRAPH_H_