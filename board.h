#ifndef BOARD_H
#define BOARD_H

#include <iostream>

class Board {
private:
    static const int M = 5;
    static const int K = 3;

/* 
   Options for board state
   0 = no play in square
   1 = player 1 (X)
  -1 = player 2 (O)
   defaults to 0
*/
    int boardState[M][K];

public:
    void printBoard();
    int playerInput(int, int, int);
    int checkIfGameWon(int);
    Board();

};

#endif
