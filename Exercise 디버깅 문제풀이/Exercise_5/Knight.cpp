#include "Knight.h"
#include <iostream>
using namespace std;

// [사양서] 기본값 Hp=100, Attack=10
Knight::Knight() : _hp(100), _maxHp(100), _attack(10)
{

}

Knight::Knight(int hp) : _hp(hp), _maxHp(hp), _attack(10)
{

}

Knight::~Knight()
{

}

void Knight::AddHp(int value)
{
	_hp += value;
	if (_hp < 0)
		_hp = 0;
	if (_hp > _maxHp)
		_hp = _maxHp;
}

bool Knight::IsDead()
{
	return (_hp <= 0);
}

/* [풀이] 0xC0000094: Integer division by zero. 해당 부분에서 문제가 발생하고 있다. */
int Knight::GetAttackDamage()
{
	// hp 50% 이하 => maxHp / hp가 2 이상
	int damage = _attack;

	if (_maxHp == 0)return damage;
	int percentage = (_hp / _maxHp) * 100;
	
	if (percentage <= 50) {
		damage *= 2;
	}

	// int ratio = _maxHp / _hp; // _hp값이 /를 진행할 당시 0이라는 값으로 진행이 되는 것을 확인
	// 나누기를 진행할 때, 0을 나눈다는 것은 사사리상 말이 안되는 소리이다.	
	//if (ratio > 2)
	//	damage *= 2;

	return damage;
}

void Knight::PrintInfo()
{
	cout << "HP: " << _hp << endl;
	cout << "ATT: " << _attack << endl;
}