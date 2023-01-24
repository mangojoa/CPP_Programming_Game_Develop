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

// 4. ���ڿ� �����̱� �Լ�
char* strCat(char* dest, char* src) {
	// int len = strLen(dest);

	// int i = 0;
	// while (src[i] != '\0') {
	// 	dest[len + i] = src[i];
	// 	i++;
	// }

	// dest[len + i] = '\0';

	// return dest;

	// pointer �� �̿��ϴ� ���
	char* ret = dest;

	while(*dest != '\0') { dest++; }

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';

	return ret;
	
}

// 5. �� ���ڿ��� ���ϴ� �Լ�
int strCmp(char* a, char* b) {
	int value;

	int i = 0;
	while (a[i] != '\0' || b[i] != '\0') {
		if (a[i] > b[i]) return 1;
		if (a[i] < b[i]) return -1;
	}

	return 0;
}

// 6. ���ڿ��� ������ �Լ�
void ReverseStr(char* str) {
	int len = strLen(str);

	for (int i = 0; i< len / 2; i++) {
		int temp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = temp;
	}

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
	//strcpy(b, a);

	// ���ڿ� ���� �Լ��� ����� �迭 ����
	strCpy(b, a);

	char c[BUF_SIZE] = "Hello";
	char d[BUF_SIZE] = "World";

	/* ���ڿ��� �����̴� �Լ� strcat(dest, src);
	src�� ���ڿ��� dest�� ���̴� ������ �Լ��̴� 
	dest�� ������ ����� '\0'�� �ٿ��־� �̾����� ����� �Լ���� �� �� ������ 
	'\0'�� �Լ� ��ü�� ���Ӱ� ���ŵ� �ϴ� �����̴�. */
	strcat(d, c);

	// ���ڿ��� �����̴� �Լ� strCat(dest, src);
	strCat(d, c); 

	/* ���ڿ� �� ���� ��Ұ� �ִ��� Ȯ���ϴ� �Լ� strcmp(a, b);
	�켱������ a�� b���� ���� ���� �� �ִ�. �׷��� �̸� �� ���ϴ°ž� ???
	if (a == b) { logic } �� �ϸ� ������ ���� �ƴѰ�?

	�̸� C�� ���鼭 ���� �򰥸��� �� �� �ִ� �κ��̶�� �� �� �ִ�.
	�켱 ������ a�� b�� �迭 ������ ���ڿ��̸� a�� b�� ��ü������ �޸��� ���� �ּҸ� ��Ÿ���ٰ� �� �� �ִ�.

	if (a == b) �� �����ϸ� ������ ���� ���ϴ� ���� �ƴ� �޸� �ּҸ� ���ϴ� ���� �ǹ��� ���� �ʴٴ� ����� ����ϰ� �ɰ��� ���ϴ�.
	��, ���빰�� ������ ���� ����� ��ġ�� �ٸ��� �����̶�� ���� ũ�� �ۿ��ϴ� ����̴�.

	�׸��� �߰������� ���Ϸ��� ���ڿ��� ���̰� ���ƾ��Ѵٴ� ���� ���� ū �����̴�.
	���ڿ��� ���̰� ���� �ٸ��ٸ� ���� �翬�� �ٸ��ٰ� ������ �����̴�.

	�̴� �ѱ��ھ� ���ϴ� ���� �������� ���Ѵ�. */ 
	int value = strcmp(a, b);
	/* ?? �� �̸� �޴� ���ڰ��� int�� �޾��ִ� ���ΰ�? strcmp() �Լ��� ��ȯ���� int �̱� �����̴�.

	�� int���� ��ȯ�ؾ� �ϴ� ������ �۵��ϴ°�? => ������ �����ϴ�. 
	��ǻ�ʹ� ���ڿ��� �״�� �������� �ʰ� �̸� �ƽ�Ű �ڵ��� ���·� �����ϰ� ���ϱ� ������ 
	�񱳰��� ���� ��������, ���� ũ�⿡ ���� ���ڸ� ��ȯ�ϴ� ���� �������� �Ǿ��־� int ���� ��ȯ�ϴ� ���̴�. */

	// �� ���ڿ��� ���ϴ� �Լ� strCmp(a, b);
	int value01 = strCmp(a, b);
	cout << value01 << endl;

	// revuese String ���ڵ����� �Լ� !
	ReverseStr(b);

	return 0;

}