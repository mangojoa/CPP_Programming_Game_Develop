#include <iostream>
using namespace std;
#include "Knight.h"
#include "Archer.h"
#include "Mage.h"
#include "Pet.h"

// [Bug Report #8]
// 펫을 궁수의 생성자에서 만드는 것이
// 깔끔하지 않다는 사장님의 지적에 따라
// 일단 밖으로 빼서 펫을 생성하게 수정했습니다.

// 그런데 막상 밖으로 빼니 또 크래시가 납니다.
// 가만히 있으면 중간은 간다던데...
// 뭐가 문제일까요?

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	while (true)
	{
		// 나중엔 궁수, 법사 등 추가 예정
		Player* p = nullptr;

		switch (rand() % 3)
		{
			case 0:
			{
				p = new Knight();
				p->_hp = 100;
				p->_attack = 100;
				break;
			}	
			case 1:
			{
				// 여기서 같이 만들어준다
				// 이런 저런 펫 정보 추가될 예정
				Pet pet;

				/* [풀이] 
				모든 직업의 생성과정을 살펴보면 동적할당을 통해 생성이 진행되는 것을 확인할 수 있다.
				
				이 중 유일하게 pet을 생성하는 과정을 가진 archer의 경우, Pet의 정보를 넘겨주어야 하는데
				이를 실행하고 pet의 메모리 영역을 까보면 컴파일러가 임의로 넣어둔 값이 있다는 것을 알수 있다.

				왜 이런 현상이 발생하는 것인가?
				-> 이는 간단하다 동적할당으로 선언한 곳에 지역변수로 선언한 pet을 넣었기 때문이다.
				이를 포인터로 선언해서 넘겨주어야만 정상적으로 실행이 된다.

				지역변수를 넣었기 때문에 Archer() 생성자에서는 이 값이 유효한 값인지를 알지 못하기에 
				이에 대한 처리가 정상적으로 이루어지지 않고 있음을 브레이크 포인트로 알 수 있다. */



				// Archer를 만들 때 pet 정보도 넘겨준다
				p = new Archer(&pet);
				p->_hp = 100;
				p->_attack = 100;

				break;
			}		
			case 2:
			{
				p = new Mage();
				p->_hp = 100;
				p->_attack = 100;
				break;
			}			
		}

		delete p;
	}

}
