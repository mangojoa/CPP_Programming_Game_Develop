#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

/* using 에 대하여
C++ 11 에서 typedef 을 대처해서 사용할 수 있는 문법이다. */

// 기존의 typedef을 이용한 선언
typedef vector<int>::iterator vecr;
typedef __int64 id;

// 하지만 using 을 사용하는 방법에 대해 알아보자.
using id2 = int;

// 1) 직관성
typedef void(*MyFunc)();
using MyFunc2 = void(*)(); // <- typedef으로 작성한 코드에 비해
// 훨씬 가독성이 현대에 사용되는 코드스타일과 맞게 변화함을 알수 있다.

// 2) 템플릿
// template<typename T>
// typedef void // C++925 Error 가 발생하며
// 템플릿은 기본적으로 typedef과 같이 사용할 수 없다.
// using 이 사용성에 있어 매우 넓고 간단하게 사용할 수 있기에
// C++ 11이후에는 using 을 더 많이 사용하긴 한다.

template<typename A>
using List = std::list<A>;

int main() {

    id playerId = 0;

    List<int> li;

    return 0;
}