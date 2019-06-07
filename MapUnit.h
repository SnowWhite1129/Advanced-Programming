#include <vector>
#include <string>
#ifndef MAPUNIT__
#define MAPUNIT__
class MapUnit
{
public:
    MapUnit(char type='?', int id=0, const std::string &name="unknown", int cost=0):type_(type), id_(id),cost_(cost),name_(name){}
    MapUnit(const MapUnit &mu):type_(mu.GetType()),id_(mu.GetId()),owner_(mu.GetOwner()),cost_(mu.GetCost()),name_(mu.GetName()){}
    ~MapUnit(){}
    int GetCost() const {return cost_;}
    void SetCost(int cost){cost_=cost;}
    int GetId() const {return id_;};
    char GetType() const {return type_;}
    int GetOwner() const {return owner_;}
    void SetOwner(int playerID){owner_=playerID;}
    const std::string &GetName() const {return name_;}
    virtual int GetFine() const {return 0;}
private:
    char type_='\0';
    int id_=0;
    int owner_=0, cost_=0;
    const std::string name_;
};
class Upgradable : public MapUnit
{
public:
    Upgradable(char type='\0', int id=0, const std::string &name="unknown", int cost=0, int upgradeCost=0, const std::vector<int> &fineList={}):MapUnit(type,id,name,cost), upgradeCost_(upgradeCost),fineList_(fineList){}
    Upgradable(const Upgradable &upg):MapUnit(upg),level_(upg.GetLevel()),upgradeCost_(upg.GetUpgradeCost()),fineList_(upg.GetFineList()){}
    ~Upgradable(){}
    const std::vector<int> &GetFineList() const {return fineList_;}
    void AddLevel(){level_+=1;};
    int GetLevel() const {return level_;}
    int GetUpgradeCost() const {return upgradeCost_;}
private:
    int level_=0,upgradeCost_=0;
    const std::vector<int> fineList_;
};
class Collectable : public MapUnit
{
public:
    Collectable(char type='\0', int id=0, const std::string &name="unknown", int cost=0, int fine=0):MapUnit(type,id,name,cost),fine_(fine){}
    Collectable(const Collectable &col):MapUnit(col),fine_(col.GetFine()){}
    ~Collectable(){}
    int GetFine() const override {return fine_;}
private:
    int fine_;
};
class RandomCost : public MapUnit
{
public:
    RandomCost(char type='\0', int id=0, const std::string &name="unknown", int cost=0, int fine=0):MapUnit(type,id,name,cost),fine_(fine){}
    RandomCost(const RandomCost &ran):MapUnit(ran),fine_(ran.GetFine()){}
    ~RandomCost(){}
    int GetFine() const override {return fine_;};
private:
    int fine_;
};
class Jail : public MapUnit
{
public:
    Jail(char type='\0', int id=0, const std::string &name="unknown",int cost=0):MapUnit(type,id,name,cost){}
    Jail(const Jail &j):MapUnit(j){}
    ~Jail(){}
};
#endif // MAPUNIT__
