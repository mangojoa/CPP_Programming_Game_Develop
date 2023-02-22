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
    Item(const Item& item) {
        cout << "Item(const Item& item)" << endl;
    }   
    ~Item() {
        cout << "~Item()" << endl;
    }
public:
    int _itemType = 0;
    int _itemDbid = 0;

    char _dummy[4096] = {}; // 이런 저런 비대한 정보들
};

void TestItem(Item item) {

}

void TestItemPtr(Item* item) {

}

int main() {

    // 연관성이 없는 클래스 사이의 포인터 변환 테스트
    {
        // Stack [ address ] -> Heap [ _hp(4) ]
        Knight* knight  = new Knight();

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
        매번 통하는 것은 아니기에 처음부터 영역침범이 일어나지 않는지 확인이 필요하다.
        */

        
        


    }

    return 0;
}