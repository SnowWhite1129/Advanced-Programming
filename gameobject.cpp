#include"gameobject.h"
#include<stdio.h>
#include<string>
#include<iostream>
#include<conio.h>
#include<stdlib.h>

void gotoxy(int xpos, int ypos)
{
    COORD scrn;
    HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
    scrn.X = xpos;
    scrn.Y = ypos;
    SetConsoleCursorPosition(hOuput,scrn);
}
void go(int x,int y)
{
    gotoxy(x,y);
}
void setcolor(int fg)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole,fg);
}
void Main_Control:: dice(const int dice1) const//色子
{
    int x=71,y=20;
    switch(dice1)
    {
    case 1:
        gotoxy(x,y+1);
        printf("╭--------------╮");
        gotoxy(x,y+2);
        printf("│              │");
        gotoxy(x,y+3);
        printf("│              │");
        gotoxy(x,y+4);
        printf("│              │");
        gotoxy(x,y+5);
        printf("│      ●      │");
        gotoxy(x,y+6);
        printf("│              │");
        gotoxy(x,y+7);
        printf("│              │");
        gotoxy(x,y+8);
        printf("│              │");
        gotoxy(x,y+9);
        printf("╰--------------╯");
        break;
    case 2:
        gotoxy(x,y+1);
        printf("╭--------------╮");
        gotoxy(x,y+2);
        printf("│              │");
        gotoxy(x,y+3);
        printf("│      ●      │");
        gotoxy(x,y+4);
        printf("│              │");
        gotoxy(x,y+5);
        printf("│              │");
        gotoxy(x,y+6);
        printf("│              │");
        gotoxy(x,y+7);
        printf("│      ●      │");
        gotoxy(x,y+8);
        printf("│              │");
        gotoxy(x,y+9);
        printf("╰--------------╯");
        break;
    case 3:
        gotoxy(x,y+1);
        printf("╭--------------╮");
        gotoxy(x,y+2);
        printf("│              │");
        gotoxy(x,y+3);
        printf("│  ●          │");
        gotoxy(x,y+4);
        printf("│              │");
        gotoxy(x,y+5);
        printf("│      ●      │");
        gotoxy(x,y+6);
        printf("│              │");
        gotoxy(x,y+7);
        printf("│          ●  │");
        gotoxy(x,y+8);
        printf("│              │");
        gotoxy(x,y+9);
        printf("╰--------------╯");
        break;
    case 4:
        gotoxy(x,y+1);
        printf("╭--------------╮");
        gotoxy(x,y+2);
        printf("│              │");
        gotoxy(x,y+3);
        printf("│  ●      ●  │");
        gotoxy(x,y+4);
        printf("│              │");
        gotoxy(x,y+5);
        printf("│              │");
        gotoxy(x,y+6);
        printf("│              │");
        gotoxy(x,y+7);
        printf("│  ●      ●  │");
        gotoxy(x,y+8);
        printf("│              │");
        gotoxy(x,y+9);
        printf("╰--------------╯");
        break;
    case 5:
        gotoxy(x,y+1);
        printf("╭--------------╮");
        gotoxy(x,y+2);
        printf("│              │");
        gotoxy(x,y+3);
        printf("│  ●      ●  │");
        gotoxy(x,y+4);
        printf("│              │");
        gotoxy(x,y+5);
        printf("│      ●      │");
        gotoxy(x,y+6);
        printf("│              │");
        gotoxy(x,y+7);
        printf("│  ●      ●  │");
        gotoxy(x,y+8);
        printf("│              │");
        gotoxy(x,y+9);
        printf("╰--------------╯");
        break;
    case 6:
        gotoxy(x,y+1);
        printf("╭--------------╮");
        gotoxy(x,y+2);
        printf("│              │");
        gotoxy(x,y+3);
        printf("│  ●      ●  │");
        gotoxy(x,y+4);
        printf("│              │");
        gotoxy(x,y+5);
        printf("│  ●      ●  │");
        gotoxy(x,y+6);
        printf("│              │");
        gotoxy(x,y+7);
        printf("│  ●      ●  │");
        gotoxy(x,y+8);
        printf("│              │");
        gotoxy(x,y+9);
        printf("╰--------------╯");
        break;
    }
}

int Main_Control:: roll_dice()const
{
    for(int i=0; i<6; i++ )
    {
        int num = rand()%6+1;
        dice(num);
        Sleep(100);
    }
    int num = rand()%6+1;
    dice(num);
    turnback();
    return num;
}

