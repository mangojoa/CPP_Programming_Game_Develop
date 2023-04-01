#include <iostream>
using namespace std;
#include "Knight.h"
#include "Archer.h"
#include "Mage.h"
#include "Pet.h"

// [Bug Report #9]
// 궁수가 죽으면 펫도 같이 죽는 사양이 추가되었습니다.
// 그런데 왜 프로그램도 같이 죽는걸까요?
// 이유를 찾아서 고쳐주세요!

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	Archer* archer = new Archer(new Pet());
	archer->_hp = 100;
	archer->_maxHp = 100;
	archer->_attack = 20;

	Knight* knight = new Knight();	
	knight->_hp = 150;
	knight->_maxHp = 150;
	knight->_attack = 100;
	
	int damage = knight->GetAttackDamage();
	archer->AddHp(-damage);

	delete archer;
	/* [풀이] _pet이 두번 delete가 진행되고 있는 상황이라는 것이다.
	상황을 살펴본다면
	
	AddHp 에서 delete _pet; 에서 진행되고 있다.

	하지만 delete Archer; 를 진행하게 되면 안에 _pet != nullptr 이라면 
	delete _pet; 을 진행하도록 코드가 설계되어있는데 이는 _pet에 올바르지 못한 메모리 영역값을 가지고 있어

	이를 delete 하려는 시도 때문에 에러가 나는 것을 확인 할 수 있다.


	꼭 해당 포인터의 데이터를 삭제하고 나서 nullptr을 상황에 맞게 지정해줘야 문제를 줄일 수 있다.
	*/
	delete knight;
}
