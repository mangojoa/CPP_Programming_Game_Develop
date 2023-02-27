#include <iostream>
#include "Game.h"
using namespace std;

int main() {
    Game game;
    game.Init(); // 게임을 시작하게 되는 함수

    while(true) {
       game.Update(); // 프레임마다 게임을 동작시키는 함수
    }

    return 0;
}