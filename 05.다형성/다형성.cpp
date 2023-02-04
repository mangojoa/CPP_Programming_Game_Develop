#include <iostream>
using namespace std;

/* ��ü���� (Object Oriented Programming)
- ��Ӽ�
- ���м�
- ������ ���� �����Ѵ�. */

/* ������(Polymorphism) = ���� �Ȱ�����, ����� �ٸ��� �����Ѵ�.
- �����ε�(Overloading) = �Լ� �ߺ� ���� = �Լ� �̸��� ����
- �������̵�(Overriding) = ������ = �θ� Ŭ������ �Լ��� �ڽ� Ŭ�������� ������
*/

class Player {
public:
	void Move() { cout << "Move Player!!" << endl; }

	// �����Լ� ����ϱ�
	virtual void VMove() { cout << "Move Player!!" << endl; }
public: 
	int _hp;
};

class Knight : public Player {
public:
	void Move() { cout << "Move Knight!!" << endl; }
	virtual void VMove() { cout << "Move Player!!" << endl; }
public:
	int _stamina;
};

class Mage : public Player {
public:
	void Move() { cout << "Move Mage!!" << endl; }
public:
	int _mp;
};

void MovePlayer(Player* player) {
	player->Move();
}

/* �������� �� ��ü���� �Լ��� ���� �����ϰ� ����߾���.

��� �̷��� ����Ѵٸ� �̴� ��ü������ ����ϴ� �ǹ̰� ���� 
void MovePlayer(Player *player) {}
void MoveKnight(Knight *knight) {} �̷��� ����ϰ� �ɶ� ��մ� ������ �ϳ� Ȯ���� �� �ִ�.

1. (��)���� Ŭ������ ���� Ŭ������ ���ڷ� �޴� �Լ��� ������� ���Ѵ�.
���� Ŭ���� = �÷��̾�
���� Ŭ���� = ���, ����, ���� �̶�� ������ �ִٰ� ����

MovePlayer(Player* player);
MoveAristocrat(Aristocrat* aristocrat);
MoveRoyalty(Royalty* royalty);

���� ���� �Լ��� ������ ��, 

MovePlayer(&aristocrat); ������ �÷��̾��ΰ�? -> true
������ �÷��̾��� ������ ���� �����̱⿡ �̴� ������ �Ǹ� ��ӹ��� ���� Ŭ������ ���ڰ����� �޴� �Լ��� ����� �� �ִ�.

MoveAristocrat(&player); �÷��̾�� �����ΰ�? -> false
������ ���� Ŭ������ ���ڰ����� �޴� �Լ��� ��� ���� Ŭ������ ���ڰ����� ���� ���, ������ �߻��ϰ� �ȴ�.
=> �÷��̾ �����ΰ�? ���� Ȥ�� ������ �� �ֱ⿡ �̿� ���� ���� false�� ��µȴ�.

���� Ŭ������ �������� �ڽ��� Ư�� �� ����� ����ϴ��� �� �� ����.
������ ���� Ŭ������ ���� ������ Ư���� ����� ��ӹް� �ִ����� �� �� �ֱ⿡ ������ ���̴�.

���� ��ʷ� �� �� �ִ� ���� 
(��)���� Ŭ������ Ȱ���� �Լ��� ����ٸ� �̴� ��ӹ��� ���� Ŭ���� ���ΰ� ����� �� �ֱ⿡ �ڵ带 �ۼ��ϴ� ȿ���� ���� �� �ִ�.
(�̰� �ٷ� ��ü������ �����̴�!) */

int main() {
	Knight k;
	/* �ٷ� �� ��찡 ���� Ŭ������ ���ڰ��� ���ؼ� ���� Ŭ������ ���ڰ��� �޴� �Լ��� �����ϴ� �κ��̴�.
	*/
	MovePlayer(&k);

}