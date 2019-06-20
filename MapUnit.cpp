#include"MapUnit.h"
void MapUnit::Show(std::ostream &os)const
{
    os<<name_<<" type="<<type_<<", id="<<id_<<", owner="<<owner_<<", cost="<<cost_;
}
std::ostream& operator <<(std::ostream &os,const MapUnit &mu)
{
    mu.Show(os);
    return os;
}
void Upgradable::Show(std::ostream &os)const
{
    MapUnit::Show(os);
    os<<", level="<<level_<<", upgradeCost="<<upgradeCost_<<", find=";
    for(auto it=fineList_.begin();it!=fineList_.end();it++)
    {
        os<<*it<<" ";
    }
    os<<std::endl;
}
void Collectable::Show(std::ostream &os)const
{
    MapUnit::Show(os);
    os<<fine_<<std::endl;
}
void Collectable::SetOwner(int playerID)
{
    MapUnit::SetOwner(playerID);
    playerCollected_[playerID]+=1;
}
int Collectable::playerCollected_[maxPlayers]={};
void RandomCost::Show(std::ostream &os)const
{
    MapUnit::Show(os);
    os<<fine_<<std::endl;
}
void Jail::Show(std::ostream &os)const
{
    MapUnit::Show(os);
    os<<std::endl;
}
