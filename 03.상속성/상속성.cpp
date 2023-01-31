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
    Player() {
        _hp = 0;
        _attack = 0;
        _defence = 0;
        cout << "Call Player 기본 생성자" << endl;
    }

    Player(int mp) { // 그렇다면 기타 생성자를 사용하고 싶을때는 어떻게 해야할까?
        _hp = 0;
        _attack = 0;
        _defence = 0;
        cout << "Call Player 기본 생성자" << endl;
    }

    ~Player() {
        cout << "Call Player 소멸자" << endl;
    }

    void Move() { cout << "Call Player Move" << endl; }
    void Attack() { cout << "Call Player Attack" << endl; }
    void Die() { cout << "Call Player Die" << endl; }

public:
    int _hp;
    int _attack;
    int _defence;

};

class Knight : public Player {
public:
    Knight() {
        _stamina = 0;
        cout << "Call Knight 기본 생성자" << endl;
    }

    ~Knight() {
        cout << "Call Knight 소멸자" << endl;
    }

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

/* 생성자와 소멸자를 최상위 클래스에 넣어서 사용하면 어떻게 될까? 그리고 상속받은 하위의 클래스에도 생성자와 소멸자를 만들면 어떻게 될까?
우선적으로 상속을 받는 개념에서 생성자와 소멸자는 제외가 된다고 알고 있어야 한다. 

그렇기에 생성자와 소멸자는 상속을 하는 쪽, 받는 쪽 둘 다 존재해야하는 것이다.
=> 컴파일러가 상위 생성자를 생성하고 나서 하위 클래스의 생성자를 생성하기 때문이다.

[  [Player]  ]
[   Knight   ] 앞서 살펴보았듯이 Player가 생성이 되고 나서 이를 상속받고 Knight가 생성되는 구조를 거치고 있다.

그렇기에 Player 의 생성자가 먼저 생성되고 하위 Knight 의 생성자가 생성됨을 이해할 수 있다.

반면에 소멸자는 어떨까? 
=> 기본적으로 소멸자는 생성자가 생성된 순서와 반대로 소멸이 된다. (C++ 책에서 그렇게 배웠다.)
하지만 그렇지 않은 경우도 존재한다고 한다. */

class Mage : public Player {
public:
    Mage() 
    /* 선 처리 영역
    - 여기서  Player() 생성자를 호출한 후에 하위 클래스의 생성자를 생성한다.*/
    {
        _mp = 0;
        cout << "Call Mage 기본 생성자" << endl;
    }

    // 하위 클래스에서는 상위 글래스에서 정의한 기타 생성자를
    // [하위 클래스 기타생성자] : [상위 클래스 기타생성자](인자값) {}
    // 위의 형식대로 작성한 후, [하위 클래스]에 들어갈 인자값의 데이터를 [상위 클래스]의 인자값에 넣어주면 된다.
    Mage(int mp) : Player(100) {
        _mp = mp;
        cout << "Call Mage 기본 생성자" << endl;
        cout << "Mage MP : " << _mp << endl;
    }
    
    ~Mage() {
        cout << "Call Mage 기본 소멸자" << endl;
    }
    /* 후 처리 영역
    - 여기서  Mage() 소멸자를 실행한 후에 상위 클래스의 소멸자를 실행한다. */
    
    //

    /* 생성자와 소멸자는 일반적인 함수와는 조금은 다른 방식의 실행 방식을 보여줌을 알 수 있다.
    
    설계하는 측면에서 본다는 [선처리 영역] -> 생성자 -> 소멸자 -> [후처리 영역]이 진행된다는 것을 이해하고 있어야한다.

    건축학적으로 본다면 토대를 만들고 바닥을 만들고 벽을 올린다음 지붕을 짓는다. -> 철거는 역순으로 */
    
public:
    int _mp = 100;

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