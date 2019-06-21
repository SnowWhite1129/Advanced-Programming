#include "WorldMap.h"
#include <sstream>
#include <fstream>
#include <vector>
#include <iostream>
WorldMap::~WorldMap()
{
    for(auto it=maps.begin();it!=maps.end();it++)
    {
        delete *it;
    }
}
WorldMap& WorldMap::operator=(const WorldMap &wm)
{
    maps.assign(wm.maps.begin(),wm.maps.end());
    mapNameList.assign(wm.mapNameList.begin(),wm.mapNameList.end());
    return *this;
}
bool WorldMap::ReadMapFile(const char filename []) {
    std::ifstream fin;
    fin.open(filename);
    if (!fin){
        std::cout << filename << " not exist!" << std::endl;
        return false;
    }
    else{
        for (int id=0;fin.peek()!=EOF;id++){
            std::string line;
            getline(fin, line);
            std::istringstream iss(line);
            char type;
            iss >> type;
            std::string name;
            iss >> name;
            mapNameList.push_back(name);
            if(type=='J'){
                Jail *j = new Jail(type,id,name,0);
                maps.push_back(j);
                continue;
            }
            int cost=0;
            iss >> cost;
            if(type=='U')
            {
                int upgradeCost=0;
                iss >> upgradeCost;
                std::vector<int> fineList;
                int fine=0;
                while(iss >> fine){
                    fineList.push_back(fine);
                }
                Upgradable *upg = new Upgradable(type,id,name,cost,upgradeCost,fineList);
                maps.push_back(upg);
            }
            else if(type=='C'){
                int fine=0;
                iss >> fine;
                Collectable *col = new Collectable(type,id,name,cost,fine);
                maps.push_back(col);
            }
            else{
                int fine=0;
                iss >> fine;
                RandomCost *ran = new RandomCost(type,id,name,cost,fine);
                maps.push_back(ran);
            }
        }
    }
    fin.close();
    return true;
}
void WorldMap::PrintMapFile() const
{
    for (std::vector<MapUnit*>::const_iterator it=maps.begin();it!=maps.end();++it)
    {
        if((*it)->GetType()=='U')
        {
            std::cout << (*it)->GetType() << " " << (*it)->GetName() << " "<< (*it)->GetCost() << " " << static_cast<Upgradable*>(*it)->GetUpgradeCost();
            for (std::vector<int>::const_iterator it_=static_cast<Upgradable*>(*it)->GetFineList().begin();it_!=static_cast<Upgradable*>(*it)->GetFineList().end();++it_)
            {
                std::cout << " " << *it_;
            }
            std::cout << std::endl;
        }
        else if((*it)->GetType()!='J')
        {
            std::cout << (*it)->GetType() << " " << (*it)->GetName() << " "<< (*it)->GetCost() << " " << (*it)->GetFine() << std::endl;
        }
        else
        {
            std::cout << (*it)->GetType() << " " << (*it)->GetName() << std::endl;
        }
    }
}
