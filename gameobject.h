#ifndef GAMEOBJECT_H_INCLUDED
#define GAMEOBJECT_H_INCLUDED
#include<windows.h>
#include<time.h>
#include <vector>
#include<string>
#include"Player.h"
#include"WorldPlayer.h"
#include"WorldMap.h"
class Main_Control
{

public:
     int roll_dice() const;
     void gmap(const std::vector<std::string> &NameList) const;
     void Kanban(const WorldPlayer &worldplayer,const int n ) const;
     void turnback() const;//back to console place
     void moving(const Player &player,const int n);
     bool win(WorldPlayer &worldplayer ,const int n) const;
     bool decide() const;
     void eraser() const;
     void winner(const WorldPlayer &worldplayer,const int n) const;
     void printowner(const WorldMap &worldmap,const int n);
private:
    void dice(const int dice1) const;
    void map_position(const int pos,int *x,int *y);
};
void go(int x,int y);


#endif // GAMEOBJECT_H_INCLUDED
