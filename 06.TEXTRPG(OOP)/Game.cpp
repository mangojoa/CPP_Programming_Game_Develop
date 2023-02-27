#include "Game.h"
#include "Player.h"
#include <iostream>
using namespace std;

/* Game이 실행될 때, 플레이어에 대한 포인터는 우선 nullptr로 넣어준다. */
Game::Game() : _player(nullptr) {

};

Game::~Game() {

};

void Game::Init() {

}

void Game::Update() {
    if (_player == nullptr) CreatePlayer();
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