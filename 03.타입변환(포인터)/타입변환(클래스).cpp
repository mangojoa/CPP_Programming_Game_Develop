#include <iostream>
using namespace std;

class Knight {
public:
    int _hp = 0;
};

class Item {
public:
    Item() {
        cout << "Item()" << endl;
    }
    Item(int itemType) : _itemType(itemType) {
        cout << "Item(int itemType)" << endl;
    }
    Item(const Item& item) {
        cout << "Item(const Item& item)" << endl;
    }
    virtual ~Item() {
        cout << "~Item()" << endl;
    }
public:
    int _itemType = 0;
    int _itemDbid = 0;

    char _dummy[4096] = {}; // 이런 저런 비대한 정보들
};

enum ItemType {
    IT_WEAPON = 1,
    IT_ARMOR = 2
};

class Weapon : public Item {
public:
    Weapon() : Item(IT_WEAPON)
    {
        cout << "Weapon()" << endl;
    }
    virtual ~Weapon()
    {
        cout << "~Weapon()" << endl;
    }
public:
    int _damage = 0;
};

class Armor : public Item {
public:
    Armor() : Item(IT_ARMOR)
    {
        cout << "Armor()" << endl;
    }
    virtual ~Armor()
    {
        cout << "~Armor()" << endl;
    }
public:
    int defence = 0;
};

void TestItem(Item item) {

}

void TestItemPtr(Item* item) {

}

