#include "Test1.h"
#include <iostream>
using namespace std;

/* xxx.cpp -> ���� ������ϰ� �̸��� ���� cpp ������ �����ϴµ� ���⿡�� ������Ͽ� ������ �Լ��� �����κ�(������)�� �ۼ��Ѵ�.

#include "Test_1.h" �� ���� ��������� ������ �� �ִ�.

���� �����θ� �ۼ��ϸ� �ȴ�. */

void Test_1() {
	Test_2();
};

void Test_2() {
	cout << "Hello World" << endl;
};

void Test_3() {

}