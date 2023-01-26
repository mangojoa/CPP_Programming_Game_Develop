#include <iostream>
#include <iomanip>
using namespace std;

// 숫자를 입력받아 그 숫자의 제곱 형태로 출력을 하는 대신 이를 달팽이 처럼 출력하라!

const int MAX = 100;
int board[MAX][MAX] = {};
int N;

// Board 값 출력
void PrintBoard() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cout << setfill('0') << setw(2) << board[y][x] << " ";
		}
		cout << endl;
	}
}

enum DIR {
	RIGHT = 0,
	DOWN = 1,
	LEFT = 2,
	UP = 3
};

bool CanGo(int y, int x) {

	if (y < 0 || y >= N) return false;
	if (x < 0 || x >= N) return false;
	if (board[y][x] != 0) return false;

	return true;
}

// Board 값 설정
void setBoard() {

	int dir = RIGHT;

	// board에 넣을 값
	int count = 1;

	// x, y 축에 대한 변수값
	int y_way = 0;
	int x_way = 0;

	while (true) {
		board[y_way][x_way] = count;

		if (count == N * N) break;

		int nextY;
		int nextX;

		switch (dir)
		{
		case RIGHT:
			nextY = y_way;
			nextX = x_way + 1;
			break;
		case DOWN:
			nextY = y_way + 1;
			nextX = x_way;
			break;
		case LEFT:
			nextY = y_way;
			nextX = x_way - 1;
			break;
		case UP:
			nextY = y_way - 1;
			nextX = x_way;
			break;
		}
		
		if (CanGo(nextY, nextX)) {
			y_way = nextY;
			x_way = nextX;
			count++;
		} else {
			switch (dir) {
			case RIGHT: 
				dir = DOWN;
				break;
			case DOWN:
				dir = LEFT;
				break;
			case LEFT:
				dir = UP;
				break;
			case UP:
				dir = RIGHT;
				break;
			}

		}


	}

}

int main() {

	cin >> N;

	setBoard();

	PrintBoard();

	return 0;
}