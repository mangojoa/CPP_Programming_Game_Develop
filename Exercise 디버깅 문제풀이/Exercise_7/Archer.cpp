#include "Archer.h"
#include "Pet.h"

Archer::Archer()
{
	// �̷� ���� ���� ä�� ����~
	_pet = new Pet();
}

Archer::Archer(int hp) : Player(hp)
{
	// �̷� ���� ���� ä�� ����~
	_pet = new Pet();
}

/* [Ǯ��] 
�ֻ��� Ŭ������ virtual �Լ��� �ٿ��� ������ ���� delete �������� 
Archer::~Archer() {} �Լ��� �Ѿ���� ���� Ȯ�� �� �� �ִ�. */
Archer::~Archer()
{
	// ��ſ��� �� �� :(
	if (_pet != nullptr)
		delete _pet;
}

