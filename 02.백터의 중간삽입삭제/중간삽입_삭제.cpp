#include <iostream>
#include <vector>
using namespace std;

int main() {

	// Container : 데이터를 저장하는 객채 ( 자료구조 Data Structure )

	// 반복자(Iterator) : 포인터와 유사한 개념. 컨테이너의 원소(데이터)를 가리키고, 다음/이전 원소로 이동 가능
	vector<int> v(10);

	for (vector<int>::size_type i = 0; i < v.size(); i++) {
		v[i] = i;
	}

	/* iterator == ? pointer 와 비슷한 개념이라고 위에서 설명했다. 그럼 어떻게 다른지에 대해 알아보자. */
	vector<int>::iterator it;
	int* ptr;

	it = v.begin(); // vector의 첫번째 값을 가리키는 기능
	ptr = &v[0];

	cout << (*it) << endl;
	cout << (*ptr) << endl;

	/* 이를 실행하여 메모리를 조사해보면 둘다 같은 값을 가리키고 있다는 것을 알수 있다.
	하지만 it 같은 경우는 ptr과는 다르게 다른 값들을 더 들고 있는 모습을 볼 수 있는데
	이는 어떤 컨테이너에 소속되어 있는지를 알려주는 여러값임을 알 수 있다. (어디에 소속된 포인터 같은 개념) 
	
	반면에 문법은 포인터와 다를바 없다. Iterator를 타고 들어가면 문법 안의 ptr에서 pointer to element in vector가 작성되어 있다. */

	// 다음/이전 데이터 이동
	it++;
	--it;

	// begin 은 처음 값을 가리키는 상태를 의미한다.
	vector<int>::iterator itBegin = v.begin();

	// end 는 마지막 값을 가리키는대 이는 v의 마지막 값이 아닌
	// 마지막 값의 ++가 된 상태임을 알고 있어야 한다. 
	// 무턱대고 v.end()를 통해서 마지막 값을 알려고 하면 이는 유효하지 않은 값을 들고있다는 것을 명심해야 한다.
	// 이는 정말로 vector의 마지막 값을 알기 위해서 사용하는 것이다.
	vector<int>::iterator itEnd = v.end();

	// 거의 이를 문법화 해서 사용하게 될 것이다.
	// 하지만 다른 컨테이너는 v[i]와 같은 인덱스 접근이 안될 수 있다.
	// iterator는 vecrot뿐 아니라, 다른 컨테이너에도 공통적으로 있는 개념이기에
	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
		cout << (*it) << endl;
	}

	// const int*
	vector<int>::const_iterator cit1 = v.cbegin();
	// *cit1 = 100;

	// 반대로 시작점을 잡는 방법 -> 거의 사용된 적은 없으나 알아두면 나쁠건 없다.
	for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); ++it) {
		cout << (*it) << endl;
	}

	return 0;
}