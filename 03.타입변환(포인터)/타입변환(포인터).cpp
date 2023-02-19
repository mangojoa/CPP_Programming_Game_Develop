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

int main() {

	// 복습
	{
		// Stack [ type(4) dbid(4) dummy(4096) ]
		Item item;

		// Stack [ 주소 (4-8) ] -> Heap 주소[ type(4) dbid(4) dummy(4096) ]
		Item* item2 = new Item();
	}

	return 0;

}