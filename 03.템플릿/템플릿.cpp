#include <iostream>
using namespace std;

void Print(int a) {
	cout << a << endl;
}

void Print(float a) {
	cout << a << endl;
}

void Print(double a) {
	cout << a << endl;
}

void Print(const char* a) {
	cout << a << endl;
}

/* C++에서 템플릿은 무엇인가.
템플릿은 C++에서 자료형을 마음대로 가지고 놀수 있는 개념이라고 보면 된다.

함수나 클래스를 개별적으로 다시 작성하지 않아도, 
여러 자료형으로 사용할 수 있도록 하게 만들어 놓은 틀이다.

함수 템플릿 / 클래스 템플릿으로 나뉜다. */

/* 1. 함수 템플릿
C++에서는 다형성의 오버로딩 특성에 의해 함수이름이 같아도 되므로 
template가 없을때는 각각 인자의 타입을 다르게 해서 만들면 된다.

*/


int main() {


	
	return 0;
}