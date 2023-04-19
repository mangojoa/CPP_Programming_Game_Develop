#include <iostream>
using namespace std;

/* Ŭ���� ���ø��� ����ؾ� �ϴ� ����?
Ŭ������ ������ ���� �̿��� ���� �߰��ȴٰų� ������ �����ϴ� ������ Ÿ���� �ٸ���, 
Ŭ������ �׶����� �߰��ϴ� �۾��� �ſ� ��ȿ�����̴�.

�̷��� ��쿡 Ŭ���� ���ø��� �̿��ϸ� ���?
Ŭ����(���赵) �󿡼� ������ �����ϴ� �κ��� ���� �ʴ�. (�Լ� or ������ ���� ���� ���̴�.)
*/

// template<typename T> // -> type�� ������ T �̿ܿ��� �ٸ� ���ø� ���� ����� �� �ִ�.

/* ������ �޸� ���ڰ��� 2���� ���ø��� ������ٰ� ����.
�̶� �߰��� int SIZE = 10 �� Ŭ���� �ȿ��� ���� ������ �ش�ȴ�.

������ �̴� �������� �ʱⰪ�� ������ ���� ��, ������ ���ڰ��� ȣ��Ǵ� �Ϳ� ���� ����� �޶�����.
(�� ����� ���ڰ����� ���� return�� �ƴ� Ŭ������ �����Ǵ� ���������� ����� �ǹ��Ѵ�.) */
template<typename T, int SIZE = 10>
class RandomBox {
public:
	T GetRandomData() {
		int idx = rand() % SIZE;
		return _data[idx];
	}
public:
	T _data[SIZE];
};

/* Ŭ���� ���ø� ���� ���ø� Ư��ȭ�� ������ �����Ѵ�.
�켱 Ŭ���� �ȿ��� ���Ǵ� ���ڰ� �� ��ȯ���� Ư�� Ÿ���϶� '���ø� Ư��ȭ'�� ����Ѵ�.

���� ��� double Ÿ���� ���������� ��������� ��찡 �ִٸ� �Ʒ��� ���� �ۼ��Ǿ���Ѵ�.
template<[��õ� Ÿ��], �������ڰ�> 

���⼭�� ���÷� ���� ���� �����Ͽ����� �̴� �������� �ٸ��� ��Ÿ�� ���ɼ��� �ſ� ���⿡ �����ٴ� 
����� template<class ~~, typename ~~, ... > ���� Ȯ������.
*/
template<int SIZE>
class RandomBox<double, SIZE> {
public:
	double GetRandomData() {
		int idx = rand() % SIZE;
		return _data[idx];
	}
public:
	double _data[SIZE];
};


int main() {
	
	srand(static_cast<unsigned int>(time(nullptr)));

	/* template<typename T, int SIZE = 10>
	���� ���ø��� ������ ���¿��� �ʱⰪ�� �������� �ʴ´ٸ� SIZE ���� 10�� �ȴ�.

	������ �����Ѵٸ� ���⼭ �ٸ� ����� ������ �ȴ�.

	RandomBox<int, 10> rb1;

	RandomBox<int, 20> rb2;  �� �ΰ��� Ŭ���� ��ü�� ������ �� ����, 

	rb1 = rb2; �� �����ϰ� �ȴٸ� ��ġ���� �ʴ´ٰ� ���´�.
	�� ������ �޾��ִ� ���ڰ�(int SIZE)�� ���� �޶��� ������ �� �� �ִ� �κ��̴�.

	���ڰ�(int SIZE)�� ���Ҵٸ� rb1 = rb2; �� ���������� ����� ����Ǿ��� ���̴�. */



	RandomBox<int, 10> rb1;

	for (int i = 0; i < 10; i++) {
		rb1._data[i] = i;
	}

	int value1 = rb1.GetRandomData();
	cout << value1 << endl;

	RandomBox<int, 20> rb2;

	for (int i = 0; i < 10; i++) {
		rb2._data[i] = i + 0.5;
	}

	float value2 = rb2.GetRandomData();
	cout << value2 << endl;


	return 0;
}