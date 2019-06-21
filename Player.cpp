#include <iomanip>
#include "Player.h"
int Player::numPlayer = 1;
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
void Player::Create(std::string name) {
    name_ = name;
    id_ = numPlayer;
    num_units_ = 0;
    num_collectable_units_ = 0;
    location_ = 0;
    ++numPlayer;
}
std::istream& operator>>(std::istream &is, Player& player){
    is >> player.name_;
    player.location_ = 0;
    player.num_units_ = 0;
    player.num_collectable_units_ = 0;
    player.money_ = player.startmoney;
    player.id_ = player.numPlayer;
    ++player.numPlayer;
    return is;
}
std::ostream& operator<<(std::ostream &os, const Player &player){
    os << "  ["<< player.id_ << "]"<< std::setw(20) << player.name_ << "  $" << player.money_  <<  " with" <<player.num_units_ << " units" << std::endl;
    return os;
}
Player& Player::operator=(const Player &player) {
    name_ = player.name_;
    id_ = player.id_;
    num_units_ = player.num_units_;
    num_collectable_units_ = player.num_collectable_units_;
    money_ = player.money_;
    location_ = player.location_;
}