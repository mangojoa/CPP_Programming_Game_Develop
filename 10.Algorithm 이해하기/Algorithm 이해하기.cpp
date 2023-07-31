#include <iostream>
#include <vector>
using namespace std;

/* 알고리즘을 통해 코드의 가독성을 높여보자. */
#include <algorithm>

/* 자료구조와 알고리즘
* 
* 위의 둘을 같은 것으로 이해하는 경우가 있다. 하지만 어면히 다른것이다.
* 
* 자료구조 = [데이터를 저장하는 구조]
* 알고리즘 = [데이터를 어떻게 사용할 것인가?]
* 
* 이는 1+1과 같은 짝꿍 같은 개념으로 통용된다.
*/

/* 오늘 배울 알고리즘 기능들

find 
find_if
count
count_if
all_of
any_of
none_of
for_each
remove
remove_if

활용빈도가 높은 친구들이며 이를 이용할줄 안다면 나머지는 충분하다고 한다!
*/

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

		for (vector<int>::iterator findIt = v.begin(); findIt < v.end(); ++findIt) {
			cout << *findIt << " ";

			if (*findIt == number) found = true;
		}

		cout << endl;

		if (found) cout << number << "를 찾았습니다!" << endl;
		else cout << number << "를 찾지 못했습니다.." << endl;

		cout << "------------------------------------------------" << endl;
		cout << "algorithm을 이용한 간결한 부분" << endl;

		// find(start, end, target); 형식으로 사용하면 된다. 
		// 위의 코드와는 다르게 매우 간결한 것을 확인할 수 있다.
		vector<int>::iterator itFind = find(v.begin(), v.end(), number);
		// C++ 11 이후부터는 auto 라는 문법을 통해 더욱 간결하게 작성할 수 있다.
		// auto itFind = find(v.begin(), v.end(), number);

		if (itFind == v.end()) cout << "찾지 못했습니다..." << endl;
		else cout << "찾았습니다!" << endl;

		cout << endl;
	}

	cout << "------------------------------------------------" << endl;

	// Q2) 11로 나뉘는 숫자가 벡터안에 있는지 체크하는 기능 (bool, 첫 등장 iterator)
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

		cout << "------------------------------------------------" << endl;
		cout << "algorithm을 이용한 간결한 부분" << endl;

		struct CanDivideBy11 {
			bool operator()(int n) {
				return (n % 11) == 0;
			}
		};

		// find_if(start, end, 함수 or 참조자); 형식으로 사용하면 된다.
		// 사실은 어떠한 조건을 넣어야 하고 이를 만족하기 위해서는 함수 혹은 람다식을 이용한 방법을 사용한다.
		// 하지만 여기서는 근.본을 알기 위해서 함수로 진행한다.
		vector<int>::iterator itFind = find_if(v.begin(), v.end(), CanDivideBy11());

		// 람다식을 이용한 일회성 함수를 적용시킨 코드
		// vector<int>::iterator itFind = find_if(v.begin(), v.end(), [](int n) { return (n % 11) == 0; });

		if (itFind == v.end()) cout << "찾지 못했습니다..." << endl;
		else cout << "찾았습니다!" << endl;

		cout << endl;

	}

	cout << "------------------------------------------------" << endl;

	// Q3) 벡터안에 홀수가 몇개 있는지 체크하는 기능 (count)
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

	// Q4) 벡터안의 모든 숫자들에 3을 곱하는 기능
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