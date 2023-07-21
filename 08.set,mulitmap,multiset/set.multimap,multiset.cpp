#include <iostream>
using namespace std;

#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>

int main() {
	set<int> s;
	
	/* set의 기능 (value = key 가 일치하는 개념으로 작동한다고 보면된다)
	넣고
	빼고
	찾고
	순회하고
	*/

	// 넣고
	s.insert(10);
	s.insert(70);
	s.insert(30);
	s.insert(60);
	s.insert(50);

	// 빼고
	s.erase(60);

	// 찾고
	set<int>::iterator findIt = s.find(50);
	if (findIt == s.end()) cout << "not find" << endl;
	else cout << "find" << endl;

	// s[10] = 10; // 이전과 같은 방법은 막혀있다.

	// 순회하고
	for (set<int>::iterator it = s.begin(); it != s.end(); ++it) {
		cout << (*it) << endl;
	}
	
	/* ------------------------------------------------------------- */
	cout << "-------------------------------------------------" << endl;
	
	/* multimap => 기존의 map 과 다른 점은 중복치를 허용한다는 점 */

	multimap<int, int> mm;

	// 넣고 (기존의 map에서는 key값이 중복될 수 없지만 multimap 에서는 이 부분이 허용된 개념이라고 보면된다.)
	mm.insert(make_pair(1, 100));
	mm.insert(make_pair(1, 200));
	mm.insert(make_pair(1, 300));
	mm.insert(make_pair(2, 400));
	mm.insert(make_pair(2, 500));
	
	// mm[1] = 400; // 이 기능은 막혀있다.

	// 빼고 (이는 key를 대상으로 값을 삭제하는 함수인데 / key값이 중복되는 multimap에서는 중복된 모든 값을 전부 삭제한다.)
	unsigned int count = mm.erase(1);

	// 찾고 (원하는 값을 정확히 삭제하고 싶다면 그 값이 위치한 자리를 알고 있어야 한다.)
	// 위와 같이 나열된 key 상태로 되어있다면
	// mm.find(itFind); 반환값인 iterator 를 find() 함수를 통해 접근하면 그 위치를 알 수 있다.
	/* iterator => mm.insert(make_pair(1, 100)); 값을 가리키는 상태에서 
	전위 연산자 (++) 를 통해 다음값 혹은 이전값으로 이동하여 삭제를 진행할 수 있다. */
	multimap<int, int>::iterator itFind = mm.find(1);
	if (itFind != mm.end()) mm.erase(itFind);

	// 순회하고
	pair<multimap<int, int>::iterator, multimap<int, int>::iterator> itPair;
	itPair = mm.equal_range(1);

	for (multimap<int, int>::iterator it = itPair.first; it != itPair.second; ++it) {
		cout << (*it).first << " " << (*it).second << endl;
	}

	multimap<int, int>::iterator itBegin = mm.lower_bound(1);
	multimap<int, int>::iterator itEnd = mm.upper_bound(1);

	for (multimap<int, int>::iterator it = itBegin; it != itEnd; ++it) {
		cout << (*it).first << " " << (*it).second << endl;
	}

	/* ------------------------------------------------------------- */
	cout << "-------------------------------------------------" << endl;

	/* multiset => 기존의 set 과 다른 점은 중복치를 허용한다는 점
	*/

	return 0;
}