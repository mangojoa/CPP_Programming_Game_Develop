#include <iostream>
using namespace std;

void Swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void Sort(int numbers[], int count) {

	for (int x = 0; x < count; x++) {

		// 제일 작은수 
		int best = x;

		// 수 비교
		for (int y = x + 1; y < count; y++) {
			if (numbers[y] < numbers[best]) 
				best = y;
		}

		// 수 교체
		if (x != best)
			Swap(numbers[x], numbers[best]);
	}
}

void ChooseLatto(int numbers[]) {
	// 랜덤함수
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
	
	// Swap 함수 만들기 
	int a = 1;
	int b = 2;
	Swap(a, b);

	// 정렬함수 만들기 (작은숫자가 먼저 오도록 정렬)
	const int count = 6;
	int numbers[6] = { 14, 45, 25, 31, 2, 6 };
	Sort(numbers, sizeof(numbers) / sizeof(int)); // 배열의 크기를 선언한 타입으로 나누어 유동적으로 작동하게 끔 만드는 방법 

	// 로또 번호 생성기
	ChooseLatto(numbers);

	for (int x = 0; x < 6; x++) { cout << numbers[x] << endl; }

}