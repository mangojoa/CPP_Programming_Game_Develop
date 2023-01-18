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

#pragma warning(disable: 4996)
// 3. ���ڿ� ���� �Լ�
void strCpy(char* dest, char* src) {
	
	/*int count = 0;
	
	bool ready = true;
	
	while (ready) {
		dest[count] = src[count];
		cout << dest[count] << endl;
		if (src[count] == '\0') ready = false;

		count++;
	}
	
	return dest;
	*/

	// �����͸� �̿��ϴ� ���
	while (*src != '\0') {

		// *dest++ = *src++; ���ε� �����ϴ�.
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
}


int main() {

	const int BUF_SIZE = 100;

	char a[BUF_SIZE] = "Hello";
	char b[BUF_SIZE];
	
	// 1. a�� ����� �����غ���!
	int len = sizeof(a);
	cout << len << endl; // �� �����ϸ� �̴� BUF_SIZE�� ��Ÿ���� �� �ۿ� ���Ѵ�.
	// a�� ���ʿ� �迭�̸� sizeof(a)�� ���ؼ��� a�� �迭 ����� �� �� �ִ�.

	// �׷� ������ ����ִ� ���� ���̸� ���Ҷ��� � ����� ����ؾ� �ϴ°�?
	int realLen01 = strlen(a);
	cout << realLen01 << endl; // �̸� ���� �迭�� ���̰� �ƴ� �迭 ���� ���� ���� ���̸� ���� �� �ִ�.

	int realLen02 = strLen(a);
	cout << realLen02 << endl; // int strLen(const char* str) �Լ��� ���� ���

	// b = a; // <- �迭�� �Ϲ����� ������ �����ϴ� ��ó�� ������ �� ����. (�޸��� ù ��° ���� ��Ÿ���� ������ �̴� ���簡 �ȵǱ� �����̴�.)

	/* ���ڿ��� �����ϴ� �Լ� strcpy()
	�� �Լ��� ��� �� ���� ���ڰ��� ������ ù ��° ���ڰ��� �� ��° ���ڰ��� �����Ѵٴ� �ǹ��̴�.
	������ �̴� ��~!~~~�� ������ �Լ��� ���輺�� �ſ� ������ �����Ϸ��� ���� ������ ����ϴ� ��찡 �ִ�.
	�׷����� �ұ��ϰ� ����ϰ� �ʹٸ� #pragma warning(disable: 4996) �̶�� ���� int main() {} ���� �����ϸ� ����� �� �ִ�.

	strcpy_s() ��� �Լ��� �ִ� (strcpy()�� �������� ������ ������ �Լ���� �� �� �ִ�.) */

	// strcpy()
	strCpy(b, a);


	return 0;

}