#include <iostream>
#include "Game.h"
using namespace std;

int main() {
    Game game;
    game.Init(); // ������ �����ϰ� �Ǵ� �Լ�

    while(true) {
       game.Update(); // �����Ӹ��� ������ ���۽�Ű�� �Լ�
    }

    return 0;
}