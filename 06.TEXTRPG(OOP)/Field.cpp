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
            /* �� ���⼭ �÷��̾ ����� ������ �ۼ����� �ʾҴ°�?
            ������ �����ϴ�. �÷��̾ �����ϴ� ������ü�� Field�� �������谡 ���� �����̴�.
            ��, player�� Game.cpp ���� �����ϰ� �ֱ⿡ �ű⿡ �������ִ� ���� �´�.

            �׷��⿡ ���� ���·� ���������� ������ �ش��ϴ� �κ��� Game ���� ���ִ� ���̴�.
             */
            break;
        }

    }
}