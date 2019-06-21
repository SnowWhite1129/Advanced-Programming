#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include<ostream>
#include<string>
#include "MapUnit.h"
class Player{
public:
    friend std::ostream& operator <<(std::ostream &os, const Player& player);
    void Move(int dice, int mapsize);
    void Bankrupt();
    bool PayMoney(Player &player, int money);
    bool UpgradeLand(Upgradable &upgradableunit);
    bool BuyLand(MapUnit &mapunit);
    void GoToJail(){movable_ = false;}
    void ReleaseFromJail(){movable_ = true;}
    bool InTheJail(){ return movable_== true;}
    void IncreaseMoney(int money) { money_ += money;}

    Player(const std::string &name):id_(numPlayer), name_(name), money_(startmoney), location_(0), num_units_(0), num_collectable_units_(0){++numPlayer;}
    Player(const char name[]):id_(numPlayer), name_(name), money_(startmoney), location_(0), num_units_(0), num_collectable_units_(0){++numPlayer;}

    int id() const {return id_;}
    std::string name() const {return name_;}
    int location()const {return location_;}
    int num_units()const {return num_units_;}
    int num_collectable_units()const {return num_collectable_units_;}
    bool movable()const {return movable_;}
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
std::ostream& operator<<(std::ostream &os, const Player& player);
#endif // PLAYER_H_INCLUDED