void Main_Control:: gmap(const std::vector<std::string> &NameList)const
{
    using namespace std;
    string name[20];
    string buffer[20];
    for(int i=0; i<20; i++)
    {
        buffer[i]="          ";
        name[i]="          ";
    }
    for(int i=0; i<20; i++)
    {
        for(int j=0; NameList[i][j]!='\0'; j++)
        {
            if(j<9)
            {
                name[i][j+1]=NameList[i][j];
            }
            if(j>=9&&j<18)
            {
                buffer[i][j-9+1]=NameList[i][j];
            }
        }
    }

    gotoxy(0,2);
    cout<<"┌──────────┬──────────┬──────────┬──────────┬──────────┐──────────┬\n";
    for(int i=0; i<6; i++)
        cout<<"│"<<name[i];
    cout<<"│"<<endl;
    //cout<<"│"<<name[0]<<"│宗哲的家  │維也納森  │          │師大科技  │    C209  │\n";
    //printf("│          │          │          │          │          │          │\n");
    for(int i=0; i<6; i++)
        cout<<"│"<<buffer[i];
    cout<<"│"<<endl;
    printf("│          │          │          │          │          │          │\n");
    printf("│          │          │          │          │          │          │\n");
    printf("│          │          │          │          │          │          │\n");
    printf("├──────────┴──────────┴──────────┴──────────┴──────────┤──────────┤\n");
    //printf("│光頭老的車│                                           │師大數學  │\n");
    cout<<"│"<<name[19]<<"│                                           │"<<name[6]<<"│\n";
    cout<<"│"<<buffer[19]<<"│                                           │"<<buffer[6]<<"│\n";
    //printf("│          │                                           │          │\n");
    printf("│          │                                           │          │\n");
    printf("│          │                                           │          │\n");
    printf("│          │                                           │          │\n");
    printf("├──────────┤                                           ├──────────┤\n");
    //printf("│欣田的小吃│                                           │          │\n");
    //printf("│          │                                           │~機 會~   │\n");
    cout<<"│"<<name[18]<<"│                                           │"<<name[7]<<"│\n";
    cout<<"│"<<buffer[18]<<"│                                           │"<<buffer[7]<<"│\n";
    printf("│          │                                           │          │\n");
    printf("│          │                                           │          │\n");
    printf("│          │                                           │          │\n");
    printf("├──────────┤                                           ├──────────┤\n");
    printf("│          │                                           │          │\n");
    //printf("│~機 會~   │                                           │gggggggggg│\n");
    //printf("│          │                                           │草皮      │\n");
    cout<<"│"<<name[17]<<"│                                           │"<<name[8]<<"│\n";
    cout<<"│"<<buffer[17]<<"│                                           │"<<buffer[8]<<"│\n";
    printf("│          │                                           │          │\n");
    printf("│          │                                           │          │\n");
    printf("├──────────┤                                           ├──────────┤\n");
    //printf("│科技工程院│                                           │分部操場  │\n");
    //printf("│          │                                           │          │\n");
    cout<<"│"<<name[16]<<"│                                           │"<<name[9]<<"│\n";
    cout<<"│"<<buffer[16]<<"│                                           │"<<buffer[9]<<"│\n";
    printf("│          │                                           │          │\n");
    printf("│          │                                           │          │\n");
    printf("│          │                                           │          │\n");
    printf("├──────────┼──────────┬──────────┬──────────┬──────────┼──────────┤\n");
    //printf("│second flo│貴萬麵鋪  │誠正中庭  │修老大課  │  E201    │          │\n");
    //printf("│        or│          │          │決定不來  │          │*命 運*   │\n");
    for(int i=15; i>=10; i--)
        cout<<"│"<<name[i];
    cout<<"│"<<endl;
    for(int i=15; i>=10; i--)
        cout<<"│"<<buffer[i];
    cout<<"│"<<endl;
    printf("│          │          │          │          │          │          │\n");
    printf("│          │          │          │          │          │          │\n");
    printf("│          │          │          │          │          │          │\n");
    printf("└──────────┴──────────┴──────────┴──────────┴──────────┴──────────┘\n");
}

