#include "WorldPlayer.h"
WorldPlayer::WorldPlayer(std::vector <std::string> &name){
    for(unsigned int i=0;i<name.size();++i){
        Player player(name.at(i));
        players_.push_back(player);
    }
}
bool WorldPlayer::AddPlayer(const Player& player){
    if(players_.size()<4){
        players_.push_back(player);
        return true;
    } else {
        return false;
    }
}
std::ostream& operator<<(std::ostream &os, const WorldPlayer &worldPlayer){
    for (unsigned int i = 0; i < worldPlayer.players_.size(); ++i) {
        os << worldPlayer[i];
    }
    return os;
}