#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

class Player {
public:
	void Attack() {
		cout << "Player!!" << endl;
	}
};

class Knight : public Player {
public:

	// ������(override) �� �����̶�� ���� �ȴ�.
	void Attack() {
		cout << "Knight!!" << endl;
	}

};

int main() {

	/* override, final
	* �̴� �����Լ��� ������ �ſ� ū �κ��̴�. (��ü������ ��? �̶�� �Ѵ�.)
	*/

	// Knight ���� ���� Attack�� ����ϴ� ����
	Knight* k = new Knight();
	k->Attack();

	/*	class Knight : public Player (���)�� ������ ���Ǿ��⿡!
		�̴� Knight ���� ���� Attack�� ������� ������?
		(�׷��� �����ߴٸ� ������ ũ��... )
		-> �̴� �ٸ��ƴ� Player* Ÿ���� �������̱� ������ Knight �� �ƴ� Player�� Attack�� ����ȴ�.
	*/
	Player* p = new Knight();
	p->Attack();

	/* ���� ��Ȳ�� �ذ��ϱ� ���ؼ��� ��� �ؾ��ϴ� �ɱ�? (�̹� ������ �����.)
	������ִ� Player �� �Լ��� �����Լ�(virtual function)���� �ۼ��Ǿ�� �Ѵٴ� ���� �ؾ�� �ȵȴ�.

	������ �Ѱ��� �˾Ƶξ�� �Ѵ�. 
	�ֻ�� Ŭ������ virtual function ���� �ۼ��� �Լ��� ��ӵǴ��� �����Լ��� �ش��Ѵ�.

	�׷��ٸ� �츮�� ��𼭺��� virtual function �� ����� ������ �� �ʿ䰡 ������?
	-> �̴� �翬�ϰԵ� �˾ƾ��Ѵ�.
	
	�̸� �˾ƾ��ϴ� ������ �˾ƺ���.

	�켱������ �Ʒ��� �ڵ� ��Ȳ�̶�� ����. */

	{
		class Creature01 {
		public:
			virtual void Attack() {}
		};

		class Player01 : public Creature01 {
		public:
			void Attack() {}
		};

		class Knight01 : public Player01 {
		public:
			void Attack() {}
		};


		Creature01* c = new Knight01();
		c->Attack();

	}

	/* �Ʒ��� ��ӵ� ��� Attack() �Լ����� virtual �Ӽ��� �پ��ִٰ� ���� �ȴ�.
    ���� �ڵ带 ���� Creature �� �ֻ�ܿ� �ش��ϱ⿡ virtual(�����Լ�)�� �����̴�.

	������ ���� ������ ���� �ٲ�ٸ� ��� �ɱ� ? */ 
	{
		class Creature01 {
		};

		class Player01 : public Creature01 {
		public:
			virtual void Attack() {}
		};

		class Knight01 : public Player01 {
		public:
			void Attack() {}
		};


		Creature01* c = new Knight01();
		c->Attack(); // <- �ű��ϰԵ� �� �ڵ�� ������ �޸� ����� �� ���� ���� Ȯ�εȴ�.

		/* ���� �ڵ� ������ �ٸ� ��
		1. �ֻ�� Ŭ������ virtual function�� �����ߴٴ� ��
		2. virtual function�� �������� �ٲ���ٴ� �� 

		�� �ΰ����� ���� ���� TEXTRPG���� ���Ǿ��� ������ �ڵ尡 ���������� �۵����� �ʴ� ����� �� �� �ִ�.

		*/
	}

	return 0;
}