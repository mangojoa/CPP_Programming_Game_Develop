#include "Game.h"
#include "Player.h"
#include "Monster.h"
#include "Field.h"
#include <iostream>
using namespace std;

/* Game�� ����� ��, �÷��̾ ���� �����ʹ� �켱 nullptr�� �־��ش�. */
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

    /* player�� �����ϴ� Game���� �޸� ������ �����ؾ� �Ѵ�. */
    if (_player->isDead()) {
        delete _player;
        _player = nullptr;
        // �׸��� ���ο� �÷��̾ ����� �־�� �Ѵ�.
        CreatePlayer();
    }

    _field->Update(_player);
}

void Game::CreatePlayer() {
    while (_player == nullptr) {
        cout << "------------------" << endl;
        cout << "ĳ���͸� �������ּ���!" << endl;
        cout << "[1]Į���� [2]Ȱ���� [3]����������" << endl;
        cout << "------------------" << endl;

        cout << " > ";
        int input = 0;
        cin >> input;

        if (input == PT_Knight) _player = new Knight();
        else if (input == PT_Archer) _player = new Archer();
        else if (input == PT_Mage) _player = new Mage();
    }
}