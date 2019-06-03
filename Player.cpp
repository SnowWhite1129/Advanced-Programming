#include "Player.h"
Player::Player(const std::string &name)
{
    id_ = numPlayer;
    name_ = name;
    money_ = startmoney;
    num_units_ = 0;
    location_ = 0;
    ++numPlayer;
}
