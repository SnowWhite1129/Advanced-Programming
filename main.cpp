#include <iostream>
#include<vector>
#include<string>
#include "WorldMap.h"
#include "WorldPlayer.h"
#include "MapUnit.h"
#include "Player.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
    std::vector <std::string> name;
    for (int i=0;WorldPlayer::MaxPlayer;++i){
        std::string tmp;
        std::cin >> tmp;
        name.push_back(tmp);
    }

    WorldPlayer mhw(name);

    return 0;
}
