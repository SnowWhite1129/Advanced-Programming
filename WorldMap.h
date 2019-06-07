#ifndef WORLDMAP_H_INCLUDED
#define WORLDMAP_H_INCLUDED
#include "MapUnit.h"
#include <vector>
#include <string>
class WorldMap
{
public:
    bool ReadMapFile();
    void PrintMapFile() const;
    int Size(){return maps.size();}
    std::vector<std::string> &GetMapNameList(){return mapNameList;}
private:
    std::vector<MapUnit*> maps;
    std::vector<std::string> mapNameList;
};

#endif // WORLDMAP_H_INCLUDED
