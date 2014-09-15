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
