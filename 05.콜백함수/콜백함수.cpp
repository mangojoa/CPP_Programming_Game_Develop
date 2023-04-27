#include <iostream>
using namespace std;

/* 콜백 (CallBack) : 다시 호출하다 역으로 호출하는 개념
게임을 만들 때 이런 콜백의 개념이 자주 등장하게 된다.

이는 어떠한 시점이 왔을때 -> 이 기능을 호출해줘!
ex) UI스킬 버튼을 누르면 -> 스킬을 쓰는 함수를 호출!

이러한 개념이 바로 콜백의 개념이라고 보면 된다. */

/* 이전 시간에 배운 
함수 포인터 + 함수 객체 + 템플릿 등의 개념들이 모여 콜백을 의미하는 결과로 이어진다. */
class Item {
public:

public:
    int _itemId = 0;
    int _rarity = 0;
    int _ownerId = 0;
};

/* 위의 class Item 에서 원하는 조건의 Item을 찾는 함수를 만든다고 가정하자.
그렇다면 이는 전체 Items[], Item의 전체 수, 찾는 조건에 대한 정보 등이 기본적으로 필요하다고 본다.

그럼 Item* items[], int itemCount, 찾는 조건이 있는가? 와 같은 인자값을 구현해보자 */

/* 처음에 배운 함수포인터를 이용하면 이를 간단하게 구현할 수 있다. 

Item* FindItem(Item items[], int itemCount, bool(*func)(const Item*)) {
하지만 지난 시간에도 배웠듯이 함수 포인터의 단점으로 '상태'를 저장할 수 없다는 점이 가장 아쉽다.

이를 함수객체로 만든다면 가능하다. */
class FindByOwnerId 
{
public:
    // 함수객체를 사용하기 위한 연산자 오버로딩이 필요하다.
    bool operator() (const Item* item) {
        return (item->_ownerId == _ownerId) ;
    }
public:
    int _ownerId;
};

class FindByRarity
{
public:
    // 함수객체를 사용하기 위한 연산자 오버로딩이 필요하다.
    bool operator() (const Item* item) {
        return (item->_rarity >= _rarity) ;
    }
public:
    int _rarity;
};

/* 위에서 함수 객체를 만들었으니 이제 bool(*func)(const Item*)과 같은 함수포인터는 사용하지 않아도 된다.
[함수포인터 사용]
Item* FindItem(Item items[], int itemCount, bool(*func)(const Item*)) {}

[함수객체 사용]
Item* findItem(Item items[], int itemCount, FindByOwnerId(or FindByRarity) selector) {}

하지만 여기서 한가지 문제가 추가적으로 발생한다 
FindByOwnerId FindByRarity 와 같은 함수객체를 둘 다 사용하기위해선 이를 인자값으로 받는 함수를 2개 만들어야 한다는 것이다.

이를 해결하기 위해서 지난 시간에 배운 Template을 사용하면 된다! */
template<typename T>
Item* FindItem(Item items[], int itemCount, T selector) {
    for (int x = 0; x < itemCount; x++) {
        Item* item = &items[x];

        if (selector(item)) return item;
    }

    return nullptr;
}

int main() {
    
    Item items[10];

    // 이제 위에서 만든 FindItem을 사용해보자!
    FindByOwnerId functor1;
    functor1._ownerId = 100;

    FindByRarity functor2;
    functor2._rarity = 2;

    // template을 통해 함수의 인자값에 원하는 값을 넣기만 하면 되는 구조로 바뀌었기에 훨씬 깔끔하다!
    FindItem(items, 10, functor1);
    FindItem(items, 10, functor2);

    return 0;
}