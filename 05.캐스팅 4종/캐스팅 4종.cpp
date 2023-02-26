#include <iostream>
using namespace std;

/* 캐스팅(타입 변환) 4종

C++ 에서는 메모리를 조작하기 때문에 캐스팅에 대한 제약 및 원리가 복잡하다.
그렇기에 제대로 알고 있어야 실수를 줄일 수 있다. (면접 단골 문제)

상황과 용도에 따라 분리해둔 애들을 하나하나 알아보자.

1. static_cast
2. dynamic_cast
3. const_cast
4. reinterpret_cast
*/

class Player {
public:	
	virtual ~Player() {}

};

class Knight : public Player {
public:
};

class Archer : public Player {
public:
};

class Dog {
public:
};

// 헤더파일 혹은 다른 사람이 만든 라이브러리를 활용하여 고칠 수 없는 함수라고 가정한다.
void PrintName(char* str) {
	cout << "str : " << str << endl;
}

int main() {

	/* static cast : 타입 원칙에 비워볼 때 상식적인 캐스팅만 허용
	int <-> float 와 같은 부분의 허용범위 안에서 캐스팅을 해주는 것이 해당한다.
	(부모)Player* -> (자식)Knight* (다운 캐스팅) << 단, 안정성은 보장되는건 아니다. */

	int hp = 100;
	int maxHp = 200;
	/* float ratio = (float)hp / maxHp; // 0.5f;
	float이 int에 비해 우선순위가 높기에 이렇게 진행을 해주어도 된다.
	하지만 C++ 친화적인 문법을 이용하면 */
	float ratio = static_cast<float>(hp) / maxHp; // 이렇게 작성해주는 편이 좋다.

	/* 일반적으로 부모->자식의 다운캐스팅의 경우, 컴파일러는 안전하지 안자는 것을 인지하여 거부한다.
	Player* p = new Player();
	Knight* k = p;
	
	하지만 원본자체가 자식이고 이를 포인터로 선언하는게 부모라고 한다면 이는 안전한 캐스팅이라고 간주한다. */
	Player* p1 = new Knight();
	//Knight* k1 = p1; 
	Knight* k1 = (Knight*)p1;

	/* 하지만 이런 경우에도 컴파일러는 우선적으로 안전하지 않다고 판단한다. 
	왜냐하면 포인터와 new로 생성한 객체의 타입이 일치하지 않기 때문이다. 그렇기에 이에 대한 추가적인 캐스팅이 필요하다. */
	Player* p2 = new Knight();
	Knight* k2 = static_cast<Knight*>(p2); // 이렇게 작성하는 것이 C++ 친화적인 문법이다.

	/* 하지만 원본타입이 기존의 자식과 다른 지식 클래스를 캐스팅한다면 이는 매우 위험한 캐스팅이 된다.
	애초에 static_cast<type>(value)를 사용한다고 해서 안전한 것은 절대 아니다. */
	Player* p3 = new Archer();
	Knight* k3 = static_cast<Knight*>(p3); 
	/* 이렇게 캐스팅을 할 때도 강제로 하는 개념이 성립되니 안전을 보장하는 것은 절대로 아니다.
	그렇기에 무엇을 캐스팅하려 하는지 원본타입이 제대로 일치하는지에 대한 확신이 보장되어야한 한다.
	(그렇지 않으면 큰일난다.) */
	
	/* --------------------------------------------------------------------------- */

	/* dynamic_cast : 상속 관계에서의 안전 형변환을 하는데 이용된다. (실시간으로 형변환을 할때 검사하는 개념)
	RTTI (RunTime Type Information) 다형성을 활용하는 방식이다. ex) virtral function */

	Knight* k2 = dynamic_cast<Knight*>(p2);

	/* virtual function이 없는 상태로 dynamic_cast를 진행하게 된다면
	'런타임 dynamic_cast의 피연산자는 다형 클래스 형식이어야 합니다.'
	'dynamic_cast':'Player'은 다형 형식이 아닙니다. 라는 Error가 나는 것을 확인할 수 있다.
	
	이를 사용하고 싶다면 virtual function을 하나라도 생성해야 한다. (매우 중요)
	
	virtual 함수를 하나라도 만들면, 객체의 메모리에 가상 함수 테이블 (vftable) 주소가 기입된다.
	만약 잘못된 타입으로 캐스팅을 했으면, nullptr 반환 ******************* 한다.

	이를 이용해서 맞는 타입으로 캐스팅을 했는지 확인하는데 유용하다.
	
	하지만 이를 사용하게 된다면 static_cast 를 활용할 때 보다 안전하지만 그만큼 성능의 차이가 발생한다.
	그러나 이를 거치게 되어 안전하다는 것을 확인할 수 있다면 사용하는 편이 좋다. */

	/* --------------------------------------------------------------------------- */

	/* const_cast : const를 붙이거나 떼거나 할 때 사용한다.
	헤더파일 혹은 다른 사람이 만든 라이브러리를 활용하여 고칠 수 없는 함수를 가져다 쓸때
	이에 넘겨줘야하는 인자값이 const 형식이라서 못 넘겨주는 상황이라면 사용한다고 보면 된다. */
	PrintName(const_cast<char*>("MangoPlatation"));

	/* --------------------------------------------------------------------------- */

	/* reinterpret_cast : 가장 위험하고 강력한 캐스팅이다.
	포인터랑 전혀 관계없는 다른 타입 변환이 해당한다. */

	__int64 address = (__int64)k2; // 당연히 캐스팅이 안된다. (아무런 연관관계가 없기 때문이다.)
	__int64 address = reinterpret_cast<__int64>(k2);

	Dog* dog1 = reinterpret_cast<Dog*>(k2); // 연관관계가 없는 클래스 사이의 관계에도 사용된다.

	/* 하지만 그럼에도 불구하고 reinterpret_cast를 활용하는 예시가 종종 발생한다.
	대표적인 예로 malloc(); 이 해당한다. malloc(); 의 경우, 
	반환형식이 void* 형식이기에 이 반환된 메모리르 사용하기 위해서 사용한다고 보면된다. */
	void* m = malloc(100);
	Dog* dog2 = (Dog*)m;
	Dog* dog2 = reinterpret_cast<Dog*>(m);

	/* 이전까지 (Type)변수 를 활용한 캐스팅을 자주 이용해왔지만 
	
	이는 어디까지나 C언어의 유산물이고 C++는 C의 superset 에 해당하는 개념이라서 적용이 되는 것이다.
	하지만 C언어의 캐스팅은 앞서 말한 위의 캐스팅을 전부 커버할 수 있는 비장의 무기? 같은 개념이기에 
	함부러 사용하는 것을 왠만하면 자제하는 것이 좋다.

	그렇기에 앞으로는 xxxxxxx_cast<>()를 상황과 용도에 맞게 이용하도록 하자
	*/

	return 0;
}