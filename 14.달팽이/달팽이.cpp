#include <iostream>
#include <iomanip>
using namespace std;

// ���ڸ� �Է¹޾� �� ������ ���� ���·� ����� �ϴ� ��� �̸� ������ ó�� ����϶�!

const int MAX = 100;
int board[MAX][MAX] = {};
int N;

// Board �� ���
void PrintBoard() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cout << setfill('0') << setw(2) << board[y][x] << " ";
		}
		cout << endl;
	}
}

void printXYway(int x, int y) {
	cout << "-----------------------" << endl;
	cout << "Y_way : " << y << " | " << "X_way : " << x << endl; 
}

// Board �� ����
void setBoard(int N) {
	int number = N;
	cout << "insert INT : " << number << endl;

	// board�� ���� �� (++�� ����)
	int count = 0;

	// x, y �࿡ ���� ������
	int x_way = 0; // x �� ����
	int y_way = 0; // y �� ����

	printXYway(x_way, y_way);

	for (int x = x_way; x < number; x++) {
		board[y_way][x] = ++count;
		if (x == (number-1)) { 
			x_way = x;
			y_way++;
		}
	}

	printXYway(x_way, y_way);

	for (int y = y_way; y < number; y++) {
		board[y][x_way] = ++count;
		if (y == (number-1)) {
			x_way--;
			y_way = y;
		}
	}

	printXYway(x_way, y_way);
	
	for (int x = (x_way+1); x--;) {
		board[y_way][x] = ++count;
		if (x == (number-number)) {
			x_way -= x_way; 
			y_way--;
			break;
		}
	}

	printXYway(x_way, y_way);

	for (int y = (y_way+1); y--;) {
		board[y][x_way] = ++count;
		if (y == number - (number -1)) {
			x_way = y;
			y_way = --y;
		}
	}

	printXYway(x_way, y_way);
}

int main() {

	cin >> N;

	setBoard(N);

	PrintBoard();

	return 0;
}