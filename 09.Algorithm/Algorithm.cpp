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

	// Q1) number라는 숫자가 벡터안에 있는지 체크하는 기능 (bool, 첫 등장 iterator)
	{
		int number = 50;
		bool found = false;

		vector<int>::iterator it;

		for (vector<int>::iterator findIt = v.begin(); findIt < v.end(); ++findIt) {
			cout << *findIt << " " ;

			if (*findIt == number) found = true;
		}

		cout << endl;

		if (found) cout << number << "를 찾았습니다!" << endl;
		else cout << number << "를 찾지 못했습니다.." << endl;
	}

	cout << "------------------------------------------------" << endl;

	// Q1) 11로 나뉘는 숫자가 벡터안에 있는지 체크하는 기능 (bool, 첫 등장 iterator)
	{
		bool found = false;

		for (vector<int>::iterator it = v.begin(); it < v.end(); ++it) {
			if (*it % 11 == 0) {
				cout << *it << " ";
				found = true;
			}
		}

		cout << endl;

		if (found) cout << "11로 나누어지는 숫자가 존재합니다!" << endl;
		else cout << "11로 나누어지는 숫자가 존재하지 않습니다.." << endl;

	}

	cout << "------------------------------------------------" << endl;

	// Q1) 벡터안에 홀수가 몇개 있는지 체크하는 기능 (count)
	{
		int count = 0;

		for (vector<int>::iterator it = v.begin(); it < v.end(); ++it) {
			if (*it % 2 != 0) {
				cout << *it << " ";
				count++;
			}
		}

		cout << endl;

		cout << "홀수인 수는 " << count << "개 입니다." << endl;
	}

	cout << "------------------------------------------------" << endl;

	// Q1) 벡터안의 모든 숫자들에 3을 곱하는 기능
	{
		for (vector<int>::iterator it = v.begin(); it < v.end(); ++it) {
			int temp = (*it) * 3;
			cout << "이전 값: " << (*it);
			*it = temp;
			cout << " | 이후 값: " << (*it) << endl;
		}
	}

	return 0;
}