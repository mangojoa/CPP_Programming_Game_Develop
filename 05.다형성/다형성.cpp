#include <iostream>
using namespace std;

/* 객체지향 (Object Oriented Programming)
- 상속성
- 은닉성
- 다형성 등이 존재한다. */

/* 다형성(Polymorphism) = 겉은 똑같은데, 기능이 다르게 동작한다.
- 오버로딩(Overloading) = 함수 중복 정의 = 함수 이른의 재사용
- 오버라이딩(Overriding) = 재정의 = 부모 클래스의 함수를 자식 클래스에서 재정의
*/

class Player {
public:
	void Move() { cout << "Move Player!!" << endl; }

	// 가상함수 사용하기
	virtual void VMove() { cout << "Move Player!!" << endl; }
public: 
	int _hp;
};

class Knight : public Player {
public:
	void Move() { cout << "Move Knight!!" << endl; }
	virtual void VMove() { cout << "Move Player!!" << endl; }
public:
	int _stamina;
};

class Mage : public Player {
public:
	void Move() { cout << "Move Mage!!" << endl; }
public:
	int _mp;
};

void MovePlayer(Player* player) {
	player->Move();
}

/* 이전까지 각 객체마다 함수를 따로 정의하고 사용했었다.

사실 이렇게 사용한다면 이는 객체지향을 사용하는 의미가 없다 
void MovePlayer(Player *player) {}
void MoveKnight(Knight *knight) {} 이렇게 사용하게 될때 재밌는 현상을 하나 확인할 수 있다.

1. (최)상위 클래스는 하위 클래스를 인자로 받는 함수를 사용하지 못한다.
상위 클래스 = 플레이어
하위 클래스 = 평민, 귀족, 왕족 이라는 가정이 있다고 하자

MovePlayer(Player* player);
MoveAristocrat(Aristocrat* aristocrat);
MoveRoyalty(Royalty* royalty);

위와 같은 함수가 존재할 때, 

MovePlayer(&aristocrat); 귀족은 플레이어인가? -> true
귀족은 플레이어라는 범위에 속한 개념이기에 이는 성립이 되며 상속받은 상위 클래스를 인자값으로 받는 함수를 사용할 수 있다.

MoveAristocrat(&player); 플레이어는 귀족인가? -> false
하지만 하위 클래스를 인자값으로 받는 함수의 경우 상위 클래스를 인자값으로 넣을 경우, 에러가 발생하게 된다.
=> 플레이어가 귀족인가? 귀족 혹은 왕족일 수 있기에 이에 대한 답은 false가 출력된다.

상위 클래스는 누구에게 자신의 특성 및 기능을 상속하는지 알 수 없다.
하지만 하위 클래스는 내가 누구의 특성과 기능을 상속받고 있는지를 알 수 있기에 가능한 것이다.

위의 사례로 알 수 있는 것은 
(최)상위 클래스를 활용한 함수를 만든다면 이는 상속받은 하위 클래스 전부가 사용할 수 있기에 코드를 작성하는 효율을 높일 수 있다.
(이게 바로 객체지향의 장점이다!) */

int main() {
	Knight k;
	/* 바로 이 경우가 하위 클래스의 인자값을 통해서 상위 클래스의 인자값을 받는 함수를 실행하는 부분이다.
	하지만 이를 실행하게 된다면 어떤 함수가 실행이 되는 걸까?
	
	void Move() { cout << "Move Player!!" << endl; }
	void Move() { cout << "Move Knight!!" << endl; }
	해당 부분 중 하나는 실행되지만 어떤 부분이 실행되어도 말은 될 수 있다.
	그러나 우리가 원하는 부분이 void Move() { cout << "Move Knight!!" << endl; } 라면 이야기는 달라진다.
	
	이는 왜 그런것인가?
	바인딩(Binding) 때문이다.
	정적 바인딩 : 컴파일 시점에 결정
	동적 바인딩 : 실행 시점에 결정

	1. 일반 함수는 정적바인딩을 사용한다.
	-> 컴파일 시점에서 MovePlayer(Player* player);라는 함수는 인자값이 뭐인지 알 수 없다.
	MovePlayer(&k); 으로 Knight의 객체를 넘겨주었음에도 불구하고 이는 Knight->Move(); 함수를 실행할 수 없다.

	컴파일을 진행하면서 MovePlayer(Player* player);라는 함수는 이미 Player* player로 묶여있기 때문에 
	어떤 값을 넣더라도 이는 하위 객체에 재정의된 함수를 사용할 수 없다.

	2. 그럼 동적 바인딩을 사용한다면 달라지는가? (virtual function)
	*/
	MovePlayer(&k);

}