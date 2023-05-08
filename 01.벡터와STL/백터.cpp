#include <iostream>
#include <vector>
using namespace std;

/* STL (Standard Template Library)
프로그래밍할 때 필요한 자료구조/알고리즘들을 템플릿으로 제공하는 라이브러리

컨테이너 (container) 
데이터를 저장하는 객체 (자료구조 Data Structure)

vector (동적배열)
- vector의 동작 원리 (size/capacity)
- 중간 삽입/삭제
- 처음/끝 삽입/삭제
- 임의 접근 */

int main() {

	/* 배열만으로 게임을 만들기 어려운 이유 (vector 가 필요한 이유) */
	const int MAX_SIZE = 10;
	int arr[MAX_SIZE] = {};

	for (int i = 0; i < MAX_SIZE; i++) {
		arr[i] = i;
	}

	for (int i = 0; i < MAX_SIZE; i++) {
		cout << arr[i] << endl;
	}

	/* 배열은 한번 크기를 정해두면 이를 유종적으로 바꾸는 것에 한계를 맞닥들이게 된다.
	이는 C++를 이용해 MMORPG를 만드는데 있어 엄청난 한계점이 될 수 있는 사항이 된다.
	
	그럼 애당초 배열을 크게 만들면 메모리 낭비가 이루어 지기에 효율적이지 않다. */

	// 동적 배열 (고무줄 처럼 늘어났다가 줄어들었다가 할 수 있다.)
	vector<int> v; 
	v.push_back(1); // 배열의 (마지막에) 값을 추가한다.
	v.pop_back(); // 마지막 값을 삭제한다.

	// 1. size (실제 사용 데이터 개수)
	const int size = v.size();
	for (int i = 0; i < size; i++) {
		cout << v[i] << endl;
	}

	/* 어떤 마법을 부렸길래 배열을 '유동적으로' 사용한 것인가?
	1) [여유분을 두고] 메모리를 할당한다.
	[ [  실제 할당된 배열  ]     앞으로 잡게될 부분에 대한 여유분      ]

	2) 여유분까지 꽉 찼으면, 메모리를 증설한다.
	[ [  실제 할당된 배열  ]     앞으로 잡게될 부분에 대한 여유분      ] + [    메모리 증설    ]
	
	int* arr2[100] = new int[100];
	delete arr2;
	arr = new int[1000]; 의 개념이라고 보면 된다. */

	vector<int> v2;
	// 2. capacity (여유분을 포함한 용량 개수)
	/* 1) 여유분은 얼만큼이 적당할까? */
	for (int i = 0; i < 1000; i++) {
		v2.push_back(100);
		cout << v2.size() << '\t' << v2.capacity() << endl;
	}

	/* 2) 증설을 얼만큼 해야할까? */
	/* size = 1 2 3 4 5 6 7 8 9 <- 들어있는 크기를 출력
	capacity = 1 2 3 4 6 9 13 26 42 63 <- 일정 구간부터 size * 1.5배의 여유분을 가지고 증가  */

	/* 3) 기존의 데이터를 어떻게 처리할까?
	왜 이런 증설방식을 가지고 있는지에 대한 의문이 든다.
	
	게임을 만듬에 있어 얼마만큼의 데이터가 필요한지는 알 수 없다. 
	그렇기에 이를 얼마만큼 할당하고 증설할지에 대한 명확한 답은 없기에
	이를 증설하는 과정에서 여분을 항상 생각하여 vector 라이브러리에서 메모리를 다른곳으로 
	이관(복사)하거나 확장(증설)하는 과정을 진행하고 있는 것이다.

	이러한 복사&확장을 거듭하다보면 안정적인 메모리를 할당한 상태에 도달할 때까지 진행되면서
	에러가 나지 않도록 설계가 된것이라고 보면 된다. */

	// 만약 우리가 capacity에 들어갈 메모리를 유추할 수 있다면 이를 처음부터 정할 수 있다.
	// reserve(); 를 사용하더라도 size > capacity 상태라면 capacity()는 증가한다.
	vector<int> v3;
	v3.reserve(1000);
	for (int i = 0; i < 1001; i++) {
		v3.push_back(100);
		cout << v3.size() << '\t' << v3.capacity() << endl;
	}

	// resize() 를 통해서 vector의 처음크기를 지정할 수 있다.
	// size > capacity 상태라면 당연히 capacity()는 증가한다.
	/* 여기서 중요한 점이 하나 있다.
	v.resize(); 를 통해서 크기를 정했다면 v.push_back(); 을 사용해서는 안된다.
	이미 크기가 만들어진** 상태에서 진행하기 때문에 v.push_back();을 사용한다면 resize()+n의 현상이 일어나기 때문에
	이때 값을 넣고 싶다면 (기존 배열의 방식인) index[] 방식을 이용해야 한다. */
	vector<int> v4(100); // <- 이렇게 resize()를 진행할 수 있다.
	v4.resize(1000);
	for (int i = 0; i < 1001; i++) {
		v4.push_back(100);
		cout << v4.size() << '\t' << v4.capacity() << endl;
	}

	// vector를 초기화 하는 방법
	// capacity는 감소하지 않는다.
	v4.clear();

	// vector의 capacity()를 초기화하는 방법 (꼼수?)
	vector<int>().swap(v4);
	cout << v4.size() << '\t' << v4.capacity() << endl;



	return 0;
}