int main() {

    // 연관성이 없는 클래스 사이의 포인터 변환 테스트
    {
        // Stack [ address ] -> Heap [ _hp(4) ]
        Knight* knight = new Knight();

        // Stack [ address ]
        Item* item = (Item*)knight;
        // 암시적으로는 할 수 없으나 명시적으로는 가능하다.

        // 만약 명시적으로 우리가 변환을 해서 사용했다고 가정해보자
        item->_itemType = 1;
        item->_itemDbid = 2;

        /* 위와 같은 코드를 실행하게 된다면 무슨일이 벌어질까?
        이를 실행하면 -> knight 의 유효 변수 범위인 4byte를 넘어서 사용하는 것으로 간주되기에
        첫 번째 실행되는 item->_itemType = 1;은 문제 없이 잘 실행이 된다.

        하지만 문제는 두 번째 실행되는 item->_itemDbid = 2; 에서부터 발생하게 된다.
        이는 우리가 new Knight(); 를 통해서 힙 영역에 할당받은 만큼에 대한 부분만 사용해야하는데
        이미 _dummy[4096] 이라는 어마어마한 데이터가 자리잡고 있는 영역을 침범하는 꼴이 된다.
        즉 저장된 데이터의 훼손을 일으키고 있다는 문제가 발생하는 것이 된다.

        그렇기에 C++에서는 이러한 캐스팅에 대한 검토를 매우 면밀하게 하지 않는다면 크래시가 나기 쉽다.

        물론 이를 초기에 막을 수 있는 delete knight; 를 통해서 에러팝업을 띄우게 하는 방법도 있지만
        매번 통하는 것은 아니기에 처음부터 영역침범이 일어나지 않는지 확인이 필요하다. */
    }

    // 자식 -> 부모 변환 테스트
    {
        Weapon* weapon = new Weapon();

        // Weapon은 Item 인가? -> 당연히 성립이 된다.
        // 애초에 이는 상속 관계이기 때문에 가능하다.

        // 게다가 암시적으로 선언했음에도 불구하고 컴파일러가 안전하다고 입증까지 해주고 있다.
        Item* item = weapon;

        delete weapon;
    }

    // 부모 -> 자식 변환 테스트
    {
        Item* item = new Item();

        // 우선적으로 item이 weapon인가? 그것은 맞을 수도 아닐 수도 있기 때문에 
        // 컴파일러는 자동적으로 Error를 출력하고 있다.
        Weapon* weapon = (Weapon*)item; // 하지만 이를 억지로 캐스팅하게 된다면? 가능하다

        weapon->_damage = 10;
        // 하지만 업캐스팅을 진행하게 된다면 그 범위를 초과해서 메모리를 건드리기 때문에 
        // 연관성이 없는 클래스 사이의 포인터 변환 테스트와 같은 결과를 내게 된다.

        delete item;
    }

    /* 명시적으로 타입 변환할 때는 항상 조심해야한다!
    암시적으로 될 때는 안전한가?
    평생 명시적으로 타입 변환(캐스팅)은 안하면 되는거 아닌가?
    경우에 따라 이는 아닐 수 있다. 
    
    아래의 경우는 자식 -> 부모 타입으로 변환하는 과정을 코드로 작성했다. */
    Item* inventory[20] = {};

    srand((unsigned int)time(nullptr));

    for (int x = 0; x < 20; x++) {
        int randValue = rand() % 2;

        switch (randValue) {
        case 0:
            inventory[x] = new Weapon();
            break;
        case 1:
            inventory[x] = new Armor();
            break;
        }

        /* 이렇게 관리할 때, 매우 도움이 되는 장점이 있다.
        최상위 객체에 공통된 함수나 값을 넣음으로써 사용하고자 하는 기능에 대한 처리를 일괄적으로 처리할 수 있도록 말이다. */

    }

    for (int x = 0; x < 20; x++) {
        Item* item = inventory[x];
        if (item == nullptr) continue;

        if (item->_itemType == IT_WEAPON) {

            // 우선적으로 부모 -> 자식의 관계로 클래스 변환을 명시적으로 진행하고 있다 
            // 사실 이는 위에서 배웠듯 매우 위험한 일로 간주된다. 하지만 왜 사용하는 것인가?

            // 이는 item이 원래는 Weapon으로 선언되었던 포인터 였기 때문에 안전하다고 보장받을 수 있기에 이를 사용해도 되는 것이다.
            // 이러한 보장관계가 없었다면 사용했을 때 메모리 오염을 피할 수 없을 것이다 .....
            Weapon* weapon = (Weapon*)item;
            cout << weapon->_damage << endl;
        }
    }

    // 언제나 메모리가 안전할까 하는 의문을 품고 있다.

    /*   ----------------------------------------------------------------------------   */

    for (int x = 0; x < 20; x++) {
        Item* item = inventory[x];
        if (item == nullptr) continue;

        // delete item;

        /* 문제는 모든 포인터를 item 형태로 선언했기에 이를 delete로 삭제한다면? 어떻게 되는가 
        
        delete item을 통해 item을 삭제한다면 이는 ~Item() 만 호출되는 것을 볼 수 있다.
        ??? -> 정상적으로 삭제가 되는 것 같은데 아닌건가 ?? -> 당연하게도 아니다.

        이유는 간단하다. item안의 내용물은 Weapon / Armor 형태로 만들어진 포인터이기에 이를 삭제할 때는
        Weapon / Armor 형태로도 삭제가 되어야 완벽하게 삭제가 되는 것이다.
        
        이를 해결하기 위해서는 어떻게 해야하는가? */

        if (item->_itemType == IT_WEAPON) {
            Weapon* weapon = (Weapon*)item;
            delete weapon;
        }
        else {
            Armor* armor = (Armor*)item;
            delete armor;
        }

        /* 원본의 클래스 형태로 소멸자를 불러주어야 한다!
        왜 이렇게 해야하는가 ? 
        
        item* 안에 들어있는 메모리 들은 전부 Weapon / Armor 이기 때문에 Item만 지운다고 해서 이들도 같이 지워지는 개념이 아니다.
        ( 남아서 존재한다는 소리이며 이 부분은 언제나 메모리 오염을 낳을 수 있다. )

        그렇기에 이를 위의 코드처럼 하나하나 경우에 따라 지워줘야 하는가?
        그렇게 한다면 프로그래머 인생이 매우 고달퍼지기 때문에 앞서 배웠던 virtual 이라는 함수르 사용하면 가능하다

        우선적으로 virtual은 가상함수의 개념으로 상속받은 객체에서 상위의 객체를 실행할 때 길잡이 역할을 할 수 있도록 도와주는 친구였다.
        이를 적극적으로 활용하게 된다면 최상위와 그 아래 클래스의 소멸자에 virtual를 추가하는 것이다.
        이렇게 진행하게 될 경우, 상위 클래스의 기능을 사용하게 된다면 하위 클래스의 상속받은 기능들은 자동으로 연쇄적인 반응을 보이게 된다.

        이렇게 작성한다면 이제 delete item; 만으로도 깔끔하게 지워진다. */

    }

    /* 결론
    포인터 와 일반타입의 차이를 확실하게 알고 있어야한다. 원리가 비슷한게 아니라 아예 다른 차원이다.
    포인터 사이의 타입 변환(캐스팅)을 할 때는 조심해야한다. (매우중요*******)

    부모-자식 관계에서 부모 클래스의 소멸자에는 까먹지 말고 virtual 을 붙이자 !!!! */

    return 0;
}