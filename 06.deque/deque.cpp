#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <deque>

/* 앞서 배운 것의 정리
vector : 동적배열
list : 이중 연결 리스트

deque : double-ended queue 데크

기존의 데이터는 건들지 않고 새로운 영역을 생성한다.
[        ] [        ] 형태로 데이터를 생성하고 이를 이어붙이는 개념이라고 보면된다 (vector 와 list의 짬뽕) 
*/

int main() {

	/* 시퀀스 컨테이너 (Sequence container)
	데이터가 삽입 순서대로 나열되는 형태 */

	deque<int> dq;

	dq.push_back(1);
	// dq.capacity(); 개념은 존재하지 않는다.
	dq.push_front(2);

	cout << dq[0] << endl; // 임의접근도 가능하다.

	/* vector와 마찬가지로 배열 기반으로 동작
	다만 메모리 할당 정책이 다르게 작동한다.
	
	vector 
	[     ]   ]

	deque
	[1 1 1 ] 데크는 기본적으로 4개의 크기를 가지고 있다고 보면 된다.

	dq.push_back(2); 을 통해 2라는 값을 추가하면 기존의 위치에 추가된 것을 확인할 수 있다.
	[1 1 1 2 ]

	하지만 dq.push_back(2);를 두번 실행하게 되므로써 이야기는 달라진다.
	기존 deque의 크기를 벗어나기 기작한다면 다른영역(메모리)에 dq1[4] 영역을 생성한다는 것이
	vector와 다른점으로 손꼽힌다. 
	
	그렇지만 신기하게도 vector와 같이 임의접근 연산은 얼마든지 가능하다는 점이 매우 신기하다.

	dq.push_front(3); 또한 dq1[4]의 영역으로 값을 밀어내어 존재하게 된다. */

	vector<int> v(3, 1);
	deque<int> dq1(3, 1);

	v.push_back(2);
	v.push_back(2);

	dq1.push_back(2);
	dq1.push_back(2);

	dq1.push_front(3);
	dq1.push_front(3);

	/* deque의 동작원리
	- 처음/끝 십입/삭제 (GOOD/GOOD)
	push_front / push_back

	- 중간 삽입/삭제 (BAD/BAD)
	중간의 데이터를 삭제하는 것은 가능하지만 vector 와 마찬가지로 동작한다.

	- 임의접근 (GOOD)
	임의접근이 매우 용이한 편이다. -> 왜 용이한가?
	vector 와 같은 원리로 동작하는 개념이지만 정확히는 vector 와 list의 짬뽕인 형태로 구성되어있다.

	첫번째 값부터 네번째 값까지 하나의 메모리를 채웠다면 다른 영역에 저장하는 원리를 가지고 있는 것이 
	deque 의 원리이다.

	그럼 5번째 값을 접근하는 방법은 arr[][] 와 같은 방법으로 저장하는 개념이라고 보면된다. 
	[1, 2, 3, 4] <- 1동
	
	[5, 6, 7, 8] <- 2동 

	이렇게 존재한다면 arr[1][0] 과 같은 개념으로 5번째 값에 접근하는 원리이다. */

	dq[3] = 10;
	cout << dq[3] << endl;

	deque<int>::iterator it;

	/* deque의 특징 양방향으로 사용하는 que의 개념이라고 보면된다.
	하지만 특징적으로 2차 배열의 개념과 비슷한 형태이지만 앞뒤로 동작한다는 것이다.
	*/

	return 0;
}