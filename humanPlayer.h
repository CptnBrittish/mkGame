#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

//doing this hurts
#include "board.h"
#include "player.h"

class humanPlayer: public Player {
public:
    virtual void input(Board&);
    humanPlayer(int);
    ~humanPlayer();
};

#endif
