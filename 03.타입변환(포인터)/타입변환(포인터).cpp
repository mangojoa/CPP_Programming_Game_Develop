#include <iostream>
using namespace std;

/* Ÿ�� ��ȯ (������)
�������� ����Ÿ�� ��ȯ�� ���ؼ� �˾ƺ������� �̴� ���������� ���� ������ �ʴ´�.
������ �����Ϳ� ���õ� Ÿ�Ժ�ȯ�� ���, ������ �� �� ���� ������ �̹� �ð����� Ÿ�Ժ�ȯ(������)�� ���� �˾ƺ���.
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

	char _dummy[4096] = {}; // �̷� ���� ������� ���� ������� ����
};

int main() {

	// ����
	{
		// Stack [ type(4) dbid(4) dummy(4096) ]
		Item item;

		// Stack [ �ּ� (4-8) ] -> Heap �ּ�[ type(4) dbid(4) dummy(4096) ]
		Item* item2 = new Item();
	}

	return 0;

}