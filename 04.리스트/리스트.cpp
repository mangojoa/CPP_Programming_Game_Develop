#include <iostream>
#include <vector>
#include <list>
using namespace std;

/*
vector : �����迭
[ [1], [2], [3], [4], [5] ]


���� / ���� / ����
list : ���� ����Ʈ

[ [1], ------------> [2], ----> [3], --> [4], ------> [5] ]
�����Ͱ� �����Ǿ ������ �Ǵ� ������ vector�� �����ϴ�.
������ ���ӵ� ������ ������� �ʴ´ٴ� ���̴�.
(��, �ٷ� ������ �����Ͱ� �������� ���� �� �ִٴ� ���̴�.)

���� ����ó�� ���� �����Ͱ� �����ϴ� ���� Node��� ǥ���ϴµ�
Node�� ���ؼ� �켱 �˾ƺ���. */

/* �����ϰ� Node�� classȭ �ߴ�.
�̴� �켱������ _data �ȿ��� ���� �����Ѵٰ� �� ��,
_next ���� *(������)���̹Ƿ� ��� �ּҰ��� ���µ�
�� �ּҰ��� �ٷ� ���� ���� �ּҰ� �̶�� ���̴�.

�̷��� ������ ��, list�� ��� -> Node ���� ���� �̶�� ������ �����ȴ�. */

class Node {
public:
	int		_data;
	Node*	_next;
};

/* ���⼭ ��̷ο� ���� �ϳ� �߻��Ѵ�.
�ڱ� �ڽ��� �����Ǳ⵵ ����*/


int main() {

	/* list ���� ����Ʈ
	- list�� ���� ����
	- �߰� ����/����
	- ó��/�� ����/����
	- �������� */

	list<int> li;

	// list ���� ����!!
	for (int i = 0; i < 100; i++) {
		li.push_back(i); // �����͸� �ڿ� �о�ִ� �Լ�
	}

	// li.push_front(10); // �����͸� �տ� �о�ִ� �Լ�
	
	int size = li.size();
	// li.capacity(); �� �������� �ʴ´�.

	int first = li.front(); // vector = begin() / list = front()
	int last = li.back(); // vector = end() / list = back()

	list<int>::iterator itBegin = li.begin();
	list<int>::iterator itEnd = li.end();

	for (list<int>::iterator it = li.begin(); it != li.end(); ++it) {
		cout << *it << endl;
	}

	li.insert(itBegin, 100); // �ش� �ε��� �ڸ��� ���� �ִ´�.
	
	li.erase(li.begin()); // ��ġ�� �ε����� ���� �����.

	li.pop_front(); // ����Ʈ ���� �տ� ���� ����

	li.remove(10); // !!! value�� ���� ���� ������ element�� ��� ����

	/* ���� ��ɾȿ� �ִ� �Լ��� �ܿ�ٴ� �͵� �߿�������
	�������� �� ��� (list)�� ��� �����ϴ��� ������ �˰��־�� �Ѵٴ°� �߿��ϴ�. */

	return 0;
}