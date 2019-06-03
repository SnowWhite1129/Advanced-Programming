#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include<string>
#include "MapUnit.h"
class Player{
public:
    void PayMoney(const Player &player, int money);
    bool BuyLand(MapUnit &mapunit);
    Player(const std::string &name);
    int id() {return id_;}
    string name(){return name_;}
    int location(){return location;}
    int num_units(){return num_units_;}
    int num_collectable_units(){return num_collectable_units_;}
    bool movable(){return movable_;}

private:
    int id_ = numPlayer;
    std::string name_;
    int money_ = startmoney;
    int location_ = 0;
    int num_units_ = 0;
    int num_collectable_units_ = 0;
    static int numPlayer = 0;
    bool movable_ = true;
    constexpr int startmoney = 25000;
};

#endif // PLAYER_H_INCLUDED
