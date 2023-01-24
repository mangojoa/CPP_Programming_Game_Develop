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

// 4. 문자열 덧붙이기 함수
char* strCat(char* dest, char* src) {
	// int len = strLen(dest);

	// int i = 0;
	// while (src[i] != '\0') {
	// 	dest[len + i] = src[i];
	// 	i++;
	// }

	// dest[len + i] = '\0';

	// return dest;

	// pointer 를 이용하는 방법
	char* ret = dest;

	while(*dest != '\0') { dest++; }

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';

	return ret;
	
}

// 5. 두 문자열을 비교하는 함수
int strCmp(char* a, char* b) {
	int value;

	int i = 0;
	while (a[i] != '\0' || b[i] != '\0') {
		if (a[i] > b[i]) return 1;
		if (a[i] < b[i]) return -1;
	}

	return 0;
}

// 6. 문자열을 뒤집는 함수
void ReverseStr(char* str) {
	int len = strLen(str);

	for (int i = 0; i< len / 2; i++) {
		int temp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = temp;
	}

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
	//strcpy(b, a);

	// 문자열 복사 함수를 사용한 배열 복사
	strCpy(b, a);

	char c[BUF_SIZE] = "Hello";
	char d[BUF_SIZE] = "World";

	/* 문자열을 덧붙이는 함수 strcat(dest, src);
	src의 문자열을 dest에 붙이는 개념의 함수이다 
	dest의 마지막 요소인 '\0'에 붙여넣어 이어지게 만드는 함수라고 볼 수 있으며 
	'\0'의 함수 자체을 새롭게 갱신도 하는 개념이다. */
	strcat(d, c);

	// 문자열을 덧붙이는 함수 strCat(dest, src);
	strCat(d, c); 

	/* 문자열 중 같은 요소가 있는지 확인하는 함수 strcmp(a, b);
	우선적으로 a와 b에는 같은 값이 들어가 있다. 그런데 이를 왜 비교하는거야 ???
	if (a == b) { logic } 만 하면 간단한 일이 아닌가?

	이를 C를 배우면서 가장 헷갈리게 할 수 있는 부분이라고 할 수 있다.
	우선 적으로 a와 b는 배열 형태의 문자열이며 a와 b의 자체만으로 메모리의 시작 주소를 나타낸다고 할 수 있다.

	if (a == b) 를 진행하면 각자의 값을 비교하는 것이 아는 메모리 주소를 비교하는 것이 되버려 같지 않다는 결과만 출력하게 될것이 뻔하다.
	즉, 내용물은 같다할 지라도 저장된 위치가 다르기 때문이라는 것이 크게 작용하는 사례이다.

	그리고 추가적으로 비교하려는 문자열의 길이가 같아야한다는 것이 가장 큰 문제이다.
	문자열의 길이가 서로 다르다면 값은 당연히 다르다고 나오기 때문이다.

	이는 한글자씩 비교하는 것이 정석으로 통한다. */ 
	int value = strcmp(a, b);
	/* ?? 왜 이를 받는 인자값이 int로 받아주는 것인가? strcmp() 함수는 반환값이 int 이기 때문이다.

	왜 int형을 반환해야 하는 원리로 작동하는가? => 이유는 간단하다. 
	컴퓨터는 문자열을 그대로 저장하지 않고 이를 아스키 코드의 형태로 저장하고 비교하기 때문에 
	비교값들 끼리 비교했을때, 값의 크기에 따라 숫자를 반환하는 것이 기준으로 되어있어 int 형을 반환하는 것이다. */

	// 두 문자열을 비교하는 함수 strCmp(a, b);
	int value01 = strCmp(a, b);
	cout << value01 << endl;

	// revuese String 문자뒤집기 함수 !
	ReverseStr(b);

	return 0;

}