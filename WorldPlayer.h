#ifndef WORLDPLAYER_H_INCLUDED
#define WORLDPLAYER_H_INCLUDED
#include "Player.h"
class WorldPlayer{
public:

private:
    constexpr static int MaxPlayer = 4;
    Player players_[MaxPlayer];
};

#endif // WORLDPLAYER_H_INCLUDED







