#include "Knight.h"
#include <iostream>
using namespace std;

// [사양서] 기본값 Hp=100, Attack=10
Knight::Knight() : _hp(100), _attack(10)
{

}

// 이 생성자에는 [_attack] 값이 정상적으로 부여되지 않고 있기에
// 컴파일러가 메모리 영역에 임시로 넣어둔 값 -> 영역구분을 위해 넣어둔 값을
// 출력하고 있다. 그렇기에 _attack을 추가하면 해당 현상을 사라지게 된다.
Knight::Knight(int hp) : _hp(hp), _attack(10)
{

}

Knight::~Knight()
{

}

void Knight::PrintInfo()
{
	cout << "HP: " << _hp << endl;
	cout << "ATT: " << _attack << endl;
}