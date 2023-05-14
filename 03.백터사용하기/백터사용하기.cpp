#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class Vector {
public:

	Vector() : _data(nullptr), _size(0), _capacity(0) {

	}
	~Vector() {
		if (_data) delete[] _data; 
	}

	int size() { return _size; }
	int capacity() { return _capacity; }

	void push_back(const T& val) {

		if (_size == _capacity) {
		// 증설 작업이 필요
		int newCapacity = static_cast<int>(_capacity * 1.5);

		if (newCapacity == _capacity) newCapacity++;

		// capacity를 증설할 크기를 정했다면
		// 이를 실질적으로 늘릴 reserve() 실행을 통해 진행한다.
			reserve(newCapacity);
		}

		// 데이터 저장
		data[_size] = val;

		// 데이터 개수 증가
		_size++;
	}

	void reserve(int capacity) {
		_capacity = capacity;

		T* newData = new T[_capacity];

		// 데이터 복사.
		for (int i = 0; i < _size; i++) {
			newData[i] = _data[i];
		}
		
		// 기존에 있던 데이터를 날린다.
		if (_data) delete[] _data;

		// 교체
		_data = newData;
	}

	/* 왜 T&로 진행을 해야하는가?
	우선적으로 지금 하려는 행위는 해당 데이터에 접근하는 것 뿐만 아니라 
	데이터를 수정하는 일도 있을 수 있기에 T&로 접근하여(주소값으로 접근하여)
	데이터를 수정하게끔 하는 것이다. 

	단순히 출력용도를 위해서 라면 T 하나만 사용해도 된다. */
	T& operator[] (const int pos) {
		return _data[pos];
	}

private:
	T* _data;
	int _size;
	int _capacity;
};

int main() {

	Vector<int> v;

	// v.reserve(100);

	for (int i = 0; i < 100; i++) {
		v.push_back(i);
		cout << v.size() << " " << v.capacity() << endl;
	}

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}

	cout << "-----------" << endl;

	/*for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
		cout << (*it) << endl;
	}*/

	return 0;
}