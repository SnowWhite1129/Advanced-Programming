#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
#include"gameobject.h"
#include"WorldPlayer.h"
#include"WorldMap.h"
#include"Player.h"
#include<vector>
#include<windows.h>



int main()
{
    /* system("mode con cols=220 lines=300");
     WorldMap worldmap;
     Main_Control c;
     worldmap.ReadMapFile();
     cout<<worldmap[0].GetName();
     c.gmap(worldmap.GetMapNameList());
     go(1,13);
     cout<<"●";

     c.turnback();*/
    WorldMap worldmap;
    Main_Control ctr;
    vector <string> player;
    if(worldmap.ReadMapFile())
    {

        //worldmap.PrintMapFile();
        cout<<"請輸入遊戲人數 :";
        int player_num = 0;
        cin>>player_num;
        if(player_num>4)
        {
            cout<<"人數超過4人 請重填"<<endl;
            cout<<"請輸入遊戲人數 :";
            cin>>player_num;
        }
        system("cls");
        for(int i=0; i<player_num; i++)
        {
            cout<<"Please input player "<<i+1<<" name :";
            string name;
            cin>>name;
            player.push_back(name);
        }
        getchar();
        WorldPlayer worldplayer(player);
        system("mode con cols=220 lines=300");
        ctr.gmap(worldmap.GetMapNameList());
        while(ctr.win(worldplayer,player_num)==false)
        {
            ctr.Kanban(worldplayer,player_num);
            ctr.turnback();
            ctr.printowner(worldmap,worldmap.Size());
            for(int i=0; i<player_num; i++)
            {
                if(worldplayer[i].movable()&&worldplayer[i].money()>0) //can play
                {
                    cout<<"player "<<worldplayer[i].name()<<" roll the dice!!"<<endl;
                    int dice = ctr.roll_dice();
                    ctr.moving(worldplayer[i],dice);
                    worldplayer[i].Move(dice,worldmap.Size());
                    int position = worldplayer[i].location();
                    //cout<<"Wow you are in the "<<worldmap[position].GetName()<<" !!                                     "<<endl;
                    ctr.turnback();
                    //getchar();
                    if(worldmap[position].GetType()=='J') //go to jail
                    {
                        cout<<"you are going to jail for a day!!"<<endl;
                        worldplayer[i].GoToJail();
                        system("pause");
                    }
                    else
                    {
                        if(worldmap[position].GetOwner()==-1) //no one own it  can buy;
                        {
                            cout<<"Do you want spend "<<worldmap[position].GetCost()<<" dollars buying "<<worldmap[position].GetName()<<" ?"<<endl;
                            bool decision = ctr.decide();
                            ctr.eraser();
                            if(decision==true)
                            {
                                if( worldplayer[i].BuyLand( worldmap[position] ) ) //Have enough money??
                                {
                                    cout<<" you buy "<<worldmap[position].GetName()<<"!\n";
                                    ctr.Kanban(worldplayer,player_num);
                                    ctr.printowner(worldmap,worldmap.Size());
                                    system("pause");
                                }
                                else
                                {
                                    cout<<"sorry you do not have enough money!"<<endl;
                                    system("pause");
                                }
                            }
                        }
                        else // someone have already buy it
                        {
                            if(worldmap[position].GetOwner()==worldplayer[i].id()) //its yours unit
                            {
                                switch(worldmap[position].GetType())
                                {
                                case 'U':
                                {
                                    cout<<worldplayer[i].name()<<" ,do you want to upgrade "<<worldmap[position].GetName()<<" to level "<<worldmap[position].GetLevel()+1<<endl;
                                    cout<<"cost you "<<static_cast<Upgradable&>(worldmap[position]).GetUpgradeCost();
                                    bool decision = ctr.decide();
                                    ctr.eraser();
                                    if(decision==true&&worldplayer[i].UpgradeLand(static_cast<Upgradable&>(worldmap[position]) ) ) //uograde
                                    {
                                        cout<<"upgrade success"<<endl;
                                        ctr.Kanban(worldplayer,player_num);
                                        system("pause");

                                    }
                                    else
                                        cout<<"upgrade fail!"<<endl;
                                        system("pause");
                                    break;
                                }
                                default :
                                    break;
                                }
                            }
                            else //not your place
                            {

                                switch(worldmap[position].GetType())
                                {
                                case 'U':
                                {


                                    cout<<"you must pay "<<worldmap[position].GetFine()<<" for "<<worldplayer[worldmap[position].GetOwner()].name()<<endl;
                                    system("pause");
                                    if( worldplayer[i].PayMoney(worldplayer[worldmap[position].GetOwner()],worldmap[position].GetFine()) ==false)
                                    {
                                        cout<<worldplayer[i].name()<<" is Bankrupt"<<endl;
                                        worldplayer[i].Bankrupt();
                                        worldmap.BankRupt(i);
                                    }
                                    break;
                                }
                                case 'C':
                                {
                                    int pay=worldplayer[ worldmap[position].GetOwner() ].num_units()*worldmap[i].GetFine();
                                    cout<<"you must pay "<<pay<<" for "<<worldplayer[worldmap[position].GetOwner()].name()<<endl;
                                    system("pause");
                                    if( worldplayer[i].PayMoney(worldplayer[worldmap[position].GetOwner()],pay) ==false)
                                    {
                                        cout<<worldplayer[i].name()<<" is Bankrupt"<<endl;
                                        worldplayer[i].Bankrupt();
                                        worldmap.BankRupt(i);
                                    }
                                    break;
                                }
                                case 'R':
                                {
                                    int num=ctr.roll_dice();
                                    int pay=num*worldmap[position].GetFine();
                                    cout<<"you must pay "<<pay<<" for "<<worldplayer[worldmap[position].GetOwner()].name()<<endl;
                                    system("pause");
                                    if( worldplayer[i].PayMoney(worldplayer[worldmap[position].GetOwner()],pay) ==false)
                                    {
                                        cout<<worldplayer[i].name()<<" is Bankrupt"<<endl;
                                        worldplayer[i].Bankrupt();
                                        worldmap.BankRupt(i);
                                    }
                                    break;

                                }
                                default :
                                    break;
                                }
                                ctr.Kanban(worldplayer,player_num);
                                ctr.printowner(worldmap,worldmap.Size());

                            }
                        }
                    }
                    ctr.turnback();

                }
                else
                {
                    cout<<worldplayer[i].name()<<" is in jail!!\n";
                    worldplayer[i].ReleaseFromJail();
                }
                ctr.eraser();
            }
        }
        ctr.winner(worldplayer,player_num);
    }
    else
        cout<<"讀取地圖失敗"<<endl;
    return 0;
}

