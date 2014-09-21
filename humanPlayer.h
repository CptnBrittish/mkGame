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
