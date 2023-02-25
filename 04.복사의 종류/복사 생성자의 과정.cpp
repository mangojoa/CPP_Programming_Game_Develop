#include <iostream>
using namespace std;

class Pet {
    // Knight 클래스가 소유할 동반자 Pet 클래스를 만든다.
public:
    Pet() {
        cout << "Pet()" << endl;
    }
    Pet(const Pet& pet) {
        cout << "Pet(const Pet& pet)" << endl;
    }
    ~Pet() {
        cout << "~Pet()" << endl;
    }

    // 복사 대입 연산자 과정을 위한
    Pet& operator=(const Pet& pet) {
        cout << "Pet& operator=(const Pet& pet)" << endl;
        return *this;
    }
};

// Knight의 부모 클래스 설정을 위한 Player 클래스 생성
class Player{
public:
    Player() {
        cout << "Player()" << endl;
    }

    // 복사 생성자
    Player(const Player& player) {
        cout << "Player(const Player&)" << endl;
        _level = player._level;
    }

    // 복사 대입 연산자
    Player& operator=(const Player& player) {
        cout << "operator=(const Player&)" << endl;
        _level = player._level;
        return *this;
    }

public: 
    int _level = 0;
};

class Knight : public Player {
public:
    Knight() {
        cout << "Knight()" << endl;
    }

    ~Knight() {
        cout << "~Knight()" << endl;
    }

    /* [ 얕은 복사 ]를 방지하기 위한 복사 생성자 / 복사 대입 연산자 */
    Knight(const Knight& knight) : Player(knight), _pet(knight._pet) {
        _hp = knight._hp;
    }

    Knight& operator=(const Knight& knight) {

        cout << "Knight& operator=(cont Knight& knight)" << endl;

        Player::operator=(knight);
        _pet = knight._pet;

        _hp = knight._hp;
        return *this;
    }


public:
    int _hp = 100;
    Pet _pet; // 깊은 복사를 사용하지 않을 것이기에 포인터 삭제
};

