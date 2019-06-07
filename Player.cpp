#include "Player.h"
int Player::numPlayer = 0;
Player::Player(const std::string &name)
{
    id_ = numPlayer;
    name_ = name;
    money_ = startmoney;
    num_units_ = 0;
    location_ = 0;
    ++numPlayer;
}
bool Player::BuyLand(MapUnit &mapunit) {
    if (money_ >= mapunit.GetCost()){
        mapunit.SetOwner(id_);
        money_ -= mapunit.GetCost();
        if (mapunit.GetType()=='C'){
            ++num_collectable_units_;
        }
        ++num_units_;
        return true;
    } else{
        return false;
    }
}
bool Player::PayMoney(Player &player, int money) {
    if (money_>= money) {
        money_ -= money;
        player.money_ += money;
        return true;
    } else{
        return false;
    }
}