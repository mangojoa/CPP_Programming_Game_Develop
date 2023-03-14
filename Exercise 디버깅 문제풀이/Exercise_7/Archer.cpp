#include "Archer.h"
#include "Pet.h"

Archer::Archer()
{
	// 이런 저런 정보 채울 예정~
	_pet = new Pet();
}

Archer::Archer(int hp) : Player(hp)
{
	// 이런 저런 정보 채울 예정~
	_pet = new Pet();
}

/* [풀이] 
최상위 클래스에 virtual 함수를 붙였기 때문에 이제 delete 과정에서 
Archer::~Archer() {} 함수로 넘어오는 것을 확인 할 수 있다. */
Archer::~Archer()
{
	// 즐거웠다 내 펫 :(
	if (_pet != nullptr)
		delete _pet;
}

