#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main() {

	/* list ���� ����Ʈ
	- list�� ���� ����
	- �߰� ����/����
	- ó��/�� ����/����
	- �������� */

	list<int> li;

	// list ���� ����!!
	for (int i = 0; i < 100; i++) {
		li.push_back(i); // �����͸� �ڿ� �о�ִ� �Լ�
	}

	// li.push_front(10); // �����͸� �տ� �о�ִ� �Լ�
	
	int size = li.size();
	// li.capacity(); �� �������� �ʴ´�.

	int first = li.front(); // vector = begin() / list = front()
	int last = li.back(); // vector = end() / list = back()

	list<int>::iterator itBegin = li.begin();
	list<int>::iterator itEnd = li.end(); 

	return 0;
}