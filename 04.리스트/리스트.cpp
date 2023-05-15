#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main() {

	/* list 연결 리스트
	- list의 동작 원리
	- 중간 삽입/삭제
	- 처음/끝 삽입/삭제
	- 임의접근 */

	list<int> li;

	// list 기초 사용법!!
	for (int i = 0; i < 100; i++) {
		li.push_back(i); // 데이터를 뒤에 밀어넣는 함수
	}

	// li.push_front(10); // 데이터를 앞에 밀어넣는 함수
	
	int size = li.size();
	// li.capacity(); 는 존재하지 않는다.

	int first = li.front(); // vector = begin() / list = front()
	int last = li.back(); // vector = end() / list = back()

	list<int>::iterator itBegin = li.begin();
	list<int>::iterator itEnd = li.end(); 

	return 0;
}