#include <iostream>
using namespace std;

/* C++ ���� ���ڿ� String�� ���� ���� �ٷ�� ���� 
* C ��Ÿ���� ���ڿ��� �ٷ�� ����� �Բ� ���� ������ Ǯ���. */

// 2. str�̶�� ���ڿ��� ���̸� ��ȯ�ϴ� �Լ��� ������! (strlen �̶�� �Լ��� ������� �ʰ� ����)
int strLen(const char* str) {
	int count = 0;

	while (str[count] != '\0') {
		count++;
	}

	return count;
}

int main() {

	const int BUF_SIZE = 100;

	char a[BUF_SIZE] = "Hello";
	
	// 1. a�� ����� �����غ���!
	int len = sizeof(a);
	cout << len << endl; // �� �����ϸ� �̴� BUF_SIZE�� ��Ÿ���� �� �ۿ� ���Ѵ�.
	// a�� ���ʿ� �迭�̸� sizeof(a)�� ���ؼ��� a�� �迭 ����� �� �� �ִ�.

	// �׷� ������ ����ִ� ���� ���̸� ���Ҷ��� � ����� ����ؾ� �ϴ°�?
	int realLen01 = strlen(a);
	cout << realLen01 << endl; // �̸� ���� �迭�� ���̰� �ƴ� �迭 ���� ���� ���� ���̸� ���� �� �ִ�.

	int realLen02 = strLen(a);
	cout << realLen02 << endl; // int strLen(const char* str) �Լ��� ���� ���

}