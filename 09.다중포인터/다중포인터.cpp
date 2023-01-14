#include <iostream>
using namespace std;

/* 다중포인터에 대하여 (n차포인터)
기존의 포인터를 이용해서 원본값을 바꿀 수 있다는 것을 배울 수 있었다.

하지만 이는 빙산의 일각에 불과했다....

우선적으로 아래의 setMessagee(msg);를 살펴보면 이는 const char* msg의 값을
변경하는 함수가 진행하려는 것을 알 수 있다. 

하지만 이를 실행하면 변경되지 않는다. (어째서 인가....)

이유는 간단하다. const char* msg라고 선언되었기에 스택프레임이 실행된다고 해서 바뀌지 않는다고 보면된다. 
즉, setMessage(const char* a)가 진행된 이후 종료 될 때, setMessage(const char* a)에서 진행된 것은 무효가 된다고 보면된다.
(이는 포인터를 배우기전 const int a = 1; 이라는 숫자를 바꾸기 위해 함수를 진행한 것과 같은 원리이다.)

이를 해결할 수 있는 방법이 무엇인가....?

우리는 포인터의 포인터를 이용하면 되는 것이다!!!! (다중 포인터)
*/

void setMessage(const char* a) { // 포인터를 사용해 넘겼지만 원본의 값을 바꾸지 못한 함수
	a = "Bye";
}

void setMessage(const char** a) { // 다중포인터를 사용해 원본의 값을 바꾸는 함수
	*a = "Bye";
}

void setMessage2(const char*& a) { // 다중포인터를 사용해 원본의 값을 바꾸는 함수 (참조버전)
	a = "Wow";
}

int main() {

	const char* msg = "Hello";

	// [매개변수][RET][지역변수(msg( Hello주소 )]
	setMessage(msg);

	const char** pp = &msg;

	// .rdata Hello주소[H][e][l][l][o][\0] 
	// msg[ Hello주소 ] << 8바이트
	// pp[ &msg ] << 8바이트
	// [매개변수][RET][지역변수(msg( Hello주소 ))][매개변수(a(&msg msg의 주소))][RET][지역변수]
	setMessage(&msg);

	/* 실제로 2차 포인터 이상으로 사용되는 경우는 많이 없다. (있다면 문제가 있다는 것이다.)
	* 2차 포인터를 사용하는 개념을 정리하면 포인터의 기존 주소를 접근하는게 아니라 
	* 포인터 자체의 주소를 참조하는 것이다.
	* 
	* 쉽게 이야기하면 양파까기라고 생각하면 된다.
	* *을 하나씩 까면서 타고 간다고 생각하면 편하다는 것이다.
	* *을 하나씩 타고 이동할때마다 주소로 접근된다고 생각하면 된다는 것이다. */

	// [매개변수][RET][지역변수(msg( Hello주소 ))][매개변수(a(&msg msg의 주소))][RET][지역변수]
	setMessage2(msg);

	return 0;
}