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

	// - 중간 삽입/삭제
	// - 처음/끝 삽입/삭제
	// - 임의 접금
	/* vector = 동적배열 = 동적으로 커지는 배열 => 어쨌든 배열이라는 것이다.
	그렇기에 원소가 하나의 메모리 블록에 연속되어 저장된다는 것인다. */

	/* vector의 중간 삽입/삭제는 매우 비효율적이다!
	[                              ]
	[0] [1] [2] [3] [4] [5] <= 중간에 데이터를 삽입하고 싶다면?
	
	[2] [3] [4] 를 밀어내고 [5]를 넣어주는 과정이 필요하다. (배운대로 한다면 말이다.)
	위의 과정은 데이터를 밀어내고 밀어낸 빈 공간에 데이터를 집어넣는 방식으로 진행된다.
	즉, 한 개 이상의 과정(복사)을 꼭 거치는 방법을 필연적으로 사용하게 된다는 것이다.

	만약, 천만 개의 데이터를 복사한다고 하면 매우 골치아파지게 된다.

	[                              ]
	[0] [1] [2] [3] [4] [5] <= 중간에 데이터를 삭제하고 싶다면?

	간단하게 삭제를 하는 개념이라면 배열의 규칙을 위반할 수 있다.
	배열은 하나의 매모리 블록에 연속되어 존재햐야 한다는 규칙을 가지고 있기에 
	만약 중간의 값을 nullptr로 지정을 해버린다면 Error는 필연적으로 발생할 것이고
	애초에 컴파일러가 허락하지 않는다.

	그렇기에 중간의 데이터를 삭제하게 된다면 삭제한 부분 뒷 부분의 데이터를 
	앞으로 밀어주는 과정(복사)가 이루어지게 되어 프로그램에 부하를 야기할 수 있다.

	일반적으로 vector 같은 경우는 '중간 삽입/삭제'가 매우 비효율적 이다. */

	/* vector의 처음/끝 삽입/삭제는 비효율/효율이다.
	
	[                              ]
	[0] [1] [2] [3] [4] [5] <= 처음에 데이터를 삽입/삭제하고 싶다면?
	중간 삽입/삭제에서 알아본 개념들과 일맥상통한 개념이 작동하기에 = 비효율적이다.

	[                              ]
	[0] [1] [2] [3] [4] [5] <= 끝에 데이터를 삽입/삭제하고 싶다면?
	정말 다행인게, 끝에서 데이터를 삽입/삭제하는 기능은 효율적으로 작동한다.
	기존의 값(들)을 복사하는 과정을 거치지 않고 진행되는 방식이다.

	유일하게 배열의 규칙을 위반하지 않으면서 데이터를 보존하는 방식으로 작동하는 개념이다.

	이에 대한 대표적인 함수로써 push_back(), pop_back() 이 존재한다. */

	/* vector의 임의 접근은 무엇인가?
	배열안에서 어느 지점에 있는 값에 접근할때 보통 arr[i]와 같은 방식으로 진행하는데

	이 방법이 바로 임의접근 Random Access 의 개념이다.

	이는 배열이 하나의 메모리 블록안에 온전히 존재하기에 가능한 것이다.

	즉, 배열이 온전하다면 임의접근은 필연적으로 동작하게 된다는 것이다. */

	/* 위에서 vector의 중간 & 처음/끝 의 삽입/삭제에 대해 알아보았다. 그럼 이를 디버깅을 통해 한번 알아보자.
	우선적으로 진행할 부분은 끝을 제외한 부분의 삽입에 대해 알아보자. (처음/중간의 삽입) */
	v.insert(v.begin(), 5); // <- 이를 살펴보면 어떠한 위치에 무슨 값을 넣을 것인가? 라는 함수이다.

	/* vector에도 처음/중간에 값을 넣을 수 있는 함수는 물론 존재한다. -> v.insert();
	하지만 이는 사용하는데 있어 문제가 발생할 수 밖에 없는 구조가 된다.

	vector<int> v(5) = [0] [1] [2] [3] [4] [5]; 이와 같은 vector가 존재할때,
	처음(중간)에 값을 넣을 경우 -> v.insert(v.begin(), 9);를 실행하게 되면 

	[9] [0] [1] [2] [3] [4] [5] 가 생성이 된다. 동시에 문제가 발생하게 된다. 

	1. capacity가 늘어날 경우 (reserve(); 를 통해 capacity를 정의하지 않은 경우)
	capacity가 늘어나게 되면 더욱 넓은 공간에 복사를 하는 과정이 일어나게 되면서 
	기존에 존재했던 부분에 iterator를 사용했다면 이 iterator는 더이상 사용할 수 없게 된다.
	(즉, 해당 값이 유효하지 않는 값으로 변한다는 것이다.)

	2. reserve(); 를 통해 capacity를 정의했지만 구조적으로 문제가 생기는 경우,
	reserve(); 를 통해 capacity를 정의해서 복사가 되는 과정은 진행되지 않았더라도

	처음(중간)에 값을 넣게 된다면 이는 기존의 값을 뒤로 밀어버리는 현상이 발생한다.
	vector에서 값이 유효한 범위는 정해져 있기에 이를 넘어버리는 현상으로 이어진다는 것이다.
	
	이는 vector를 낭비하는 결과로 이어질 수 있다. */

	/* vector에도 처음/중간에 값을 삭제할 수 있는 함수는 물론 존재한다. -> v.erase();
	인자값에 따라 다양한 값들을 동시에 지울 수 있다는 점도 있다. 
	v.erase(v.begin()); 
	v.erase(v.begin(), v.begin()+2); 어디부터 어디까지의 개념으로 작동한다.

	하지만 문제는 범위를 선택하여 삭제를 진행할 경우, 문제가 발생한다.

	vector<int> v(5) = [0] [1] [2] [3] [4] [5]; 이와 같은 vector가 존재할때,
	v.erase(v.begin()); 을 실행하면 당연히 [0] 값만 사라지게 된다.

	v.erase(v.begin(), v.begin()+2); 를 실행한다면?
	[0] [1] [2] 값이 사라져야 한다고 생각할 수 있지만 전혀 아니다.

	범위를 정한 erase의 두 번째 인자값은 v.end()의 성격을 지니고 있다.
	그렇기에 실제로 지워지는 값은 [0] [1] 뿐이다. */
	v.erase(v.begin()); // <- 어떠한 위치의 값을 삭제할 것인가? 라는 함수이다.
	v.erase(v.begin()+2, v.begin()+4); // <- 어떠한 위치부터 어디까지의 값을 삭제할 것인가? 라는 함수이다.



	return 0;
}