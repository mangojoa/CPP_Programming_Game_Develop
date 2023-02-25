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
};

class Knight {
public:
    Knight() {
        _pet = new Pet();
    }
    
    /* [ 얕은 복사 ]를 방지하기 위한 복사 생성자 / 복사 대입 연산자 */
    Knight(const Knight& knight) {
        _hp = knight._hp;
        // _pet = knight._pet; -> 이렇게 진행하면 [얕은 복사]가 이루어지기에 의미가 없다.
        _pet = new Pet(*(knight._pet));
    }

    Knight& operator=(const Knight& knight) {
        _hp = knight._hp;
        _pet = new Pet(*(knight._pet)); // -> [깊은복사]

        return *this;
    }

    ~Knight() {
        delete _pet;
    }
    /* 아래에서와 같이 앝은 복사가 이루어지고 있다면 이를 생성자에 넣어서 새로운 형태로 만드는건 어떤가?
    위의 방법은 설명을 위해 간단하게 생성되었지만, 원래 생성자 안에서 new / delete를 하는 것은 좋지 않다.

    위의 코드대로 생명주기는 맞추었지만 한가지 문제가 발생한다.
    첫 번째 Knight가 삭제될 때, 두 번째 / 세 번째 Knight가 바라보는 pet이 없어졌기 때문에 
    두 번째 / 세 번째 Knight가 삭제될 때, 없는 pet을 delete하려하기 때문에 double free가 발생한다.

    우리가 원하는 것은 각 객체마다 다른 Pet을 들고 있는 [깊은 복사]의 개념이 필요하다.
    */

public:
    int _hp = 100;
    Pet pet; // Pet 클래스를 만들었으니 이를 기사에게 추가하자.
    /* 하지만 이를 클래스 형태로 Knight 클래스에 추가하게 된다면
    클래스의 생명주기에 대한 문제가 발생한다.

    설계 -> 펫은 플레이어가 죽더라도 소유한 펫은 사라지면 안된다.
    하지만 Knight 클래스가 삭제됨과 동시에 Pet 클래스도 삭제가 된다.
    (설계가 처음부터 이런게 아니라면)

    우선적으로 클래스 안에 클래스를 생성하는 일은 되도록이면
    자제해야 한다. 위의 경우처럼 생명주기가 매우 복잡하게 된다.

    이를 위해서 이때는 Pet* pet; 포인터를 이용한 생성이 올바르다. */
    Pet* _pet;
};

int main() {

    Knight knight;
    knight._hp = 200;

    Knight knight2 = knight; // 복사 생성자를 이용해서 생성된다
    // Knight knight2(knight); 위의 코드와 같은 의미를 지닌다.

    Knight knight3; // 기본 생성자를 이용해서 생성
    knight3 = knight; // 복사 대입 연산자를 사용하여 복사를 진행한다.

    /* 컴파일러가 알아서 암시적으로 다 만들어 주니까 편하네 ?!
    이런 생각을 하면 C++를 너무 쉽게 생각하는 마인드이다.

    위의 코드가 진행되면서 원래의 의도와는 다르게 진행되고 있음을 나는 인지하지 못하고 있었다.
    우선 첫 번째 기사의 _hp 값을 200으로 설정했다.

    여기서 두 번째, 세 번째 코드가 실행될 때, 등장하는 개념이 [얕은 복사]이다.

    [ 얕은 복사 Shallow Copy ]
    맴버 데이터를 비트열 단위로 '똑같이' 복사 (메모리 영역 값을 그대로 복사)

    Stack : Knight1 [ hp : 200 / pet : 0x012fc388]
    Stack : Knight2 [ hp : 200 / pet : 0x012fc388]
    Stack : Knight3 [ hp : 200 / pet : 0x012fc388]

    분명 나는 Knight1에만 hp = 200; 을 실행했는데, 후에 생성된 Knight에도 같은 값이 들어간 상황을 볼 수 있다.

    포인터는 주소값 바구니의 개념인데 이 주소값을 똑같이 복사한다보 보면 된다. 
    즉, 동일한 객체를 가리키는 상태가 된다는 것이다.

    왜 이런 상황이 발생하는 것인가? -> 컴파일러가 알아서 '암시적으로' 생성할 때 [얕은 복사]형식으로 복사를 했기 때문이다.
    그럼 복사를 마치고 Knight1 에만 hp = 200; 을 실행하는 방법을 진행하면 되는 것 아닌가?
    -> [얕은 복사]의 개념을 전혀 모를때 할 수 있는 생각이다.

    만약 이를 동적 할당을 받은 상태라고 한다면. 동적 할당을 받은 변수의 주소값을 공유한게 된다.
    즉, [메모리 영역 값을 그대로 들고 온다.] -> 즉, 위의 기사 123 들의 값이 바뀌는 것에 따라 모두의 값이 바뀌는 개념이라고 보면 된다.

    매우 골때리는 상황이 펼쳐진 것이다... */

    /* [얕은 복사]를 진행된다는 것을 모르고 진행했었던 것이다.
    
    [ 깊은 복사 Deep Copy ]
    맴버 데이터가 참조(주소) 값이라면, 데이터를 새로 만들어준다. (원본 객체가 참조하는 대상까지 새로 만들어서 복사)
    포인터는 주소값 바구니 -> 새로운 객체를 생성 -> 상이한 객체를 가리키는 상태가 된다.
    Stack : Knight1 [ hp : 0x112fc388 / pet : 0x042fc388]
    Stack : Knight2 [ hp : 0x212fc388 / pet : 0x052fc388]
    Stack : Knight3 [ hp : 0x312fc388 / pet : 0x062fc388]

    [결론] 컴파일러가 자동으로 생성해주는 것에 대한 원리를 알아야한다는 것이다.

    이를 무턱대고 믿고 진행하면 작은 실수로 인해 큰 피해가 초래될 수 있기 때문이다.

    그렇기에 [복사 생성자]를 사용할 일이 있다면 이를 꼭 생성자로 작성해두고 진행해야 한다는 것이다. */

    return 0;

}