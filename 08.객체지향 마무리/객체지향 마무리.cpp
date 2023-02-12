#include <iostream>
using namespace std;

/* 객체지향 마무리

1. struct vs class

사실 C++ 에서는 struct 나 class나 차이가 없다. */

struct TestStruct {
    int _a;
};

class TestClass {
    int _a;
};
/* 접근 지정자를 선언하지 않고 이를 진행하면 
해당 부분에 접근을 할때, struct는 접근할 수 있지만, 
class는 접근할 수 없다는 차이점이 존재한다.

struct = public 
calss = private 가 기본 접근 지정자로 설정되어 있다.

왜 이렇게 했을까?
c언어에서 파생되어 발정했기 때문에, 호환성을 지키기 위해 남겨진 부분이다.

-> struct 는 그냥 구조체(데이터 묶음)
-> class 는 객체지향 프로그래민 의 특징을 나타내는 용도 */

/* 2. static 함수 / static 변수 (정적 = 고정된) 
초기화 하면 .data
초기화 안하면 .bss
*/
class Marine {
    public:
    // 특정 객체에 묶여있는 종속적인 관계
    int _hp;
    void TakeDamage(int damage) {
        _hp -= damage;
    }

    /* static 변수 사용법
    특정 객체에 묶인게 아닌 특정 마린 객체와 무관
    마린 클래스 자체와 연관 */
    static int s_attack; // 설계도상으로만 존재

    /* static 함수 사용법 
    이렇게 선언한 것 까지는 좋다. 하지만 이는 특정 객체에 묶인 종속적인 개념이 아니기에 _hp를 접근할 수 없다.
    (종속적인 변수를 사용할 수 없다는 것이다.)
    그렇다면 어떻게 해야하는가? 
    static 으로 선언된 변수는 접근할 수 있다. 이를 이용해서 s_attack을 수정해보자*/
    static void SetAttack() {
        s_attack = 100;
    }
};

int Marine::s_attack = 0;

/* static을 이용한(정적 지역 변수) player id 늘리기*/
int GenerateId() {
    // 생명주기 = 프로그램 시작/종료 (메모리에 항상 올라가 있다.)
    // 가시범위 = 함수 안에서만 유효
    // static 으로 선언한 정적 지역 변수는 첫 함수가 호출될 때, 초기화가 이루어지고 이후에는 연산된 값을 계속 지니고 있다.
    // 그렇기에 이를 활용한 고유한 값을 연산하는데 유용하다.

    // 만약 int s_id = 1; 로 선언했다면 이는 매번 호출될 때마다 초기화가 되어 사실상 사용하기에는 적합하지 않을 수 있다.
    static int s_id = 1;
    return s_id++;
}




int main() {

    TestStruct ts;
    ts._a = 1;

    TestClass tc;
    tc._a = 1; // 이처럼 접근 지정자를 선택하지 않았기에 접근 할 수 없는 모습을 보여준다.

    Marine m1;
    m1._hp = 40;
    // m1.s_attack = 6;

    Marine m2;
    m2._hp = 40;
    // m2.s_attack = 6;

    // 마린 공격력 업그레이드를 통해 공격력을 변동해야 한다면 ?
    // m1.s_attack = 7;
    // m2.s_attack = 7;
    // 이전에는 이렇게 무식하게 선언해야 했다 하지만 static 변수를 가지고 있다면 이야기가 달라진다.
    // static으로 선언한 s_attack 를 int Marine::s_attack = 0; 으로 선언했다.
    // 이렇게 선언된 이후 다음과 같이 코드를 작성한다면 모든 생성된 marine에 대한 s_attack 에 대한 값을 수정할 수 있다.
    Marine::s_attack = 7;
    Marine::SetAttack();
}