#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

/* using �� ���Ͽ�
C++ 11 ���� typedef �� ��ó�ؼ� ����� �� �ִ� �����̴�. */

// ������ typedef�� �̿��� ����
typedef vector<int>::iterator vecr;
typedef __int64 id;

// ������ using �� ����ϴ� ����� ���� �˾ƺ���.
using id2 = int;

// 1) ������
typedef void(*MyFunc)();
using MyFunc2 = void(*)(); // <- typedef���� �ۼ��� �ڵ忡 ����
// �ξ� �������� ���뿡 ���Ǵ� �ڵ彺Ÿ�ϰ� �°� ��ȭ���� �˼� �ִ�.

// 2) ���ø�
// template<typename T>
// typedef void // C++925 Error �� �߻��ϸ�
// ���ø��� �⺻������ typedef�� ���� ����� �� ����.
// using �� ��뼺�� �־� �ſ� �а� �����ϰ� ����� �� �ֱ⿡
// C++ 11���Ŀ��� using �� �� ���� ����ϱ� �Ѵ�.

template<typename A>
using List = std::list<A>;

int main() {

    id playerId = 0;

    List<int> li;

    return 0;
}