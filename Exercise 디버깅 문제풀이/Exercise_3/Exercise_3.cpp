#include <iostream>
using namespace std;
#include "Knight.h"

// [Bug Report #3]
// 우여곡절 끝에 버그#1, #2가 해결된 것으로 판단됩니다.
// 이제 데미지 피격 실험을 해보기 위해
// Knight1의 스탯을 (100/10)으로,
// Knight2의 스탯을 (2000/200)으로 올렸습니다.
// Knight2가 Knight1를 한방에 처치해야 하는데...
// 왜일까요? 죽었다는 로그가 뜨지 않습니다.
// 문제 원인을 파악해서 수정해주세요!

int main()
{
	Knight* k1 = new Knight();
	k1->_hp = 100;
	k1->_attack = 10;

	Knight* k2 = new Knight();
	k2->_hp = 2000;
	k2->_attack = 200;

	/* [풀이] k2이 k1를 쉽게 죽일 수 있을 만큼의 _attack값을 가지고 있는데 
	* 이를 실행하면 k1은 살아있다고 출력이 되고있는 상황이다.
	* 
	* 분명 캐릭터의 죽음을 관장하는 함수가 문제가 있을 것이라 판단된다.
	* IsDead() 함수를 살펴본다면 이는 다름아닌 
	* return (_hp == 0) 이라는 값으로 되어있는데 
	* 
	* 이는 매우 큰 문제를 야기할 수 밖에 없다.
	* 
	* 1. damage 값 > hp값 일 경우, _hp를 0으로 바꿔주는 로직이 존재했다면 
	* IsDead()는 정상적으로 작동했을 것이다. 
	* 
	* 하지만 여기서는 _hp를 0으로 처리하는 로직이 존재하지 않기에 IsDead()에서 이를 처리해주어야 한다.
	* return (_hp <= 0);이라고 하면 정상적으로 처리가 된다.
	
	*/
	int damage = k2->_attack;
	k1->AddHp(-damage);

	if (k1->IsDead())
	{
		cout << "죽었습니다!" << endl;
	}
	else
	{
		cout << "엥? 살았습니다!" << endl;
	}

	delete k1;
	delete k2;
}
