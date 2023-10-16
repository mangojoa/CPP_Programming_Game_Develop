#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <algorithm>


	/* NULL과 0 의 표현
	* 없다는 것을 표현하기 위해서는 0 아니면 null 과 같은 식으로 사용했다.
	*
	* 하지만 이렇게 사용하면 문제가 있다.
	*
	* 우리가 어떤 포인터를 표현하고 싶은데
	* 포인터 자체가 어떤 값도 없을때는 사실상 0이라는 값이 들어가는 것은 맞다.
	*
	* 하지만 타고갈 주소가 없음을 나타내고 있는 값은 0으로 나타난다. */
	int* ptr = NULL; // 0 NULL

	/* NULL를 타고 들어가면 #define NULL 0 이라는 것을 확인할 수 있다.
	 NULL이라는 값은 이 변수가 포인터라는 힌트를 프로그램한테 주기 위한 용도이지
	 사실상 ptr 이라는 변수를 '0'이라는 값으로 놓은 것과 별반 다를바가 없다.

	 NULL = 0 이라는 것이다! */

void Test(int a) {
	cout << "Test(int)" << endl;
}

void Test(void* ptr) {
	cout << "Test(*)" << endl;
}
/* 위의 두 개의 함수가 있다고 가정하자.
각 인자값에 따라 다른 로직이 실행되는 양상으로 보여진다.

하지만 결과값은 상당히 충격적이다. */


int main() {
	int* ptr = NULL; // 0 NULL

	/* 위의 각각의 함수를 실행시킬려고 했을 때, 
	
	*/
	Test(0);
	Test(NULL);

	return 0;
}