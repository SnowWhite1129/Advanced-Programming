#include "Player.h"
int Player::numPlayer = 0;
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
bool Player::UpgradeLand(Upgradable &upgradableunit) {
    if (money_ >= upgradableunit.GetUpgradeCost()) {
        money_ -= upgradableunit.GetUpgradeCost();
        upgradableunit.AddLevel();
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
void Player::Bankrupt() {
    name_ = "";
    num_collectable_units_ = 0;
    money_ = 0;
    num_units_ = 0;
    location_ = 0;
}
void Player::Move(int dice, int mapsize) {
    if (movable_)
    {
        location_ += dice;
        location_ = location_ % mapsize;
    }
}
std::ostream& operator<<(std::ostream &os, const Player &player){
    os << player.id_ << player.location_ << player.money_ << player.name_ << player.num_units_;
    return os;
}
