#include <iostream>
using namespace std;

void Swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void Sort(int numbers[], int count) {

	for (int x = 0; x < count; x++) {

		// ���� ������ 
		int best = x;

		// �� ��
		for (int y = x + 1; y < count; y++) {
			if (numbers[y] < numbers[best]) 
				best = y;
		}

		// �� ��ü
		if (x != best)
			Swap(numbers[x], numbers[best]);
	}
}

void ChooseLatto(int numbers[]) {
	// �����Լ�
	srand((unsigned)time(0));

	int count = 0;
	while (count != 6) {
		int randValue = 1 + (rand() % 45);

		bool found = false;
		for (int i = 0; i < count; i++) {
			if (numbers[i] == randValue) {
				found = true;
				break;
			}
		}

		if (found == false) {
			numbers[count] = randValue;
			count++;
		}
	}

	Sort(numbers, 6);

}

int main() {
	
	// Swap �Լ� ����� 
	int a = 1;
	int b = 2;
	Swap(a, b);

	// �����Լ� ����� (�������ڰ� ���� ������ ����)
	const int count = 6;
	int numbers[6] = { 14, 45, 25, 31, 2, 6 };
	Sort(numbers, sizeof(numbers) / sizeof(int)); // �迭�� ũ�⸦ ������ Ÿ������ ������ ���������� �۵��ϰ� �� ����� ��� 

	// �ζ� ��ȣ ������
	ChooseLatto(numbers);

	for (int x = 0; x < 6; x++) { cout << numbers[x] << endl; }

}