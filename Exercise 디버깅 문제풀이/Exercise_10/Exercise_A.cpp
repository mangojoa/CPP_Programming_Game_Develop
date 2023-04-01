#include <iostream>
using namespace std;
#include "Knight.h"
#include "Archer.h"
#include "Mage.h"
#include "Pet.h"
#include "Arrow.h"

// [Bug Report #10]
// 궁수라며면 자고로 화살을 쏴야겠죠.
// Arrow는 자신을 목표 대상물을 target으로 관리하고
// Arrow를 만들 때 설정한 데미지 만큼 target의 체력을 깎습니다.
// 테스트를 위해 화살 10개를 생성해서 기사를 피격했는데...
// C++이 늘 그렇지만 되는 일이 없고 또 크래시가 납니다.
// 뭐가 문제일까요?

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
	knight->_attack = 10;
	
	Arrow* arrows[10] = {};
	for (int i = 0; i < 10; i++)
	{
		// 기사를 타겟으로, 궁수의 공격력을 지닌 상태
		Arrow* arrow = new Arrow(knight, archer->_attack);
		arrows[i] = arrow;
	}

	for (int i = 0; i < 10; i++)
	{
		arrows[i]->AttackTarget();
		/* [풀이] User After Free 
		* 대상의 메모리가 로직에 의해 삭제된 이후,
		* 대상 메모리에 접근시, 유효하지 않은 메모리가 되어 
		* 정상적인 로직이 실행되는데 오류를 발생시키는 현상이 일어나고 잇다.
		* 
		* 이는 로직상으로 실행되는 와중에 대상의 메모리를 delete로 
		* 삭제를 진행해서 해당하는 값이 정상적인 값이 아닌 상태가 아니라서
		* 발생하는 문제이다 이런 경우 */

		// 아래의 로직을 바깥으로 이동시켜 로직이 실행된 이후에 진행하는 것이 최우선의 방안이다.
		// 하지만 이는 스마트 포인터 및 고급기술을 익히게 된다면 이는 문제가 간단히 해결된다.
		// 기사가 죽었으면 소멸시켜준다
		if (knight != nullptr)
		{
			if (knight->IsDead())
			{
				delete knight;
				knight = nullptr;
			}
		}	

		delete arrows[i];
		arrows[i] = nullptr;
	}
}
