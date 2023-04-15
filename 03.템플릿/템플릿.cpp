#include <iostream>
using namespace std;

/* C++에서 템플릿은 무엇인가.
템플릿은 C++에서 자료형을 마음대로 가지고 놀수 있는 개념이라고 보면 된다.

함수나 클래스를 개별적으로 다시 작성하지 않아도, 
여러 자료형으로 사용할 수 있도록 하게 만들어 놓은 틀이다.

함수 템플릿 / 클래스 템플릿으로 나뉜다. */

/* 1. 함수 템플릿
C++에서는 다형성의 오버로딩 특성에 의해 함수이름이 같아도 되므로 
template가 없을때는 각각 인자의 타입을 다르게 해서 만들면 된다. */


/* 함수 템플릿을 사용하는 방법
Template 을 사용하게 되면
위와 같이 4개의 함수를 반복해서 작성할 필요가 없어진다. */

// 인자값이 하나일 때,
template <typename T> // 받아줄 인자를 나타내는 typename T ! -> C++ 에서는 class 라고 칭하는 경우도 있다.
void print(T a) { // 여기에는 기존의 타입을 작성하는 것이 아닌 typename T를 작성해주는 것이다.
	// 그럼 모든 인자값을 다 받아줄 수 있는 함수가 된다.
	cout << a << endl;
}

/* 인자값이 다수일 때, 
typename -> class 로 변경하고 작성하면 된다 */
template <class A, class B>
void println(A a, B b) {
	cout << a << " " << b << endl;
}

class Knight {
public:
	// ... 
public:
	int _hp = 100;
};

template<typename C>
void PrintClassInfo(C c) {
	cout << c << endl;

	// 이 코드가 실행될 때, 정상적인 경우가 아니기에 이를 사용할 수 없다. (클래스 인자를 넣었을 경우)
	// 이를 파훼하는 방법은 연산자 오버로딩이 있다.
}

// 연산자 오버로딩 (전역함수 버전)
ostream& operator<<(ostream& os, const Knight& k) {
	os << k._hp;
	return os;
}

/* 특수한 버전에 따른 예외처리가 필요하다고 하자 그럼 이때 템플릿 틀수화가 필요하다. 
이는 [함수 템플릿] 과는 다른 방식으로 사용한다.

template<> 안에 인자값을 정의하지 않고 
기존에 정의한 함수 템플릿의 오버로딩을 하는 개념으로 진핸된다고 보면된다
하지만 오버로딩된 인자의 값을 그대로 사용하는 것이 아닌
다음과 같이 특정 인자값을 넣어주어야 한다. (이외에도 다른 방법을 통해 진행하면 된다.)
*/
template<>
void PrintClassInfo(Knight a) {
	cout << "Knight !!!!!!!!!!!!!!!" << endl;
	cout << a._hp << endl;
}


int main() {

	print<int>(10);
	print(1.5f);
	print(1.9);
	print('H');
	/* 함수의 시그니처, 인자값의 수, 로직까지 같은 함수를 여러 개 만든다는 것은 
	사실상 비효율적인 일이나 다름없다. (어떻게 본다면 이는 중복이나 다름없다.)

	그렇기에 이의 '틀'을 만든다는 개념이 바로 '함수 템플릿'이다. */

	int num1 = 3;
	int num2 = 6;
	println(num1, num2);

	float f1 = 10.3f;
	float f2 = 17.3f;
	println(f1, f2);

	// 위처럼 println 가 다양한 타입의 인자값을 받아도 컴파일러가 오류가 아니라는 것을 증명한다.

	/* --------------------------------------------------------------- */

	Knight k1;
	PrintClassInfo(k1); // <- 지금 이 부분까지만 본다면 에러는 나지 않는 상황이다.
	/* 하지만 빌드를 진행함과 동시에 컴파일이 되지 않는다.
	이유는 무엇인가?
	
	다름아닌 클래스를 템플릿으로 이용할 때, 
	#include <iostream>의 입력 >> / 출력 <<을
	정상적으로 사용할 수 없기 때문이다.

	그렇기에 이는 특수한 전처리 작업을 진행해주어야 한다. */


	

	return 0;
}