#include <iostream>
#include <vector>
#include <list>
using namespace std;

/*
vector : 동적배열
[ [1], [2], [3], [4], [5] ]


단일 / 이중 / 원형
list : 연결 리스트

** 단일리스트
[ [1], ------------> [2], ----> [3], --> [4], ------> [5] ]

** 이중리스트
[ [1], <-----------> [2], <---> [3], <-> [4], <-----> [5] ]

** 원형리스트
[ [1], <-----------> [2], <---> [3], <-> [4], <-----> [5], <-> ]

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
	Node* _next;
	Node* _prev;
	int		_data;
};

/* 여기서 흥미로운 점이 하나 발생한다.
자기 자신이 생성되기도 전에 자신을 타입으로 생성한다? 
매우 낮설어 할 수 있다.

class Node2 {
public:
	int		_data;
	Node2 _next;
};

이렇게 생성을 한다고 할 때, 컴파일러는 생성이 되지 않는다고 한다. 
왜 ? => 이를 살펴보면 
[ data(4)  next(  data(4)  next( data(4)  next( ........... ) ) ] 

이렇게 무한정으로 계속 생성이 되는 구조로 이어지기 때문에 
컴파일러는 이를 수행할 수 없다고 Error를 발생시킬 것이다.

그럼 왜 class Node는 되는것인가?
왜? => 이를 살펴보면
class Node {
public:
	int		_data;
	Node*	_next;
};

Node*의 포인터 값을 들고 진행하고 있기 때문에 가능한 것이라고 컴파일러는 인식한다.
[ data(4) next(4/8) ] -> 왜 nest() 에 4/8 로 기입되는가? x64 x86 으로 실행하느냐에 따라서
용량이 정해지기 때문에 이는 가능한 이야기라는 것이다. 

-> 이후 Node 안에 무엇이 들어있는지는 추후의 일이고
Node -> Node 가 있다는 개념을 알고만 있자... */


int main() {

	/* list 연결 리스트
	- list의 동작 원리
	- 중간 삽입/삭제
	- 처음/끝 삽입/삭제
	- 임의접근 
	
	1. list의 중간 삽입/삭제에 대하여
	vector와는 달리 list는 각자의 다음/이전의 주소값을 알고 있기 때문에 중간에 삽입/삭제를 진행하더라도

	다음/이전의 주소값이 유효한 값이라면 이는 용이하게 진행된다는 것을 알 수 있다.

	2. list의 처음/끝 삽입/삭제에 대하여
	vector의 경우, 처음 삽입/삭제는 한 칸을 밀어내고 그 칸에 값을 집어 넣는 형식이지만
	list는 주소값을 연결짓는 부분으로 진행되기에 복사의 단계를 거치지 않기 때문에
	vector에 비해 이점을 가진다고 볼 수 있다.

	끝 삽입/삭제의 경우, vector & list는 같은 이점을 가지고 있다.
	하지만 작동 방식이 다르다는 것을 알아두자.

	3. list의 임의접근에 대하여
	vector의 경우, 연속된 데이터의 배열이라는 개념이 성립된 데이터 구조라는 점에서
	vector<int> v1 = [1,2,3,4,5]; 일 때, v1[3]; 과 같이 간단하게 접근할 수 있다. 
	(연속된 배열의 개념이기에)

	하지만 list의 경우는 반대이다.

	list의 경우, indexing 의 개념이 성립되지 않는데
	이유는 연속된 데이터의 배열이라는 개념이 성립되지 않은 데이터 구조라는 점이 이유이다.
	vector 처럼 1 다음의 데이터가 2가 아닐 수도 있다는 경우가 있다는 것이기에
	indexing 방법이 성립되지 않는다. */

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

	// li[3] = 10 // 없음

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