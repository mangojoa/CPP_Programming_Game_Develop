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
T print(T a) { // 여기에는 기존의 타입을 작성하는 것이 아닌 typename T를 작성해주는 것이다.
	// 그럼 모든 인자값을 다 받아줄 수 있는 함수가 된다.
	cout << a << endl;
}

// 인자값이 다수일 때, 
// typename -> class 로 변경하고 작성하면 된다
template <class A, class B>
void println(A, B) {
	cout << A << " " << B << endl;
}

int main() {

	print<int>(10.0f);
	print(1.5f);
	print(1.9);
	print('H');
	/* 함수의 시그니처, 인자값의 수, 로직까지 같은 함수를 여러 개 만든다는 것은 
	사실상 비효율적인 일이나 다름없다. (어떻게 본다면 이는 중복이나 다름없다.)

	그렇기에 이의 '틀'을 만든다는 개념이 바로 '함수 템플릿'이다. */

	int num1 = 3;
	int num2 = 6;
	println(num1, num2);

	float f1 = 10.3;
	float f2 = 17.3;
	println(f1, f2);

	// 위처럼 println 가 다양한 타입의 인자값을 받아도 컴파일러가 오류가 아니라는 것을 증명한다.

	return 0;
}