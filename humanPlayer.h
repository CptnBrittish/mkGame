#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

//doing this hurts
#include "board.h"

class humanPlayer {
private:
    int player;

public:
    void input(Board&);
    humanPlayer(int);
    ~humanPlayer();
};

#endif
