/*************************************************************************
Copyright 2014 Thomas Atkinson
This file is part of mkGame.
mkGame is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.
mkGame is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with mkGame. If not, see <http://www.gnu.org/licenses/>.
*************************************************************************/

#ifndef BOARD_H
#define BOARD_H

#include <iostream>

class Board {
private:
    int M;
    int K;

/* 
   Options for board state
   0 = no play in square
   1 = player 1 (X)
  -1 = player 2 (O)
   defaults to 0
*/
    int **boardState;

public:
    void printBoard();
    int playerInput(int, int, int);
    int checkIfGameWon(int);
    int getK();
    int getM();
    int ** getBoard();
    Board();
    Board(int, int);
    ~Board();
};

#endif
