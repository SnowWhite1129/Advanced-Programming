#ifndef WORLDPLAYER_H_INCLUDED
#define WORLDPLAYER_H_INCLUDED
#include <vector>
#include "Player.h"
class WorldPlayer{
public:
    friend std::ostream& operator <<(std::ostream &os, const WorldPlayer& worldPlayer);
    WorldPlayer(std::vector <std::string> &name);
    bool AddPlayer(const Player& player);
    Player&operator [](int id){ return players_[id];}
    const Player & operator[](int id) const { return players_[id];}
    constexpr static int MaxPlayer = 4;
private:
    std::vector<Player> players_;
};
std::ostream& operator<<(std::ostream &os, const WorldPlayer& worldPlayer);
#endif // WORLDPLAYER_H_INCLUDED







