#include "Test1.h"
#include <iostream>
using namespace std;

/* xxx.cpp -> 보통 헤더파일과 이름이 같은 cpp 파일을 생성하는데 여기에는 헤더파일에 선언한 함수의 구현부분(구현부)을 작성한다.

#include "Test_1.h" 를 먼저 선언해줘야 진행할 수 있다.

이후 구현부를 작성하면 된다. */

void Test_1() {
	Test_2();
};

void Test_2() {
	cout << "Hello World" << endl;
};

void Test_3() {

}