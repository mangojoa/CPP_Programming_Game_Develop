#include <iostream>
using namespace std;

/* 클래스 템플릿을 사용해야 하는 경우는?
클래스에 정의한 변수 이외의 값이 추가된다거나 기존에 존재하는 변수의 타입이 다를때, 
클래스를 그때마다 추가하는 작업은 매우 비효율적이다.

이러한 경우에 클래스 템플릿을 이용하면 어떨까?
클래스(설계도) 상에서 변수를 지정하는 부분은 많지 않다. (함수 or 변수가 많은 것일 뿐이다.)
*/

// template<typename T> // -> type의 약자인 T 이외에도 다른 템플릿 명을 사용할 수 있다.

/* 기존과 달리 인자값이 2개인 템플릿을 만들었다고 하자.
이때 추가된 int SIZE = 10 은 클래스 안에서 사용될 변수에 해당된다.

하지만 이는 어디까지나 초기값을 설정한 것일 뿐, 들어오는 인자값은 호출되는 것에 따라 결과가 달라진다.
(이 결과는 인자값으로 인한 return이 아닌 클래스가 생성되는 과정에서의 결과를 의미한다.) */
template<typename T, int SIZE = 10>
class RandomBox {
public:
	T GetRandomData() {
		int idx = rand() % SIZE;
		return _data[idx];
	}
public:
	T _data[SIZE];
};

/* 클래스 템플릿 또한 템플릿 특수화의 개념이 존재한다.
우선 클래스 안에서 사용되는 인자값 및 반환값이 특정 타입일때 '템플릿 특수화'를 사용한다.

예를 들어 double 타입이 예외적으로 만들어지는 경우가 있다면 아래와 같이 작성되어야한다.
template<[명시된 타입], 기존인자값> 

여기서는 예시로 위와 같이 설명하였으나 이는 실전에서 다르게 나타날 가능성이 매우 많기에 값보다는 
공통된 template<class ~~, typename ~~, ... > 등을 확인하자.
*/
template<int SIZE>
class RandomBox<double, SIZE> {
public:
	double GetRandomData() {
		int idx = rand() % SIZE;
		return _data[idx];
	}
public:
	double _data[SIZE];
};


int main() {
	
	srand(static_cast<unsigned int>(time(nullptr)));

	/* template<typename T, int SIZE = 10>
	위의 템플릿을 지정한 상태에서 초기값을 지정하지 않는다면 SIZE 값은 10이 된다.

	하지만 지정한다면 여기서 다른 결과가 나오게 된다.

	RandomBox<int, 10> rb1;

	RandomBox<int, 20> rb2;  이 두개의 클래스 객체는 생성이 된 직후, 

	rb1 = rb2; 를 진행하게 된다면 일치하지 않는다고 나온다.
	그 이유는 받아주는 인자값(int SIZE)에 따라 달라진 결과라고 볼 수 있는 부분이다.

	인자값(int SIZE)가 같았다면 rb1 = rb2; 는 정상적으로 통과가 진행되었을 것이다. */



	RandomBox<int, 10> rb1;

	for (int i = 0; i < 10; i++) {
		rb1._data[i] = i;
	}

	int value1 = rb1.GetRandomData();
	cout << value1 << endl;

	RandomBox<int, 20> rb2;

	for (int i = 0; i < 10; i++) {
		rb2._data[i] = i + 0.5;
	}

	float value2 = rb2.GetRandomData();
	cout << value2 << endl;


	return 0;
}