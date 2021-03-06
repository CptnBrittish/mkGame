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

#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

//doing this hurts
#include "board.h"
#include "player.h"

class humanPlayer: public Player {
public:
    Board *playerBoard;
    virtual void input();
    humanPlayer(int, Board*);
    ~humanPlayer();
};

#endif
