#include <iostream>
using namespace std;

/* 클래스 템플릿을 사용해야 하는 경우는?
클래스에 정의한 변수 이외의 값이 추가된다거나 기존에 존재하는 변수의 타입이 다를때, 
클래스를 그때마다 추가하는 작업은 매우 비효율적이다.

이러한 경우에 클래스 템플릿을 이용하면 어떨까?
클래스(설계도) 상에서 변수를 지정하는 부분은 많지 않다. (함수 or 변수가 많은 것일 뿐이다.)
*/

template<typename T> // -> type의 약자인 T 이외에도 다른 템플릿 명을 사용할 수 있다.
class RandomBox {
public:
	T GetRandomData() {
		int idx = rand() % 10;
		return _data[idx];
	}
public:
	T _data[10];
};

int main() {
	
	srand(static_cast<unsigned int>(time(nullptr)));

	RandomBox<int> rb1;

	for (int i = 0; i < 10; i++) {
		rb1._data[i] = i;
	}

	int value1 = rb1.GetRandomData();
	cout << value1 << endl;

	RandomBox<float> rb2;

	for (int i = 0; i < 10; i++) {
		rb2._data[i] = i + 0.5f;
	}

	float value2 = rb2.GetRandomData();
	cout << value2 << endl;


	return 0;
}