enum ArrowKey { keyENTER = 13, keyESC = 27, keyUP = 72, keyDOWN = 80, keyLEFT = 75, keyRIGHT = 77  };
enum ForegroundColor {fgBLACK = 0, fgNORMAL = 7, fgGRAY, fgBLUE, fgGREEN, fgCYAN, fgRED, fgPINK, fgYELLOW, fgWHITE};
void Main_Control:: Kanban( const WorldPlayer &worldplayer,const int n)const //記錄版
{
    int x=14,y=10,i,j,color=0;
    gotoxy(x,y);
    printf("---------------------------------------");
    gotoxy(x,y+1);
    printf("|        玩  家  狀  態  看  版       |");
    gotoxy(x,y+2);
    printf("---------------------------------------");
    gotoxy(x,y+3);
    printf("|顏  色|  名  稱  | 總 資 產 | 狀  態 |");
    gotoxy(x,y+4);
    printf("---------------------------------------");
    for(i=0; i<=n; i++)
    {
        gotoxy(x,y+5+i);
        printf("|      |          |          |        |");
        setcolor(fgRED+i-1);
        gotoxy(x+2,y+5+i);
        printf("●");
        setcolor(fgWHITE);
    }
    gotoxy(x,y+4+i);
    printf("---------------------------------------");
    for(j=0; j<n; j++)
    {
        gotoxy(x+8,y+5+j);
        std::cout<<worldplayer[j].name();//名子
    }
    for(j=0; j<n; j++)
    {
        gotoxy(x+19,y+5+j);
        if(worldplayer[j].money()>=0)
            std::cout<<worldplayer[j].money();
        else
            printf("0");//money
    }
    for(j=0; j<n; j++)
    {
        gotoxy(x+30,y+5+j);
        if(worldplayer[j].money()>0)
            printf("存在");
        else
            printf("破產");//sataus
    }
    turnback();
}
void Main_Control:: turnback()const
{
    gotoxy(0,39);
}
void Main_Control:: map_position(const int pos,int *x,int *y)
{
    if(pos>=0&&pos<=5)
    {
        *x=pos*11+1;
        *y=7;
    }
    if(pos>=6&&pos<=10)
    {
        *x=56;
        *y=13+(pos-6)*6;
    }
    if(pos>=11&&pos<=15)
    {
        *x=45-(pos-11)*11;
        *y=37;
    }
    if(pos>=16&&pos<=19)
    {
        *x=1;
        *y=31-(pos-16)*6;
    }
}
bool Main_Control::win(WorldPlayer &worldplayer,const int n) const
{
    int count = 0;
    for(int i=0; i<n; i++)
    {
        if(worldplayer[i].money()>0)
            count++;
    }
    if(count>1)
        return false;
    else
        return true;
}
bool Main_Control:: decide() const
{
    bool count;
    char d;

    do
    {
        gotoxy(0,41);
        printf(">是   否  ");
        d=getch();
        count=true;
        if(d==keyRIGHT)
        {
            gotoxy(0,41);
            printf("是   >否  ");
            count=false;
            d=getch();
        }
    }
    while (d !=keyENTER);
    gotoxy(0,41);
    printf("               \n");
    return count;
}
void Main_Control:: moving(const Player &player,const int n)
{
    using namespace std;
    int x,y;
    map_position(player.location(),&x,&y);
    go(x+player.id()*2,y);
    cout<<"  ";
    setcolor(fgRED+(player.id())-1);
    int i=player.location()+1,j=n;
    while(j--)
    {
        map_position(i,&x,&y);
        go(x+player.id()*2,y);
        cout<<"●";
        Sleep(300);
        go(x+player.id()*2,y);
        cout<<"  ";
        i=(i+1)%20;
    }
    go(x+player.id()*2,y);
        cout<<"●";
        turnback();
        setcolor(fgWHITE);
}
void Main_Control::eraser() const
{
    turnback();
    std::cout<<"                                                             "<<std::endl;
    std::cout<<"                                                             "<<std::endl;
    std::cout<<"                                                             "<<std::endl;
    std::cout<<"                                                             "<<std::endl;
    turnback();
}
void Main_Control:: winner(const WorldPlayer &worldplayer,const int n) const
{
    for(int i=0;i<n;i++)
    {
        if(worldplayer[i].money()>0)
        {
            system("cls");
            std::cout<<"The winner is .........> "<<worldplayer[i].name();
            break;
        }
    }
}
void Main_Control::printowner(const WorldMap &worldmap,const int n)
{
    for(int i=0;i<n;i++)
    {
        int x,y;
        map_position(i,&x,&y);
        y--;
        gotoxy(x,y);
        if(worldmap[i].GetOwner()==-1)
        {
            setcolor(fgWHITE);
        }
        else setcolor(fgRED+worldmap[i].GetOwner()-1);
        std::cout<<"  owner";
        setcolor(fgWHITE);
    }
    turnback();
}

