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
    ~Item() {
        cout << "~Item()" << endl;
    }
public:
    int _itemType = 0;
    int _itemDbid = 0;

    char _dummy[4096] = {}; // �̷� ���� ����� ������
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
    ~Weapon()
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
    ~Armor()
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

    // �������� ���� Ŭ���� ������ ������ ��ȯ �׽�Ʈ
    {
        // Stack [ address ] -> Heap [ _hp(4) ]
        Knight* knight = new Knight();

        // Stack [ address ]
        Item* item = (Item*)knight;
        // �Ͻ������δ� �� �� ������ ��������δ� �����ϴ�.

        // ���� ��������� �츮�� ��ȯ�� �ؼ� ����ߴٰ� �����غ���
        item->_itemType = 1;
        item->_itemDbid = 2;

        /* ���� ���� �ڵ带 �����ϰ� �ȴٸ� �������� ��������?
        �̸� �����ϸ� -> knight �� ��ȿ ���� ������ 4byte�� �Ѿ ����ϴ� ������ ���ֵǱ⿡
        ù ��° ����Ǵ� item->_itemType = 1;�� ���� ���� �� ������ �ȴ�.

        ������ ������ �� ��° ����Ǵ� item->_itemDbid = 2; �������� �߻��ϰ� �ȴ�.
        �̴� �츮�� new Knight(); �� ���ؼ� �� ������ �Ҵ���� ��ŭ�� ���� �κи� ����ؾ��ϴµ�
        �̹� _dummy[4096] �̶�� ���� �����Ͱ� �ڸ���� �ִ� ������ ħ���ϴ� ���� �ȴ�.
        �� ����� �������� �Ѽ��� ����Ű�� �ִٴ� ������ �߻��ϴ� ���� �ȴ�.

        �׷��⿡ C++������ �̷��� ĳ���ÿ� ���� ���並 �ſ� ����ϰ� ���� �ʴ´ٸ� ũ���ð� ���� ����.

        ���� �̸� �ʱ⿡ ���� �� �ִ� delete knight; �� ���ؼ� �����˾��� ���� �ϴ� ����� ������
        �Ź� ���ϴ� ���� �ƴϱ⿡ ó������ ����ħ���� �Ͼ�� �ʴ��� Ȯ���� �ʿ��ϴ�.
        */
    }

    // �ڽ� -> �θ� ��ȯ �׽�Ʈ
    {
        Weapon* weapon = new Weapon();

        // Weapon�� Item �ΰ�? -> �翬�� ������ �ȴ�.
        // ���ʿ� �̴� ��� �����̱� ������ �����ϴ�.

        // �Դٰ� �Ͻ������� ������������ �ұ��ϰ� �����Ϸ��� �����ϴٰ� �������� ���ְ� �ִ�.
        Item* item = weapon;

        delete weapon;
    }

    // �θ� -> �ڽ� ��ȯ �׽�Ʈ
    {
        Item* item = new Item();

        // �켱������ item�� weapon�ΰ�? �װ��� ���� ���� �ƴ� ���� �ֱ� ������ 
        // �����Ϸ��� �ڵ������� Error�� ����ϰ� �ִ�.
        Weapon* weapon = (Weapon*)item; // ������ �̸� ������ ĳ�����ϰ� �ȴٸ�? �����ϴ�

        weapon->_damage = 10;
        // ������ ��ĳ������ �����ϰ� �ȴٸ� �� ������ �ʰ��ؼ� �޸𸮸� �ǵ帮�� ������ 
        // �������� ���� Ŭ���� ������ ������ ��ȯ �׽�Ʈ�� ���� ����� ���� �ȴ�.

        delete item;
    }

    // ��������� Ÿ�� ��ȯ�� ���� �׻� �����ؾ��Ѵ�!
    // �Ͻ������� �� ���� �����Ѱ�?
    // ��� ��������� Ÿ�� ��ȯ(ĳ����)�� ���ϸ� �Ǵ°� �ƴѰ�?

    // ��쿡 ���� �̴� �ƴ� �� �ִ�.
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

    }

    return 0;
}