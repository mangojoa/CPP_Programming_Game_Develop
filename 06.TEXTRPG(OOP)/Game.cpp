#include "Game.h"
#include "Player.h"
#include <iostream>
using namespace std;

/* Game�� ����� ��, �÷��̾ ���� �����ʹ� �켱 nullptr�� �־��ش�. */
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