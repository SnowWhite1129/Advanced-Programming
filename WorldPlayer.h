#ifndef WORLDPLAYER_H_INCLUDED
#define WORLDPLAYER_H_INCLUDED
#include "Player.h"
class WorldPlayer{
public:
    Player&operator [](int id){ return players_[id];}
    const Player & operator[](int id) const { return players_[id];}
private:
    constexpr static int MaxPlayer = 4;
    Player players_[MaxPlayer];
};

#endif // WORLDPLAYER_H_INCLUDED







