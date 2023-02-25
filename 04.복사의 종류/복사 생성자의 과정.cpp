#include <iostream>
using namespace std;

class Pet {
    // Knight Ŭ������ ������ ������ Pet Ŭ������ �����.
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

// Knight�� �θ� Ŭ���� ������ ���� Player Ŭ���� ����
class Player{
public:
    Player() {
        cout << "Player()" << endl;
    }

    // ���� ������
    Player(const Player& player) {
        cout << "Player(const Player&)" << endl;
        _level = player._level;
    }

    // ���� ���� ������
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

    /* [ ���� ���� ]�� �����ϱ� ���� ���� ������ / ���� ���� ������ */
    Knight(const Knight& knight) : Player(knight), _pet(knight._pet) {
        _hp = knight._hp;
    }

    // Knight& operator=(const Knight& knight) {
    //     _hp = knight._hp;
    //     return *this;
    // }


public:
    int _hp = 100;
    Pet _pet; // ���� ���縦 ������� ���� ���̱⿡ ������ ����
};

int main() {

    /* �̿� ���� ���縦 �����ϸ� 
    - �Ͻ��� ���� ������ Steps
    1. �θ� Ŭ������ ���� ������ ȣ��
    2. �ɹ� Ŭ������ ���� ������ ȣ�� 
    {
        Pet _pet; ���·� �ɹ� �ȿ� �ۼ��� ���� ����
    }

    Player(const Player&)
    Pet(const Pet&) ���� ����� ����� Ȯ���� �� �ִ�.
    -----------------------------------------------
    �̷��� �� ���� ���� �����ڰ� ȣ���� �Ǵ� ���� �� �� �־���. 
    ������ ������ Knight�� ���� �����ڸ� ��������� �����ߴٸ� �̴� ��� �ɱ�?

    [Knight class ���� ���� ������]
    Knight(const Knight& knight) {
        _hp = knight._hp;
    }
    ���� �ڵ带 �ۼ��� ���¿��� �Ʒ��� �ڵ���� �ٽ� �����Ѵٸ� �̾߱Ⱑ �޶�����.

    Player()
    Pet()
    Knight(const Knight&) �� ����� ����� Ȯ���� �� �ִ�.
    ��, ��������� ���� �����ڸ� �ۼ��ߴٸ� �̿� ������ ��� �κ��� ���� �ް� å�������Ѵ�.
    �̸� �������� �ʴ´ٸ� �����Ϸ��� �⺻ �����ڸ� ȣ���� �� �ۿ� ���� �����̴�.

    �׷��ٸ� �̸� �����޾Ҵٸ� ��� ����ؾ� �ϴ°�?
    [������ Knight class ���� ���� ������]
    ���⼭�� Player / _pet �� ���� ���� �����ڸ� ȣ���ϴ� �κ��� �߰������� �ۼ����־�� �Ѵ�.

    Knight(const Knight& knight) : Player(knight), _pet(knight._pet) {
        _hp = knight._hp;
    }

    �̸� �����ϴ� ���, 
    Player(const Player&)
    Pet(const Pet&)
    Knight(const Knight&) �� ����Ǵ� ����� Ȯ���� �� �ִ�. */

    Knight knight;
    knight._hp = 200;

    Knight knight2 = knight;

    Knight knight3;
    knight3 = knight;

    /* [ ���� ���� Shallow Copy ]
    �ɹ� �����͸� ��Ʈ�� ������ '�Ȱ���' ���� (�޸� ���� ���� �״�� ����)

    Stack : Knight1 [ hp : 200 / pet : 0x012fc388]
    Stack : Knight2 [ hp : 200 / pet : 0x012fc388]
    Stack : Knight3 [ hp : 200 / pet : 0x012fc388] */

    /* [ ���� ���� Deep Copy ]
    �ɹ� �����Ͱ� ����(�ּ�) ���̶��, �����͸� ���� ������ش�. (���� ��ü�� �����ϴ� ������ ���� ���� ����)
    �����ʹ� �ּҰ� �ٱ��� -> ���ο� ��ü�� ���� -> ������ ��ü�� ����Ű�� ���°� �ȴ�.
    Stack : Knight1 [ hp : 0x112fc388 / pet : 0x042fc388]
    Stack : Knight2 [ hp : 0x212fc388 / pet : 0x052fc388]
    Stack : Knight3 [ hp : 0x312fc388 / pet : 0x062fc388] */

    /* ����)
    - �Ͻ��� ���� ������ Steps
    1. �θ� Ŭ������ ���� ������ ȣ��
    2. �ɹ� Ŭ������ ���� ������ ȣ�� 
    {
        Pet _pet; ���·� �ɹ� �ȿ� �ۼ��� ���� ����
    }
    ���� �ΰ��� �ش����� ���� ���,
    3. �ɹ��� �⺻ Ÿ���� ��� �޸� ���� (���� ����)

    - ����� ���� ������ Steps -> ����� ��� �κ��� ��Ʈ���Ѵٴ� �ǹ�
    1. �θ� Ŭ������ �⺻ ������ ȣ��
    2. �ɹ� Ŭ������ �⺻ ������ ȣ��

    */

    return 0;

}