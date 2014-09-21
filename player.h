#ifndef PLAYER_H
#define PLAYER_H

#include "board.h"

class Player {
public:
    int player;
    virtual void input() = 0;
    Player();
};

#endif
