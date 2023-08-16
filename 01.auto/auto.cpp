#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Knight {
public:
	int _hp;
};

int main() {

	// Modern C++ (C++ 11)

	/*int a = 3;
	float b = 3.14f;
	double c = 1.23;
	Knight d = Knight();
	const char* e = "dusan";*/

	auto a = 3;
	auto b = 3.14f;
	auto c = 1.23;
	auto d = Knight();
	auto e = "dusan";

	// auto 는 일종의 조커카드 같은 개념이다.
	// 형식 연역(type deduction)
	// -> 말이 되게 잘 맞춰보려무나~~~ (추론을 해야하는 개념으로 보면 된다.)
	// 프로그렘이 복잡해질수록 추론하기가 어려워 질 수 있다. 

	auto f = &d;
	const auto test1 = b;
	const auto* test2 = e; // 사실 변수에 마우스를 가져다 대면 타입을 알 수 있다.

	// auto 가 모든 것을 커버할 수 있는 것은 아니다. 
	// 어느정도 말이 되어야 이를 커버해주는 개념이라고 보면된다.

	// auto* test3 = d; 라고 한다면 컴파일러는 에러를 떨어트릴 것이다.
	// 이는 auto 의 대상 타입이 추론할 수 없는 경우 이기에 그런 것이다.

	// !주의
	// 기본 auto 는 const, & 를 무시한다.
	int& ref = a;
	const int cst = a;

	auto test1 = ref;
	auto test2 = cst; 
	// 이렇게 앞서 선언한 값의 타입을 따라가지 않는 것이 기본옵션이다.
	// 이를 따라가게 하기 위해서는 어떻게 해야할까?
	auto& test3 = ref;
	const auto test4 = cst;
	// 앞서 정의한 타입과 같이 auto를 선언해주면 된다. (생각보다 간단하다.)

	// 기존의 타압은 잊어버리고 auto만 사용하는 것은 어떤가?
	// 절대로 추천하지 않는다.
	// -> 모든 타입을 auto로 선언하게 되면 '가독성'이 떨어지게 된다. 
	// 어떤 타입인지 알아야 얼마만큼의 메모리를 차지하는지에 대한 부분을 알기 쉽지 않기 때문이다.
	
	// 그럼에도 불구하고 auto를 배우는 이유는 무엇이냐?
	// 타이핑이 길어지는 경우에 사용한다는 개념이다. 

	map<int, int> m;
	auto m = m.insert(make_pair(1, 100));

	vector<int> v;

	// vector<int>::iterator 를 생략!
	for (auto it = v.begin(); it != v.end(); ++it) {
		cout << *it << endl;
	}

	// make_pair(_Ty1&& _Val1, _Ty2&& _Val2) 와 같이 반환 타입의 길이가 매우긴 시간을 단축하기 위해 
	// auto를 사용한다고 보면된다. (시간절약의 개념이라는 것이다 -> 나아가 가독성을 높이는 효과도 볼 수 있기에)



	return 0;
}