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
		// ���� �۾��� �ʿ�
		int newCapacity = static_cast<int>(_capacity * 1.5);

		if (newCapacity == _capacity) newCapacity++;

		// capacity�� ������ ũ�⸦ ���ߴٸ�
		// �̸� ���������� �ø� reserve() ������ ���� �����Ѵ�.
			reserve(newCapacity);
		}

		// ������ ����
		data[_size] = val;

		// ������ ���� ����
		_size++;
	}

	void reserve(int capacity) {
		_capacity = capacity;

		T* newData = new T[_capacity];

		// ������ ����.
		for (int i = 0; i < _size; i++) {
			newData[i] = _data[i];
		}
		
		// ������ �ִ� �����͸� ������.
		if (_data) delete[] _data;

		// ��ü
		_data = newData;
	}

	/* �� T&�� ������ �ؾ��ϴ°�?
	�켱������ ���� �Ϸ��� ������ �ش� �����Ϳ� �����ϴ� �� �Ӹ� �ƴ϶� 
	�����͸� �����ϴ� �ϵ� ���� �� �ֱ⿡ T&�� �����Ͽ�(�ּҰ����� �����Ͽ�)
	�����͸� �����ϰԲ� �ϴ� ���̴�. 

	�ܼ��� ��¿뵵�� ���ؼ� ��� T �ϳ��� ����ص� �ȴ�. */
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