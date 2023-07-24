#include <iostream>
#include <vector>
using namespace std;

int main() {

	srand(static_cast<unsigned int>(time(nullptr)));

	vector<int> v;

	for (int i = 0; i < 100; i++) {
		int num = rand() % 100;
		v.push_back(num);
	}
	/* ---------------------------------------------- */

	// Q1) number��� ���ڰ� ���;ȿ� �ִ��� üũ�ϴ� ��� (bool, ù ���� iterator)
	{
		int number = 50;
		bool found = false;

		vector<int>::iterator it;

		for (vector<int>::iterator findIt = v.begin(); findIt < v.end(); ++findIt) {
			cout << *findIt << " " ;

			if (*findIt == number) found = true;
		}

		cout << endl;

		if (found) cout << number << "�� ã�ҽ��ϴ�!" << endl;
		else cout << number << "�� ã�� ���߽��ϴ�.." << endl;
	}

	cout << "------------------------------------------------" << endl;

	// Q1) 11�� ������ ���ڰ� ���;ȿ� �ִ��� üũ�ϴ� ��� (bool, ù ���� iterator)
	{
		bool found = false;

		for (vector<int>::iterator it = v.begin(); it < v.end(); ++it) {
			if (*it % 11 == 0) {
				cout << *it << " ";
				found = true;
			}
		}

		cout << endl;

		if (found) cout << "11�� ���������� ���ڰ� �����մϴ�!" << endl;
		else cout << "11�� ���������� ���ڰ� �������� �ʽ��ϴ�.." << endl;

	}

	cout << "------------------------------------------------" << endl;

	// Q1) ���;ȿ� Ȧ���� � �ִ��� üũ�ϴ� ��� (count)
	{
		int count = 0;

		for (vector<int>::iterator it = v.begin(); it < v.end(); ++it) {
			if (*it % 2 != 0) {
				cout << *it << " ";
				count++;
			}
		}

		cout << endl;

		cout << "Ȧ���� ���� " << count << "�� �Դϴ�." << endl;
	}

	cout << "------------------------------------------------" << endl;

	// Q1) ���;��� ��� ���ڵ鿡 3�� ���ϴ� ���
	{
		for (vector<int>::iterator it = v.begin(); it < v.end(); ++it) {
			int temp = (*it) * 3;
			cout << "���� ��: " << (*it);
			*it = temp;
			cout << " | ���� ��: " << (*it) << endl;
		}
	}

	return 0;
}