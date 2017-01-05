#include "StdAfx.h"
#include"GameState.h"


iMAT GameState::getBlock(BLOCK_POS pos)
{
	int x, y;
	switch (pos)
	{
	case UP_LEFT:
		x = 0; y = 0; break;
	case UP_MID:
		x = 0; y = 3; break;
	case UP_RIGHT:
		x = 0; y = 6; break;
	case MID_LEFT:
		x = 3; y = 0; break;
	case MID_MID:
		x = 3; y = 3; break;
	case MID_RIGHT:
		x = 3; y = 6; break;
	case DOWN_LEFT:
		x = 6; y = 0; break;
	case DOWN_MID:
		x = 6; y = 3; break;
	case DOWN_RIGHT:
		x = 6; y = 6; break;
	}
	iMAT tempMAT(3,3);
	for(int i = x; i < x+3; i++)
	{
		for(int j = y; j < y+3; j++)
			tempMAT.coeffRef(i-x, j-y) = currentState.coeff(i, j);
	}
	return tempMAT;
}
iMAT GameState::getCol(int col)
{
	int row = currentState.rows();
	iMAT tempMat(row, 1);
	for(int i = 0; i < row; i++)
		tempMat.coeffRef(i, 0) = currentState.coeff(i, col);
	return tempMat;
}
iMAT GameState::getRow(int row)
{
	int col = currentState.cols();
	iMAT tempMat(1, col);
	for(int i = 0; i < col; i++)
		tempMat.coeffRef(0, i) = currentState.coeff(row, i);
	return tempMat;
}
bool GameState::isNumAcceptable(int num, int x, int y)
{
	if(currentState.coeff(x,y) != 0)
		return false;
	BLOCK_POS pos;
#pragma region DETERMINE_BLOCK_POS
	switch(x/3)
	{
	case 0:
		switch(y/3)
		{
		case 0:
			pos = UP_LEFT; break;
		case 1:
			pos = UP_MID; break;
		case 2:
			pos = UP_RIGHT; break;
		}
		break;
	case 1:
		switch(y/3)
		{
		case 0:
			pos = MID_LEFT; break;
		case 1:
			pos = MID_MID; break;
		case 2:
			pos = MID_RIGHT; break;
		}
		break;
	case 2:
		switch(y/3)
		{
		case 0:
			pos = DOWN_LEFT; break;
		case 1:
			pos = DOWN_MID; break;
		case 2:
			pos = DOWN_RIGHT; break;
		}
		break;
	}
#pragma endregion
	return !(GameState::getCol(y).findItem(num)||GameState::getRow(x).findItem(num)||GameState::getBlock(pos).findItem(num));
}
bool GameState::isNumAcceptable(int num, Coord2D coord)
{
	int x = coord.getX();
	int y = coord.getY();
	return GameState::isNumAcceptable(num, x, y);
}
bool GameState::isContradiction()
{
	for(int i = 0; i < 9; i++)
	{
		iMAT tempRow = GameState::getRow(i);
		iMAT tempCol = GameState::getCol(i);
		iMAT tempBlock = GameState::getBlock(i);
		for(int j = 0; j < 9; j++)
		{
			if(currentState.coeff(i, j) == 0)
			{
				int count = 0;
				for(int k = 1; k <= 9; k++)
				{
					if(GameState::isNumAcceptable(k, i, j))
						count++;
				}
				if(count == 0)
					return true;
			}
			if(tempRow.coeff(0, j) != 0)
			{
				for(int k = j + 1; k < 9; k++)
				{
					if(tempRow.coeff(0, k) == tempRow.coeff(0, j))
						return true;
				}
			}
			if(tempCol.coeff(j, 0) != 0)
			{
				for(int k = j + 1; k < 9; k++)
				{
					if(tempCol.coeff(k, 0) == tempCol.coeff(j, 0))
						return true;
				}
			}
		}
		/*for(int m = 0; m < 3; m++)
		{
			for(int n = 0; n < 3; n++)
			{
				int tempNum = tempBlock.coeff(m, n);
				if(tempNum != 0)
				{
					int p = m , q = n + 1;
					if((p == 2)&&(q == 3))
							break;
					while(1)
					{
						if(tempNum == tempBlock.coeff(p, q))
							return true;
						if((p == 2)&&(q == 2))
							break;
						q++;
						if(q > 2)
						{
							q = 0;
							p++;
						}
					}
				}
			}//different col
		}//different row*/
		iMAT blockToRow(1, 9);
		for(int m = 0; m < 3; m++)
		{
			for(int n = 0; n < 3; n++)
			{
				blockToRow(0, 3*m + n) = tempBlock.coeff(m, n);
			}
		}
		for(int j = 0; j < 9; j++)
		{
			if(blockToRow.coeff(0, j) != 0)
			{
				for(int k = j + 1; k < 9; k++)
				{
					if(blockToRow.coeff(0, k) == blockToRow.coeff(0, j))
						return true;
				}
			}
		}
	}
	return false;
}
bool GameState::isOprtAcceptable(OPERATION OP)
{
	int num = OP.getNum();
	int x = OP.getCO().getX();
	int y = OP.getCO().getY();
	return GameState::isNumAcceptable(num, x, y);
}
numStack GameState::getNumSuccessorsOfPos(int x, int y)
{
	numStack numSuccessor;
	for(int i = 1; i <=9; i++)
	{
		if(GameState::isNumAcceptable(i, x, y))
			numSuccessor.push(i);
	}
	return numSuccessor;
}
numStack GameState::getNumSuccessorsOfPos(Coord2D coord)
{
	int x = coord.getX();
	int y = coord.getY();	
	return GameState::getNumSuccessorsOfPos(x, y);
}
coordStack GameState::getCoordSuccessorsOfNumInBlock(int num, BLOCK_POS pos)
{
	coordStack coordstack;
	if(GameState::getBlock(pos).findItem(num))
		return coordstack;
	int x, y;
	switch (pos)
	{
	case UP_LEFT:
		x = 0; y = 0; break;
	case UP_MID:
		x = 0; y = 3; break;
	case UP_RIGHT:
		x = 0; y = 6; break;
	case MID_LEFT:
		x = 3; y = 0; break;
	case MID_MID:
		x = 3; y = 3; break;
	case MID_RIGHT:
		x = 3; y = 6; break;
	case DOWN_LEFT:
		x = 6; y = 0; break;
	case DOWN_MID:
		x = 6; y = 3; break;
	case DOWN_RIGHT:
		x = 6; y = 6; break;
	}
	for(int i = x; i < x+3; i++)
	{
		for(int j = y; j < y+3; j++)
		{
			if(!(GameState::getCol(j).findItem(num)||GameState::getRow(i).findItem(num)||(currentState.coeff(i, j) != 0)))
			{
				Coord2D CO(i, j);
				coordstack.push(CO);
			}
		}
	}
	return coordstack;
}
coordStack GameState::getCoordSuccessorsOfNumInRow(int num, int row)
{
	coordStack coordstack;
	if(GameState::getRow(row).findItem(num))
		return coordstack;
	int x = row;
	BLOCK_POS pos;
	for(int y = 0; y < 9; y++)
	{
#pragma region DETERMINE_BLOCK_POS_2
	switch(x/3)
	{
	case 0:
		switch(y/3)
		{
		case 0:
			pos = UP_LEFT; break;
		case 1:
			pos = UP_MID; break;
		case 2:
			pos = UP_RIGHT; break;
		}
		break;
	case 1:
		switch(y/3)
		{
		case 0:
			pos = MID_LEFT; break;
		case 1:
			pos = MID_MID; break;
		case 2:
			pos = MID_RIGHT; break;
		}
		break;
	case 2:
		switch(y/3)
		{
		case 0:
			pos = DOWN_LEFT; break;
		case 1:
			pos = DOWN_MID; break;
		case 2:
			pos = DOWN_RIGHT; break;
		}
		break;
	}
#pragma endregion
	if(!(GameState::getCol(y).findItem(num)||GameState::getBlock(pos).findItem(num)||(currentState.coeff(x, y) != 0)))
		{
			Coord2D CO(x, y);
			coordstack.push(CO);
		}
	}
	return coordstack;
}
coordStack GameState::getCoordSuccessorsOfNumInCol(int num, int col)
{
	coordStack coordstack;
	if(GameState::getCol(col).findItem(num))
		return coordstack;
	int y = col;
	BLOCK_POS pos;
	for(int x = 0; x < 9; x++)
	{
#pragma region DETERMINE_BLOCK_POS_2
	switch(x/3)
	{
	case 0:
		switch(y/3)
		{
		case 0:
			pos = UP_LEFT; break;
		case 1:
			pos = UP_MID; break;
		case 2:
			pos = UP_RIGHT; break;
		}
		break;
	case 1:
		switch(y/3)
		{
		case 0:
			pos = MID_LEFT; break;
		case 1:
			pos = MID_MID; break;
		case 2:
			pos = MID_RIGHT; break;
		}
		break;
	case 2:
		switch(y/3)
		{
		case 0:
			pos = DOWN_LEFT; break;
		case 1:
			pos = DOWN_MID; break;
		case 2:
			pos = DOWN_RIGHT; break;
		}
		break;
	}
#pragma endregion
	if(!(GameState::getRow(x).findItem(num)||GameState::getBlock(pos).findItem(num)||(currentState.coeff(x, y) != 0)))
		{
			Coord2D CO(x, y);
			coordstack.push(CO);
		}
	}
	return coordstack;
}
int GameState::numOfPosSuccessorOfNum(int num)
{
	int count = 0;
	for(int i = 0; i < 9; i++)
	{
		for(int j = 0; j < 9; j++)
		{
			if(GameState::isNumAcceptable(num, i, j))
				count++;
		}
	}
	return count;
}
int GameState::numOfItem(int item)
{
	int count = 0;
	for(int i = 0; i < 9; i++)
	{
		for(int j = 0; j < 9; j++)
		{
			if(currentState.coeff( i, j) == item)
				count++;
		}
	}
	return count;
}
OprtStack GameState::sweep()
{
	iMAT tempState;
	OprtStack OPStack;
	while(1)
	{
		tempState = currentState;
		for(int i = 0; i < 9; i++)
		{
			for(int j = 0; j < 9; j++)
			{
				if(GameState::getNumSuccessorsOfPos(i, j).getLen() - 1 == 1)
				{
					for(int k = 1; k <= 9; k++)
					{
						if(GameState::isNumAcceptable(k, i, j))
						{
							currentState(i, j) = k;
							OPERATION tempOP(i, j, k);
							OPStack.push(tempOP);
						}
					}
				}
			}
		}
		if(currentState == tempState)
			break;
	}
	return OPStack;
}
OprtStack GameState::sweep2()
{
	iMAT tempState;
	OprtStack OPStack;
	while(1)
	{
		tempState = currentState;
		for(int num = 1; num<= 9; num++)
		{
			for(BLOCK_POS pos = 0; pos < 9; pos++)
			{
				coordStack coordstack = GameState::getCoordSuccessorsOfNumInBlock(num, pos);
				if(coordstack.getLen() -1 == 1)
				{
					OPERATION OP(coordstack[1], num);
					GameState::doOPRT(OP);
					OPStack.push(OP);
				}
			}
			for(int row = 0; row < 9; row++)
			{
				coordStack coordstack = GameState::getCoordSuccessorsOfNumInRow(num, row);
				if(coordstack.getLen() -1 == 1)
				{
					OPERATION OP(coordstack[1], num);
					GameState::doOPRT(OP);
					OPStack.push(OP);
				}
			}
			for(int col = 0; col < 9; col++)
			{
				coordStack coordstack = GameState::getCoordSuccessorsOfNumInCol(num, col);
				if(coordstack.getLen() -1 == 1)
				{
					OPERATION OP(coordstack[1], num);
					GameState::doOPRT(OP);
					OPStack.push(OP);
				}
			}
		}
		if(tempState == currentState)
			break;
	}
	return OPStack;
}
void GameState::doOPRT(OPERATION OP)
{
	int x = OP.getCO().getX();
	int y = OP.getCO().getY();
	currentState.coeffRef(x, y) = OP.getNum();
}
void GameState::doOPRT(OprtStack OPs)
{
	OPERATION OP;
	while(OPs.getLen() > 1)
	{
		OP = OPs.pop();
		GameState::doOPRT(OP);
	}
}
void GameState::undoOPRT(OPERATION OP)
{
	int x = OP.getCO().getX();
	int y = OP.getCO().getY();
	currentState.coeffRef(x, y) = 0;
}
void GameState::undoOPRT(OprtStack OPs)
{
	OPERATION OP;
	while(OPs.getLen() > 1)
	{
		OP = OPs.pop();
		GameState::undoOPRT(OP);
	}
}
Coord2D GameState::getCoordOfLeastNumSuccessor()
{
	Coord2D coord;
	int numOfSuccessor = 9;
	for(int i = 0; i < 9; i++)
	{
		for(int j = 0; j < 9; j++)
		{
			if(currentState.coeff(i, j) != 0)
				continue;
			int temp = GameState::getNumSuccessorsOfPos(i, j).getLen() - 1;
			if((temp < numOfSuccessor)&&(temp != 0))
			{
				Coord2D tempCO(i, j);
				coord = tempCO;
				numOfSuccessor = temp;
			}
		}
	}
	return coord;
}
