/*********** Declaration*******
I hereby certify that no part of this assignment has been copied from
any other student’s work or from any other source. No part of the code
has been written/produced for me by another person or copied from any
other source.
I hold a copy of this assignment that I can produce if the original is
lost or damaged.
**************************/

#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H

#include "board.h"
#include "player.h"

class computerPlayer: public Player {
private:
    int findMove(int&, int&,int, int, int**);
    int findPersonToBlock(int&, int&, int, int, int**);
    int findVertical(int&, int&, int, int, int**);
    int findHorizontal(int&, int&, int, int, int**);
    int findDiagonalLeft(int&, int&, int, int, int**);
    int findDiagonalRight(int&, int&, int, int, int**);
    int opponant; //required for findMoves()
public:
    virtual void input(Board&);
    computerPlayer(int);
};

#endif
