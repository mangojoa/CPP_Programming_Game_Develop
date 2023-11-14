#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

/* 오른값(rvalue) 참조와 std::move
* 
* lvalue(왼값) / rvalue(오른값) 이란 무엇인가?
* 
* - lvalue : 단일식을 넘어서 계속 지속되는 개체
* - rvalue : lvalue가 아닌 나머지 (임시 값, 열거형, 람다, i++ 등) */

class Knight {
public:

public:
	int _hp = 100;
};

/* void TestKnight_Copy(Knight knight) {  }
위의 방식의 경우, Knight 클래스가 복사 생성자를 통해서 진행되는 프로세스이다.

위의 로직 안에서 무슨 일을 진행하더라도 원본 k1에는 어떤 영향도 줄 수 없으며 

Knight 클래스가 단순하면 상관없을지 몰라도 (영향력이 작을지 몰라도)
매우 복잡한 클래스라면 이는 큰 영향력을 미치는 치명적인 로직으로 작용할 수 있는 단접으로 작용할 수 있다. */
void TestKnight_Copy(Knight knight) {  }

/* 하지만 이를 참조값 (혹은 포인터)를 이용해서 진행한다면 이야기가 다르다.
why? -> 우선적으로 복사가 이루어지는 개념이 아닌 원본(혹은 인자값에 해당하는 포인터 / 참조값의 원본 위치)을 
직접적으로 수정하는 원리로 작동한다. (이를 왼값참조라고 한다.) 

왜 lvalue에 해당하는가?
-> 지속적으로 사용될 개체가 해당되는데 여기서는 Knight가 해당된다. 
임시적으로 사용될 클래스가 아니며 생성된 Knight 원본의 포인터(혹은 참조값)을 이용

즉, 지속적으로 사용될 개체에 해당하므로 lvalue!! */
void TestKnight_LValueRef(Knight& knight) {  }
void TestKnight_ConstLValueRef(const Knight& knight) {  }

void TestKnight_RValueRef(Knight&& knight) {  }

int main() {

	Knight k1;

	TestKnight_Copy(k1); // 일반 복사생성자 이용
	TestKnight_LValueRef(k1); // lvalue 값의 (포인터/참조자) 사용

	{
		void TestKnight_LValueRef(Knight & knight);
		TestKnight_LValueRef(Knight());
	}
	/* 그럼 이번에는 Knight()라는 임시값을 인자로 넣어본다면 어떻게 될까?
	
	컴파일러는 "비const 참조에 대한 초기 값은 lvalue여야 합니다." 라는 Error 문구를 출력하고 있다. 

	왜 이렇게 출력이 되는 것인가?
	위의 컴파일러가 말하고 있는 설명처럼 기존의 우리가 사용하는 대부분의 함수는 lvalue를 기준으로 인자값을 넣어야한다.

	하지만 지금 사용하는 Knight() 라는 인자값은 임시적은 Knight class의 임시 기본 생성자에 해당한다.
	함수(TestKnight_LValueRef)가 종료된 이후 인자값으로 사용된 Knight class의 임시 기본 생성자는 사라지기에 lvalue에 해당하지 않아서
	컴파일러가 사전에 방지하고자 방패병 역할을 하고 있는 것이다.

	컴파일러 : 넌~ 못 지나간다 */

	/* 그럼 이를 사용할 수 있는 방법은 존재하지 않는 것인가 ?
	-> 존재한다. 하지만 이는 "비const 참조에 대한 초기 값은 lvalue여야 합니다." Error를 반대로 해석하면 된다.

	즉 const 참조에 대한 초기 값은 rvalue여야 합니다. 라는 결론이 나온다.

	그럼 이를 적용시켜보자. */
	{
		void TestKnight_ConstLValueRef(const Knight & knight);
		TestKnight_ConstLValueRef(Knight());
	}
	/* 함수의 인자값을 const로 받는다면 전혀 문제가 되지 않음을 알 수 있다.
	하지만 const로 선언된 인자값이므로 수정같은 작업은 진행할 수 없다. (readonly 형태)
	{ logic.. } 안에서 수정을 진행할 경우 컴파일러가 막는 것을 볼 수 있다....

	그렇기에 읽기전용의 작업만 진행할 수 있다는 반쪽짜리 함수가 되는 셈이다. */

	{ // 아래의 두 함수는 같은 것을 의미한다.
		void TestKnight_ConstLValueRef(const Knight & knight);
		void TestKnight_RValueRef(Knight && knight);
	}
	TestKnight_RValueRef(Knight()); 

	return 0;
}