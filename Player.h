#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include<string>
#include "MapUnit.h"
class Player{
public:
    void Move(int dice, int mapsize);
    void Bankrupt();
    bool PayMoney(Player &player, int money);
    bool UpgradeLand(Upgradable &upgradableunit);
    bool BuyLand(MapUnit &mapunit);
    void GoToJail(){movable_ = false;}
    void ReleaseFromJail(){movable_ = true;}
    bool InTheJail(){ return movable_== true;}
    void IncreaseMoney(int money) { money_ += money;}
    Player(const std::string &name);
    int id() {return id_;}
    std::string name(){return name_;}
    int location(){return location_;}
    int num_units(){return num_units_;}
    int num_collectable_units(){return num_collectable_units_;}
    bool movable(){return movable_;}
    static int numPlayer;
private:
    int id_ = numPlayer;
    std::string name_;
    int money_ = startmoney;
    int location_ = 0;
    int num_units_ = 0;
    int num_collectable_units_ = 0;

    bool movable_ = true;
    constexpr static int startmoney = 25000;
};
#endif // PLAYER_H_INCLUDED
