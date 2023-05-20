#include <iostream>
#include <vector>
#include <list>
using namespace std;

/*
vector : 동적배열
[ [1], [2], [3], [4], [5] ]


단일 / 이중 / 원형
list : 연결 리스트

[ [1], ------------> [2], ----> [3], --> [4], ------> [5] ]
데이터가 나열되어서 저장이 되는 개념은 vector와 동일하다.
하지만 연속된 개념이 적용되지 않는다는 것이다.
(즉, 바로 다음에 데이터가 존재하지 않을 수 있다는 것이다.)

위의 설명처럼 다음 데이터가 존재하는 곳을 Node라고 표현하는데
Node에 대해서 우선 알아보자. */

/* 간단하게 Node를 class화 했다.
이는 우선적으로 _data 안에는 값이 존재한다고 할 때,
_next 에는 *(포인터)형이므로 어떠한 주소값이 들어가는데
이 주소값이 바로 다음 값이 주소값 이라는 것이다.

이렇게 보았을 때, list의 경우 -> Node 들의 집합 이라는 개념이 성립된다. */

class Node {
public:
	int		_data;
	Node*	_next;
};

/* 여기서 흥미로운 점이 하나 발생한다.
자기 자신이 생성되기도 전에*/


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

	for (list<int>::iterator it = li.begin(); it != li.end(); ++it) {
		cout << *it << endl;
	}

	li.insert(itBegin, 100); // 해당 인덱스 자리에 값을 넣는다.
	
	li.erase(li.begin()); // 위치한 인덱스의 값을 지운다.

	li.pop_front(); // 리스트 제일 앞에 원소 삭제

	li.remove(10); // !!! value와 같은 값을 가지는 element를 모두 제거

	/* 위의 기능안에 있는 함수를 외운다는 것도 중요하지만
	무엇보다 이 기능 (list)가 어떻게 동작하는지 원리를 알고있어야 한다는게 중요하다. */

	return 0;
}