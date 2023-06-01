#include <iostream>
#include <vector>
#include <list>
using namespace std;

template<typename T>
class Node {
public:

	Node() : _next(nullptr), _prev(nullptr), _data(T()) {}
	Node(const T& value) : _next(nullptr), _prev(nullptr), _data(value) {}

public:
	Node*	_next;
	Node*	_prev;
	T		_date;
};

// [1] <-> [2] <-> [3] <-> [header] <->
template<typename T>
class List {
public:
	List() : _size(0) {
		_header = new Node<T>();
		_header->_next = _header;
		_header->_prev = _header;
	}
	~List() {
		/* List�� ���������� �ؾ��� �κ��� �ſ� ����.
		������ Node�� �迭�� �ƴ� ������ �޸𸮿� ����� �����̶�� ���̴�.
		�׷��⿡ �̸� �����ϴ� �Ͽ��� ���� �ð��� ����. (vector�� ����) */

		while (_size > 0) pop_back();
		delete _header;
	}

	void push_back(const T& value) {
		AddNode(_header, value);
	}

	void pop_back() {
		RemoveNode(_header->_prev);
	}

	// <-> [header] <->
	// [1] <-> [2] <-> [before] <-> [4] <-> [header] <->
	// [1] <-> [2] <-> [value] <-> [before] <-> [4] <-> [header] <->

	/* ��� �� insert()�� �����ϱ� ���ؼ� AddNode�� return ���°� Node<T>* �� �ʿ䰡 �ִ�!
	�ֳ��ϸ� ����->erase()�� ����ϱ� ���ؼ�! */
	Node<T>* AddNode(Node<T>* before, const T& value) {

		/* ���� ��尡 �ϳ��� ���� �ʱ���¶�� �� �κ��� ��� �۵��ϴ°�?
		������ζ�� [header]�� �����ϴ� ���� �Ұ����� ���̴�.
		������ ���⼭�� header���� ������ ������ ��带 �����߱⿡ �����ϴ�.*/

		// [1] <-> [2] - [value] - [before] <-> [4] <-> [header] <->
		// ������ �� ���¿��� �� ���� �������ִ� �۾��� ��������� �Ѵ�.
		Node<T>* node = new Node<T>(value);

		// [2] <-> [value] �۾��Ϸ�
		Node<T>* prevNode = before->_prev;
		prevNode->_next = node;
		node->_prev = prevNode;

		// [value] <-> [4] �۾��Ϸ�
		node->_next = before;
		before->_prev = node;

		_size++;
	}

	// [1] <-> [2] <-> [node] <-> [4] <-> [header] <->
	// [1] <-> [2] <-> [4] <-> [header] <->
	Node<T>* RemoveNode(Node<T>* node) {

		Node<T>* prevNode = node->_prev;
		Node<T>* nextNode = node->_next;

		prevNode->_next = nextNode;
		nextNode->_prev = prevNode;

		delete node;

		_size--;

		return nextNode;
	}

	int size() { return _size; }

public:
	Node<T>* _header;
	int _size;
};

int main() {

	list<int> li;

	list<int>::iterator eraseIt;

	for (int i = 0; i < 10; i++) {
		if (i == 5) eraseIt = li.insert(li.end(), i);
		else li.push_back(i);
	}

	li.pop_back();

	li.erase(eraseIt);

	for (list<int>::iterator it = li.begin(); it != li.end(); ++it) {
		cout << (*it) << endl;
	}

	return 0;
}