int main() {

    /* 이에 대한 복사를 진행하면 
    - 암시적 복사 생성자 Steps
    1. 부모 클래스의 복사 생성자 호출
    2. 맴버 클래스의 복사 생성자 호출 
    {
        Pet _pet; 형태로 맴버 안에 작성된 것을 말함
    }

    Player(const Player&)
    Pet(const Pet&) 으로 실행된 결과를 확인할 수 있다.
    -----------------------------------------------
    이렇게 두 개의 복사 생성자가 호출이 되는 것을 알 수 있었다. 
    하지만 문제는 Knight에 복사 생성자를 명시적으로 선언했다면 이는 어떻게 될까?

    [Knight class 안의 복사 생성자]
    Knight(const Knight& knight) {
        _hp = knight._hp;
    }
    위의 코드를 작성한 상태에서 아래의 코드들을 다시 진행한다면 이야기가 달라진다.

    Player()
    Pet()
    Knight(const Knight&) 로 실행된 결과를 확인할 수 있다.
    즉, 명시적으로 복사 생성자를 작성했다면 이와 연관된 모든 부분을 전가 받고 책임져야한다.
    이를 진행하지 않는다면 컴파일러는 기본 생성자를 호출할 수 밖에 없기 때문이다.

    그렇다면 이를 전가받았다면 어떻게 사용해야 하는가?
    [수정한 Knight class 안의 복사 생성자]
    여기서는 Player / _pet 에 대한 복사 생성자를 호출하는 부분을 추가적으로 작성해주어야 한다.

    Knight(const Knight& knight) : Player(knight), _pet(knight._pet) {
        _hp = knight._hp;
    }

    이를 실행하는 경우, 
    Player(const Player&)
    Pet(const Pet&)
    Knight(const Knight&) 로 실행되는 결과를 확인할 수 있다. */

    Knight knight;
    knight._hp = 200;

    Knight knight2 = knight;

    Knight knight3;
    knight3 = knight;
    
    /* 이에 대한 복사 대입 연산자를 실행하면
    - 암시적 복사 대입 연산자 Steps
    1. 부모 클래스의 복사 대입 연산자 호출
    2. 맴버 클래스의 복사 대입 연산자 호출
    
    operator=(const Player&)
    operator=(const Pet&) 으로 실행되는 결과를 볼 수 있다. 
    --------------------------------
    하지만 여기에 Knight 클래스에서 복사 대입 연산자(깊은 복사)를 생성한다면 이야기가 달라진다.

    [Knight 클래스에 작성한 복사 대입 연산자]
    Knight& operator=(const Knight& knight) {
        cout << "Knight& operator=(cont Knight& knight)" << endl;
        _hp = knight._hp;
        return *this;
    }
    위와 같은 코드를 작성했다면 한 가지 문제가 발생하게 된다.
    [깊은 복사] 부분을 진행하지 않은 부분은 정상적으로 복사가 진행되지 않는다... 

    - 명시적 복사 대입 연산자 Steps
    1. 알아서 해주는거 없음 .... 

    [수정한 Knight 클래스에 작성한 복사 대입 연산자]
    Knight& operator=(const Knight& knight) {

        cout << "Knight& operator=(cont Knight& knight)" << endl;

        [누락된 복사 영역을 추가로 작성해주어야 한다.]
        Player::operator=(knight); 
        _pet = knight._pet;

        _hp = knight._hp;
        return *this;
    } 
    
    왜 이렇게까지 복잡하게 만들었는가 .... 어렵다 .... 
    객체를 '복사'한다는 것은 두 객체의 값들을 일치시키려는 것
    따라서 기본적으로 얕은 복사 방식으로 동작

    명시적 복사 -> [모든 책임]을 프로그래머한테 취임하겠다는 의미이다.

    */


    /* [ 얕은 복사 Shallow Copy ]
    맴버 데이터를 비트열 단위로 '똑같이' 복사 (메모리 영역 값을 그대로 복사)

    Stack : Knight1 [ hp : 200 / pet : 0x012fc388]
    Stack : Knight2 [ hp : 200 / pet : 0x012fc388]
    Stack : Knight3 [ hp : 200 / pet : 0x012fc388] */

    /* [ 깊은 복사 Deep Copy ]
    맴버 데이터가 참조(주소) 값이라면, 데이터를 새로 만들어준다. (원본 객체가 참조하는 대상까지 새로 만들어서 복사)
    포인터는 주소값 바구니 -> 새로운 객체를 생성 -> 상이한 객체를 가리키는 상태가 된다.
    Stack : Knight1 [ hp : 0x112fc388 / pet : 0x042fc388]
    Stack : Knight2 [ hp : 0x212fc388 / pet : 0x052fc388]
    Stack : Knight3 [ hp : 0x312fc388 / pet : 0x062fc388] */

    /* 실험)
    - 암시적 복사 생성자 Steps
    1. 부모 클래스의 복사 생성자 호출
    2. 맴버 클래스의 복사 생성자 호출 
    {
        Pet _pet; 형태로 맴버 안에 작성된 것을 말함
    }
    위의 두개에 해당하지 않을 경우,
    3. 맴버가 기본 타입일 경우 메모리 복사 (얕은 복사)

    - 명시적 복사 생성자 Steps -> 선언시 모든 부분을 컨트롤한다는 의미
    1. 부모 클래스의 기본 생성자 호출
    2. 맴버 클래스의 기본 생성자 호출


    - 암시적 복사 대입 연산자 Steps
    1. 부모 클래스의 복사 대입 연산자 호출
    2. 맴버 클래스의 복사 대입 연산자 호출
    위의 두개에 해당하지 않을 경우,
    3. 맴버가 기본 타입일 경우 메모리 복사 (얕은 복사)

    - 명시적 복사 대입 연산자 Steps
    1. 알아서 해주는거 없음 .... */

    return 0;

}