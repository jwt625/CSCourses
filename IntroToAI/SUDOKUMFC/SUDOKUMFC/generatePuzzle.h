/*****************************************************************
generatePuzzle.h

This file contains classe for generating sudoku puzzles

Realized in generatePuzzle.cpp
*****************************************************************/
#pragma once
/*****************************************************************
generatePuzzle.h

This file contains classe for generating sudoku puzzles

Realized in generatePuzzle.cpp
*****************************************************************/

#ifndef GENERATEPUZZLE_H_
#define GENERATEPUZZLE_H_

#include"GameState.h"
#include<Windows.h>

class generatePuzzle
{
private:
	iMAT gameMat;
	coordStack CoStack;
public:
	generatePuzzle():gameMat(9, 9)
	{
		for(int i = 0; i < 9; i++)
		{
			for(int j = 0; j < 9; j++)
				gameMat(i, j) = 0;
		}
	}
	iMAT preGenerate();
	iMAT getGameMat(){return gameMat;}
	iMAT generateNaive();
	iMAT generateEasy();
	iMAT generateNormal();
	iMAT generateHard();
	iMAT generateSometimesNaive();
};

#endif
