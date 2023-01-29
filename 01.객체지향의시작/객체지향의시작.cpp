#include <iostream>
using namespace std;

// 객체랑 무엇인가?
// 게임으로 치면 게임안의 모든 요소를 개체라고 할 수 있는데
// 각 요소마다 특징을 가지고 있는(?) 혹은 역할을 할 수 있는 것을 객체라고 생각해보자 
// ex) player monster gameroom 등


// Knight를 설계해보자
// - 속성 : hp, attack, y, x 
// - 기능 : move, attack, die

/* 아래의 구조는 class를 만드는 것이라고 보면 된다.
안에 선언한 함수와 변수는 안에서만 유효한 값으로 치부되며, 사용하지 않을 경우에는 메모리를 잡아먹지 않는다.

하지만 이는 이전에 사용한 방식과 조금 다른면이 있다.
void xxxx(); 로 작성한 선언부는 안에서 선언+구현부로 작성해도 문제가 없다. 

하지만 이를 Knight 바깥영역에서 사용하기 위해서는 일반적인 함수 사용법과는 달리 
클래스에 속해 있는 함수 이기에
void Knight::Move(int y, int x) {  } 와 같이 함수의 이름 앞에 클래스명을 작성해주어야 한다는 것이다. */ 

class Knight { // Knight 의 속성과 기능을 만들어보자! 
	// 클래스는 데이터와 동작이 함께 들어있다는 것이 매우 큰 차이점이다.

public:
	// 맴버 함수
	void Move(int y, int x);
	void Attact();

	void Die() {
		hp = 0;
		cout << "Die" << endl;
	}
public:
	// 멤버 변수
	int hp;
	int attack;
	int posY;
	int posX;
};

void Knight::Move(int y, int x) {
	posY = y;
	posX = x;

	cout << "Move" << endl;
}

void Knight::Attact() {
	cout << "Attact : " << attack << endl;
}

/*	기존 우리가 사용한 방식은 전역변수 혹은 스택 메모리에 올라가는 변수를 사용했지만 
	이제는 객체를 이용한 변수를 사용하는 방법을 사용해보자!

	우선적으로 객체를 이용한 변수의 사용은 객체타입의 바구니를 만드는 것에서부터 시작된다.

	기존의 변수를 선언하는 방법처럼 이를 생성하면 된다는 개념이다. 

	[생성해둔 변수이름] [변수이름]; <- 이런 방식으로 객체를 이용한 변수를 생성하면 된다. */

int main() {
	Knight k1;
	k1.hp = 100;
	k1.attack = 10;
	k1.posY = 0;
	k1.posX = 0;

	Knight k2;
	k2.hp = 80;
	k2.attack = 5;
	k2.posY = 1;
	k2.posX = 1;

	// 이렇게 생성해준 객체는 생성한 변수만큼의 독립적인 존재로 생성이 된다.
	// 기존의 방법과는 달리 하나하나에 생명을 불어넣은 개념과 같다는 것이다.

	k1.Move(2, 2);
	k1.Attact();
	k1.Die();
}
