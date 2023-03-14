#include "Player.h"
#include <iostream>
using namespace std;

Player::Player() : _hp(100), _maxHp(100), _attack(10)
{

}


Player::Player(int hp) : _hp(hp), _maxHp(hp), _attack(10)
{
	
}

/* [풀이]
지속적으로 생성하고 이를 삭제하는 구조를 지닌 이 프로젝트의 경우,
삭제하는 과정에서 가장 중요한 부분인 소멸자에 virtual 을 붙이지 않아서 발생한 경우라고 볼 수 있다.

굳이 virtual을 붙이는 이유는 무엇인가?
-> 상속을 받고 있는 클래스의 소멸자를 제대로 찾아가기 위한 방법이라고 보면된다.
이를 붙이지 않는다면 최상위 클래스의 소멸자를 실행하는 것에서 끝난다. 

하지만 virtual을 붙이게 된다면 이는 본래의 타입이 무엇인지를 추적하는 과정을 거치기 때문에 
(virtual 함수의 가상 테이블안에 본래의 타입을 저장해두었기 때문에) 본래 타입의 소멸자를 실행한다.

그렇기에 최상위 클래스의 소멸자라면 항상 virtual 함수를 붙여서 사용하는 것을 잊지말자.

안그러면 이와같은 메모리 누수의 현상을 겪으면서 고달프게 살 수 밖에 없다. */
Player::~Player()
{
	
}


void Player::AddHp(int value)
{
	_hp += value;
	if (_hp < 0)
		_hp = 0;
	if (_hp > _maxHp)
		_hp = _maxHp;
}

bool Player::IsDead()
{
	return (_hp <= 0);
}

int Player::GetAttackDamage()
{
	int damage = _attack;

	if (_maxHp > 0)
	{
		int percentage = (100 * _hp) / _maxHp;
		if (percentage <= 50)
			damage *= 2;
	}

	return damage;
}

void Player::PrintInfo()
{
	cout << "HP: " << _hp << endl;
	cout << "ATT: " << _attack << endl;
}

void Player::OnDamaged(Player* attacker)
{
	if (attacker == nullptr)
		return;
	if (IsDead())
		return;

	// 내 체력 깎는다
	int damage = attacker->GetAttackDamage();
	AddHp(-damage);

	// 반격!
	attacker->OnDamaged(this);
}