#include <iostream>
using namespace std;

/* 생성자와 소멸자
* 클래스에 '소속'된 함수들은 맴버 함수하고 한다.
* 이 중에서 됭장히 특별한 함수 2종이 있는데, 바로 [시작]과 [끝]을 알리는 함수들
* - 시작(탄생) -> 생성자 (여러개 존재 가능)
* - 끝(소멸) -> 소멸자 (오직 1개만)
*/

/* [암시적(inplicit) 생성자]
* 생성자를 명시적으로 만들지 않으면
* 아무 인자도 받지 않는 [기본 생성자]가 컴파일러에 의해 자동으로 만들어짐
* -> 그러나 우리가 명시적으로(Explicit)으로 아무 생성자 하나 만들면, 
* 자동으로 만들어지던 [기본 생성자]는 더이상 만들어지지 않는다.
*/

class Knight {

public:
	// 기본 생성자 (인자가 없는 생성자)
	Knight() {
		cout << "Knight() 기본 생성자 호출" << endl;

		_hp = 100;
		_attack = 10;
		_posY = 0;
		_posX = 0;
	}

	// 소멸자
	~Knight() {
		cout << "~Knight() 소멸자 호출" << endl;
	}

	// 복사 생성자
	Knight(const Knight& knight) { // 자기 자신의 클래스 참조 타입을 인자로 받는다.
		// 어쩔 때 사용하는가?

		// 기존에 생성된 객체(k1)이 있다고 가정하자.
		// 일반적으로 똑같은 데이터릴 지닌 객체가 생성되길 기대하는 생성자라고 생각하면 된다.

		_hp = knight._hp;
		_attack = knight._attack;
		_posY = knight._posY;
		_posX = knight._posX;
	}

	/* 이를 실행하면 프로그램이 실행될 때, 종료될 때 나타나고 있다는 것을 알 수 있다.
	* 이들이 어떤 의미를 가지고 있는가?
	* 
	* 생명주기적으로 생각해보면 생성될때 실행괴면 좋은 로직이 존재할 것이다. 이를 생성자에 넣게 된다면 코드가 간결해지고 파악하기 좋을 것이다.
	* 생성자는 여러개가 존재할 수 있다. 특정조건에 따라 다른 값을 받는 생성자를 사용할 수 있다는 것이다.
	* 
	* 생명주기적으로 소멸자는 마지막에서 한번만 실행되면 된다는 것이 정설이다.
	*/

	void Move(int y, int x);
	void Attact();

	void Die() {
		_hp = 0;
		cout << "Die" << endl;
	}
public:
	int _hp;
	int _attack;
	int _posY;
	int _posX;
};

void Knight::Move(int y, int x) {
	_posY = y;
	_posX = x;

	cout << "Move" << endl;
}

void Knight::Attact() {
	cout << "Attact : " << _attack << endl;
}

int main() {
	Knight k1;

	// 복사 생성자를 이용해 k2를 생성해보자
	Knight k2(k1); // k1과 같은 객체를 생성할 것이기에 이렇게 작성한다면 매우 간결하게 같은 객체를 클론할 수 있다는 장점이 돋보인다.

	k1.Move(2, 2);
	k1.Attact();
	k1.Die();
}
