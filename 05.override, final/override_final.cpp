#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

class Player {
public:
	void Attack() {
		cout << "Player!!" << endl;
	}
};

class Knight : public Player {
public:

	// 재정의(override) 된 개념이라고 보면 된다.
	void Attack() {
		cout << "Knight!!" << endl;
	}

};

int main() {

	/* override, final
	* 이는 가상함수와 연관이 매우 큰 부분이다. (객체지향의 꽃? 이라고 한다.)
	*/

	// Knight 에서 만든 Attack을 사용하는 개념
	Knight* k = new Knight();
	k->Attack();

	/*	class Knight : public Player (상속)의 개념이 사용되었기에!
		이는 Knight 에서 만든 Attack을 사용하지 않을까?
		(그렇게 생각했다면 문제가 크다... )
		-> 이는 다름아닌 Player* 타입의 포인터이기 때문에 Knight 가 아닌 Player의 Attack이 실행된다.
	*/
	Player* p = new Knight();
	p->Attack();

	/* 위의 상황을 해결하기 위해서는 어떻게 해야하는 걸까? (이미 이전에 배웠다.)
	상속해주는 Player 의 함수는 가상함수(virtual function)으로 작성되어야 한다는 것을 잊어서는 안된다.

	하지만 한가지 알아두어야 한다. 
	최상단 클래스가 virtual function 으로 작성한 함수는 상속되더라도 가상함수에 해당한다.

	그렇다면 우리는 어디서부터 virtual function 이 진행된 것인지 알 필요가 있을까?
	-> 이는 당연하게도 알아야한다.
	
	이를 알아야하는 이유를 알아보자.

	우선적으로 아래의 코드 상황이라고 하자. */

	{
		class Creature01 {
		public:
			virtual void Attack() {}
		};

		class Player01 : public Creature01 {
		public:
			void Attack() {}
		};

		class Knight01 : public Player01 {
		public:
			void Attack() {}
		};


		Creature01* c = new Knight01();
		c->Attack();

	}

	/* 아래로 상속된 모든 Attack() 함수에는 virtual 속성이 붙어있다고 봐도 된다.
    위의 코드를 볼때 Creature 가 최상단에 해당하기에 virtual(가상함수)의 시작이다.

	하지만 이제 다음과 같이 바뀐다면 어떻게 될까 ? */ 
	{
		class Creature01 {
		};

		class Player01 : public Creature01 {
		public:
			virtual void Attack() {}
		};

		class Knight01 : public Player01 {
		public:
			void Attack() {}
		};


		Creature01* c = new Knight01();
		c->Attack(); // <- 신기하게도 이 코드는 이전과 달리 사용할 수 없는 것이 확인된다.

		/* 위의 코드 영역과 다른 점
		1. 최상단 클래스의 virtual function을 삭제했다는 것
		2. virtual function의 시작점이 바뀌었다는 것 

		이 두가지로 인해 기존 TEXTRPG에서 사용되었던 개념의 코드가 정상적으로 작동하지 않는 모습을 볼 수 있다.

		*/
	}

	return 0;
}