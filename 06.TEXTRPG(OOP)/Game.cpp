#include "Game.h"
#include "Player.h"
#include "Monster.h"
#include "Field.h"
#include <iostream>
using namespace std;

/* Game이 실행될 때, 플레이어에 대한 포인터는 우선 nullptr로 넣어준다. */
Game::Game() : _player(nullptr), _field(nullptr) {

};

Game::~Game() {
    if (_player != nullptr) delete _player;
    if (_field != nullptr) delete _field;
};

void Game::Init() {
    _field = new Field();
}

void Game::Update() {
    if (_player == nullptr) CreatePlayer();

    /* player를 관리하는 Game에서 메모리 삭제를 진행해야 한다. */
    if (_player->isDead()) {
        delete _player;
        _player = nullptr;
        // 그리고 새로운 플레이어를 만들어 주어야 한다.
        CreatePlayer();
    }

    _field->Update(_player);
}

void Game::CreatePlayer() {
    while (_player == nullptr) {
        cout << "------------------" << endl;
        cout << "캐릭터를 생성해주세요!" << endl;
        cout << "[1]칼잡이 [2]활잡이 [3]힘찍은법사" << endl;
        cout << "------------------" << endl;

        cout << " > ";
        int input = 0;
        cin >> input;

        if (input == PT_Knight) _player = new Knight();
        else if (input == PT_Archer) _player = new Archer();
        else if (input == PT_Mage) _player = new Mage();
    }
}