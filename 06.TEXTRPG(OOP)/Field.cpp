#include "Field.h"
#include "Player.h"
#include "Monster.h"
#include <stdlib.h>

Field::Field() : _monster(nullptr) {

}

Field::~Field() {
    if (_monster != nullptr) delete _monster;
}

void Field::Update(Player* player) {
    if (_monster == nullptr) CreateMonster();
}

void Field::CreateMonster() {
    int randValue = 1 + rand() % 3;

    switch (randValue)
    {
    case MT_Slime:
        _monster = new Slime();
        break;
    case MT_Orc:
        _monster = new Orc();
        break;
    case MT_Skeleton:
        _monster = new Skeleton();
        break;
    
    }
}

void Field::StartBattle(Player* player) {
    
    while(true) {
        player->PrintInfo();
        _monster->PrintInfo();

        _monster->onAttacked(player);
        if (_monster->isDead()) {
            _monster->PrintInfo();
            delete _monster;
            _monster = nullptr;
            break;
        }

        player->onAttacked(_monster);
        if (player->isDead()) {
            player->PrintInfo();
            /* 왜 여기서 플레이어를 지우는 로직을 작성하지 않았는가?
            이유는 간단하다. 플레이어를 관리하는 로직자체가 Field와 연관관계가 없기 때문이다.
            즉, player는 Game.cpp 에서 관리하고 있기에 거기에 생성해주는 것이 맞다.

            그렇기에 죽은 상태로 돌려보내고 삭제에 해당하는 부분은 Game 에서 해주는 것이다.
             */
            break;
        }

    }
}