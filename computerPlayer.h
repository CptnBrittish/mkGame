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
