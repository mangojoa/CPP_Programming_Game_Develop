#pragma once
// �̷��� ���־���� Creature.h�� ���縦 �� �� �ִ�.
#include <Creature.h>

enum PlayerType {
    PT_Knight = 1,
    PT_Archer = 2,
    PT_Mage = 3
};

/* Player.h ������ Creature.h ������ ���縦 
#include <Creature.h> ���ֱ� ������ �����ϴ����� �𸥴�.
C++ ������ ������ ������ ���������� ���尡 ����Ǳ⿡ ���� 
import(#include)�� ���� ������ �������־�� �Ѵ�. */
class Player : public Creature
{
public:
    /* ���� #include������ �Ѱ�ٸ� ���������� ����� �ް��ִ� ��Ȳ�� ���̴�.
    ������ Player�� �����ڴ� �⺻ �����ڸ� ������� ���ϴ� ��Ȳ�̱⿡ ������ �߻��Ѵ�.
    
    �̸� �ذ��ϱ� ���ؼ��� Creature���� ������ �����ڸ� �����;��Ѵ�. */
    Player(int playerType) : Creature(CT_Player), _playerType(playerType) {

    }

    virtual ~Player() {

    }
    
    virtual void PrintInfo();
protected:
    int _playerType;  
};


/* ���� Ŭ�������� ���� ������� �ʱ� ������
���� �����ص� ������ ���� ��������� .h .cpp�� ���� �����ϴ°� �´�. */
class Knight : public Player {
public:
    /* Ÿ�Ժ�ȯ �����ڸ� ���� ������ ���̱⿡ �̸� �ٷ� �־��ִ� �����ڸ� �������Ѵ�. */
    Knight() : Player(PT_Knight) {
        _hp = 150;
        _attack = 10;
        _defence = 5;
    }
};

class Archer : public Player {
public:
    Archer() : Player(PT_Archer) {
        _hp = 80;
        _attack = 15;
        _defence = 3;
    }
};

class Mage : public Player {
public:
    Mage() : Player(PT_Mage) {
        _hp = 50;
        _attack = 25;
        _defence = 0;
    }
};
