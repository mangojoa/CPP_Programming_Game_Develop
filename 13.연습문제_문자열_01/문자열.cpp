#include <iostream>
using namespace std;

/* C++ 에서 문자열 String과 같은 것을 다루기 전에 
* C 스타을의 문자열을 다루는 방법과 함께 연습 문제를 풀어보자. */

// 2. str이라는 문자열의 길이를 반환하는 함수를 만들어보자! (strlen 이라는 함수를 사용하지 않고 진행)
int strLen(const char* str) {
	int count = 0;

	while (str[count] != '\0') {
		count++;
	}

	return count;
}

int main() {

	const int BUF_SIZE = 100;

	char a[BUF_SIZE] = "Hello";
	
	// 1. a의 사이즈를 측정해보자!
	int len = sizeof(a);
	cout << len << endl; // 를 진행하면 이는 BUF_SIZE를 나타내는 것 밖에 못한다.
	// a는 애초에 배열이며 sizeof(a)를 통해서는 a의 배열 사이즈만 알 수 있다.

	// 그럼 실제로 들어있는 값의 길이를 구할때는 어떤 방법을 사용해야 하는가?
	int realLen01 = strlen(a);
	cout << realLen01 << endl; // 이를 통해 배열의 길이가 아닌 배열 안의 실제 값의 길이를 구할 수 있다.

	int realLen02 = strLen(a);
	cout << realLen02 << endl; // int strLen(const char* str) 함수의 값을 출력

}