#include "StdAfx.h"
#include"generatePuzzle.h"
#include"methods.h"

iMAT generatePuzzle::preGenerate()
{
	GameState tempGS(gameMat);
	srand( (unsigned)GetCurrentTime() );
	int numOfPos = rand()%3 + 5;
	int tempX, tempY, tempNum;
	for(int i = 0; i < numOfPos; i++)
	{
		tempX = rand()%9;
		tempY = rand()%9;
		tempNum = rand()%9 + 1;
		if(tempGS.isNumAcceptable(tempNum, tempX, tempY))
		{
			OPERATION tempOP(tempX, tempY, tempNum);
			tempGS.doOPRT(tempOP);
		}
		else
			i--;
	}
	tempGS = depthFirstSearchWithSweep2(tempGS);
	gameMat = tempGS.getCurrentState();
	return gameMat;
}
iMAT generatePuzzle::generateNaive()
{
	GameState tempGS(gameMat);
	GameState tempTempGS;
	int tempX, tempY, num;
	srand( (unsigned)GetCurrentTime() );
	int numOfEmpty = rand()%6 + 35;
	int count = 0;
	while(1)
	{
		tempX = rand()%9;
		tempY = rand()%9;
		if(tempGS.getCurrentState()(tempX, tempY) == 0)
			continue;	
		Coord2D tempCO(tempX, tempY);
		if(CoStack.findItem(tempCO))
			continue;
		num = tempGS.getCurrentState()(tempX, tempY);
		OPERATION tempOP(tempX, tempY, num);
		tempGS.undoOPRT(tempOP);
		if(depthFirstSearchForJudge(tempGS, 1) > 1)
		{
			tempGS.doOPRT(tempOP);
			CoStack.push(tempCO);
			continue;
		}
		tempTempGS = tempGS;
		tempTempGS.sweep();
		if(!tempTempGS.isGoalState())
		{
			tempGS.doOPRT(tempOP);
			break;
		}
		count++;
		if(count >= numOfEmpty)
			break;
	}
	cout<<"Succeed!\n";
	return tempGS.getCurrentState();
}
iMAT generatePuzzle::generateEasy()
{
	GameState tempGS(gameMat);
	GameState tempTempGS;
	int tempX, tempY, num;
	srand( (unsigned)GetCurrentTime() );
	while(1)
	{
		tempX = rand()%9;
		tempY = rand()%9;
		if(tempGS.getCurrentState()(tempX, tempY) == 0)
			continue;		
		Coord2D tempCO(tempX, tempY);
		if(CoStack.findItem(tempCO))
			continue;
		num = tempGS.getCurrentState()(tempX, tempY);
		OPERATION tempOP(tempX, tempY, num);
		tempGS.undoOPRT(tempOP);
		if(depthFirstSearchForJudge(tempGS, 1) > 1)
		{
			tempGS.doOPRT(tempOP);
			CoStack.push(tempCO);
			continue;
		}
		tempTempGS = tempGS;
		tempTempGS.sweep();
		if(!tempTempGS.isGoalState())
		{
			tempGS.doOPRT(tempOP);
			break;
		}
	}
	cout<<"Succeed!\n";
	return tempGS.getCurrentState();
}
iMAT generatePuzzle::generateNormal()
{
	GameState tempGS(gameMat);
	GameState tempTempGS;
	int tempX, tempY, num;
	int counter = 0; 
	srand( (unsigned)GetCurrentTime() );
	while(1)
	{
		tempX = rand()%9;
		tempY = rand()%9;
		if(tempGS.getCurrentState()(tempX, tempY) == 0)
			continue;		
		Coord2D tempCO(tempX, tempY);
		if(counter > 200)
			break;
		if(CoStack.findItem(tempCO))
		{
			counter++;
			continue;
		}
		num = tempGS.getCurrentState()(tempX, tempY);
		OPERATION tempOP(tempX, tempY, num);
		tempGS.undoOPRT(tempOP);
		if(depthFirstSearchForJudge(tempGS, 1) > 1)
		{
			tempGS.doOPRT(tempOP);
			CoStack.push(tempCO);
			continue;
		}
		tempTempGS = tempGS;
		tempTempGS.sweep2();
		if(!tempTempGS.isGoalState())
		{
			tempGS.doOPRT(tempOP);
			break;
		}
	}
	cout<<"Succeed!\n";
	return tempGS.getCurrentState();
}
iMAT generatePuzzle::generateHard()
{
	GameState tempGS(gameMat);
	GameState tempTempGS;
	int tempX, tempY, num;
	srand( (unsigned)GetCurrentTime() );
	while(1)
	{
		if(tempGS.numOfItem(0) + CoStack.getLen() - 1 == 81)
			break;
		tempX = rand()%9;
		tempY = rand()%9;
		if(tempGS.getCurrentState()(tempX, tempY) == 0)
			continue;
		Coord2D tempCO(tempX, tempY);
		if(CoStack.findItem(tempCO))
			continue;
		OPERATION tempOP(tempX, tempY, 1);
		num = tempGS.getCurrentState()(tempX, tempY);
		tempGS.undoOPRT(tempOP);
		if(depthFirstSearchForJudge(tempGS, 1) > 1)
		{
			OPERATION OP(tempX, tempY, num);
			tempGS.doOPRT(OP);
			CoStack.push(tempCO);
			continue;
		}
		tempTempGS = tempGS;
		tempTempGS.sweep2();
		sudokuLoopSearchProblem problem(tempTempGS);
		OprtStack tempOPs = breadthFirstSearchForPath(problem);
		tempTempGS.doOPRT(tempOPs);
		tempTempGS.sweep2();
		if(!tempTempGS.isGoalState())
			break;
	}
	cout<<"Succeed!\n";
	return tempGS.getCurrentState();
}
iMAT generatePuzzle::generateSometimesNaive()
{
	GameState tempGS(gameMat);
	//tempGS.getCurrentState() = generatePuzzle::generateNormal();
	int tempX, tempY, num;
	int count = 0;
	int CoLen = 1;
	
	srand( (unsigned)GetCurrentTime() );
	while(1)
	{
		tempX = rand()%9;
		tempY = rand()%9;
		if(tempGS.getCurrentState()(tempX, tempY) == 0)
			continue;
		if(CoLen == CoStack.getLen())
			count++;
		else
			count = 0;
		CoLen = CoStack.getLen();
		if(count > 150)
			break;
		//cout<<"\nlen: "<<CoLen;
		Coord2D tempCO(tempX, tempY);
		if(CoStack.findItem(tempCO))
			continue;		
		OPERATION tempOP(tempCO, 1);
		num = tempGS.getCurrentState()(tempCO.getX(), tempCO.getY());
		tempGS.undoOPRT(tempOP);
		if(depthFirstSearchForJudge(tempGS, 1) != 1)
		{
			OPERATION OP(tempCO.getX(), tempCO.getY(), num);
			tempGS.doOPRT(OP);
			CoStack.push(tempCO);
		}
	}
	cout<<"Succeed!\n";
	return tempGS.getCurrentState();
}