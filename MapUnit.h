#ifndef MAPUNIT__
#define MAPUNIT__
#include <vector>
#include <string>
#include<iostream>
constexpr int maxPlayers=4;
class MapUnit
{
public:
    MapUnit(char type='?', int id=0, const std::string &name="unknown", int cost=0):type_(type), id_(id),cost_(cost),name_(name){}
    MapUnit(const MapUnit &mu):type_(mu.GetType()),id_(mu.GetId()),owner_(mu.GetOwner()),cost_(mu.GetCost()),name_(mu.GetName()){}
    virtual ~MapUnit()=default;
    int GetCost() const {return cost_;}
    void SetCost(int cost){cost_=cost;}
    int GetId() const {return id_;};
    char GetType() const {return type_;}
    int GetOwner() const {return owner_;}
    virtual void SetOwner(int playerID){owner_=playerID;}
    const std::string &GetName() const {return name_;}
    virtual int GetFine()const{return 0;}
    virtual void Show(std::ostream &os)const=0;
    virtual int GetLevel()const{return -1;}
    virtual bool isRandom()const{return false;};
    friend std::ostream& operator <<(std::ostream &os,const MapUnit &mu);
    virtual void Reset(){owner_=-1;};
    virtual MapUnit* Clone()const=0;
private:
    char type_='\0';
    int id_=0;
    int owner_=-1, cost_=0;
    const std::string name_;
};
class Upgradable final: public MapUnit
{
public:
    using MapUnit::Show;
    using MapUnit::GetFine;
    Upgradable(char type='\0', int id=0, const std::string &name="unknown", int cost=0, int upgradeCost=0, const std::vector<int> &fineList={}):MapUnit(type,id,name,cost),level_(1), upgradeCost_(upgradeCost),fineList_(fineList){}
    Upgradable(const Upgradable &upg):MapUnit(upg),level_(upg.GetLevel()),upgradeCost_(upg.GetUpgradeCost()),fineList_(upg.GetFineList()){}
    virtual ~Upgradable()=default;
    const std::vector<int> &GetFineList() const {return fineList_;}
    void AddLevel(){level_+=1;};
    virtual int GetLevel() const override{return level_;}
    int GetUpgradeCost() const {return upgradeCost_;}
    virtual void Show(std::ostream &os)const override;
    virtual int GetFine() const override {return fineList_[level_];}
    virtual void Reset(){level_=1;MapUnit::Reset();}
    virtual Upgradable* Clone()const override{return new Upgradable(*this);}
private:
    int level_=1,upgradeCost_=0;
    const std::vector<int> fineList_;
};
class Collectable final: public MapUnit
{
public:
    using MapUnit::Show;
    using MapUnit::GetFine;
    using MapUnit::SetOwner;
    Collectable(char type='\0', int id=0, const std::string &name="unknown", int cost=0, int fine=0):MapUnit(type,id,name,cost),fine_(fine){}
    Collectable(const Collectable &col):MapUnit(col),fine_(col.GetFine()){}
    virtual ~Collectable()=default;
    virtual int GetFine() const override {return fine_*playerCollected_[this->GetOwner()];}
    virtual void SetOwner(int playerID)override;
    virtual void Show(std::ostream &os)const override;
    virtual void Reset(){playerCollected_[this->GetOwner()]=0;MapUnit::Reset();}
    virtual Collectable* Clone()const override{return new Collectable(*this);}
private:
    int fine_;
    static int playerCollected_[maxPlayers];
};
class RandomCost final: public MapUnit
{
public:
    using MapUnit::Show;
    using MapUnit::GetFine;
    using MapUnit::isRandom;
    RandomCost(char type='\0', int id=0, const std::string &name="unknown", int cost=0, int fine=0):MapUnit(type,id,name,cost),fine_(fine){}
    RandomCost(const RandomCost &ran):MapUnit(ran),fine_(ran.GetFine()){}
    virtual ~RandomCost()=default;
    virtual int GetFine() const override {return fine_;}
    virtual bool isRandom() const override {return true;}
    virtual void Show(std::ostream &os)const override;
    virtual RandomCost* Clone()const override{return new RandomCost(*this);}
private:
    int fine_;
};
class Jail final: public MapUnit
{
public:
    using MapUnit::Show;
    Jail(char type='\0', int id=0, const std::string &name="unknown",int cost=0):MapUnit(type,id,name,cost){}
    Jail(const Jail &j):MapUnit(j){}
    virtual ~Jail()=default;
    virtual void Show(std::ostream &os)const override;
    virtual Jail* Clone()const override{return new Jail(*this);}
};
#endif // MAPUNIT__
