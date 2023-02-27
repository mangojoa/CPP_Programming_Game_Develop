#pragma once

/* 게임을 만들다보면 공통적으로 사용되는 변수는 참 다양하지만 저마다 다른 능력치를 가지고 생성된다. 
하지만 그렇다고 해서 이를 따로 생성하게 될 경우는 하지말자. 매우 난잡해질 뿐더러 
관리하기가 매우 어려워진다.

항상 이런 문제에 봉착하게 된다면 공통적인 부분을 최대한 추출하여 상위 단계의 클래스를 만들자. */

enum CreatureType {
    CT_Player = 0,
    CT_Monster = 1
};

/* 구현부는 .cpp 파일에서 진행하고 
여기서는 선언만 간단하게 진행한다. */
class Creature
{
public:
    Creature(int creatureType)
     : _creatureType(creatureType), _hp(0), _attack(0), _defence(0) {

    }
    
    /* 소멸자는 virtual로 선언해줘야 한다는 것을 잊지 말자. */
    virtual ~Creature() {

    }

    virtual void PrintInfo() = 0;

    void onAttacked(Creature* attacker);
    bool isDead() { return _hp <= 0; }

/* 이 변수에 직접적으로 접근하는 것은 매우 위험하다.
그렇기에 객체지향적 프로그래밍에 준수하여
Get/Set 문법을 통해 만들어보도록 하자. */
protected:
    int _creatureType;
    int _hp;
    int _attack;
    int _defence;
};

