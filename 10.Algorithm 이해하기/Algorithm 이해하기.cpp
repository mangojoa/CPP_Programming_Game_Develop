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

		cout << "------------------------------------------------" << endl;
		cout << "algorithm을 이용한 간결한 부분" << endl;

		struct IsOdd {
			bool operator()(int n) {
				return (n % 2) == 0;
			}
		};

		// count_if(start, end, 함수 or 람다식) 으로 사용된다.
		// count / count_if 의 반환타입은 int 이기때문에 vector<int>::iterator 와 같은 것으로 받으면 안된다.
		int number = count_if(v.begin(), v.end(), IsOdd());
		// count_if를 타고 들어가서 확인하면 조건으로 넣은 함수에 맞는 조건일 경우, ++ 이 되는 로직을 확인할 수 있다.

		cout << "홀수인 수는 " << number << "개 입니다." << endl;

		// 모든 데이터가 홀수 입니까?
		bool b1 = all_of(v.begin(), v.end(), IsOdd());
		// 홀수인 데이터가 하나라도 있습니까?
		bool b2 = any_of(v.begin(), v.end(), IsOdd());
		// 모든 데이터가 홀수가 아닙니까?
		bool b3 = none_of(v.begin(), v.end(), IsOdd());

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

		cout << "------------------------------------------------" << endl;
		cout << "algorithm을 이용한 간결한 부분" << endl;

		struct MultiplyBy3 {
			void operator()(int& n) {
				n = n * 3;
			}
		};

		// for_each(start, end, 함수 or 람다식) 으로 사용된다.

		for_each(v.begin(), v.end(), MultiplyBy3());
	}

	// 홀수인 데이터를 일괄 삭제
	// remove
	// remove_if 이 두개의 함수는 특이하게(?) 작동한다고 한다.
	{
		// 홀수인 데이터를 삭제할때 이를 함부러 삭제하게 된다면 굉장히 위험한 상황이라고 배웠으며
		// 해당 데이터를 지우고 뒤의 데이터를 앞으로 복사하는 과정을 거친다면 
		// 이는 매우 비효율적으로 작동하게 될 것이라는 걸 앞서 배웠었다.

		/*for (vector<int>::iterator it = v.begin(); it != v.end();) {
			if ((*it % 2) != 0) it = v.erase(it);
		}*/

		v.clear();

		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);

		// std::remove(v.begin(), v.end(), 3);

		struct IsOdd {
			bool operator()(int n) {
				return (n % 2) != 0;
			}
		};

		// 이전 데이터의 상태
		// 1 2 3 4 5

		// 이후 데이터의 상태
		// 2 4 3 4 5

		// 뭔가 이상한 값으로 변해있다는 것을 알 수 있다. 

		/* 이 코드를 분석해보자!!
		template <class ForwardIt, class UnaryPredicate>
		ForwardIt remove_if(ForwardIt first, ForwardIt last, UnaryPredicate p) {
		  first = std::find_if(first, last, p); -> 우리가 찾아야하는 위치에 접근하는 코드
		  if (first != last)
			for (ForwardIt i = first; ++i != last;) -> 전체를 스캔하는 부분
			  if (!p(*i)) *first++ = std::move(*i); -> 해당하는 데이터가 아닌경우, 이를 이동시키는 코드
		  return first; -> 이 부분이 가장 중요

		  return 을 왜 first로 하는가?

		  이후 데이터의 상태를 보면
		  2 4 3 4 5

		  1 3 5 는 삭제의 대상 2 4 는 삭제의 대상이 아니다

		  위의 코드를 보면 if (!p(*i)) *first++ = std::move(*i); 코드에서 삭제의 대상이 아닌 것을 
		  앞으로 가져오는 코드를 볼 수 있다.

		  이후 뒤의 코드는 그대로 남게 되는데 (그러면 삭제가 안된거 아닌가?)

		  여기서 return 을 왜 first로 했는지 알 수 있다.

		  first는 삭제의 대상이 아닌 포인터를 반환한다. 
		  즉, 대상이 아닌 포인터 지점부터는 삭제를 진행해도 된다는 것이다.
		  
		}
		*/

		vector<int>::iterator it = std::remove_if(v.begin(), v.end(), IsOdd());
		v.erase(it, v.end());

		int a = 3;
	}

	return 0;
}