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

int Knight::GetAttackDamage()
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

void Knight::PrintInfo()
{
	cout << "HP: " << _hp << endl;
	cout << "ATT: " << _attack << endl;
}

void Knight::OnDamaged(Knight* attacker)
{
	if (attacker == nullptr)
		return;

	// 내 체력 깎는다
	int damage = attacker->GetAttackDamage();
	AddHp(-damage);

	// 이 로직의 문제는 반격을 마무리하는 로직이 없다는 것이다.
	if (damage == 0) return;
	if (IsDead()) return;

	// 반격!
	attacker->OnDamaged(this);

	/* [풀이]
	가장 큰 문제는 stack overflow가 발생한다는 것인데 
	함수가 제귀함수(자기 자신을 호출하는 구조)로 되어있다면 지속적으로 
	스택 영역의 메모리를 사용하게 되므로 프로그램이 뻗어버리게 된다는 것이다. */
}