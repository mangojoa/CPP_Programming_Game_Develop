#include <iostream>
using namespace std;

/* 함수 객체 (Functor) : 함수처럼 동작하는 객체
함수 포인터 완전히 동일한 시그니처로만 동작하는 단점이 존재한다
하지만 함수 포인터의 단점을 보완할 수 있는 방법이 함수 객체이다. */

void HelloWorld() {
	cout << "Hello World!!" << endl;
}

// 함수처럼 동작하는 객체 -> 함수 객체
class Functor {
public:
	void operator() () {
		cout << "Functor Test" << endl;
		cout << _value << endl;
	}

	bool operator() (int num) {
		cout << "Functor Test" << endl;
		_value += num;
		cout << _value << endl;

		return true;
	}

private:
	int _value = 0;
};

class MoveTask {
public:
	void operator() () {
		cout << "해당 좌표로 플레이어 이동!!" << endl;
	}
public: 
	int _playerId;
	int _posX;
	int _posY;
};

int main() {

	/* 기존의 함수 포인터의 경우 동작을 넘겨줄때 유용한 면이 돋보였다
	하지만 함수 포인터의 단점 
	1. 시그니처가 안 맞으면 사용할 수 없다. */
	void (*pfunc)(void);
	pfunc = &HelloWorld;
	(*pfunc)();

	/* 2. 상태를 가질 수 없다.
	일반적으로 클래스를 만들 때, 데이터와 동작(함수)을 동시에 들고 있을 수 있다.

	클래스의 동작은 상태를 나타내는데 이를 가지고 있을 수 없다는 개념으로 생각하면 된다.

	하지만 함수 객체를 사용하게 된다면 이러한 단점을 극복할 수 있다는 것이다. */
	HelloWorld();

	// 함수 객체를 사용해보자!!
	// () 연산자 오버로딩
	Functor functor;

	functor(); // -> 오버로딩을 통해 작성된 함수
	// -> 이 함수가 기존의 함수 포인터와 무엇이 다른것인가?
	// 동작을 하는데 있어 차이가 없으나 상태값을 지닐 수 있다는 점이 큰 차이로 나타난다.

	bool ret = functor(3);

	// 엄청난 코드를 작성해서 사용하는 것이 아닌 기존에 배운 연산자 오버로딩을 통해서 
	// 만들어진 개념이라고 보면된다.
	// 
	// 객체지향적인 문법을 통해 함수처럼 동작하게끔 함수 객체를 만드는 개념이라고 할 수 있다.

	// 그럼 어디서 사용하게 되는가 ? -> mmorpg에서 서버를 다루는데 많이 사용된다.
	// 네트워크 통신이 이루어지는 과정에서 사용되는 개념이라고 보면된다.

	// ex) 클라 : 나 (5, 0) 좌표로 이동시켜줘! <- 이 부분이 100,000 건이 동시에 진행된다면?
	// 이를 순자적으로 처리할 수 있도록 만들어주면 주문하는 시점과 처리하는 시점, 즉 분리하는 시점을 나눌 수 있다는 것이다.

	MoveTask task; // <- 이동했다는 주문 영역!

	task._playerId = 100;
	task._posX = 5;
	task._posY = 0;

	task(); // <- 처리하는 영역!

	// 이 둘을 합해서 커멘드 패턴 이라는 전문적인 언어로 통용된다.



	return 0;

}