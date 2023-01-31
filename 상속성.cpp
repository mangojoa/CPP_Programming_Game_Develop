#include <iostream>
using namespace std;

/* 객체지향 (Object Oriented Programming)
- 상속성
- 은닉성
- 다형성 등이 존재한다. */

/* 대규모 mmorpg를 만든다고 하면 유저들이 선택할 수 있는 직업(클래스)의 다양성은 무궁무진하다.
그렇기에 직업(클래스)의 수만큼 앞서 배운 클래스를 생성하면 되겠지!! (이러면 혼난다)
왜? => class 안의 코드가 직업(클래스)만큼 중복이 이루어지기 때문에 좋지 못하기 때문이다.

이를 해결할 수 있는 객체지향의 '상속성'에 대해서 알아보자. */

/* 그전에 !!!! 이전에 사용한 struct를 활용한 중복을 줄이는 방법을 사용하는건 어떨까?
우선적으로 struct는 변수에 대한 묶음을 진행할 수 있지만,
void function() {} 에 대한 부분은 묶음으로 둘 수가 없다는 단점이 존재한다.

그렇기에 우리는 상속성을 더욱 사용할 명분이 생겼다.(한 번에 관리하면 편하잖아?)
*/
struct StatInfo {
    int _hp;
    int _attacl;
    int _defence;
};

/* 상속(ingeritance) 부모 클래스가 자식 클래스에게 기능을 사용할 수 있게 만들어 주는 것
1. 중복적으로 사용되는 클래스들의 공통점을 찾는다.
2. 해당 공통점을 묶어 최상위 클래스를 작성한다.
3. class temp : public [최상위 클래스] {} 와 같은 상속코드를 작성해주면 된다.
4. 그럼 class temp 는 최상위 클래스의 변수와 함수를 사용할 수 있다. */
class Player {
public:
    void Move() { cout << "Call Player Move" << endl; }
    void Attack() { cout << "Call Player Attack" << endl; }
    void Die() { cout << "Call Player Die" << endl; }

public:
    int _hp;
    int _attack;
    int _defence;

};

class Knight : public Player{
public:
    /* 상위 클래스에서 상속받은 변수 혹은 함수는 재정의를 통해 다르게 사용할 수 있다. (혹은 사용하지 않아도 무방하다.)
    여기서 상속받은 함수를 재정의(함수 A)하고 나서 상속받은 함수(함수 B)를 사용하고 싶다면 사용은 할 수 있다.

    하지만 위의 경우대로 진행할 경우, 재정의의 의미가 모호해지며 그런 방법보다는 함수 A의 이름을 다르게 작성하는 편이 옳다.
    (이런 일은 없도록 하자.) */
    void Move() { cout << "Call Knight Move" << endl; }

public:
    /* 상속을 받은 클래스의 경우, 받은 기능 이외에 
    다른 변수나 함수를 추가적으로 작성하여 사용할 수 있다. */
    int _stamina;

};

class Mage {
public:
    int _mp;

};


int main() {

    /* Player를 상속받은 Knight를 사용해보자.
    암시적 생성자로 Knight를 생성 후, k. 를 통해 Player의 변수와 함수에 접근할 수 있는지 보자.
    k._hp = 100;
    k.Attack(); 정상적으로 접근할 수 있다. */
    Knight k;
    k._hp = 100;
    k._attack = 10;
    k._defence = 5;
    k._stamina = 50;
    k.Attack();
    /* 상속받은 변수와 함수를 이용해 객체에 데이터를 넣을 수 있다. 그렇다면 이를 메모리 측면에서 조사해보자.
    [  [Player]  ]
    [   Knight   ] 라는 형식으로 메모리가 생성된다.

    이렇게 생성되는 이유는 Player의 바이트와 Knight의 바이트를 이어붙여서 만들기 때문이다. */

    return 0;
}