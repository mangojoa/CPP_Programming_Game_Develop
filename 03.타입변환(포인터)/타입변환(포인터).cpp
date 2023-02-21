#include <iostream>
using namespace std;

/* 타입 변환 (포인터)
지난번에 참조타입 변환에 대해서 알아보았지만 이는 현업에서도 자주 사용되지 않는다.
하지만 포인터와 관련된 타입변환의 경우, 땔래야 땔 수 없기 때문에 이번 시간에는 타입변환(포인터)에 대해 알아보자.
*/

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

	char _dummy[4096] = {}; // 이런 저런 정보들로 인해 비대해진 정보
};

/* 이 두 함수의 차이점에 대하여
void TestItem(Item item) 은 인자를 받아서 복사하는 개념에 해당하기에 
생성자나 소멸자를 실행하게 된다. 이때 실행되는 생성자/소멸자는 복사 생성자/소멸자가 실행된다.

하지만 여기서 문제가 발생한다. class에 담긴 자료가 많으면 많을 수록 이에 대한 부하가 발생할 수 있다는 것인데
Item 클래스 안의 _dummy[4096]의 크기 + @ 로 사용하지도 않는 양의 메모리를 매번 받다보면 문제가 될 양상이기 때문!

void TestItemPtr(Item* item) 은 인자를 받을 때, 무언가를 복사하는 개념이 아닌
이에 대한 주소값에 접근하는 것이기에 생성자/소멸자가 출력되지 않는다.

*/
void TestItem(Item item) {

}

void TestItemPtr(Item* item) {

}

int main() {

	// 복습
	{
		// Stack [ type(4) dbid(4) dummy(4096) ]
		Item item;

		// Stack [ 주소 (4-8) ] -> Heap 주소[ type(4) dbid(4) dummy(4096) ]
		Item* item2 = new Item();

		// 인자값이 일반적이라면 이는 해당하는 변수를 넣어주면 된다.
		// 하지만 포인터의 경우, 포인터라는 것을 명시해야 한다.
		TestItem(item);
		TestItem(*item2);
		
		// 하지만 인자값이 포인터형 이라면 이야기가 다르다.
		// 엄연히 주소값을 받아야하기 때문에 일반 변수의 경우 주소값을 명시해야 한다.
		TestItemPtr(&item);
		TestItemPtr(item2);

		// 메모리 누수(Memory Leek)가 일어날 수 있기에 이에 대한 삭제를 진행해줘야 한다.
		delete item2;
	}

	// 배열
	{
		// 진짜 아이템이 100개가 있는 것 (스택 메모리에 올라와 있는 개념)
		Item item3[100] = {};

		// 포인터는 반면에 아이템이 100개가 있는 것이 아니라.
		// 아이템을 가리키는 바구니가 100개가 있는 개념이다. 실제 아이템은 1개도 없을 수도 있다.
		Item* item4[100] = {};
	}

	return 0;

}