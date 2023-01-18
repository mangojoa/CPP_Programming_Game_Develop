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

#pragma warning(disable: 4996)
// 3. 문자열 복사 함수
void strCpy(char* dest, char* src) {
	
	/*int count = 0;
	
	bool ready = true;
	
	while (ready) {
		dest[count] = src[count];
		cout << dest[count] << endl;
		if (src[count] == '\0') ready = false;

		count++;
	}
	
	return dest;
	*/

	// 포인터를 이용하는 방법
	while (*src != '\0') {

		// *dest++ = *src++; 으로도 가능하다.
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
}


int main() {

	const int BUF_SIZE = 100;

	char a[BUF_SIZE] = "Hello";
	char b[BUF_SIZE];
	
	// 1. a의 사이즈를 측정해보자!
	int len = sizeof(a);
	cout << len << endl; // 를 진행하면 이는 BUF_SIZE를 나타내는 것 밖에 못한다.
	// a는 애초에 배열이며 sizeof(a)를 통해서는 a의 배열 사이즈만 알 수 있다.

	// 그럼 실제로 들어있는 값의 길이를 구할때는 어떤 방법을 사용해야 하는가?
	int realLen01 = strlen(a);
	cout << realLen01 << endl; // 이를 통해 배열의 길이가 아닌 배열 안의 실제 값의 길이를 구할 수 있다.

	int realLen02 = strLen(a);
	cout << realLen02 << endl; // int strLen(const char* str) 함수의 값을 출력

	// b = a; // <- 배열을 일반적인 변수를 복사하는 것처럼 진행할 순 없다. (메모리의 첫 번째 값을 나타내고 있으며 이는 복사가 안되기 때문이다.)

	/* 문자열을 복사하는 함수 strcpy()
	이 함수의 경우 두 개의 인자값을 받으며 첫 번째 인자값에 두 번째 인자값을 복사한다는 의미이다.
	하지만 이는 아~!~~~주 오래된 함수라서 위험성이 매우 높으며 컴파일러에 따라 오류를 출력하는 경우가 있다.
	그럼에도 불구하고 사용하고 싶다면 #pragma warning(disable: 4996) 이라는 문을 int main() {} 전에 선언하면 사용할 수 있다.

	strcpy_s() 라는 함수도 있다 (strcpy()의 안정성이 높아진 버전의 함수라고 볼 수 있다.) */

	// strcpy()
	strCpy(b, a);


	return 0;

}