#pragma once
// 이렇게 해주어야한 Creature.h의 존재를 알 수 있다.
#include <Creature.h>

enum PlayerType {
    PT_Knight = 1,
    PT_Archer = 2,
    PT_Mage = 3
};

/* Player.h 파일은 Creature.h 파일의 존재를 
#include <Creature.h> 해주기 전까지 존재하는지를 모른다.
C++ 에서는 각각의 파일이 독립적으로 빌드가 진행되기에 직접 
import(#include)와 같은 과정을 진행해주어야 한다. */
class Player : public Creature
{
public:
    /* 위의 #include과정을 넘겼다면 정상적으로 상속을 받고있는 상황일 것이다.
    하지만 Player의 생성자는 기본 생성자를 사용하지 못하는 상황이기에 에러가 발생한다.
    
    이를 해결하기 위해서는 Creature에서 생성한 생성자를 가져와야한다. */
    Player(int playerType) : Creature(CT_Player), _playerType(playerType) {

    }

    virtual ~Player() {

    }
    
    virtual void PrintInfo();
protected:
    int _playerType;  
};


/* 아직 클래스마다 양이 방대하지 않기 때문에
같이 선언해도 되지만 양이 방대해지면 .h .cpp를 따로 생성하는게 맞다. */
class Knight : public Player {
public:
    /* 타입변환 생성자를 통해 생성할 것이기에 이를 바로 넣어주는 생성자를 만들어야한다. */
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
