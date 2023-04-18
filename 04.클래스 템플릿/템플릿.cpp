#include <iostream>
using namespace std;

/* Ŭ���� ���ø��� ����ؾ� �ϴ� ����?
Ŭ������ ������ ���� �̿��� ���� �߰��ȴٰų� ������ �����ϴ� ������ Ÿ���� �ٸ���, 
Ŭ������ �׶����� �߰��ϴ� �۾��� �ſ� ��ȿ�����̴�.

�̷��� ��쿡 Ŭ���� ���ø��� �̿��ϸ� ���?
Ŭ����(���赵) �󿡼� ������ �����ϴ� �κ��� ���� �ʴ�. (�Լ� or ������ ���� ���� ���̴�.)
*/

template<typename T> // -> type�� ������ T �̿ܿ��� �ٸ� ���ø� ���� ����� �� �ִ�.
class RandomBox {
public:
	T GetRandomData() {
		int idx = rand() % 10;
		return _data[idx];
	}
public:
	T _data[10];
};

int main() {
	
	srand(static_cast<unsigned int>(time(nullptr)));

	RandomBox<int> rb1;

	for (int i = 0; i < 10; i++) {
		rb1._data[i] = i;
	}

	int value1 = rb1.GetRandomData();
	cout << value1 << endl;

	RandomBox<float> rb2;

	for (int i = 0; i < 10; i++) {
		rb2._data[i] = i + 0.5f;
	}

	float value2 = rb2.GetRandomData();
	cout << value2 << endl;


	return 0;
}