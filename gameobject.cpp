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
void Main_Control:: dice(const int dice1) const//��l
{
    int x=71,y=20;
    switch(dice1)
    {
    case 1:
        gotoxy(x,y+1);
        printf("�~--------------��");
        gotoxy(x,y+2);
        printf("�x              �x");
        gotoxy(x,y+3);
        printf("�x              �x");
        gotoxy(x,y+4);
        printf("�x              �x");
        gotoxy(x,y+5);
        printf("�x      ��      �x");
        gotoxy(x,y+6);
        printf("�x              �x");
        gotoxy(x,y+7);
        printf("�x              �x");
        gotoxy(x,y+8);
        printf("�x              �x");
        gotoxy(x,y+9);
        printf("��--------------��");
        break;
    case 2:
        gotoxy(x,y+1);
        printf("�~--------------��");
        gotoxy(x,y+2);
        printf("�x              �x");
        gotoxy(x,y+3);
        printf("�x      ��      �x");
        gotoxy(x,y+4);
        printf("�x              �x");
        gotoxy(x,y+5);
        printf("�x              �x");
        gotoxy(x,y+6);
        printf("�x              �x");
        gotoxy(x,y+7);
        printf("�x      ��      �x");
        gotoxy(x,y+8);
        printf("�x              �x");
        gotoxy(x,y+9);
        printf("��--------------��");
        break;
    case 3:
        gotoxy(x,y+1);
        printf("�~--------------��");
        gotoxy(x,y+2);
        printf("�x              �x");
        gotoxy(x,y+3);
        printf("�x  ��          �x");
        gotoxy(x,y+4);
        printf("�x              �x");
        gotoxy(x,y+5);
        printf("�x      ��      �x");
        gotoxy(x,y+6);
        printf("�x              �x");
        gotoxy(x,y+7);
        printf("�x          ��  �x");
        gotoxy(x,y+8);
        printf("�x              �x");
        gotoxy(x,y+9);
        printf("��--------------��");
        break;
    case 4:
        gotoxy(x,y+1);
        printf("�~--------------��");
        gotoxy(x,y+2);
        printf("�x              �x");
        gotoxy(x,y+3);
        printf("�x  ��      ��  �x");
        gotoxy(x,y+4);
        printf("�x              �x");
        gotoxy(x,y+5);
        printf("�x              �x");
        gotoxy(x,y+6);
        printf("�x              �x");
        gotoxy(x,y+7);
        printf("�x  ��      ��  �x");
        gotoxy(x,y+8);
        printf("�x              �x");
        gotoxy(x,y+9);
        printf("��--------------��");
        break;
    case 5:
        gotoxy(x,y+1);
        printf("�~--------------��");
        gotoxy(x,y+2);
        printf("�x              �x");
        gotoxy(x,y+3);
        printf("�x  ��      ��  �x");
        gotoxy(x,y+4);
        printf("�x              �x");
        gotoxy(x,y+5);
        printf("�x      ��      �x");
        gotoxy(x,y+6);
        printf("�x              �x");
        gotoxy(x,y+7);
        printf("�x  ��      ��  �x");
        gotoxy(x,y+8);
        printf("�x              �x");
        gotoxy(x,y+9);
        printf("��--------------��");
        break;
    case 6:
        gotoxy(x,y+1);
        printf("�~--------------��");
        gotoxy(x,y+2);
        printf("�x              �x");
        gotoxy(x,y+3);
        printf("�x  ��      ��  �x");
        gotoxy(x,y+4);
        printf("�x              �x");
        gotoxy(x,y+5);
        printf("�x  ��      ��  �x");
        gotoxy(x,y+6);
        printf("�x              �x");
        gotoxy(x,y+7);
        printf("�x  ��      ��  �x");
        gotoxy(x,y+8);
        printf("�x              �x");
        gotoxy(x,y+9);
        printf("��--------------��");
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
    cout<<"�z�w�w�w�w�w�w�w�w�w�w�s�w�w�w�w�w�w�w�w�w�w�s�w�w�w�w�w�w�w�w�w�w�s�w�w�w�w�w�w�w�w�w�w�s�w�w�w�w�w�w�w�w�w�w�{�w�w�w�w�w�w�w�w�w�w�s\n";
    for(int i=0; i<6; i++)
        cout<<"�x"<<name[i];
    cout<<"�x"<<endl;
    //cout<<"�x"<<name[0]<<"�x�v�����a  �x���]�Ǵ�  �x          �x�v�j���  �x    C209  �x\n";
    //printf("�x          �x          �x          �x          �x          �x          �x\n");
    for(int i=0; i<6; i++)
        cout<<"�x"<<buffer[i];
    cout<<"�x"<<endl;
    printf("�x          �x          �x          �x          �x          �x          �x\n");
    printf("�x          �x          �x          �x          �x          �x          �x\n");
    printf("�x          �x          �x          �x          �x          �x          �x\n");
    printf("�u�w�w�w�w�w�w�w�w�w�w�r�w�w�w�w�w�w�w�w�w�w�r�w�w�w�w�w�w�w�w�w�w�r�w�w�w�w�w�w�w�w�w�w�r�w�w�w�w�w�w�w�w�w�w�t�w�w�w�w�w�w�w�w�w�w�t\n");
    //printf("�x���Y�Ѫ����x                                           �x�v�j�ƾ�  �x\n");
    cout<<"�x"<<name[19]<<"�x                                           �x"<<name[6]<<"�x\n";
    cout<<"�x"<<buffer[19]<<"�x                                           �x"<<buffer[6]<<"�x\n";
    //printf("�x          �x                                           �x          �x\n");
    printf("�x          �x                                           �x          �x\n");
    printf("�x          �x                                           �x          �x\n");
    printf("�x          �x                                           �x          �x\n");
    printf("�u�w�w�w�w�w�w�w�w�w�w�t                                           �u�w�w�w�w�w�w�w�w�w�w�t\n");
    //printf("�x�Y�Ъ��p�Y�x                                           �x          �x\n");
    //printf("�x          �x                                           �x~�� �|~   �x\n");
    cout<<"�x"<<name[18]<<"�x                                           �x"<<name[7]<<"�x\n";
    cout<<"�x"<<buffer[18]<<"�x                                           �x"<<buffer[7]<<"�x\n";
    printf("�x          �x                                           �x          �x\n");
    printf("�x          �x                                           �x          �x\n");
    printf("�x          �x                                           �x          �x\n");
    printf("�u�w�w�w�w�w�w�w�w�w�w�t                                           �u�w�w�w�w�w�w�w�w�w�w�t\n");
    printf("�x          �x                                           �x          �x\n");
    //printf("�x~�� �|~   �x                                           �xgggggggggg�x\n");
    //printf("�x          �x                                           �x���      �x\n");
    cout<<"�x"<<name[17]<<"�x                                           �x"<<name[8]<<"�x\n";
    cout<<"�x"<<buffer[17]<<"�x                                           �x"<<buffer[8]<<"�x\n";
    printf("�x          �x                                           �x          �x\n");
    printf("�x          �x                                           �x          �x\n");
    printf("�u�w�w�w�w�w�w�w�w�w�w�t                                           �u�w�w�w�w�w�w�w�w�w�w�t\n");
    //printf("�x��ޤu�{�|�x                                           �x�����޳�  �x\n");
    //printf("�x          �x                                           �x          �x\n");
    cout<<"�x"<<name[16]<<"�x                                           �x"<<name[9]<<"�x\n";
    cout<<"�x"<<buffer[16]<<"�x                                           �x"<<buffer[9]<<"�x\n";
    printf("�x          �x                                           �x          �x\n");
    printf("�x          �x                                           �x          �x\n");
    printf("�x          �x                                           �x          �x\n");
    printf("�u�w�w�w�w�w�w�w�w�w�w�q�w�w�w�w�w�w�w�w�w�w�s�w�w�w�w�w�w�w�w�w�w�s�w�w�w�w�w�w�w�w�w�w�s�w�w�w�w�w�w�w�w�w�w�q�w�w�w�w�w�w�w�w�w�w�t\n");
    //printf("�xsecond flo�x�Q�U�ѾQ  �x�ۥ����x  �x�צѤj��  �x  E201    �x          �x\n");
    //printf("�x        or�x          �x          �x�M�w����  �x          �x*�R �B*   �x\n");
    for(int i=15; i>=10; i--)
        cout<<"�x"<<name[i];
    cout<<"�x"<<endl;
    for(int i=15; i>=10; i--)
        cout<<"�x"<<buffer[i];
    cout<<"�x"<<endl;
    printf("�x          �x          �x          �x          �x          �x          �x\n");
    printf("�x          �x          �x          �x          �x          �x          �x\n");
    printf("�x          �x          �x          �x          �x          �x          �x\n");
    printf("�|�w�w�w�w�w�w�w�w�w�w�r�w�w�w�w�w�w�w�w�w�w�r�w�w�w�w�w�w�w�w�w�w�r�w�w�w�w�w�w�w�w�w�w�r�w�w�w�w�w�w�w�w�w�w�r�w�w�w�w�w�w�w�w�w�w�}\n");
}

enum ArrowKey { keyENTER = 13, keyESC = 27, keyUP = 72, keyDOWN = 80, keyLEFT = 75, keyRIGHT = 77  };
enum ForegroundColor {fgBLACK = 0, fgNORMAL = 7, fgGRAY, fgBLUE, fgGREEN, fgCYAN, fgRED, fgPINK, fgYELLOW, fgWHITE};
void Main_Control:: Kanban( const WorldPlayer &worldplayer,const int n)const //�O����
{
    int x=14,y=10,i,j,color=0;
    gotoxy(x,y);
    printf("---------------------------------------");
    gotoxy(x,y+1);
    printf("|        ��  �a  ��  �A  ��  ��       |");
    gotoxy(x,y+2);
    printf("---------------------------------------");
    gotoxy(x,y+3);
    printf("|�C  ��|  �W  ��  | �` �� �� | ��  �A |");
    gotoxy(x,y+4);
    printf("---------------------------------------");
    for(i=0; i<=n; i++)
    {
        gotoxy(x,y+5+i);
        printf("|      |          |          |        |");
        setcolor(fgRED+i-1);
        gotoxy(x+2,y+5+i);
        printf("��");
        setcolor(fgWHITE);
    }
    gotoxy(x,y+4+i);
    printf("---------------------------------------");
    for(j=0; j<n; j++)
    {
        gotoxy(x+8,y+5+j);
        std::cout<<worldplayer[j].name();//�W�l
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
            printf("�s�b");
        else
            printf("�}��");//sataus
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
        printf(">�O   �_  ");
        d=getch();
        count=true;
        if(d==keyRIGHT)
        {
            gotoxy(0,41);
            printf("�O   >�_  ");
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
        cout<<"��";
        Sleep(300);
        go(x+player.id()*2,y);
        cout<<"  ";
        i=(i+1)%20;
    }
    go(x+player.id()*2,y);
        cout<<"��";
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

