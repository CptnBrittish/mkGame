#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H

#include "board.h"
#include "player.h"

class computerPlayer: public Player {
private:
    int findMove(int&, int&,int, int);
    int findPersonToBlock(int&, int&, int, int);

    int findVertical(int&, int&, int, int);
    int findHorizontal(int&, int&, int, int);
    int findDiagonalLeft(int&, int&, int, int);
    int findDiagonalRight(int&, int&, int, int);

    void syncBoard();

    int opponant; //required for findMoves()
    Board *playerBoard;
    int **board;
public:
    virtual void input();
    computerPlayer(int, Board*);
};

#endif
