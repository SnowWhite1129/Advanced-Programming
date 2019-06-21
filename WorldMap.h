#ifndef WORLDMAP_H_INCLUDED
#define WORLDMAP_H_INCLUDED
#include "MapUnit.h"
#include <vector>
#include <string>
class WorldMap
{
public:
    WorldMap()=default;
    WorldMap(const WorldMap &wm):maps(wm.GetMaps()),mapNameList(GetMapNameList()){}
    ~WorldMap();
    WorldMap &operator=(const WorldMap &wm);
    bool ReadMapFile(const char filename []);
    void PrintMapFile() const;
    int Size(){return maps.size();}
    std::vector<std::string> &GetMapNameList(){return mapNameList;}
    MapUnit &operator[](int index){return *(maps[index]);}
    const MapUnit &operator[](int index)const{return *(maps[index]);}
    const std::vector<MapUnit*>GetMaps()const{return maps;}
    const std::vector<std::string>GetMapNameList()const{return mapNameList;}
private:
    std::vector<MapUnit*> maps;
    std::vector<std::string> mapNameList;
};

#endif // WORLDMAP_H_INCLUDED
