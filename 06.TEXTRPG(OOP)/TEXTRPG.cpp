#include <iostream>
#include "Game.h"
using namespace std;

int main() {
    srand((unsigned int)time(nullptr));

    Game game;
    game.Init(); // ������ �����ϰ� �Ǵ� �Լ�

    while(true) {
       game.Update(); // �����Ӹ��� ������ ���۽�Ű�� �Լ�
    }

    return 0;
}