#ifndef WORLDPLAYER_H_INCLUDED
#define WORLDPLAYER_H_INCLUDED
#include <vector>
#include "Player.h"
class WorldPlayer{
public:
    WorldPlayer(std::vector <std::string> &name);
    bool AddPlayer(const Player& player);
    Player&operator [](int id){ return players_[id];}
    const Player & operator[](int id) const { return players_[id];}
    constexpr static int MaxPlayer = 4;
private:
    std::vector<Player> players_;
};

#endif // WORLDPLAYER_H_INCLUDED







