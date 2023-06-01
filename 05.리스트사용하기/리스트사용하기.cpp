#include <iostream>
#include <vector>
#include <list>
using namespace std;

template<typename T>
class Node {
public:

	Node() : _next(nullptr), _prev(nullptr), _data(T()) {
	
	}

	Node(const T& value) : _next(nullptr), _prev(nullptr), _data(value) {
	
	}

public:
	Node*	_next;
	Node*	_prev;
	T		_date;
};

template<typename T>
class Iterator {
public:
	Iterator() : _node(nullptr) {}

	Iterator(Node<T>* node) : _node(node) {}

	//++it
	Iterator<T>& operator++() {
		_node = _node->_next;
		return *this;
	}

	//it++
	Iterator<T>& operator++(int) {
		Iterator<T> temp = *this;
		_node = _node->_next;

		return temp;
	}

	//--it
	Iterator<T>& operator--() {
		_node = _node->_prev;
		return *this;
	}

	//it--
	Iterator<T>& operator--(int) {
		Iterator<T> temp = *this;
		_node = _node->_prev;

		return temp;
	}

	T& operator*() {
		return _node->_data;
	}

	bool operator==(const Iterator& right) {
		return _node == right._node;
	}

	bool operator!=(const Iterator& right) {
		return _node != right._node;
	}

public:
	Node<T>* _node;
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
		/* List가 없어질때는 해야할 부분이 매우 많다.
		언제나 Node는 배열이 아닌 각각의 메모리에 저장된 개념이라는 것이다.
		그렇기에 이를 삭제하는 일에는 많은 시간이 들어간다. (vector에 비해) */

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

	/* 기능 중 insert()를 구현하기 위해서 AddNode의 return 형태가 Node<T>* 일 필요가 있다!
	왜냐하면 삭제->erase()를 사용하기 위해서! */
	Node<T>* AddNode(Node<T>* before, const T& value) {

		/* 만약 노드가 하나도 없는 초기상태라면 이 부분은 어떻게 작동하는가?
		원래대로라면 [header]에 접근하는 것은 불가능할 것이다.
		하지만 여기서는 header에도 접근이 가능한 노드를 설정했기에 가능하다.*/

		// [1] <-> [2] - [value] - [before] <-> [4] <-> [header] <->
		// 아직은 이 상태에서 양 옆을 연결해주는 작업을 진행해줘야 한다.
		Node<T>* node = new Node<T>(value);

		// [2] <-> [value] 작업완료
		Node<T>* prevNode = before->_prev;
		prevNode->_next = node;
		node->_prev = prevNode;

		// [value] <-> [4] 작업완료
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
	typedef Iterator<T> iterator;

	// iterator의 기본적인 기능에 대한 구현
	iterator begin() { return iterator(_header->_next); }
	iterator end() { return iterator(_header); }

	// insert / erase 의 기본적인 반환값에 대한 구현
	iterator insert(iterator it, const T& value) {
		AddNode(it._node, value);
		return iterator(node);
	}
	
	iterator erase(iterator it) {
		Node<T>* node = RemoveNode(it._node);
		return iterator(node);
	}

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
