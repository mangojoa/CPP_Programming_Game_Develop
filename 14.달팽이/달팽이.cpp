#include <iostream>
#include <iomanip>
using namespace std;

// 숫자를 입력받아 그 숫자의 제곱 형태로 출력을 하는 대신 이를 달팽이 처럼 출력하라!

const int MAX = 100;
int board[MAX][MAX] = {};
int N;

void PrintBoard() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cout << setfill('0') << setw(2) << board[y][x] << " ";
		}
		cout << endl;
	}
}

int main() {

	cin >> N;

	PrintBoard();

	return 0;
}